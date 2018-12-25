#include "productcategory.h"

ProductCategory::ProductCategory(const QString &categoryName, int categoryCode)
{
    m_name = categoryName;
    m_code = categoryCode;
}

const QString &ProductCategory::name() const
{
    return m_name;
}

int ProductCategory::code() const
{
    return m_code;
}

QString ProductCategory::nameByCode(int code)
{

}
