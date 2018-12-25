#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QThread>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#include "paramstypes.h"
#include "categoriescontaner.h"
#include "productcategory.h"

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    static QSqlDatabase *db();
    void loadProductData(const QString &productName);
    void loadProductsData(const ProductCategory &category);
    void loadProductsData(CategoriesContaner *container, bool freeFlag = true);

    void loadCategoriesList();

signals:
    void productLoaded(ProductSaveData*);
    void productsLoaded(QList<ProductSaveData*>&);

    void categoriesLoaded(QList<ProductCategory*>&);
};

class DatabaseWorker : public QThread {
    Q_OBJECT
public:
    DatabaseWorker(QString query);

    void run() override;

signals:
    void queryDone(QSqlQuery result);

private:
    QString m_query;
};

#endif // DATABASEMANAGER_H
