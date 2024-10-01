//
// Created by Yoo Cherry on 01.10.24.
//

#include <gtest/gtest.h>
#include "../lib/src/helperfunction.h"

class HelperFunctionTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};


TEST_F(HelperFunctionTest, CalculateSHA256Hash_EmptyInput) {
    QString input = "";
    QString expectedOutput = "";
    ASSERT_EQ(HelperFunction::CalculateSHA256Hash(input), expectedOutput);
}

TEST_F(HelperFunctionTest, CalculateSHA256Hash_DifferentCharsets) {
    QString input = "你好, 世界!"; // "Hello, World!" on chinese :D
    QString expectedOutput = "12477654131605bfc19ba5a3862ac54f18f9140509fcb3c1faad687c75ff64d1";
    ASSERT_EQ(HelperFunction::CalculateSHA256Hash(input), expectedOutput);
}

TEST_F(HelperFunctionTest, CalculateSHA256Hash_NumericInput) {
    QString input = "1234567890";
    QString expectedOutput = "c775e7b757ede630cd0aa1113bd102661ab38829ca52a6422ab782862f268646";
    ASSERT_EQ(HelperFunction::CalculateSHA256Hash(input), expectedOutput);
}

TEST_F(HelperFunctionTest, CalculateSHA256Hash_SpecialCharacters) {
    QString input = "!@#$%^&*()_+";
    QString expectedOutput = "36d3e1bc65f8b67935ae60f542abef3e55c5bbbd547854966400cc4f022566cb";
    ASSERT_EQ(HelperFunction::CalculateSHA256Hash(input), expectedOutput);
}

