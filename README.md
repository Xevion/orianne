# Orianne

A Qt6 application for administering tests. Highly experimental.

Feature Targets:
- Cross platform (Windows, Linux, Mac)
- Automatic build scripts with Workflows
- Multilingual support (English, Spanish)
    - UI support would be straightforward, but the test content could not be translated easily.
- Commandline Options
    - `--test <test_file>`: Open a test file on startup
    - `--lang <language>`: Set the language on startup
- Profile

## Concerns

- Testing on VDI
    - It's important that these builds are fully compatible on the VDI machines (Windows, no admin privileges).
    - Potential for integration testing on VDI-like machines?
- MacOS ARM/Intel support
    - ARM machines are notorious for not supporting lots of software, but many students have Macs. Testing on both architectures is important.
- Release/Debug builds
    - It would be good to have debug builds availble for testing.
- Runtime & Build-time Version
    - Version, environment type & target information is important to have available at both runtime & build time.
    - Builds must have artifacts that contain this information automatically.
    - Commit hash, build date, build type, target platform, etc.

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