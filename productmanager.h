#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H

#include <QObject>
#include "paramstypes.h"

class Product;

#include "product.h"

class ProductManager : public QObject
{
    Q_OBJECT
public:
    static Product *createProduct(ProductRegisterFormParam *productParams);
    static Product *loadProduct(ProductSaveData *productSaveParams);

    static Product *findProduct();

signals:

public slots:
};

#endif // PRODUCTMANAGER_H
