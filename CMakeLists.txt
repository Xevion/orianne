cmake_minimum_required(VERSION 3.16)
project(Orianne LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui UiTools Widgets)

# Bake commit hash, build date/type & target platform into the binary so
# artifacts are self-describing (see README Concerns).
find_package(Git QUIET)
set(ORIANNE_GIT_HASH "unknown")
set(ORIANNE_GIT_DIRTY 0)
if(Git_FOUND)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} rev-parse --short=8 HEAD
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE ORIANNE_GIT_HASH_OUT
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET
        RESULT_VARIABLE ORIANNE_GIT_HASH_RESULT
    )
    if(ORIANNE_GIT_HASH_RESULT EQUAL 0 AND ORIANNE_GIT_HASH_OUT)
        set(ORIANNE_GIT_HASH "${ORIANNE_GIT_HASH_OUT}")
    endif()

    execute_process(
        COMMAND ${GIT_EXECUTABLE} status --porcelain
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE ORIANNE_GIT_DIRTY_OUT
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET
    )
    if(ORIANNE_GIT_DIRTY_OUT)
        set(ORIANNE_GIT_DIRTY 1)
    endif()
endif()

string(TIMESTAMP ORIANNE_BUILD_DATE "%Y-%m-%dT%H:%M:%SZ" UTC)

if(NOT CMAKE_BUILD_TYPE)
    set(ORIANNE_BUILD_TYPE "Unspecified")
else()
    set(ORIANNE_BUILD_TYPE "${CMAKE_BUILD_TYPE}")
endif()

if(WIN32)
    set(ORIANNE_PLATFORM "windows")
elseif(APPLE)
    set(ORIANNE_PLATFORM "macos")
else()
    set(ORIANNE_PLATFORM "linux")
endif()

configure_file(
    "${CMAKE_SOURCE_DIR}/src/Version.h.in"
    "${CMAKE_BINARY_DIR}/generated/Version.h"
    @ONLY
)

message(STATUS "Orianne version: hash=${ORIANNE_GIT_HASH} dirty=${ORIANNE_GIT_DIRTY} date=${ORIANNE_BUILD_DATE} type=${ORIANNE_BUILD_TYPE} platform=${ORIANNE_PLATFORM}")

file(GLOB orianne_SRC
     "src/*.h"
     "src/*.cpp"
)

qt_add_executable(Orianne ${orianne_SRC})

target_include_directories(Orianne PRIVATE "${CMAKE_BINARY_DIR}/generated")

# Precompiling the Qt headers cuts a meaningful chunk off clean-build time;
# FlowLayout.cpp/main.cpp both drag in most of QtWidgets already.
target_precompile_headers(Orianne PRIVATE
    <QtWidgets/QApplication>
    <QtWidgets/QWidget>
    <QtCore/QString>
)

set_target_properties(Orianne PROPERTIES
    WIN32_EXECUTABLE TRUE  # Required for GUI executables
    MACOSX_BUNDLE TRUE  # Required for GUI executables to be launchable from Finder
)

target_link_libraries(Orianne PUBLIC
    Qt::Core
    Qt::Gui
    Qt::UiTools
    Qt::Widgets
)

qt6_add_resources(Orianne "Orianne"
    PREFIX
        "/forms"
    FILES
        "src/form.ui"
)

if(NOT INSTALL_EXAMPLEDIR)
    set(INSTALL_EXAMPLEDIR "bin")
endif()

install(TARGETS Orianne
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
