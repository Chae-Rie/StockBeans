//
// Created by Yoo Cherry on 09.10.24.
//

#include "AppSettings.h"

AppSettings::AppSettings(const json &jsonFile) : jsonFile_(jsonFile) {
}

void AppSettings::load() {
  if (jsonFile_.is_null()) {
    SPDLOG_ERROR("Given json object is empty.");
    return;
  }
  const char *default_value = "NoValue";
  setAppName(jsonFile_.value("appName", default_value).c_str());
  setAppVersion(jsonFile_.value("version", default_value).c_str());
  setDefaultLanguage(jsonFile_.value("defaultLanguage", default_value).c_str());
  setMaxRetries(jsonFile_.value("maxRetries", 3));
}

void AppSettings::save() {
}

QString AppSettings::getAppName() const {
  return appName_;
}

QString AppSettings::getAppVersion() const {
  return appVersion_;
}

QString AppSettings::getDefaultLanguage() const {
  return defaultLanguage_;
}

int AppSettings::getMaxRetries() const {
  return maxRetries_;
}

void AppSettings::setAppName(const QString &appName) {
  appName_ = appName;
}

void AppSettings::setAppVersion(const QString &appVersion) {
  appVersion_ = appVersion;
}

void AppSettings::setDefaultLanguage(const QString &defaultLanguage) {
  defaultLanguage_ = defaultLanguage;
}

void AppSettings::setMaxRetries(int maxRetries) {
  maxRetries_ = maxRetries;
}
