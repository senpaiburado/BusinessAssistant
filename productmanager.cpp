#include "productmanager.h"

#include "keygenerator.h"
#include "databasemanager.h"

Product *ProductManager::createProduct(ProductRegisterFormParam *productParams)
{
    Product *product = new Product(nullptr);
    product->m_key = KeyGenerator::generateKey(productParams);
    product->m_name = productParams->name;
    product->m_imgPath = productParams->imgPath;
    product->m_price = productParams->price;
    
    delete productParams;

    return product;
}

Product *ProductManager::loadProduct(ProductSaveData *productSaveParams)
{
    Product *product = new Product(nullptr);
    product->m_key = productSaveParams->key;
    product->m_name = productSaveParams->name;
    product->m_imgPath = productSaveParams->imgPath;
    product->m_price = productSaveParams->price;

    delete productSaveParams;
    return product;
}

Product *ProductManager::findProduct()
{

}
