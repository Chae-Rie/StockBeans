cmake_minimum_required(VERSION 3.5)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Sammeln der Dateien für die Unittests

add_subdirectory(database/)
add_subdirectory(util/)
#add_subdirectory(ui/)

set(TEST_SOURCES
        testmain.cpp
        ${TEST_DATABASE_SOURCES}
        ${TEST_UTIL_SOURCES}
)

find_package(GTest CONFIG REQUIRED)


# Fügen Sie Unittests hinzu
# Jetzt bekommt also die .exe für die Tests alle Inhalte der PROJECT_SOURCES und
# der offensichtlichen Testdateien (die hoffentlich immer test im Namen haben)
if (${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(StockBeansTests
            ${TEST_SOURCES}
    )
else ()
    add_executable(StockBeansTests
            ${TEST_SOURCES}
    )
endif ()


# Bevor diese CMakeLists.txt ausgeführt wird, werden bereits die notwendigen Pakete
# mit findpackage gefunden, heißt hier müssen sie nur noch gelinked werden
# Pakete mit der Test-Executable verbinden
target_link_libraries(StockBeansTests PRIVATE
        StockBeansLib
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Sql
        MyTools_lib::MyTools_lib
        spdlog::spdlog
        nlohmann_json::nlohmann_json
        GTest::gtest
        GTest::gtest_main
)

enable_testing()
add_test(NAME MyTests COMMAND tests)
