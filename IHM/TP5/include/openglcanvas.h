#ifndef __OPENGLCANVAS_H__
#define __OPENGLCANVAS_H__

#include <wx/glcanvas.h>
#include <wx/dcclient.h>
#include <wx/event.h>
#include <wx/utils.h>
#include <wx/wx.h>
#include "triangle.h"


class OpenGLCanvas: public wxGLCanvas
{
	public:
		OpenGLCanvas(wxWindow *parent, wxWindowID id, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=0, const wxString& name=wxT("oglc"));
		~OpenGLCanvas(void);
		void Draw();
		
		//Menu Contextuel défaut
		wxMenu popup;
		wxMenu* submenu1;		
		wxMenu* submenu2;		
		wxMenu* submenu3;
		
		//Menu Contextuel triangle
		wxMenu popup_tri;
		wxMenuItem* propri;
		wxMenuItem* supprim;
	private:
		int selected_tri;
		unsigned int etape;
	
		DECLARE_EVENT_TABLE();
		void OnPaint( wxPaintEvent& event );
		void OnSize( wxSizeEvent& event );
		void OnEraseBackground( wxEraseEvent& event );
		void OnMouseMove(wxMouseEvent& event);
		void OnLeftDown(wxMouseEvent& event);
		void OnLeftUp(wxMouseEvent& event);
		void OnRightDown(wxMouseEvent& event);
		void OnContextPptes(wxCommandEvent& event);
		void OnContextSuppr(wxCommandEvent& event);
		
		bool est_dans(wxString s);
		int Est_dans_triangle(int x, int y);
}; //OpenGLCanvas

#include "mainframe.h"

#endif // fin de __OPENGLCANVAS_H__
