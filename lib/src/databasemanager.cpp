#include "databasemanager.h"

DatabaseManager::DatabaseManager() {}

DatabaseManager::~DatabaseManager()
{}

// Für Testzwecke und Mobiles arbeiten könnte ich eine Qsqlite Datenbank verwenden, aber für die tatsächliche
// Implementierung sollte ich etwas anderes verwenden, was ich auch auf dem Raspi- zum Laufen bekomme

bool DatabaseManager::ConnectDatabase()
{
    // 192.168.0.205 Raspi Login
    // QString hostname = "192.168.0.205";
    // int port = 5432; // Der Port, auf dem PostgreSQL läuft (Standardport ist 5432)
    // QString dbname = "postgres"; // Der Name der Datenbank
    // QString username = "postgres"; // Der Benutzername für die Datenbankverbindung
    // QString password = "postgres"; // Das Passwort für die Datenbankverbindung

    // Lokale DB aktuell
    QString hostname = "localhost";
    constexpr int port = 5432;
    QString dbname = "stockbeans";
    QString username = "stockbeans";
    QString password = "stockbeans1337!";



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
