#include "startupmanager.h"

#include "databasemanager.h"
#include "product.h"
#include "guicontroller.h"


StartupManager::StartupManager(QObject *parent) : QObject(parent)
{
    dbManager = new DatabaseManager;
}

void StartupManager::init()
{
    connect(dbManager, &DatabaseManager::categoriesLoaded, this, [=](QList<ProductCategory*> &categories) {
        ProductCategory::allCategories = new CategoriesContaner;
        for (int i = 0; i < categories.length(); i++) {
            (*ProductCategory::allCategories) << categories[i];
        }
    });
    connect(dbManager, &DatabaseManager::productsLoaded, this, [=](QList<ProductSaveData*> &productList) {
        QList<Product*> products;
        for (int i = 0; i < productList.length(); i++) {
            products[i] = ProductManager::loadProduct(productList[i]);
            delete productList[i];
        }
        productList.clear();
        GuiController::instance()->setProductsList(products);
    });


    dbManager->loadCategoriesList();
    dbManager->loadProductsData(&ProductCategory::allCategories[0]);

}
