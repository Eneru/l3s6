/****************************************************************************
** Form implementation generated from reading ui file 'mainwindow.ui'
**
** Created: mar. mars 18 11:49:19 2014
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "mainwindow.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qaction.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qtoolbar.h>

/*
 *  Constructs a MainWindow as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 */
MainWindow::MainWindow( QWidget* parent, const char* name, WFlags fl )
    : QMainWindow( parent, name, fl )
{
    (void)statusBar();
    if ( !name )
	setName( "MainWindow" );
    setCentralWidget( new QWidget( this, "qt_central_widget" ) );

    QWidget* privateLayoutWidget = new QWidget( centralWidget(), "layout7" );
    privateLayoutWidget->setGeometry( QRect( 10, 10, 543, 234 ) );
    layout7 = new QVBoxLayout( privateLayoutWidget, 11, 6, "layout7"); 

    lineEdit1 = new QLineEdit( privateLayoutWidget, "lineEdit1" );
    layout7->addWidget( lineEdit1 );

    layout4 = new QHBoxLayout( 0, 0, 6, "layout4"); 

    layout1 = new QGridLayout( 0, 1, 1, 0, 6, "layout1"); 

    pushButton1_8 = new QPushButton( privateLayoutWidget, "pushButton1_8" );

    layout1->addWidget( pushButton1_8, 3, 2 );

    pushButton1_10 = new QPushButton( privateLayoutWidget, "pushButton1_10" );

    layout1->addWidget( pushButton1_10, 2, 1 );

    pushButton1_15 = new QPushButton( privateLayoutWidget, "pushButton1_15" );

    layout1->addWidget( pushButton1_15, 1, 0 );

    pushButton1_18 = new QPushButton( privateLayoutWidget, "pushButton1_18" );

    layout1->addWidget( pushButton1_18, 3, 0 );

    pushButton1_13 = new QPushButton( privateLayoutWidget, "pushButton1_13" );

    layout1->addWidget( pushButton1_13, 0, 1 );

    pushButton1_14 = new QPushButton( privateLayoutWidget, "pushButton1_14" );

    layout1->addWidget( pushButton1_14, 0, 0 );

    pushButton1_17 = new QPushButton( privateLayoutWidget, "pushButton1_17" );

    layout1->addWidget( pushButton1_17, 1, 2 );

    pushButton1_11 = new QPushButton( privateLayoutWidget, "pushButton1_11" );

    layout1->addWidget( pushButton1_11, 1, 1 );

    pushButton1_9 = new QPushButton( privateLayoutWidget, "pushButton1_9" );

    layout1->addWidget( pushButton1_9, 2, 2 );

    pushButton1_16 = new QPushButton( privateLayoutWidget, "pushButton1_16" );

    layout1->addWidget( pushButton1_16, 2, 0 );

    pushButton1_12 = new QPushButton( privateLayoutWidget, "pushButton1_12" );

    layout1->addWidget( pushButton1_12, 0, 2 );
    layout4->addLayout( layout1 );
    spacer3 = new QSpacerItem( 30, 180, QSizePolicy::Fixed, QSizePolicy::Minimum );
    layout4->addItem( spacer3 );

    layout2 = new QGridLayout( 0, 1, 1, 0, 6, "layout2"); 

    pushButton1_4 = new QPushButton( privateLayoutWidget, "pushButton1_4" );

    layout2->addWidget( pushButton1_4, 1, 1 );

    pushButton1 = new QPushButton( privateLayoutWidget, "pushButton1" );

    layout2->addMultiCellWidget( pushButton1, 3, 3, 0, 1 );

    pushButton1_3 = new QPushButton( privateLayoutWidget, "pushButton1_3" );

    layout2->addWidget( pushButton1_3, 2, 0 );

    pushButton1_5 = new QPushButton( privateLayoutWidget, "pushButton1_5" );

    layout2->addWidget( pushButton1_5, 1, 0 );

    pushButton1_2 = new QPushButton( privateLayoutWidget, "pushButton1_2" );

    layout2->addWidget( pushButton1_2, 2, 1 );

    pushButton1_6 = new QPushButton( privateLayoutWidget, "pushButton1_6" );

    layout2->addWidget( pushButton1_6, 0, 1 );

    pushButton1_7 = new QPushButton( privateLayoutWidget, "pushButton1_7" );

    layout2->addWidget( pushButton1_7, 0, 0 );
    layout4->addLayout( layout2 );
    layout7->addLayout( layout4 );
    spacer4 = new QSpacerItem( 541, 16, QSizePolicy::Maximum, QSizePolicy::Minimum );
    layout7->addItem( spacer4 );

    // actions
    fichierParamtres_conversionAction = new QAction( this, "fichierParamtres_conversionAction" );
    fichierQuitterAction = new QAction( this, "fichierQuitterAction" );
    aideA_proposAction = new QAction( this, "aideA_proposAction" );
    aideA_propos_de_Qt_Action = new QAction( this, "aideA_propos_de_Qt_Action" );


    // toolbars


    // menubar
    MenuBarEditor = new QMenuBar( this, "MenuBarEditor" );


    Fichier = new QPopupMenu( this );
    fichierParamtres_conversionAction->addTo( Fichier );
    fichierQuitterAction->addTo( Fichier );
    MenuBarEditor->insertItem( QString(""), Fichier, 1 );

    Aide = new QPopupMenu( this );
    aideA_proposAction->addTo( Aide );
    aideA_propos_de_Qt_Action->addTo( Aide );
    MenuBarEditor->insertItem( QString(""), Aide, 2 );

    languageChange();
    resize( QSize(562, 302).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
MainWindow::~MainWindow()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void MainWindow::languageChange()
{
    setCaption( tr( "MainWindow" ) );
    pushButton1_8->setText( tr( "." ) );
    pushButton1_10->setText( tr( "2" ) );
    pushButton1_15->setText( tr( "4" ) );
    pushButton1_18->setText( tr( "0" ) );
    pushButton1_13->setText( tr( "8" ) );
    pushButton1_14->setText( tr( "7" ) );
    pushButton1_17->setText( tr( "6" ) );
    pushButton1_11->setText( tr( "5" ) );
    pushButton1_9->setText( tr( "3" ) );
    pushButton1_16->setText( tr( "1" ) );
    pushButton1_12->setText( tr( "9" ) );
    pushButton1_4->setText( trUtf8( "\xe2\x82\xac\x20\x2d\x3e\x20\x24" ) );
    pushButton1->setText( tr( "=" ) );
    pushButton1_3->setText( tr( "*" ) );
    pushButton1_5->setText( tr( "-" ) );
    pushButton1_2->setText( tr( "/" ) );
    pushButton1_6->setText( trUtf8( "\x24\x20\x2d\x3e\x20\xe2\x82\xac" ) );
    pushButton1_7->setText( tr( "+" ) );
    fichierParamtres_conversionAction->setText( trUtf8( "\x50\x61\x72\x61\x6d\xc3\xa8\x74\x72\x65\x73\x20\x63\x6f\x6e\x76\x65\x72\x73\x69\x6f"
    "\x6e\x20\x2e\x2e\x2e" ) );
    fichierParamtres_conversionAction->setMenuText( trUtf8( "\x50\x61\x72\x61\x6d\xc3\xa8\x74\x72\x65\x73\x20\x63\x6f\x6e\x76\x65\x72\x73\x69\x6f"
    "\x6e\x20\x2e\x2e\x2e" ) );
    fichierQuitterAction->setText( tr( "Quitter" ) );
    fichierQuitterAction->setMenuText( tr( "Quitter" ) );
    aideA_proposAction->setText( tr( "A propos ..." ) );
    aideA_proposAction->setMenuText( tr( "A propos ..." ) );
    aideA_propos_de_Qt_Action->setText( tr( "A propos de Qt ..." ) );
    aideA_propos_de_Qt_Action->setMenuText( tr( "A propos de Qt ..." ) );
    if (MenuBarEditor->findItem(1))
        MenuBarEditor->findItem(1)->setText( tr( "Fichier" ) );
    if (MenuBarEditor->findItem(2))
        MenuBarEditor->findItem(2)->setText( tr( "Aide" ) );
}

