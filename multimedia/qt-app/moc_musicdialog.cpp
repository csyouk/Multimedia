/****************************************************************************
** Meta object code from reading C++ file 'musicdialog.h'
**
** Created: Thu Nov 16 18:38:57 2017
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qdemo/musicdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musicdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MusicDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      37,   12,   12,   12, 0x08,
      61,   12,   12,   12, 0x08,
      85,   12,   12,   12, 0x08,
     110,   12,   12,   12, 0x08,
     134,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MusicDialog[] = {
    "MusicDialog\0\0on_exitButton_clicked()\0"
    "on_openButton_clicked()\0on_playButton_clicked()\0"
    "on_pauseButton_clicked()\0"
    "on_stopButton_clicked()\0handleCommand(int)\0"
};

void MusicDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MusicDialog *_t = static_cast<MusicDialog *>(_o);
        switch (_id) {
        case 0: _t->on_exitButton_clicked(); break;
        case 1: _t->on_openButton_clicked(); break;
        case 2: _t->on_playButton_clicked(); break;
        case 3: _t->on_pauseButton_clicked(); break;
        case 4: _t->on_stopButton_clicked(); break;
        case 5: _t->handleCommand((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MusicDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MusicDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MusicDialog,
      qt_meta_data_MusicDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MusicDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MusicDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MusicDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MusicDialog))
        return static_cast<void*>(const_cast< MusicDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MusicDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
