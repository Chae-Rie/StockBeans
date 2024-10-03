#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(DatabaseManager &dbManager,QWidget *parent)
    : QDialog(parent)
    , m_ui(new Ui::LoginDialog)
    , m_dbManagerReference(&dbManager)
{
    m_ui->setupUi(this);
    connect(m_ui->pushButtonCancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(m_ui->pushButtonRegister, SIGNAL(clicked()), this, SLOT(OnClickRegister()));
}

LoginDialog::~LoginDialog()
{
    delete m_ui;
}

// Hauptaufgabe: Die Inputs des Benutzers zu sammeln und zu validieren, anschließend soll mit den Informationen
// eine Query an die DB erzeugt werden.
void LoginDialog::OnClickRegister()
{
   QString givenEmail =  m_ui->lineEditEmail->text();
   QString givenPassword = m_ui->lineEditPassword->text();


    int i = 1;
}

void LoginDialog::onLoginClicked() {
    // TODO: Add logic to handle login
    QString username = usernameField->text();
    QString password = passwordField->text();

    if (username.isEmpty() || password.isEmpty()) {
        // Inform the user to fill in both fields
    } else {
        // Validate credentials
    }
}

void LoginDialog::onRegisterClicked() {
}

void LoginDialog::onCancelClicked() {
    reject();
}
