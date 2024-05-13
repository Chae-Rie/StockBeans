#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "databasemanager.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(DatabaseManager &dbManager, QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    // declare slot handling mechanism
    void OnClickRegister();

private:
    Ui::LoginDialog *m_ui;
    DatabaseManager *m_dbManagerReference;


};

#endif // LOGINDIALOG_H
