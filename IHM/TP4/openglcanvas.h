#ifndef __OPENGLCANVAS_H__
#define __OPENGLCANVAS_H__

#include <wx/glcanvas.h>
#include <wx/dcclient.h>
#include "mainframe.h"

class OpenGLCanvas: public wxGLCanvas
{
	public:
		OpenGLCanvas(wxWindow *parent, wxWindowID id, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=0, const wxString& name=wxT("oglc"));
		~OpenGLCanvas(void);
		
		
	private:
		void OnPaint( wxPaintEvent& event );
		void OnSize( wxSizeEvent& event );
		void OnEraseBackground( wxEraseEvent& event );
		void Draw(void);
		DECLARE_EVENT_TABLE();
}; //OpenGLCanvas

#endif // fin de __OPENGLCANVAS_H__
