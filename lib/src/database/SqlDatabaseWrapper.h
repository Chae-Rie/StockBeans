//
// Created by Yoo Cherry on 08.10.24.
// Wrapperclass for the implementation of a class for using a psql database
//

#ifndef SQLDATABASEWRAPPER_H
#define SQLDATABASEWRAPPER_H

#include "IDatabase.h"
#include "QSqlDatabase"

class SqlDatabaseWrapper : public IDatabase {
public:
    SqlDatabaseWrapper();

    ~SqlDatabaseWrapper() override;

    void setHostName(const QString &host) override;

    void setDatabaseName(const QString &name) override;

    void setUserName(const QString &username) override;

    void setPassword(const QString &password) override;

    void setPort(unsigned int port) override;

    bool open() override;

    [[nodiscard]] bool isOpen() const override;

    [[nodiscard]] bool isValid() const override;

private:
    QSqlDatabase m_database;
};


#endif //SQLDATABASEWRAPPER_H
