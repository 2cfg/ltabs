#pragma once

#include <QObject>
#include <QtWidgets>
#include "configuration.h"

class GridControlLayout : public QGridLayout
{
    Q_OBJECT

private:
    int m_nrows;
    int m_ncolls;
    int m_btnCount;
    int m_buttonSize;
    QList<QToolButton *>  m_buttons;

public:
    GridControlLayout(QWidget* parent = 0);
    void addWidget   (QWidget* wgt       );
};
