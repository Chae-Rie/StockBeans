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

}
