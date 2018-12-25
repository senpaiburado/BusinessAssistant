#ifndef PARAMSTYPES_H
#define PARAMSTYPES_H

#include <QString>

struct ProductRegisterFormParam {
    QString name;
    QString imgPath;
    float price;
    int count;
};

struct ProductSaveData {
    QString key;
    QString name;
    QString imgPath;
    float price;
    int count;
    int countSold;
    int categoryCode;
};

struct ProductWarehouseData {
    QString productKey;
    int count;
    int countSold;
    int countReturned;
    bool isAvailable;
};

#endif // PARAMSTYPES_H
