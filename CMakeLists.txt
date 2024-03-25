cmake_minimum_required(VERSION 3.5)

project(StockBeans VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ausmachen der QT-Pakete
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS
    Widgets
)

set(PROJECT_SOURCES
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

# Alles was ich fernab der GUI erzeuge und kein Test ist, wird hier erfasst
# set (LIB_SOURCES

# )

# Erstelle eine statische Bibliothek für das Hauptprojekt
# Hier ist alles drin außerhalb der Main-Schleifen
add_library(StockBeansLib STATIC
    ${PROJECT_SOURCES}
    # ${LIB_SOURCES}
)

# Verknüpfen der Bibliothek mit allem was sie braucht um lauffähig zu sein
target_link_libraries(StockBeansLib PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
)

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
