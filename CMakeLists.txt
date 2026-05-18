cmake_minimum_required(VERSION 3.19)
project(OutputHooker LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets SerialPort Network Multimedia)

qt_standard_project_setup()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(app_icon_resource_windows "${CMAKE_CURRENT_SOURCE_DIR}/version.rc")

qt_add_executable(OutputHooker
    WIN32 MACOSX_BUNDLE
    main.cpp ${app_icon_resource_windows}
    OutputHooker.cpp
    OutputHooker.h
    OutputHooker.ui
    Global.h
    core/COMPortModule.h core/COMPortModule.cpp
    core/HidapiModule.h core/HidapiModule.cpp
    core/LedWizModule.h core/LedWizModule.cpp
    core/NetCmdModule.h core/NetCmdModule.cpp
    core/OutputHookerConfig.h core/OutputHookerConfig.cpp
    core/OutputHookerCore.h core/OutputHookerCore.cpp
    core/PacDriveModule.h core/PacDriveModule.cpp
    core/SdlCtrlModule.h core/SdlCtrlModule.cpp
    core/TCPSocketModule.h core/TCPSocketModule.cpp
    core/WinMsgModule.h core/WinMsgModule.cpp
    gui/DeviceWindow.h gui/DeviceWindow.cpp gui/DeviceWindow.ui
    gui/TestOutputWindow.h gui/TestOutputWindow.cpp gui/TestOutputWindow.ui
    gui/EditorWindow.h gui/EditorWindow.cpp gui/EditorWindow.ui
    gui/EditorAddCmdWindow.h gui/EditorAddCmdWindow.cpp gui/EditorAddCmdWindow.ui
    gui/EditorAddKeyStateWindow.h gui/EditorAddKeyStateWindow.cpp gui/EditorAddKeyStateWindow.ui
    gui/AboutWindow.h gui/AboutWindow.cpp gui/AboutWindow.ui
    gui/GuiUtilities.h
    gui/SyntaxHighlighter.h
    resources/resources.qrc
    sounds/notification.wav
    ini/default.ini
    ini/digdug.ini
)

target_include_directories(OutputHooker
    PRIVATE
    ${Qt6Core_INCLUDE_DIRS}
    ${Qt6Widgets_INCLUDE_DIRS}
    ${Qt6SerialPort_INCLUDE_DIRS}
    ${Qt6Network_INCLUDE_DIRS}
    ${Qt6Multimedia_INCLUDE_DIRS}
    C:/HIDAPI/include
    C:/LEDWizSDK
    C:/PacDriveSDK
    C:/SDL3/include
)

target_link_directories(OutputHooker
    PRIVATE
    C:/HIDAPI/x64
    C:/LEDWizSDK
    C:/PacDriveSDK
    C:/SDL3/lib/x64
)

target_link_libraries(OutputHooker
    PRIVATE
        Qt6::Core
        Qt6::Widgets
        Qt6::SerialPort
        Qt6::Network
        Qt6::Multimedia
        user32
        hidapi
        PacDrive64
        SDL3
)

target_link_options(OutputHooker PRIVATE "-Wl,--start-group")

include(GNUInstallDirs)

install(TARGETS OutputHooker
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET OutputHooker
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
    NO_TRANSLATIONS
)

install(SCRIPT ${deploy_script})
