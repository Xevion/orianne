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

## Deployment

Deployment strategies are still highly experimental, use the list below to develop, improve & form best practices for cross platform development & deployment.

- Deployment Systems
    - [linuxdeployqt](https://github.com/probonopd/linuxdeployqt)
    - [linuxdeploy](https://github.com/linuxdeploy/linuxdeploy) (not used at this moment)
    - [macdeployqt](https://doc.qt.io/qt-5/macos-deployment.html#macdeploy)
    - [windeployqt](https://doc.qt.io/qt-6/windows-deployment.html)
- Workflow References
    - [QOwnNotes (build-release.yaml)](https://github.com/pbek/QOwnNotes/blob/main/.github/workflows/build-release.yml)
        - Windows, MacOS, Linux AppImage (`linuxdeploy`), Linux Snap
        - Lots of heavily involved build systems. Advanced application.
    - Ripes
        - [linux-release.yml](https://github.com/mortbopet/Ripes/blob/master/.github/workflows/linux-release.yml) (AppImage with `linuxdeployqt`)
        - [windows-release.yml](https://github.com/mortbopet/Ripes/blob/master/.github/workflows/windows-release.yml) (Ninja build)
        - [mac-release.yml](https://github.com/mortbopet/Ripes/blob/master/.github/workflows/mac-release.yml)
        - Simpler build systems.
        - WASM target.