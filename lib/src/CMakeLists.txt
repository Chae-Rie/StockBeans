cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Setting up all the relevant files for the main.cpp in the StockBeansApp
set(LIB_SOURCES
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    databasemanager.h databasemanager.cpp
    logindialog.h logindialog.cpp logindialog.ui
    helperfunction.h helperfunction.cpp
    corelogger.h corelogger.cpp
    types.h
)

# Adds everything together so the result is a static library which can be linked from the StockBeansApp and StockBeansTests
# It is just more easy to manage the different executeables when the logical codebase is compiled to a library
# You can see that decision more as a decision of making my life a bit easier rather than compiling it to a "real" library
add_library(StockBeansLib STATIC
    ${LIB_SOURCES}

)

# Here I only need to link everything together
target_link_libraries(StockBeansLib PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Sql
        spdlog::spdlog
)
