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

class DatabaseManager {
public:
    DatabaseManager();

    virtual ~DatabaseManager();

    bool ConnectDatabase();

    bool ConnectDatabase(json jsonFile, const Settings::DbConfig &config);

    //
    bool QueryPostgres(USER_CREDENTIALS userCredentialContent, QString queryString);

    bool QueryPostgres(INVENTORY inventoryContent, QString queryString);

    bool QueryPostgres(TYPE typeContent, QString queryString);

    bool QueryPostgres(INVENTORY_PRODUCTS inventoryProductsContent, QString queryString);

    bool QueryPostgres(UNIT unitContent, QString queryString);

    bool QueryPostgres(TEMPLATE_PRODUCTS templateProductsContent, QString queryString);

    bool QueryPostgres(CATEGORY categoryContent, QString queryString);

    bool QueryPostgres(INGREDIENT ingredientConent, QString queryString);

    bool QueryPostgres(BARCODE barcodeContent, QString queryString);
};

#endif // DATABASEMANAGER_H
