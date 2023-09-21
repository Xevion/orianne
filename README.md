# test-taker

A Qt6 application for administering tests. Highly experimental.

Feature Targets:
- Cross platform (Windows, Linux, Mac)
- Automatic build scripts with Workflows

## VS Code

- Requirements
    - C/C++ Extension
    - CMake Tools Extension
- Configuraiton
    - `c_cpp_properties.json` (C/C++ Extension)
        - `configurations[].configurationProvider` must be set to `ms-vscode.cmake-tools`
    - `settings.json`
        - `cmake.configureArgs` must contain `-DCMAKE_PREFIX_PATH=<QT_INSTALL_DIR>`
            - For example, my QT installation directory was `/home/xevion/Qt/6.5.2/gcc_64`