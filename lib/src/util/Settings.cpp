//
// Created by Yoo Cherry on 27.09.24.
//
#include "Settings.h"

Settings::Settings() {
}

Settings::~Settings() {
}

// appConfig is the major settings object I am using to transfer different settings between the objects
// The given reference gets updated depending on the mode (dbConfig) which corellates to the used compilation
// --> Release or Debug. This ends ultimatively in different possible configurations
bool Settings::LoadSettings(AppConfig &appConfig, DbConfig dbConfig, json &jsonFile) {
    json jsonDbFragment;
    switch (dbConfig) {
        case(DbConfig::Debug):

            jsonDbFragment = MyTools::JsonManager::getDatabaseConfig(jsonFile, "development");
            appConfig.setDatabaseSettings(jsonDbFragment);
            break;
        case(DbConfig::Release):
            jsonDbFragment = MyTools::JsonManager::getDatabaseConfig(jsonFile, "production");
            appConfig.setDatabaseSettings(jsonDbFragment);
            break;
        default:
            break;
    }

    // TODO: Pollute the generic Settings
    return true;
}



