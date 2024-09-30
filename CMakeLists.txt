cmake_minimum_required(VERSION 3.5)

project(StockBeans VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Setting Custom Environment variables
#set(QT_DEBUG_PLUGINS ON)

if (NOT PROJECT_IS_TOP_LEVEL)
    message(FATAL_ERROR "project is intended to be a standalone, top-level project. Do not vendor this directory.")
endif ()

# resolve some important paths:
#       - Some of the packages are installed on my dev machine, like QT... I won't be setting them into the project
#       - Some of the packages are going to be resolved automatically, when I specify the vcpkg-toolchain
#       - Some of the packages are NOT going to be resolved automatically, so I just specify the path manually...
# ----------------------------------------------------------------------------------------------------------------------
# First get the vcpkg-toolchain file and use it for all the packages installed
set(CMAKE_TOOLCHAIN_FILE
        ${CMAKE_CURRENT_LIST_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING
        "Vcpkg toolchain file"
)

# the vcpkg_installed-directory is the one where installed packages in the manifest mode are going to be placed
# this is highly propretary because I hardcode the OS, but this will be a problem of another day. The share-directory
# is working fine.
set(nlohmann_json_DIR "${CMAKE_CURRENT_LIST_DIR}/vcpkg_installed/arm64-osx/share/nlohmann_json")
set(GTest_DIR "${CMAKE_CURRENT_LIST_DIR}/vcpkg_installed/arm64-osx/share/gtest")
# QT paths on the dev machine... using QT 6.6.2 --> make sure the path is still valid after some updates on the framework
set(CMAKE_PREFIX_PATH "$ENV{HOME}/dev/qt_framework/6.6.2/macos")
set(QT_DIR "$ENV{HOME}/dev/qt_framework/6.6.2/macos/lib/cmake/Qt6")

# This is the place where I installed my lib and where my cmake files are located
set(MyTools_lib_DIR "${CMAKE_CURRENT_LIST_DIR}/cmake/MyTools/cmake")
find_package(MyTools_lib 1 CONFIG REQUIRED)

# now it finds the packages for the QT files
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS
        Widgets
        Sql
)

# TODO: Exclude the GetSourceDir-Function out of the fileparser, to make it widely accessible, bc. I don't want the fileparser anymore
# Needed for one function in the lib -> fileparser.h -> uses this macro to specify where the source-directory is to orientate itself
add_compile_definitions(SOURCE_DIR="${CMAKE_SOURCE_DIR}")

# logging library
find_package(spdlog CONFIG REQUIRED)
# library for managing json files
find_package(nlohmann_json CONFIG REQUIRED)

find_package(GTest CONFIG)

add_subdirectory(lib/src/)

# I need all the project sources here already
add_subdirectory(tests)

# Create the main-App, there are also StockBeans-Lib and Tests, so take care
add_executable(StockBeansApp
        main.cpp
)

# Verknüpfen der gefundenen Pakete mit der Anwendungs-Target
# Heißt die ausführbare Datei
target_link_libraries(StockBeansApp PRIVATE
        StockBeansLib
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Sql
        MyTools_lib::MyTools_lib
        spdlog::spdlog
        nlohmann_json::nlohmann_json
        GTest::gtest
        GTest::gtest_main
)

# Setting properties for the tests
set_target_properties(StockBeansTests PROPERTIES
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
        BUNDLE_ID "com.example.StockBeansTests.tests"
)

# Setting properties for the App
set_target_properties(StockBeansApp PROPERTIES
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
        BUNDLE_ID "com.example.StockBeansTests.app"
)

include(GNUInstallDirs)
install(TARGETS StockBeansApp StockBeansLib
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(StockBeansApp)
endif ()
