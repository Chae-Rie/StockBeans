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


TEST_F(DatabaseManagerTest, initializeDatabaseConnectionSucceeded) {
  bool expectedOutput{true};
  bool actualOutput = {false};
  ASSERT_EQ(expectedOutput, actualOutput);
}

