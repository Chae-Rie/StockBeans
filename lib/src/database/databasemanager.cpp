#include "databasemanager.h"
#include "fileparser.h"
#include "misc.h"

/* Make sure you are getting the absolute path to the libpq.5.dylib file inside the
 * Postgresql@15 directory. Otherwise you won't be able to establish a working connection.
 */

DatabaseManager::DatabaseManager(IDatabase &databaseRef) : m_database(databaseRef) {
}

bool DatabaseManager::connect(const Settings::AppConfig &appConfig) {
    m_database.setHostName(appConfig.databaseSettings.host);
    m_database.setDatabaseName(appConfig.databaseSettings.dbName);
    m_database.setUserName(appConfig.databaseSettings.user);
    m_database.setPassword(appConfig.databaseSettings.password);
    m_database.setPort(appConfig.databaseSettings.port);
    return m_database.open();
}
