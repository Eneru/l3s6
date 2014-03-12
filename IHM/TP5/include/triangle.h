#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include <wx/colour.h>

enum
{
	POPUP_SUB1,
	POPUP_SUB2,
	POPUP_SUB3,
	CTX_PPTE,
	CTX_SUPPR,
	SLIDER_EPAISSEUR,
	BOITE_COULEUR,
	LISTE_TRIANGLE,
	B_PROP,
	B_SUPPR,
	T_CONTROLE,
	S_CONTROLE,
	BOITE_COULEUR2,
	MENU_NEW,
	MENU_OPEN,
	MENU_SAVE,
	MENU_QUIT,
	MENU_THICKNESS,
	MENU_COLOR,
	MENU_TRIANGLE_MANAGEMENT,
	MENU_TOOLBAR,
	MENU_VERSION,
	TOOLBAR_TOOLS,
	TOOLBAR_DRAW,
	MENU_AIDE,
	ID_TEXT = 10000
};

typedef struct 
{
	float x;	
	float y;	
} point;


// Define a new triangle class
class Triangle
{
	public:	
		//Attributs
		point p1;
		point p2;
		point p3;
		const wxColour * colour;
		float thickness;
		
		int ComputeZCoordinate(point p1, point p2, int x, int y);
		bool IsPointInTriangle(int x, int y);
};



#endif // #ifndef __TRIANGLE_H__


