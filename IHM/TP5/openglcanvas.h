#ifndef __OPENGLCANVAS_H__
#define __OPENGLCANVAS_H__

#include <wx/glcanvas.h>
#include <wx/dcclient.h>
#include <wx/event.h>
#include <wx/utils.h>

class OpenGLCanvas: public wxGLCanvas
{
	public:
		OpenGLCanvas(wxWindow *parent, wxWindowID id, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=0, const wxString& name=wxT("oglc"));
		~OpenGLCanvas(void);
		void Draw();
		
	private:
		unsigned int etape;
	
		DECLARE_EVENT_TABLE();
		void OnPaint( wxPaintEvent& event );
		void OnSize( wxSizeEvent& event );
		void OnEraseBackground( wxEraseEvent& event );
		void OnMouseMove(wxMouseEvent& event);
		void OnLeftDown(wxMouseEvent& event);
		void OnLeftUp(wxMouseEvent& event);
		void OnRightDown(wxMouseEvent& event);
		
		bool est_dans(wxString s);
}; //OpenGLCanvas

#include "mainframe.h"

#endif // fin de __OPENGLCANVAS_H__
