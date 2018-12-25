#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <QObject>

class Warehouse : public QObject
{
    Q_OBJECT
public:
    explicit Warehouse(QObject *parent = nullptr);

signals:

public slots:
};

#endif // WAREHOUSE_H
