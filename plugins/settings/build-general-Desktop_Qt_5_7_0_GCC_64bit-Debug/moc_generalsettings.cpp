/****************************************************************************
** Meta object code from reading C++ file 'generalsettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../general/generalsettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'generalsettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GeneralSettings_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GeneralSettings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GeneralSettings_t qt_meta_stringdata_GeneralSettings = {
    {
QT_MOC_LITERAL(0, 0, 15) // "GeneralSettings"

    },
    "GeneralSettings"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GeneralSettings[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void GeneralSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject GeneralSettings::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GeneralSettings.data,
      qt_meta_data_GeneralSettings,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GeneralSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GeneralSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GeneralSettings.stringdata0))
        return static_cast<void*>(const_cast< GeneralSettings*>(this));
    if (!strcmp(_clname, "IApplicationPlugin"))
        return static_cast< IApplicationPlugin*>(const_cast< GeneralSettings*>(this));
    if (!strcmp(_clname, "ru.ltabs.plugins.IApplicationPlugin"))
        return static_cast< IApplicationPlugin*>(const_cast< GeneralSettings*>(this));
    return QObject::qt_metacast(_clname);
}

int GeneralSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}

QT_PLUGIN_METADATA_SECTION const uint qt_section_alignment_dummy = 42;

#ifdef QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    0xb0, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0x9c, 0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    '#',  0x00, 'r',  'u',  '.',  'l',  't',  'a', 
    'b',  's',  '.',  'p',  'l',  'u',  'g',  'i', 
    'n',  's',  '.',  'I',  'A',  'p',  'p',  'l', 
    'i',  'c',  'a',  't',  'i',  'o',  'n',  'P', 
    'l',  'u',  'g',  'i',  'n',  0x00, 0x00, 0x00,
    0x1b, 0x0a, 0x00, 0x00, 0x09, 0x00, 'c',  'l', 
    'a',  's',  's',  'N',  'a',  'm',  'e',  0x00,
    0x0f, 0x00, 'G',  'e',  'n',  'e',  'r',  'a', 
    'l',  'S',  'e',  't',  't',  'i',  'n',  'g', 
    's',  0x00, 0x00, 0x00, ':',  0xe0, 0xa0, 0x00,
    0x07, 0x00, 'v',  'e',  'r',  's',  'i',  'o', 
    'n',  0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00,
    0x05, 0x00, 'd',  'e',  'b',  'u',  'g',  0x00,
    0x15, 0x12, 0x00, 0x00, 0x08, 0x00, 'M',  'e', 
    't',  'a',  'D',  'a',  't',  'a',  0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    0x80, 0x00, 0x00, 0x00, '@',  0x00, 0x00, 0x00,
    't',  0x00, 0x00, 0x00, 'd',  0x00, 0x00, 0x00
};

#else // QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    0xb0, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0x9c, 0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    '#',  0x00, 'r',  'u',  '.',  'l',  't',  'a', 
    'b',  's',  '.',  'p',  'l',  'u',  'g',  'i', 
    'n',  's',  '.',  'I',  'A',  'p',  'p',  'l', 
    'i',  'c',  'a',  't',  'i',  'o',  'n',  'P', 
    'l',  'u',  'g',  'i',  'n',  0x00, 0x00, 0x00,
    0x15, 0x0a, 0x00, 0x00, 0x08, 0x00, 'M',  'e', 
    't',  'a',  'D',  'a',  't',  'a',  0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x9b, 0x0d, 0x00, 0x00,
    0x09, 0x00, 'c',  'l',  'a',  's',  's',  'N', 
    'a',  'm',  'e',  0x00, 0x0f, 0x00, 'G',  'e', 
    'n',  'e',  'r',  'a',  'l',  'S',  'e',  't', 
    't',  'i',  'n',  'g',  's',  0x00, 0x00, 0x00,
    '1',  0x00, 0x00, 0x00, 0x05, 0x00, 'd',  'e', 
    'b',  'u',  'g',  0x00, ':',  0xe0, 0xa0, 0x00,
    0x07, 0x00, 'v',  'e',  'r',  's',  'i',  'o', 
    'n',  0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    '@',  0x00, 0x00, 0x00, '\\', 0x00, 0x00, 0x00,
    0x80, 0x00, 0x00, 0x00, 0x8c, 0x00, 0x00, 0x00
};
#endif // QT_NO_DEBUG

QT_MOC_EXPORT_PLUGIN(GeneralSettings, GeneralSettings)

struct qt_meta_stringdata_GeneralSettingsPage_t {
    QByteArrayData data[1];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GeneralSettingsPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GeneralSettingsPage_t qt_meta_stringdata_GeneralSettingsPage = {
    {
QT_MOC_LITERAL(0, 0, 19) // "GeneralSettingsPage"

    },
    "GeneralSettingsPage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GeneralSettingsPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void GeneralSettingsPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject GeneralSettingsPage::staticMetaObject = {
    { &ISettingsPage::staticMetaObject, qt_meta_stringdata_GeneralSettingsPage.data,
      qt_meta_data_GeneralSettingsPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GeneralSettingsPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GeneralSettingsPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GeneralSettingsPage.stringdata0))
        return static_cast<void*>(const_cast< GeneralSettingsPage*>(this));
    return ISettingsPage::qt_metacast(_clname);
}

int GeneralSettingsPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ISettingsPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
