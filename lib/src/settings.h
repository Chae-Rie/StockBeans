//
// Created by Yoo Cherry on 27.09.24.
//

#ifndef SETTINGS_H
#define SETTINGS_H

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
        // TODO: trying to use QString instead of std::string//std::wstring
        QString host;
        QString port;
        QString user;
        QString password;
        QString dbName;
    };

    struct GeneralSettings {
        QString appname;
        QString version;
        QString defaultLanguage;
        QString maxRetries;
    };

    // Majorsetting object
    struct AppConfig {
        DatabaseSettings databaseSettings;
        GeneralSettings generalSettings;
    };

    bool LoadSettings(AppConfig appConfig, DbConfig dbConfig);
};
#endif //SETTINGS_H
