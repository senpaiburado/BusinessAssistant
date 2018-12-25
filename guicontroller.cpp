#include "guicontroller.h"

GuiController::GuiController(QObject *parent) : QObject(parent)
{

}

GuiController *GuiController::instance()
{
    static GuiController *guiController = new GuiController;
    return guiController;
}

void GuiController::setProductsList(const QList<Product *> productsList)
{

}
