#include "helperfunction.h"


QString HelperFunction::GetCurrentTime() {
    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("yyyy-MM-dd HH:mm:ss");
    return formattedTime;
}


QString HelperFunction::CalculateSHA256Hash(const QString &input) {
    if (input.isEmpty()) {
        return {};
    }
    QByteArray byteArray = input.toUtf8(); // fills a QByteArray with the utf8 encoded input
    QByteArray hashArray = QCryptographicHash::hash(byteArray, QCryptographicHash::Sha256); // Berechne den SHA-256-Hash
    return hashArray.toHex(); // returns hash array as a converted hexvalue
}


