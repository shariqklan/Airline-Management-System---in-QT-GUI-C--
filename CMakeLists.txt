cmake_minimum_required(VERSION 3.5)

project(Task2Cmake VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        newindow1.h
        newindow1.cpp
        newindow1.ui
        newwindow2.h
        newwindow2.cpp
        newwindow2.ui
        newwindow3.h
        newwindow3.cpp
        newwindow3.ui
        reviewticket.h
        reviewticket.cpp
        reviewticket.ui
        complain.h
        complain.cpp
        complain.ui
        adminportal.h
        adminportal.cpp
        adminportal.ui
        adminmenu.h
        adminmenu.cpp
        adminmenu.ui
        bill.h
        bill.cpp
        bill.ui
        cancelticket.h
        cancelticket.cpp
        cancelticket.ui
        updateticket.h
        updateticket.cpp
        updateticket.ui
        complainreview.h
        complainreview.cpp
        complainreview.ui
        paktour.h
        paktour.cpp
        paktour.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Task2Cmake
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Task2Cmake APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Task2Cmake SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Task2Cmake
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Task2Cmake PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Task2Cmake PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Task2Cmake
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Task2Cmake)
endif()



