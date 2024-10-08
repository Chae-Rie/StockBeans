//
// Created by Yoo Cherry on 08.10.24.
//

#include "SqlDatabaseWrapper.h"

// Initializing the SqlDatabaseWrapper object automatically loads all the drivers
// for QPSQL. If this fails, most likely the given paths to libpq.5.dylib arent correct
SqlDatabaseWrapper::SqlDatabaseWrapper()
    : m_database(QSqlDatabase::addDatabase("QPSQL")) {
}

// Closes the database connection automatically.
SqlDatabaseWrapper::~SqlDatabaseWrapper() {
    m_database.close();
}

void SqlDatabaseWrapper::setHostName(const QString &host) {
    m_database.setHostName(host);
}

void SqlDatabaseWrapper::setDatabaseName(const QString &name) {
    m_database.setDatabaseName(name);
}

void SqlDatabaseWrapper::setUserName(const QString &username) {
    m_database.setUserName(username);
}

void SqlDatabaseWrapper::setPassword(const QString &password) {
    m_database.setPassword(password);
}

void SqlDatabaseWrapper::setPort(unsigned int port) {
    m_database.setPort(port);
}


bool SqlDatabaseWrapper::open() {
    return m_database.open();
}

bool SqlDatabaseWrapper::isOpen() const {
    return m_database.isOpen();
}

bool SqlDatabaseWrapper::isValid() const {
    return m_database.isValid();
}
