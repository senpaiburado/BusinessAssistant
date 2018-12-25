#ifndef PRODUCTCATEGORY_H
#define PRODUCTCATEGORY_H

#include <QObject>
#include <QString>

class CategoriesContaner;

#include "categoriescontaner.h"

class ProductCategory
{
public:
    explicit ProductCategory(const QString &categoryName, int categoryCode);
    inline static CategoriesContaner *allCategories;

    const QString &name() const;
    int code() const;

    static QString nameByCode(int code);
    static int codeByName(const QString &name);

private:
    QString m_name;
    int m_code;
};

#endif // PRODUCTCATEGORY_H
