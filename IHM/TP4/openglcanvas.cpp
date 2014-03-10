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
	CMainFrame * courant = (CMainFrame *)GetParent();
	
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	int w, h;
	GetClientSize(&w, &h);
	glOrtho(-w/2., w/2., -h/2., h/2., -1., 3.);
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	glClearColor( .3f, .4f, .6f, 1 );
	glClear( GL_COLOR_BUFFER_BIT);
	
	for (int i = 0; i<courant->num_tri; i++)
	{
		glColor3ui(courant->tab_tri[i].colour->Red(),courant->tab_tri[i].colour->Green(),courant->tab_tri[i].colour->Blue())
		glBegin(GL_TRIANGLE)
			glVertex2i(courant->tab_tri[i].p1.x,courant->tab_tri[i].p1.y);
			glVertex2i(courant->tab_tri[i].p2.x,courant->tab_tri[i].p2.y);
			glVertex2i(courant->tab_tri[i].p3.x,courant->tab_tri[i].p3.y);
		glEnd();
	}
	
	for (int i = 0; i<courant->num_tri; i++)
	{
		glColor3ui(0,0,0);
		glBegin(GL_LINES)
			glLineWidth(courant->tab_tri[i].thickness);
			glVertex2i(courant->tab_tri[i].p1.x,courant->tab_tri[i].p1.y);
			glVertex2i(courant->tab_tri[i].p2.x,courant->tab_tri[i].p2.y);
			glVertex2i(courant->tab_tri[i].p3.x,courant->tab_tri[i].p3.y);
		glEnd();
	}
	
	glFlush();
}
