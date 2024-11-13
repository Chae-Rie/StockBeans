//
// Created by Yoo Cherry on 27.10.24.
//

#include "SettingsManager.h"

SettingsManager::SettingsManager(const json &completeConfig) : database_settings_(completeConfig),
                                                               app_settings_(completeConfig) {
}

SettingsManager::~SettingsManager() {
}

DatabaseSettings &SettingsManager::GetDatabaseSettings() {
    return database_settings_;
}

AppSettings &SettingsManager::GetAppSettings() {
    return app_settings_;
}

void SettingsManager::LoadAllSettings() {
    database_settings_.load();
    app_settings_.load();
}
