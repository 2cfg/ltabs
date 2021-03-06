#pragma once
#include <QObject>
#include <QAbstractListModel>
#include <QSettings>
#include "pluginhelper.h"
#include "iapplicationplugin.h"
#include "../../app/include/configuration.h"

class PluginHelperListModel : public QAbstractListModel
{
    Q_OBJECT

private:
    QList<PluginHelper> m_list;
    bool moveRows(const QModelIndex &sourceParent, int sourceRow, int count,
                          const QModelIndex &destinationParent, int destinationChild) override;


public:
    PluginHelperListModel();
    QVariant data(const QModelIndex &index, int nRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex {}) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    void moveUp(QModelIndex &index);
    void moveDown(QModelIndex &index);
    void load();
    void save();

public slots:
    void add(QString &filename);
    void remove(QModelIndex &index);
};
