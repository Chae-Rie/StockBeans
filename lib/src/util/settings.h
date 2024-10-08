//
// Created by Yoo Cherry on 27.09.24.
//

#ifndef SETTINGS_H
#define SETTINGS_H

#include "jsonmanager.h"
#include <QString>

class Settings {
public:
    Settings();

    virtual ~Settings();

    // this enum class helps me to decide which database config I wanna use
    enum class DbConfig {
        Debug,
        Release
    };

    struct DatabaseSettings {
        QString host;
        unsigned int port;
        QString user;
        QString password;
        QString dbName;
    };

    struct GeneralSettings {
        QString appname;
        QString version;
        QString defaultLanguage;
        int maxRetries;
    };

    // Majorsetting object
    struct AppConfig {
        DatabaseSettings databaseSettings;
        GeneralSettings generalSettings;

        // little helperfunction to be able to stick to DRY
        inline void setDatabaseSettings(json configFragment) {
            this->databaseSettings.host = QtPrivate::convertToQString(
                MyTools::JsonManager::GetStringValue(configFragment, "host")
            );
            this->databaseSettings.port = MyTools::JsonManager::GetIntValue(configFragment, "port");

            this->databaseSettings.user = QtPrivate::convertToQString(
                MyTools::JsonManager::GetStringValue(configFragment, "username")
            );
            this->databaseSettings.password = QtPrivate::convertToQString(
                MyTools::JsonManager::GetStringValue(configFragment, "password")
            );
            this->databaseSettings.dbName = QtPrivate::convertToQString(
                MyTools::JsonManager::GetStringValue(configFragment, "databaseName")
            );
        }
    };

    static bool LoadSettings(AppConfig &appConfig, DbConfig dbConfig, json &jsonFile);
};
#endif //SETTINGS_H
