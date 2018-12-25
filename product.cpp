#include "product.h"

const QString &Product::key() const
{
    return m_key;
}

const QString &Product::name() const
{
    return m_name;
}

const QString &Product::imgPath() const
{
    return m_imgPath;
}

float Product::price() const
{
    return m_price;
}

int Product::categoryCode() const
{
    return m_categoryCode;
}

Product::Product(QObject *parent) : QObject(parent)
{

}

Product::Product()
{

}
