/********************************************************************************
** Form generated from reading UI file 'cameradialog.ui'
**
** Created: Thu Nov 16 18:38:54 2017
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERADIALOG_H
#define UI_CAMERADIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CameraDialog
{
public:
    QPushButton *captureButton;
    QPushButton *exitButton;

    void setupUi(QDialog *CameraDialog)
    {
        if (CameraDialog->objectName().isEmpty())
            CameraDialog->setObjectName(QString::fromUtf8("CameraDialog"));
        CameraDialog->resize(400, 300);
        captureButton = new QPushButton(CameraDialog);
        captureButton->setObjectName(QString::fromUtf8("captureButton"));
        captureButton->setGeometry(QRect(280, 200, 80, 26));
        exitButton = new QPushButton(CameraDialog);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(280, 240, 80, 26));

        retranslateUi(CameraDialog);

        QMetaObject::connectSlotsByName(CameraDialog);
    } // setupUi

    void retranslateUi(QDialog *CameraDialog)
    {
        CameraDialog->setWindowTitle(QApplication::translate("CameraDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        captureButton->setText(QApplication::translate("CameraDialog", "Capture", 0, QApplication::UnicodeUTF8));
        exitButton->setText(QApplication::translate("CameraDialog", "Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CameraDialog: public Ui_CameraDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERADIALOG_H
