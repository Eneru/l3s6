#include "openglcanvas.h"

BEGIN_EVENT_TABLE(OpenGLCanvas, wxGLCanvas)
	EVT_PAINT(OpenGLCanvas::OnPaint)
	EVT_SIZE(OpenGLCanvas::OnSize)
	EVT_ERASE_BACKGROUND(OpenGLCanvas::OnEraseBackground)
END_EVENT_TABLE()

OpenGLCanvas::OpenGLCanvas(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name): wxGLCanvas(parent, id, pos, size, style, name)
{
	
}

OpenGLCanvas::~OpenGLCanvas(void)
{
	
}

void OpenGLCanvas::OnPaint(wxPaintEvent& event)
{
	wxPaintDC dc(this);
	SetCurrent();
	Draw();
	SwapBuffers();
}

void OpenGLCanvas::OnSize(wxSizeEvent& event)
{
	wxGLCanvas::OnSize(event);
	int w, h;
	GetClientSize(&w, &h);
	glViewport(0, 0, (GLint) w, (GLint) h);
}

void OpenGLCanvas::OnEraseBackground(wxEraseEvent& event)
{
		
}

void OpenGLCanvas::Draw()
{
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	int w, h;
	GetClientSize(&w, &h);
	glOrtho(-w/2., w/2., -h/2., h/2., -1., 3.);
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	glClearColor( .3f, .4f, .6f, 1 );
	glClear( GL_COLOR_BUFFER_BIT);
}
