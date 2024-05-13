cmake_minimum_required(VERSION 3.5)

project(StockBeans VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Setting Custom Environment variables
#set(QT_DEBUG_PLUGINS ON)

# Ausmachen der QT-Pakete
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS
    Widgets
    Sql
)


add_subdirectory(lib/src/)

# Hiervor müssen die LibSources und projectSources feststehen
add_subdirectory(tests)

#
# Erstelle die Anwendung, achte auf den Suffix App
add_executable(StockBeansApp
    main.cpp
)


# Verknüpfen der gefundenen Pakete mit der Anwendungs-Target
# Heißt die ausführbare Datei
target_link_libraries(StockBeansApp PRIVATE
    StockBeansLib
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Sql
)

# Setze die Ziel-Eigenschaften für die Unittests
set_target_properties(StockBeansTests PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    BUNDLE_ID "com.example.StockBeansTests.tests"
)

# Setze die Ziel-Eigenschaften für die Anwendung
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

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(StockBeansApp)
endif()
