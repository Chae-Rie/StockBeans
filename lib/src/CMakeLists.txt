cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# In der Root-CMakeLists.txt werden die Pakete die es für die Anwendung
# braucht gefunden und hier müssen dann nur noch die einzelnen Dateien gefunden und gelinkt werden

set(LIB_SOURCES
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    databasemanager.h databasemanager.cpp
    logindialog.h logindialog.cpp logindialog.ui
    helperfunction.h helperfunction.cpp
    types.h
)

# Eine statische Bibliothek erzeugen, auf die sich unter anderem das Testprojekt beziehen wird
add_library(StockBeansLib STATIC
    ${LIB_SOURCES}

)

# Verknüpfen der Bibliothek mit allem was sie braucht um lauffähig zu sein
target_link_libraries(StockBeansLib PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Sql
)
