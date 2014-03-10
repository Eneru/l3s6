#ifndef __OPENGLCANVAS_H__
#define __OPENGLCANVAS_H__

#include <wx/glcanvas.h>
#include <wx/dcclient.h>
#include <wx/event.h>

class OpenGLCanvas: public wxGLCanvas
{
	public:
		OpenGLCanvas(wxWindow *parent, wxWindowID id, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=0, const wxString& name=wxT("oglc"));
		~OpenGLCanvas(void);
		void Draw();
		void OnMouseMove(wxMouseEvent& event);
		void OnLeftDown(wxMouseEvent& event);
		void OnLeftUp(wxMouseEvent& event);
		
		unsigned int etape;
		
	private:
		void OnPaint( wxPaintEvent& event );
		void OnSize( wxSizeEvent& event );
		void OnEraseBackground( wxEraseEvent& event );
		DECLARE_EVENT_TABLE();
}; //OpenGLCanvas

#include "mainframe.h"

#endif // fin de __OPENGLCANVAS_H__
