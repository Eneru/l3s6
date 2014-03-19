#ifndef QONVERTISSEUR__H_
#define QONVERTISSEUR__H_

#include "ui_mainwindow.h"

class Qonvertisseur : public QMainWindow, private Ui::MainWindow
{
	Q_OBJECT
	
public : 
	Qonvertisseur (QWidget* parent = 0);
	~Qonvertisseur (void);
};

#endif //QONVERTISSEUR__H_
