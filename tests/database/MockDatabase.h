//
// Created by Yoo Cherry on 08.10.24.
//

#ifndef MOCKDATABASE_H
#define MOCKDATABASE_H

#include "database/IDatabase.h"

#include <gmock/gmock.h>

class MockDatabase : public IDatabase {
public:
    MOCK_METHOD(void, setHostName, (const QString &host), (override));
    MOCK_METHOD(void, setDatabaseName, (const QString &name), (override));
    MOCK_METHOD(void, setUserName, (const QString &username), (override));
    MOCK_METHOD(void, setPassword, (const QString &password), (override));
    MOCK_METHOD(void, setPort, (unsigned int port), (override));
    MOCK_METHOD(bool, open, (), (override));
    MOCK_METHOD(bool, isValid, (), (const, override));
    MOCK_METHOD(bool, isOpen, (), (const, override));
};
#endif //MOCKDATABASE_H
