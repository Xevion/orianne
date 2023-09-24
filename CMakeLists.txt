cmake_minimum_required(VERSION 3.16)
project(TestTaker LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui UiTools Widgets)

qt_add_executable(TestTaker src/main.cpp)

set_target_properties(TestTaker PROPERTIES
    WIN32_EXECUTABLE TRUE  # Required for GUI executables
    MACOSX_BUNDLE TRUE  # Required for GUI executables to be launchable from Finder
)

target_link_libraries(TestTaker PUBLIC
    Qt::Core
    Qt::Gui
    Qt::UiTools
    Qt::Widgets
)

qt6_add_resources(TestTaker "TestTaker"
    PREFIX
        "/forms"
    FILES
        "src/form.ui"
)

install(TARGETS TestTaker
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
