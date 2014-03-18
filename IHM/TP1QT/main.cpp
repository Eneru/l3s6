#include <QtGui>
#include "qconvertisseur.h"

int main (int argc, char * argv[])
{
	QApplication app (argc,argv);
	
	Qonvertisseur mainwin;
	mainwin.show();
	
	return app.exec();	
}
