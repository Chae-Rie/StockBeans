//
// Created by Yoo Cherry on 09.10.24.
//

#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QString>
#include "ISettings.h"
#include "jsonmanager.h"


class AppSettings : public ISettings {
public:
    AppSettings(const json &jsonFile);

    virtual ~AppSettings();

    void load() override;

    void save() override;

    // getter
    QString getAppName() const;

    QString getAppVersion() const;

    QString getDefaultLanguage() const;

    int getMaxRetries() const;

    // setter
    void setAppName(const QString &appName);

    void setAppVersion(const QString &appVersion);

    void setDefaultLanguage(const QString &defaultLanguage);

    void setMaxRetries(int maxRetries);

private:
    json jsonFile_;
    QString appName_;
    QString appVersion_;
    QString defaultLanguage_;
    int maxRetries_ = 0;
};


#endif //APPSETTINGS_H
