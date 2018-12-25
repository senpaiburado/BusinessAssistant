#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>
#include <QString>

class ProductManager;

#include "productmanager.h"
#include "productcategory.h"

class Product : public QObject
{
    Q_OBJECT
public:
    inline const QString &key() const;
    inline const QString &name() const;
    inline const QString &imgPath() const;
    inline float price() const;
    inline int categoryCode() const;



private:
    friend class ProductManager;
    explicit Product(QObject *parent = nullptr);
    explicit Product();

    QString m_key;
    QString m_name;
    float m_price;
    QString m_imgPath;
    int m_categoryCode;

signals:

public slots:
};

#endif // PRODUCT_H
