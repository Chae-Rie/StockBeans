#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H


#include <QtSql/QSqlDatabase>
#include <QCoreApplication>
#include <QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlError>

#include "types.h"

class DatabaseManager
{
public:
    DatabaseManager();
    virtual ~DatabaseManager();

    bool ConnectDatabase();
    bool QueryPostgres(USER_CREDENTIALS userCredentialContent);
    bool QueryPostgres(INVENTORY inventoryContent);
    bool QueryPostgres(TYPE typeContent);
    bool QueryPostgres(INVENTORY_PRODUCTS inventoryProductsContent);
    bool QueryPostgres(UNIT unitContent);
    bool QueryPostgres(TEMPLATE_PRODUCTS templateProductsContent);
    bool QueryPostgres(CATEGORY categoryContent);
    bool QueryPostgres(INGREDIENT ingredientConent);
    bool QueryPostgres(BARCODE barcodeContent);
};

#endif // DATABASEMANAGER_H
