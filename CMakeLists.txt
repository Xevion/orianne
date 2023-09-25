cmake_minimum_required(VERSION 3.16)
project(Orianne LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui UiTools Widgets)

file(GLOB orianne_SRC
     "src/*.h"
     "src/*.cpp"
)

qt_add_executable(Orianne ${orianne_SRC})

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

install(TARGETS Orianne
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
