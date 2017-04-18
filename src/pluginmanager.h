#pragma once

#include <QObject>
#include <QtWidgets>
#include "controlbarlayout.h"
#include "plugins/isettingspage.h"
#include <QPluginLoader>
#include "plugins/iapplicationplugin.h"
#include "plugins/iwidgetpage.h"
#include "plugins/pluginhelper.h"


class PluginManager : public QObject
{
    Q_OBJECT
private:
    explicit PluginManager(QObject *parent = 0) {  }
public:
    static QList<IApplicationPlugin *> pluginsList;
    //static QList<ISettingsPage *> settingPages;
    //static QList<IWidgetPage*> widgetPages;
    static void loadPlugins();

};
