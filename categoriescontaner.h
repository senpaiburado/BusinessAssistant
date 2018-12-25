#ifndef CATEGORIESCONTANER_H
#define CATEGORIESCONTANER_H

#include <QObject>

class ProductCategory;

#include "productcategory.h"

class CategoriesContaner
{
public:
    explicit CategoriesContaner();

    CategoriesContaner &operator<<(const ProductCategory &category);
    CategoriesContaner &operator<<(ProductCategory *category);
    void append(const ProductCategory &category);

    const QString &nameAt(int pos) const;
    int codeAt(int pos) const;
    ProductCategory *operator[](int pos);

    void clear();
    int size();

private:
    QList<ProductCategory*> categories;
};

#endif // CATEGORIESCONTANER_H
