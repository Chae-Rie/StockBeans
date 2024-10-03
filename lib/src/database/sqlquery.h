//
// Created by Yoo Cherry on 30.09.24.
//

#ifndef SQLQUERY_H
#define SQLQUERY_H


#include <QString>
#include <QStringList>

class SqlQuery {
public:
    // Konstruktor für eine einfache SELECT-Abfrage
    SqlQuery& select(const QStringList& columns);
    SqlQuery& from(const QString& table);
    SqlQuery& where(const QString& condition);

    QString getQuery() const;

private:
    QString query;
};


#endif //SQLQUERY_H
