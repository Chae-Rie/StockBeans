//
// Created by Yoo Cherry on 27.09.24.
//
#include "settings.h"

Settings::Settings() {
}

Settings::~Settings() {
}

bool Settings::LoadSettings(AppConfig appConfig, DbConfig dbConfig) {
    switch (dbConfig) {
        case(DbConfig::Debug):
            break;
        // TODO: Pollute the DatabaseSettings
        case(DbConfig::Release):
            break;
        default:
            break;
    }


    // TODO: Pollute the generic Settings
}

