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


# Sammeln der Dateien für die Unittests
set (TEST_SOURCES
    tests/testmain.cpp
)



# Fügen Sie Unittests hinzu
# Jetzt bekommt also die .exe für die Tests alle Inhalte der PROJECT_SOURCES und
# der offensichtlichen Testdateien (die hoffentlich immer test im Namen haben)
# sie heißt mediaSelectorTests
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(StockBeansTests
        ${PROJECT_SOURCES}
        #${LIB_SOURCES}
        ${TEST_SOURCES}
    )
else()
    add_executable(StockBeansTests
        ${PROJECT_SOURCES}
        #${LIB_SOURCES}
        ${TEST_SOURCES}
    )
endif()

# Pakete mit der Test-Executable verbinden
target_link_libraries(StockBeansTests PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
)



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
