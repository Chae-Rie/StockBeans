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

    // Lokale DB aktuell
    QString hostname = "localhost";
    constexpr int port = 5432;
    QString dbname = "stockbeans";
    QString username = "stockbeans";
    QString password = "stockbeans1337!";


    // TODO: Hol die .env Datei
    // TODO: der relative Pfad passt nicht, könnte theorethisch den Pfad mithilfe von MyTools::Fileparser::GetSourceDirPath()
    // den Pfad bestimmen

    std::string SourcePath = MyTools::Fileparser::GetSourceDirPath();

    SourcePath += "/.env";
    std::unordered_map<std::string, std::string>envMap = MyTools::Fileparser::parseEnvFile(SourcePath);

    std::string stDbname = MyTools::Fileparser::getValueByKey(envMap, "DBNAME");

    // Datenbankverbindung initialisieren
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(hostname);
    db.setPort(port);
    db.setDatabaseName(dbname);
    db.setUserName(username);
    db.setPassword(password);

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
