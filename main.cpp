#include "lib/src/ui/LoginDialog.h"
#include "lib/src/database/DatabaseManager.h"
#include "lib/src/util/HelperFunction.h"
#include "lib/src/util/CoreLogger.h"
#include <QApplication>

// TODO: Fix the yaml CI/CD file...
// TODO: Create a Setup-Namespace in setup.h setup.cpp to abstract all of the setup stuff
/*
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

#ifdef NDEBUG
//constexpr auto currentDbConfig = DbConfig::Release;
#else
//constexpr auto currentDbConfig = DbConfig::Debug;
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
    SPDLOG_INFO("Starting Application...");


    // don't show the mainwindow until I logged in successfully!

    // MainWindow w;
    // w.show();
    return application.exec();
}
