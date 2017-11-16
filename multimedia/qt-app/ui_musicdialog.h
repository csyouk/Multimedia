/********************************************************************************
** Form generated from reading UI file 'musicdialog.ui'
**
** Created: Thu Nov 16 18:38:54 2017
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICDIALOG_H
#define UI_MUSICDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MusicDialog
{
public:
    QLabel *openFileLabel;
    QPushButton *openButton;
    QPushButton *playButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QPushButton *exitButton;

    void setupUi(QDialog *MusicDialog)
    {
        if (MusicDialog->objectName().isEmpty())
            MusicDialog->setObjectName(QString::fromUtf8("MusicDialog"));
        MusicDialog->resize(400, 300);
        openFileLabel = new QLabel(MusicDialog);
        openFileLabel->setObjectName(QString::fromUtf8("openFileLabel"));
        openFileLabel->setGeometry(QRect(60, 80, 211, 21));
        openButton = new QPushButton(MusicDialog);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setGeometry(QRect(50, 50, 80, 26));
        playButton = new QPushButton(MusicDialog);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setGeometry(QRect(50, 150, 80, 26));
        pauseButton = new QPushButton(MusicDialog);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));
        pauseButton->setGeometry(QRect(150, 150, 80, 26));
        stopButton = new QPushButton(MusicDialog);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(260, 150, 80, 26));
        exitButton = new QPushButton(MusicDialog);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(270, 250, 80, 26));

        retranslateUi(MusicDialog);

        QMetaObject::connectSlotsByName(MusicDialog);
    } // setupUi

    void retranslateUi(QDialog *MusicDialog)
    {
        MusicDialog->setWindowTitle(QApplication::translate("MusicDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        openFileLabel->setText(QApplication::translate("MusicDialog", "Open File", 0, QApplication::UnicodeUTF8));
        openButton->setText(QApplication::translate("MusicDialog", "Open", 0, QApplication::UnicodeUTF8));
        playButton->setText(QApplication::translate("MusicDialog", "Play", 0, QApplication::UnicodeUTF8));
        pauseButton->setText(QApplication::translate("MusicDialog", "Pause", 0, QApplication::UnicodeUTF8));
        stopButton->setText(QApplication::translate("MusicDialog", "Stop", 0, QApplication::UnicodeUTF8));
        exitButton->setText(QApplication::translate("MusicDialog", "Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MusicDialog: public Ui_MusicDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICDIALOG_H
