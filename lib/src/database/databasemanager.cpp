#include "databasemanager.h"
#include "fileparser.h"
#include "misc.h"

/*
Es ist wichtig, dass unbedingt libpq.5.dylib eingebunden wird, die aus dem Postgresql@15 Ordner in opt/homebrew/cellar... kommt.
Andernfalls kann sich Postgresql nicht verbinden
*/

bool DatabaseManager::initializeDatabaseConnection(Settings::AppConfig &appConfig) {
    return false;
}


bool DatabaseManager::QueryPostgres(USER_CREDENTIALS userCredentialContent, QString queryString) {
    // Einfachste Möglichkeit an eine gültige Instanz der Datenbank zu bekommen
    // und sie anschließend mit dem Queryobjekt zu verknüpfen
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery dbQuery(db);
    return false;
}
