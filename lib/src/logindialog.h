#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QVBoxLayout>
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
    void onLoginClicked();
    void onRegisterClicked();
    void onCancelClicked();
private:
    Ui::LoginDialog *m_ui;
    DatabaseManager *m_dbManagerReference;
    QLineEdit *usernameField;
    QLineEdit *passwordField;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QPushButton *cancelButton;

};

#endif // LOGINDIALOG_H
