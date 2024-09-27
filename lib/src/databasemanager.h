#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H


#include <QtSql/QSqlDatabase>
#include <QCoreApplication>
#include <QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlError>

#include "types.h"
#include "corelogger.h"
#include "settings.h"
#include <MyTools/jsonmanager.h>
class DatabaseManager
{
public:
    DatabaseManager();
    virtual ~DatabaseManager();

    bool ConnectDatabase();
    bool ConnectDatabase(json jsonFile,const Settings::DbConfig& config);
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
