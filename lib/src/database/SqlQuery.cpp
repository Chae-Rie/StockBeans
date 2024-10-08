//
// Created by Yoo Cherry on 30.09.24.
//

#include "SqlQuery.h"

SqlQuery& SqlQuery::select(const QStringList& columns) {
    query = "SELECT ";
    query += columns.join(", ");
    return *this;
}

SqlQuery& SqlQuery::from(const QString& table) {
    query += " FROM " + table;
    return *this;
}

SqlQuery& SqlQuery::where(const QString& condition) {
    query += " WHERE " + condition;
    return *this;
}

QString SqlQuery::getQuery() const {
    return query;
}

/*
// This could look like this... I think this should be pretty much understandable
    SqlQuery query;
    query.select(QStringList() << "id" << "name" << "email")
         .from("users")
         .where("id = 1");
 */