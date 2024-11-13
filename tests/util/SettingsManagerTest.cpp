//
// Created by Yoo Cherry on 13.11.24.
//

#include <gtest/gtest.h>
#include <util/SettingsManager.h>

class SettingsManagerTest : public testing::Test {
   // TODO: create a mock object for the logfile so I can test it..
};

TEST(SettingsManagerTest, LoadConfigfileSucess) {
   SettingsManager settingsManager("test.settings.json");
}
