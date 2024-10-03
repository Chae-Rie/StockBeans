//
// Created by Yoo Cherry on 01.10.24.
//
#include <gtest/gtest.h>
#include "../lib/src/database/databasemanager.h"

class DatabaseManagerTest : public ::testing::Test {
  void SetUp() override {
  };

  void TearDown() override {
  };
};

TEST_F(DatabaseManagerTest, initializeDatabaseConnectionSucceeded) {
  bool expectedOutput{true};
  bool actualOutput = {false};
  ASSERT_EQ(expectedOutput, actualOutput);
}

