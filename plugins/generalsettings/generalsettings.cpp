#include "generalsettings.h"

//------------------------ GeneralSettings --------------------------------//
GeneralSettings::GeneralSettings():
    m_settingPage(nullptr),
    m_widgetPage(nullptr)
{
    setUuid(QUuid("db507711-94ad-4f54-bffd-1a7789882839"));
}

ISettingsPage* GeneralSettings::getSettingsPage()
{
    if (!m_settingPage) {
        m_settingPage = new GeneralSettingsPage();
    }
    return m_settingPage;
}

IWidgetPage* GeneralSettings::getWidgetPage()
{
    return nullptr; //no implement for this
}


//------------------------ GeneralSettings --------------------------------//
//------------------------  ISettingsPage  --------------------------------//
GeneralSettingsPage::GeneralSettingsPage():
    m_page(nullptr),
    m_displayName("General")\
{

}

QMap<QString, QVariant> tempSettings;
QSettings settings;

//create widget for settings with single values
template<typename T, typename ParamType, typename Signal>
T* createSingleWidget( ISettingsPage* _page, Signal _signal, const char* _prop, QString _param, QVariant _default) {
    T* w = new T(); //sub of QWidget
    //w->setProperty(_prop, settings.value(_param, _default));
    QObject::connect(w, _signal, [=](ParamType val) {
        tempSettings[_param] = QVariant::fromValue(val);
    } );

    QObject::connect(_page, &ISettingsPage::restoreSettings, [=]() {
        w->setProperty(_prop, settings.value(_param, _default));
    });

    return w;
}


QStringList themesFromDirectory() {
    QDir dir;
    dir.cd("themes");
    return dir.entryList(QStringList() << "*.qss");
}


QWidget* GeneralSettingsPage::page()
{
    if (!m_page) {
        m_page = new QWidget();
        /*QLineEdit *lineWidthParam = createWidget<QLineEdit,QString>(
         * this,
         * &QLineEdit::textChanged,
         * "text",
         * QString("MainWindow/width"),
         * QString("210"));*/

        QSpinBox *mwWidthParam = createSingleWidget<QSpinBox,int>
            (
                this,
                static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
                "value",
                QString("MainWindow/width"),
                QVariant::fromValue(250)
            );
        mwWidthParam->setRange(160, 320);

        QComboBox *mwPositionParam = createSingleWidget<QComboBox,QString>
            (
                this,
                &QComboBox::currentTextChanged,
                "currentText",
                QString("MainWindow/DockEdge"),
                QVariant::fromValue<QString>("Right")
            );
        mwPositionParam->addItems(QStringList() << "Left" << "Right");

        QSpinBox *bsParam = createSingleWidget<QSpinBox,int>
            (
                this,
                static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
                "value",
                QString("ControlButtons/Size"),
                QVariant::fromValue(40)
            );
        bsParam->setRange(24, 64);

        QCheckBox* dsEnableParam = createSingleWidget<QCheckBox,int>
            (
                this,
                &QCheckBox::stateChanged,
                "checked",
                QString("Application/showDesktops"),
                QVariant::fromValue(2)
            );


        QComboBox *dsDefaultParam = createSingleWidget<QComboBox,QString>
            (
                this,
                &QComboBox::currentTextChanged,
                "currentText",
                QString("Environment/DefaultDesktop"),
                QVariant::fromValue<QString>("0")
            );

        int ndesktops = settings.value("Environment/Desktops").toInt();
        QStringList nitems;
        for (int i = 0; i < ndesktops; i++) {
            nitems << QString::number(i);
        }
        dsDefaultParam->addItems(nitems);

        connect(dsEnableParam, &QCheckBox::stateChanged, [=](int state) {
            dsDefaultParam->setEnabled(!state);
        });


        QComboBox *appIconsParam = createSingleWidget<QComboBox,QString>
            (
                this,
                &QComboBox::currentTextChanged,
                "currentText",
                QString("Application/icons"),
                QVariant::fromValue<QString>("Light")
            );
        appIconsParam->addItems(QStringList() << "Dark" << "Light");

        QComboBox *appThemeParam = createSingleWidget<QComboBox,QString>
            (
                this,
                &QComboBox::currentTextChanged,
                "currentText",
                QString("Application/theme"),
                QVariant::fromValue<QString>("stylesheet.qss")
            );
        appThemeParam->addItems(themesFromDirectory());

        connect(appThemeParam, &QComboBox::currentTextChanged, [=](QString val) {
            QString themeName = "./themes/" + val;
            QFile themeFile(themeName);
            themeFile.open(QFile::ReadOnly);
            if (themeFile.isOpen()) {
                QString StyleSheet = QLatin1String(themeFile.readAll());
                qApp->setStyleSheet(StyleSheet);
            }
        });

        QFormLayout *formLayout = new QFormLayout;
        formLayout->addRow(tr("&Ширина главного окна:"), mwWidthParam);
        formLayout->addRow(tr("&Позиция окна:"), mwPositionParam);
        formLayout->addRow(tr("&Размер кнопок нижней панели:"), bsParam);
        formLayout->addRow(tr("&На всех раб. столах:"), dsEnableParam);
        formLayout->addRow(tr("&Отображать на раб.столе:"), dsDefaultParam);
        formLayout->addRow(tr("&Тема иконок:"), appIconsParam);
        formLayout->addRow(tr("&Тема оформления:"), appThemeParam);

        m_page->setLayout(formLayout);
    }
    return m_page;
}


void GeneralSettingsPage::apply()
{
    for(auto &item: tempSettings.toStdMap()) {
        qDebug() << item.first << " : " << item.second;
        settings.setValue(item.first , item.second);
    }

    settings.sync();
    tempSettings.clear();
}


void GeneralSettingsPage::reject() {
    emit restoreSettings();
    tempSettings.clear();
}


QString GeneralSettingsPage::displayName() const {
    return m_displayName;
}


QPixmap GeneralSettingsPage::displayIcon() {
    QSettings settings;
    QString iconTheme = settings.value("Application/icons", "Light").toString();
    if (!m_icon) {
        m_icon = QPixmap(":" + iconTheme + ".general.png");
    }
    return m_icon;
}
//------------------------  ISettingsPage  --------------------------------//
//------------------------   IWidgetPage   --------------------------------//




//------------------------   IWidgetPage   --------------------------------//
