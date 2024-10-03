cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Setting up all the relevant files for the main.cpp in the StockBeansApp
#set(LIB_SOURCES
#        ui/mainwindow.cpp
#        ui/mainwindow.h
#        ui/mainwindow.ui
#        database/databasemanager.h database/databasemanager.cpp
#        ui/logindialog.h ui/logindialog.cpp ui/logindialog.ui
#        util/helperfunction.h util/helperfunction.cpp
#        util/corelogger.h util/corelogger.cpp
#        database/types.h
#        util/settings.h util/settings.cpp
#)

# calling the different CMakeLists.txt to gather all the needed sources
add_subdirectory(database/)
add_subdirectory(ui/)
add_subdirectory(util)

# adds all the stuff together
add_library(StockBeansLib STATIC ${DATABASE_SOURCES} ${UTIL_SOURCES} ${UI_SOURCES})

# links all the sources with the needed thirdparty libs
target_link_libraries(StockBeansLib PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Sql
        spdlog::spdlog
        nlohmann_json::nlohmann_json
        MyTools_lib::MyTools_lib
)