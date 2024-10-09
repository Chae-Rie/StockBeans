#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H


#include <QtSql/QSqlDatabase>
#include <QCoreApplication>
#include <QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlError>

#include "IDatabase.h"
#include "Types.h"
#include "../util/CoreLogger.h"
#include "jsonmanager.h"

class DatabaseManager {
public:
    DatabaseManager();

    virtual ~DatabaseManager() = default;

    //_---------
    bool QueryPostgres(USER_CREDENTIALS userCredentialContent, QString queryString);

    bool QueryPostgres(INVENTORY inventoryContent, QString queryString);

    bool QueryPostgres(TYPE typeContent, QString queryString);

    bool QueryPostgres(INVENTORY_PRODUCTS inventoryProductsContent, QString queryString);

    bool QueryPostgres(UNIT unitContent, QString queryString);

    bool QueryPostgres(TEMPLATE_PRODUCTS templateProductsContent, QString queryString);

    bool QueryPostgres(CATEGORY categoryContent, QString queryString);

    bool QueryPostgres(INGREDIENT ingredientConent, QString queryString);

    bool QueryPostgres(BARCODE barcodeContent, QString queryString);

private:
    IDatabase &m_database;
};

#endif // DATABASEMANAGER_H
