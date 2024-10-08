#ifndef TYPES_H
#define TYPES_H

#include <QString>

/*
    name            varchar100
    lastname        varchar100
    email           varchar100
    password        varchar140
    role            varchar100
    registered_at   timestamp
    updated_at      timestamp
    last_login      timestamp
*/
typedef struct USER_CREDENTIALS{
    QString name;
    QString lastname;
    QString email;
    QString password;
    QString role;
    QString registered_at;
    QString updated_at;
    QString last_login;
} USER_CREDENTIALS;


/*
    owner_id        int4
    name            varchar140
    type_id         int4
    location        varchar140
    created_at      timestamp
    updated_at      timestamp

*/
typedef struct INVENTORY {
    int ownerID;
    QString name;
    int typeID;
    QString location;
    QString created_at;
    QString updated_at;
}INVENTORY;


/*
    name            text
    created_at      timestamp
    updated_at      timestamp
*/
typedef struct TYPE{
    QString name;
    QString created_at;
    QString updated_at;
}TYPE;


/*
    template_product_id int4
    quantity            int4
    added_at            timestamp
    expiry_date         timestamp
*/
typedef struct INVENTORY_PRODUCTS{
    int template_product_ID;
    int quantity;
    QString added_at;
    QString expriry_date;
}INVENTORY_PRODUCTS;

/*
    template_product_id int4
    unit                varchar(50)
    created_at          timestamp
    updated_at          timestamp
*/
typedef struct UNIT{
    int template_poduct_ID;
    QString unit;
    QString created_at;
    QString updated_at;

}UNIT;


/*
    barcode_id          int4
    ingredient_id       int4
    image               bytea
    best_before_in_days int
    created_at          timestamp
    updated_at          timestamp
*/
    typedef struct TEMPLATE_PRODUCTS{
    int barcode_ID;
    int ingredient_ID;
    unsigned char image;
    int best_before_in_days;
    QString created_at;
    QString updated_at;
    } TEMPLATE_PRODUCTS;

    /*
    name                varchar(140)
    created_at          timestamp
    updated_at          timestamp
*/
    typedef struct CATEGORY{
        QString name;
        QString created_at;
        QString updated_at;
    } CATEGORY;
/*
    barcode             varchar(50)
    own_article_number  varchar(50)
    created_at          timestamp
    updated_at          timestamp
*/
    typedef struct BARCODE{
        QString barcode;
        QString own_article_number;
        QString created_at;
        QString updated_at;
    } BARCODE;


/*
    category_id         int4
    name                varchar(140)
    created_at          timestamp
    updated_at          timestamp
*/
    typedef struct INGREDIENT{
        int category_ID;
        QString name;
        QString created_at;
        QString updated_at;
    } INGREDIENT;


#endif // TYPES_H

