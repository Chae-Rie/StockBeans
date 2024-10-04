#include "databasemanager.h"
#include "fileparser.h"
#include "misc.h"

DatabaseManager::DatabaseManager() {
}

DatabaseManager::~DatabaseManager() {
}

// Für Testzwecke und Mobiles arbeiten könnte ich eine Qsqlite Datenbank verwenden, aber für die tatsächliche
// Implementierung sollte ich etwas anderes verwenden, was ich auch auf dem Raspi- zum Laufen bekomme

/*
Es ist wichtig, dass unbedingt libpq.5.dylib eingebunden wird, die aus dem Postgresql@15 Ordner in opt/homebrew/cellar... kommt.
Andernfalls kann sich Postgresql nicht verbinden
*/
bool DatabaseManager::ConnectDatabase() {
    // Read out that local .env-file
    std::string SourcePath = MyTools::Misc::GetSourceDir();
    SourcePath += "/.env";
    std::unordered_map<std::string, std::string> envMap = MyTools::Fileparser::parseEnvFile(SourcePath);


    // save the values into some locals -> they need to get converted anyways
    // I won't change the return type from std::string to QStrings...
    std::string hostname = MyTools::Fileparser::getValueByKey(envMap, "HOST");
    std::string port = MyTools::Fileparser::getValueByKey(envMap, "PORT");
    std::string dbname = MyTools::Fileparser::getValueByKey(envMap, "DBNAME");
    std::string username = MyTools::Fileparser::getValueByKey(envMap, "USERNAME");
    std::string password = MyTools::Fileparser::getValueByKey(envMap, "PASSWORD");


    // initialize database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(QString::fromStdString(hostname));
    db.setPort(std::stoi(port));
    db.setDatabaseName(QString::fromStdString(dbname));
    db.setUserName(QString::fromStdString(username));
    db.setPassword(QString::fromStdString(password));

    // actually connect
    if (db.open()) {
        qDebug() << "Connected to database at '" << hostname << "'!";
    } else {
        qDebug() << "Failed connecting to database with errormsg: " << db.lastError().text();
    }

    return false;
}

bool DatabaseManager::initializeDatabaseConnection(Settings::AppConfig &appConfig) {
}


bool DatabaseManager::QueryPostgres(USER_CREDENTIALS userCredentialContent, QString queryString) {
    // Einfachste Möglichkeit an eine gültige Instanz der Datenbank zu bekommen
    // und sie anschließend mit dem Queryobjekt zu verknüpfen
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery dbQuery(db);
    return false;
}
