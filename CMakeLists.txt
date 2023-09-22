cmake_minimum_required(VERSION 3.16)
project(testtaker LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/designer/testtaker")

find_package(Qt6 REQUIRED COMPONENTS Core Gui UiTools Widgets)

qt_add_executable(testtaker main.cpp)

set_target_properties(testtaker PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

#! [0]
target_link_libraries(testtaker PUBLIC
    Qt::Core
    Qt::Gui
    Qt::UiTools
    Qt::Widgets
)
#! [0]

qt6_add_resources(testtaker "testtaker"
    PREFIX
        "/forms"
    FILES
        "calculatorform.ui"
)

install(TARGETS testtaker
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
