cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DATABASE_SOURCES
        database/databasemanager.cpp
        database/databasemanager.h
        database/IDatabase.h
        database/SqlDatabaseWrapper.cpp
        database/SqlDatabaseWrapper.h
        database/sqlquery.cpp
        database/sqlquery.h
        database/types.h
)

set(UI_SOURCES
        ui/LoginDialog.ui
        ui/logindialog.cpp
        ui/logindialog.h
        ui/MainWindow.ui
        ui/mainwindow.cpp
        ui/mainwindow.h
)

set(UTIL_SOURCES
        util/corelogger.cpp
        util/corelogger.h
        util/helperfunction.cpp
        util/helperfunction.h
)
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