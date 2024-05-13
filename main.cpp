#include "lib/src/logindialog.h"
#include "lib/src/databasemanager.h"
#include "lib/src/helperfunction.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // Setup Database

    DatabaseManager dbManager;
    dbManager.ConnectDatabase();

    QString currentTimeStamp = HelperFunction::GetCurrentTime();
    // LoginDialog bekommt dbManager als Referenz übergeben, da wir im Dialog Queries versenden
    // wollen -> TODO: ggf. std::shared_pointer verwenden, falls die Übersicht verloren gehen sollte.
    LoginDialog loginDialog(dbManager);
    loginDialog.show();

    // MainWindow w;
    // w.show();
    return a.exec();
}
