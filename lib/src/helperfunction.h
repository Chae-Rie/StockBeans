#ifndef HELPERFUNCTION_H
#define HELPERFUNCTION_H

#include <QString>
#include <QCryptographicHash>
#include <QDateTime>

# TODO: This doesn't need to be a class. MISC? Delete it completely?
class HelperFunction
{
public:
   static QString GetCurrentTime();
   static QString CalculateSHA256Hash(const QString &input);
};

#endif // HELPERFUNCTION_H
