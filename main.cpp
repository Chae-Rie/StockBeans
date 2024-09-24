#include "lib/src/logindialog.h"
#include "lib/src/databasemanager.h"
#include "lib/src/helperfunction.h"
#include "lib/src/corelogger.h"
#include <QApplication>

// Setze den Log-Level basierend auf dem Modus
#ifdef NDEBUG
constexpr spdlog::level::level_enum logLevel = spdlog::level::info; // Release-Modus
#else
constexpr spdlog::level::level_enum logLevel = spdlog::level::debug; // Debug-Modus
#endif

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    CoreLogger coreLogger;

    coreLogger.SetupLogger(logLevel);



    SPDLOG_INFO("Starting Application...");

    // Setup Database
    DatabaseManager dbManager;
    // TODO: Implement the JSON parsing
    // TODO: construct the connectionstring
    // TODO: Connect to the database
//    dbManager.ConnectDatabase();

    // TODO: Why did I get the timestamp?
    QString currentTimeStamp = HelperFunction::GetCurrentTime();

    // LoginDialog bekommt dbManager als Referenz übergeben, da wir im Dialog Queries versenden
    // wollen -> TODO: ggf. std::shared_pointer verwenden, falls die Übersicht verloren gehen sollte.
    LoginDialog loginDialog(dbManager);
    loginDialog.show();


// don't show the mainwindow until I logged in successfully!

    // MainWindow w;
    // w.show();
    return application.exec();
}
