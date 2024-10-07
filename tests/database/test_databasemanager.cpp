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

class MockDatabaseManager : public DatabaseManager {
public:
    // simulate the QSql methods
    MOCK_METHOD(bool, open, (), ());
    MOCK_METHOD(void, setHostName, (const QString&), ());
    MOCK_METHOD(void, setPort, (int), ());
    MOCK_METHOD(void, setDatabaseName, (const QString&), ());
    MOCK_METHOD(void, setUserName, (const QString&), ());
    MOCK_METHOD(void, setPassword, (const QString&), ());
    MOCK_METHOD(QSqlError, lastError, (), ());
};


TEST(DatabaseManagerTest, ConnectSuccess) {
    MockDatabaseManager mockDb;
    DatabaseManager dbManager;

    EXPECT_CALL(mockDb, setHostName(QString("localhost")));
    EXPECT_CALL(mockDb, setPort(5432));
    EXPECT_CALL(mockDb, setDatabaseName(QString("testdb")));
    EXPECT_CALL(mockDb, setUserName(QString("user")));
    EXPECT_CALL(mockDb, setPassword(QString("pass")));
    EXPECT_CALL(mockDb, open()).WillOnce(testing::Return(true));

    // I dont get this...
    //  bool connected = dbManager.connect(mockDb, "localhost", "5432", "testdb", "user", "pass");
    // EXPECT_TRUE(connected);
}

TEST_F(DatabaseManagerTest, initializeDatabaseConnectionSucceeded) {
    bool expectedOutput{true};
    bool actualOutput = {false};
    ASSERT_EQ(expectedOutput, actualOutput);
}

