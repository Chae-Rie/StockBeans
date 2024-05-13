#ifndef HELPERFUNCTION_H
#define HELPERFUNCTION_H

#include <QString>
#include <QCryptographicHash>
#include <QDateTime>

class HelperFunction
{
public:
   static QString GetCurrentTime();
   static QString CalculateSHA256Hash(const QString &input);
};

#endif // HELPERFUNCTION_H
