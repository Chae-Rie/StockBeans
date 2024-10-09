//
// Created by Yoo Cherry on 09.10.24.
//

#include "DatabaseSettings.h"

#ifdef NDEBUG
constexpr auto currentDbConfig = DbConfig::Release;
#else
constexpr auto currentDbConfig = DbConfig::Debug;
#endif

DatabaseSettings::DatabaseSettings(const json &jsonFile) : jsonFile_(jsonFile) {
}

void DatabaseSettings::load() {
    if (jsonFile_.is_null()) {
        SPDLOG_ERROR("Given json object is empty.");
        return;
    }

    // automatically selects the right database config out of the config.json
    std::string mode = "";
    switch (currentDbConfig) {
        case(DbConfig::Release):
            mode = "production";
            break;
        case(DbConfig::Debug):
            mode = "development";
            break;
    }
    json jsonDatabaseFragment = MyTools::JsonManager::getDatabaseConfig(jsonFile_, mode);

    if (jsonDatabaseFragment.is_null()) {
        SPDLOG_ERROR("Database config fragment is invalid.");
        return;
    }
    const char *defaultValue = "NoValue";

    // implicitly converts to QString
    setHostName(jsonDatabaseFragment.value("host", defaultValue).c_str());
    // todo: implement the rest
}

void DatabaseSettings::save() {
}

QString DatabaseSettings::getHostName() const {
    return hostname_;
}

QString DatabaseSettings::getUserName() const {
    return username_;
}

QString DatabaseSettings::getPassword() const {
    return password_;
}

QString DatabaseSettings::getDatabaseName() const {
    return databaseName_;
}

int DatabaseSettings::getPort() const {
    return port_;
}

void DatabaseSettings::setHostName(const QString &hostname) {
    hostname_ = hostname;
}

void DatabaseSettings::setUserName(const QString &username) {
    username_ = username;
}

void DatabaseSettings::setPassword(const QString &password) {
    password_ = password;
}

void DatabaseSettings::setDatabaseName(const QString &databaseName) {
    databaseName_ = databaseName;
}

void DatabaseSettings::setPort(int port) {
    port_ = port;
}
