cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Setting up all the relevant files for the main.cpp in the StockBeansApp
set(UI_SOURCES
        logindialog.ui
        logindialog.cpp
        logindialog.h
        mainwindow.ui
        mainwindow.cpp
        mainwindow.h
)

#[[
add_library(StockBeansLib STATIC ${DATABASE_SOURCES})

# Here I only need to link everything together
target_link_libraries(StockBeansLib PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Sql
        spdlog::spdlog
        nlohmann_json::nlohmann_json
        MyTools_lib::MyTools_lib
)
]]
