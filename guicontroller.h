#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include <QObject>

#include "product.h"

class GuiController : public QObject
{
    Q_OBJECT
public:
    explicit GuiController(QObject *parent = nullptr);

    static GuiController *instance();

    void setProductsList(const QList<Product*> productsList);


};

#endif // GUICONTROLLER_H
