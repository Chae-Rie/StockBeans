#include "databasemanager.h"


DatabaseManager::DatabaseManager() {}

DatabaseManager::~DatabaseManager()
{}

// Für Testzwecke und Mobiles arbeiten könnte ich eine Qsqlite Datenbank verwenden, aber für die tatsächliche
// Implementierung sollte ich etwas anderes verwenden, was ich auch auf dem Raspi- zum Laufen bekomme

/*
Es ist wichtig, dass unbedingt libpq.5.dylib eingebunden wird, die aus dem Postgresql@15 Ordner in opt/homebrew/cellar... kommt.
Andernfalls kann sich Postgresql nicht verbinden
*/
bool DatabaseManager::ConnectDatabase()
{

    std::string SourcePath = MyTools::Fileparser::GetSourceDirPath();

    SourcePath += "/.env";
    std::unordered_map<std::string, std::string>envMap = MyTools::Fileparser::parseEnvFile(SourcePath);

    // Lokale DB aktuell
    std::string hostname = MyTools::Fileparser::getValueByKey(envMap, "HOST");
    std::string port = MyTools::Fileparser::getValueByKey(envMap, "PORT");
    std::string dbname = MyTools::Fileparser::getValueByKey(envMap, "DBNAME");
    std::string username = MyTools::Fileparser::getValueByKey(envMap, "USERNAME");
    std::string password = MyTools::Fileparser::getValueByKey(envMap, "PASSWORD");




    // Datenbankverbindung initialisieren
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(QString::fromStdString(hostname));
    db.setPort(std::stoi( port ));
    db.setDatabaseName(QString::fromStdString(dbname));
    db.setUserName(QString::fromStdString(username));
    db.setPassword(QString::fromStdString(password));

    // Verbindung zur Datenbank herstellen
    if (db.open()) {
        qDebug() << "Verbindung zur Datenbank hergestellt!";
        // Hier können Sie Datenbankabfragen ausführen oder andere Aktionen durchführen
    } else {
        qDebug() << "Fehler beim Herstellen der Verbindung zur Datenbank:" << db.lastError().text();
    }

}

bool DatabaseManager::QueryPostgres(USER_CREDENTIALS userCredentialContent)
{
    // Einfachste Möglichkeit an eine gültige Instanz der Datenbank zu bekommen
    // und sie anschließend mit dem Queryobjekt zu verknüpfen
    QSqlDatabase db = QSqlDatabase::database();

    QSqlQuery dbQuery(db);


}
