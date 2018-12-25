#ifndef STARTUPMANAGER_H
#define STARTUPMANAGER_H

#include <QObject>

#include "databasemanager.h"

class StartupManager : public QObject
{
    Q_OBJECT
public:
    explicit StartupManager(QObject *parent = nullptr);
    void init();

private:
    DatabaseManager *dbManager;
};

#endif // STARTUPMANAGER_H
