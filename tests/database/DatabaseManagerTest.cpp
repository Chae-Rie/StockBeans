//
// Created by Yoo Cherry on 01.10.24.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "database/DatabaseManager.h"
#include "MockDatabase.h"
#include "util/Settings.h"

class MockSettings {
public:
    static Settings::AppConfig getTestAppConfig() {
        Settings::AppConfig config;
        config.databaseSettings.host = "localhost";
        config.databaseSettings.port = 6379;
        config.databaseSettings.user = "root";
        config.databaseSettings.password = "root";
        config.databaseSettings.dbName = "supercooldb1!";
        return config;
    }
};

class DatabaseManagerTest : public ::testing::Test {
protected:
    void SetUp() override {
        m_config = MockSettings::getTestAppConfig();
    };

    Settings::AppConfig m_config;
    MockDatabase m_mockDatabase;
};


// --------- End Declaration ----------

// TODO: The following lines are producing heavy linker errors... please get behind that
// TEST_F(DatabaseManagerTest, ConnectsToDatabaseSuccessfully) {
//     EXPECT_CALL(m_mockDatabase, setHostName(QString("localhost")));
//     EXPECT_CALL(m_mockDatabase, setDatabaseName(QString("test_db")));
//     EXPECT_CALL(m_mockDatabase, setUserName(QString("test_user")));
//     EXPECT_CALL(m_mockDatabase, setPassword(QString("test_password")));
//     EXPECT_CALL(m_mockDatabase, setPort(2222));
//     EXPECT_CALL(m_mockDatabase, open()).WillOnce(::testing::Return(true));
//
//     DatabaseManager dbManager(m_mockDatabase);
//     bool isConnected = dbManager.connect(m_config);
//
//     ASSERT_TRUE(isConnected);
// }
