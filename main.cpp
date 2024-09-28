#include "lib/src/logindialog.h"
#include "lib/src/databasemanager.h"
#include "lib/src/helperfunction.h"
#include "lib/src/corelogger.h"
#include <QApplication>

// Sets the logging level
#ifdef NDEBUG
constexpr spdlog::level::level_enum logLevel = spdlog::level::info; // Release-Modus
#else
constexpr spdlog::level::level_enum logLevel = spdlog::level::debug; // Debug-Modus
#endif


#include <MyTools/jsonmanager.h>
#include <MyTools/fileparser.h>
#include <MyTools/misc.h>
#include "lib/src/settings.h"

#ifdef NDEBUG
constexpr auto currentDbConfig = Settings::DbConfig::Release;
#else
constexpr auto currentDbConfig = Settings::DbConfig::Debug;
#endif

int main(int argc, char *argv[]) {
    // Creating the main application
    QApplication application(argc, argv);

    // Set up the corelogging pool which will be handed to every important object
    CoreLogger coreLogger;
    coreLogger.SetupLogger(logLevel);

    // Gets the filepath of root-CMakeLists.txt because I can use that path as a basepath for other file operations
    std::string sourceFilePath = MyTools::Misc::GetSourceDir();
    // Gets the contents of the config files
    json configurationFile = MyTools::JsonManager::ReadFile(sourceFilePath + "/config.json");

    // Gets the databaseconfig
    json dbConfigFragment = MyTools::JsonManager::getDatabaseConfig(configurationFile, "development");
    std::string value = MyTools::JsonManager::GetStringValue(dbConfigFragment, "host");

    Settings::AppConfig appConfig;


    SPDLOG_INFO("Starting Application...");

    // Setup Database
    DatabaseManager dbManager;
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
