#include "lib/src/ui/LoginDialog.h"
#include "lib/src/database/DatabaseManager.h"
#include "lib/src/util/HelperFunction.h"
#include "lib/src/util/CoreLogger.h"
#include <QApplication>

// TODO: Fix the yaml CI/CD file...
// TODO: Create a Setup-Namespace in setup.h setup.cpp to abstract all of the setup stuff
/*
 * TODO: Projektstruktur anpassen, PRIO 1
*project_root/
├── src/
│   ├── main.cpp
│   ├── util/
│   │   ├── utils.cpp
│   │   └── utils.h
│   ├── ui/
│   │   ├── main_window.cpp
│   │   ├── main_window.h
│   └── database/
│       ├── db_manager.cpp
│       └── db_manager.h
├── include/
│   ├── project_name/
│   │   ├── utils.h
│   │   └── db_manager.h
├── tests/
│   ├── main.cpp
│   ├── util/
│   │   └── test_utils.cpp
│   ├── ui/
│   │   └── test_main_window.cpp
│   └── database/
│       └── test_db_manager.cpp
├── CMakeLists.txt
├── vcpkg.json
└── README.md
 **/

// Sets the logging level
#ifdef NDEBUG
constexpr spdlog::level::level_enum logLevel = spdlog::level::info; // Release-Modus
#else
constexpr spdlog::level::level_enum logLevel = spdlog::level::debug; // Debug-Modus
#endif


#include <jsonmanager.h>
#include <fileparser.h>
#include <misc.h>
#include "lib/src/util/Settings.h"

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
    // Creates the major settings object
    Settings::AppConfig appConfig;

    // Load all the needed settings I already know about... ---> appconstants, dbConfigs, anything which will be set
    // once and only needs to be readonly
    bool gotLoaded = false;
    gotLoaded = Settings::LoadSettings(appConfig, currentDbConfig, configurationFile);
    if (!gotLoaded) {
        // bad
        SPDLOG_ERROR("Failed to load settings from {0}", sourceFilePath);
        return EXIT_FAILURE; // this translates to 1
    }
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
