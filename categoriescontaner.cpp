#include "categoriescontaner.h"

CategoriesContaner::CategoriesContaner()
{

}

CategoriesContaner &CategoriesContaner::operator<<(const ProductCategory &category)
{
    categories.append(new ProductCategory(category.name(), category.code()));
    return (*this);
}

CategoriesContaner &CategoriesContaner::operator<<(ProductCategory *category)
{
    categories.append(category);
    return (*this);
}

void CategoriesContaner::append(const ProductCategory &category)
{
    categories.append(new ProductCategory(category.name(), category.code()));
}

const QString &CategoriesContaner::nameAt(int pos) const
{
    return categories[pos]->name();
}

int CategoriesContaner::codeAt(int pos) const
{
    return categories[pos]->code();
}

ProductCategory *CategoriesContaner::operator[](int pos)
{
    return categories[pos];
}

void CategoriesContaner::clear()
{
    qDeleteAll(categories);
    categories.clear();
}

int CategoriesContaner::size()
{
    return categories.length();
}
