//
// Created by Yoo Cherry on 01.10.24.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "database/databasemanager.h"

class DatabaseManagerTest : public ::testing::Test {
    void SetUp() override {
    };

    void TearDown() override {
    };
};

// I need a mock class because I don't want to establish a real database connection for testing
// In this case I simulate those important objects through a mock-object... (can be understood
// as a placeholderobject)
class MockDatabaseManager : public DatabaseManager {
public:
};


// --------- End Declaration ----------

TEST(DatabaseManagerTest, createdValidDatabaseObject) {
    bool isConnectionValid = false;

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

    isConnectionValid = db.isValid();
    EXPECT_TRUE(isConnectionValid);
}
