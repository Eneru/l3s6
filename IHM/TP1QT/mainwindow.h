/****************************************************************************
** Form interface generated from reading ui file 'mainwindow.ui'
**
** Created: mar. mars 18 11:48:57 2014
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qvariant.h>
#include <qmainwindow.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QAction;
class QActionGroup;
class QToolBar;
class QPopupMenu;
class QLineEdit;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( QWidget* parent = 0, const char* name = 0, WFlags fl = WType_TopLevel );
    ~MainWindow();

    QLineEdit* lineEdit1;
    QPushButton* pushButton1_8;
    QPushButton* pushButton1_10;
    QPushButton* pushButton1_15;
    QPushButton* pushButton1_18;
    QPushButton* pushButton1_13;
    QPushButton* pushButton1_14;
    QPushButton* pushButton1_17;
    QPushButton* pushButton1_11;
    QPushButton* pushButton1_9;
    QPushButton* pushButton1_16;
    QPushButton* pushButton1_12;
    QPushButton* pushButton1_4;
    QPushButton* pushButton1;
    QPushButton* pushButton1_3;
    QPushButton* pushButton1_5;
    QPushButton* pushButton1_2;
    QPushButton* pushButton1_6;
    QPushButton* pushButton1_7;
    QMenuBar *MenuBarEditor;
    QPopupMenu *Fichier;
    QPopupMenu *Aide;
    QAction* fichierParamtres_conversionAction;
    QAction* fichierQuitterAction;
    QAction* aideA_proposAction;
    QAction* aideA_propos_de_Qt_Action;

protected:
    QVBoxLayout* layout7;
    QSpacerItem* spacer4;
    QHBoxLayout* layout4;
    QSpacerItem* spacer3;
    QGridLayout* layout1;
    QGridLayout* layout2;

protected slots:
    virtual void languageChange();

};

#endif // MAINWINDOW_H
