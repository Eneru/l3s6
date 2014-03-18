#ifndef _QONVERTISSEUR_H_
#define _QONVERTISSEUR_H_
// Inclure le fichier contenant la definition de la fenetre
#include "ui_qonvertisseur . h"

class Qonvertisseur : public QMainWindow, private Ui::MainWindow
{
	Q_OBJECT
// Necessaire a QT
public :
	Qonvertisseur (QWidget∗parent = 0);
	~Qonvertisseur();
};
#endif /* Fin _QONVERTISSEUR_H_ */
