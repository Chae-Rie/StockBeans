cmake_minimum_required(VERSION 3.5)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# shortening the needed include paths
include_directories(${CMAKE_CURRENT_LIST_DIR}/../lib/src/)

set(TEST_DATABASE_SOURCES
        database/DatabaseManagerTest.cpp
        database/MockDatabase.h
)

set(TEST_UTIL_SOURCES
        util/HelperFunctionTest.cpp
)


set(COMBINED_TEST_SOURCES
        testmain.cpp
        ${TEST_DATABASE_SOURCES}
        ${TEST_UTIL_SOURCES}
)

find_package(GTest CONFIG REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Fügen Sie Unittests hinzu
# Jetzt bekommt also die .exe für die Tests alle Inhalte der PROJECT_SOURCES und
# der offensichtlichen Testdateien (die hoffentlich immer test im Namen haben)
if (${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(StockBeansTests
            ${COMBINED_TEST_SOURCES}
    )
else ()
    add_executable(StockBeansTests
            ${COMBINED_TEST_SOURCES}
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
        ${GTEST_BOTH_LIBRARIES}
        pthread
)

enable_testing()
add_test(NAME MyTests COMMAND tests)
