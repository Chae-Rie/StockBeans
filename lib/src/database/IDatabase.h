//
// Created by Yoo Cherry on 08.10.24.
// This should be the interface class my real implementation and the mocking
// class is working with to establish a connection.
//

#ifndef IDATABASE_H
#define IDATABASE_H

#include <QString>

class IDatabase {
public:
    virtual ~IDatabase() = default;

    // Creating all the virtual functions the inheriting class must override
    virtual void setHostName(const QString &host) = 0;

    virtual void setDatabaseName(const QString &name) = 0;

    virtual void setUserName(const QString &username) = 0;

    virtual void setPassword(const QString &password) = 0;

    virtual void setPort(unsigned int port) = 0;

    virtual bool open() = 0;

    [[nodiscard]] virtual bool isValid() const = 0;

    [[nodiscard]] virtual bool isOpen() const = 0;
};

#endif //IDATABASE_H
