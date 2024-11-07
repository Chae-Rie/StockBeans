//
// Created by Yoo Cherry on 27.10.24.
//

#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include "DatabaseSettings.h"
#include "AppSettings.h"
#include "jsonmanager.h"

class SettingsManager {
 public:
  SettingsManager(const json &completeConfig);
  virtual ~SettingsManager();

  DatabaseSettings &GetDatabaseSettings();
  AppSettings &GetAppSettings();

  void LoadAllSettings();
  // void SaveAllSettings(); // Maybe this could be needed later, but for now I don't allow any changes to settings

  
 private:
  DatabaseSettings database_settings_;
  AppSettings app_settings_;
};

#endif //SETTINGSMANAGER_H
