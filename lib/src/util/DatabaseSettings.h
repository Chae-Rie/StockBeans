//
// Created by Yoo Cherry on 09.10.24.
//

#ifndef DATABASESETTINGS_H
#define DATABASESETTINGS_H

#include <QString>
#include "ISettings.h"
#include "jsonmanager.h"
#include "../util/CoreLogger.h"

enum class DbConfig {
  Debug,
  Release
};

class DatabaseSettings : public ISettings {
 public:
  explicit DatabaseSettings(const json &jsonFile);

  void load() override;

  void save() override;

  // getter
  QString getHostName() const;

  QString getUserName() const;

  QString getPassword() const;

  QString getDatabaseName() const;

  int getPort() const;

  // setter
  void setHostName(const QString &hostname);

  void setUserName(const QString &username);

  void setPassword(const QString &password);

  void setDatabaseName(const QString &databaseName);

  void setPort(int port);

 private:
  json jsonFile_;
  QString hostname_;
  QString username_;
  QString password_;
  QString databaseName_;
  int port_;
};

#endif //DATABASESETTINGS_H
