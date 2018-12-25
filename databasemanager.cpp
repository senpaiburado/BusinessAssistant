#include "databasemanager.h"

#include <QDebug>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>

QSqlDatabase *DatabaseManager::db()
{
    auto db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    db->setUserName(DB_USERNAME);
    db->setPassword(DB_PASSWORD);

    if (!db->open()) {
        qCritical() << "Cannot open database:" << db->lastError();
        return nullptr;
    }
    return db;
}

void DatabaseManager::loadProductData(const QString &productName)
{
    DatabaseWorker *workerProductData = new DatabaseWorker(QString("SELECT * FROM products INNER JOIN warehouse ON products.key = warehouse.key "
                                                                   "WHERE products.name = %1;").arg(productName));
    connect(workerProductData, &DatabaseWorker::queryDone, this, [&](QSqlQuery result) {
        ProductSaveData *data = new ProductSaveData;
        if (result.next()) {
            data->key = result.value(1).toString();
            data->name = result.value(2).toString();
            data->imgPath = result.value(3).toString();
            data->price = result.value(4).toFloat();
            data->count = result.value(5).toInt();
            data->countSold = result.value(6).toInt();
            data->categoryCode = result.value(7).toInt();

            delete workerProductData;
            emit productLoaded(data);
        }
    });

    workerProductData->run();
}

void DatabaseManager::loadProductsData(const ProductCategory &category)
{
    DatabaseWorker *workerProductData = new DatabaseWorker(QString("SELECT * FROM products INNER JOIN warehouse ON products.key = warehouse.key "
                                                                   "WHERE warehouse.category_code = %1;").arg(category.code()));
    connect(workerProductData, &DatabaseWorker::queryDone, this, [&](QSqlQuery result) {
        QList<ProductSaveData*> list;
        while (result.next()) {
            ProductSaveData *data = new ProductSaveData;
            data->key = result.value(1).toString();
            data->name = result.value(2).toString();
            data->imgPath = result.value(3).toString();
            data->price = result.value(4).toFloat();
            data->count = result.value(5).toInt();
            data->countSold = result.value(6).toInt();
            data->categoryCode = result.value(7).toInt();
            list.append(data);
        }
        delete workerProductData;
        emit productsLoaded(list);
    });

    workerProductData->run();
}

void DatabaseManager::loadProductsData(CategoriesContaner *container, bool freeFlag)
{
    QString query = "SELECT * FROM products INNER JOIN warehouse ON products.key = warehouse.key WHERE warehouse.category_code IN (";
    for (int i = 0; i < container->size(); i++) {
        query += QString::number(container->codeAt(i));
        if (i + 1 != container->size())
            query += ",";
        else
            query += ");";
    }

    if (freeFlag) {
        container->clear();
        delete container;
    }

    DatabaseWorker *workerProductData = new DatabaseWorker(query);

    connect(workerProductData, &DatabaseWorker::queryDone, this, [&](QSqlQuery result) {
            QList<ProductSaveData*> list;
            while (result.next()) {
                ProductSaveData *data = new ProductSaveData;
                data->key = result.value(1).toString();
                data->name = result.value(2).toString();
                data->imgPath = result.value(3).toString();
                data->price = result.value(4).toFloat();
                data->count = result.value(5).toInt();
                data->countSold = result.value(6).toInt();
                data->categoryCode = result.value(7).toInt();
                list.append(data);
            }
            delete workerProductData;
            emit productsLoaded(list);
        });

    workerProductData->run();
}

void DatabaseManager::loadCategoriesList()
{
    DatabaseWorker *workerProductData = new DatabaseWorker(QString("SELECT name, code FROM categories;"));
    connect(workerProductData, &DatabaseWorker::queryDone, this, [&](QSqlQuery result) {
        QList<ProductCategory*> list;
        while (result.next()) {
            list.append(new ProductCategory(result.value(0).toString(), result.value(1).toInt()));
        }
        delete workerProductData;
        emit categoriesLoaded(list);
    });

    workerProductData->run();
}

DatabaseWorker::DatabaseWorker(QString query)
{
    m_query = query;
}

void DatabaseWorker::run()
{
    auto db = DatabaseManager::db();
    auto result = db->exec(m_query);
    db->close();
    delete db;
    emit queryDone(result);
}
