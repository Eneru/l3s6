#include "openglcanvas.h"

BEGIN_EVENT_TABLE(OpenGLCanvas, wxGLCanvas)
	EVT_PAINT(OpenGLCanvas::OnPaint)
	EVT_SIZE(OpenGLCanvas::OnSize)
	EVT_ERASE_BACKGROUND(OpenGLCanvas::OnEraseBackground)
	EVT_MOTION(OpenGLCanvas::OnMouseMove)
	EVT_LEFT_UP(OpenGLCanvas::OnLeftUp)
	EVT_LEFT_DOWN(OpenGLCanvas::OnLeftDown)
END_EVENT_TABLE()

OpenGLCanvas::OpenGLCanvas(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name): wxGLCanvas(parent, id, pos, size, style, name)
{
	etape=0;
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
		glLineWidth(courant->tab_tri[i].thickness);
		glColor3f(courant->tab_tri[i].colour->Red(),courant->tab_tri[i].colour->Green(),courant->tab_tri[i].colour->Blue());
		glBegin(GL_TRIANGLES);
			glVertex2f(courant->tab_tri[i].p1.x,courant->tab_tri[i].p1.y);
			glVertex2f(courant->tab_tri[i].p2.x,courant->tab_tri[i].p2.y);
			glVertex2f(courant->tab_tri[i].p3.x,courant->tab_tri[i].p3.y);
		glEnd();
		glColor3ui(0,0,0);
		glBegin(GL_LINES);
			glVertex2f(courant->tab_tri[i].p1.x,courant->tab_tri[i].p1.y);
			glVertex2f(courant->tab_tri[i].p2.x,courant->tab_tri[i].p2.y);
			glVertex2f(courant->tab_tri[i].p2.x,courant->tab_tri[i].p2.y);
			glVertex2f(courant->tab_tri[i].p3.x,courant->tab_tri[i].p3.y);
			glVertex2f(courant->tab_tri[i].p3.x,courant->tab_tri[i].p3.y);
			glVertex2f(courant->tab_tri[i].p1.x,courant->tab_tri[i].p1.y);
		glEnd();
	}
	glFlush();
}

void OpenGLCanvas::OnMouseMove(wxMouseEvent& event)
{
	Draw();
	CMainFrame * courant = (CMainFrame *)GetParent();
	if (courant->num_tri >= 5 || etape == 0 || !courant->is_drawing)
	{
		etape=0;
		return;
	}
	
	int w, h;
	GetClientSize(&w, &h);
	
	switch(etape)
	{
		case 1 :glColor3ui(0,0,0);
				courant->tab_tri[courant->num_tri].thickness = courant->epaisseurtraitcourante;
				glLineWidth(courant->tab_tri[courant->num_tri].thickness);
				glBegin(GL_LINES);
					glVertex2f(courant->tab_tri[courant->num_tri].p1.x,courant->tab_tri[courant->num_tri].p1.y);
					glVertex2f(event.m_x-w/2,-1*(event.m_y-h/2));
				glEnd();
				glFlush();break;
				
		case 2 :courant->tab_tri[courant->num_tri].colour = courant->couleurcourante;
				int r,g,b;
				r = (int)courant->tab_tri[courant->num_tri].colour->Red();
				g = (int)courant->tab_tri[courant->num_tri].colour->Green();
				b = (int)courant->tab_tri[courant->num_tri].colour->Blue();
				glColor3ui(r,g,b);
				glBegin(GL_TRIANGLES);
					glVertex2f(courant->tab_tri[courant->num_tri].p1.x,courant->tab_tri[courant->num_tri].p1.y);
					glVertex2f(courant->tab_tri[courant->num_tri].p2.x,courant->tab_tri[courant->num_tri].p2.y);
					glVertex2f(event.m_x-w/2,-1*(event.m_y-h/2));
				glEnd();
				glFlush();break;
	}
	SwapBuffers();
}

bool OpenGLCanvas::est_dans(wxString s)
{
	CMainFrame * courant = (CMainFrame *)GetParent();
	for (int i = 0; i<courant->num_tri; i++)
	{
		if (s.Contains(courant->liste_nom_triangle[i]))
		{
			return true;
		}
	}
	return false;
}

void OpenGLCanvas::OnLeftDown(wxMouseEvent& event)
{
	CMainFrame * courant = (CMainFrame *)GetParent();
	if (courant->num_tri >= 5 && courant->is_drawing)
	{
		courant->detogglisation();
		etape=0;
		return;
	}
	
	if(!courant->is_drawing)
	{
		etape=0;
		return;
	}
	
	wxString buffer = wxT("triangle");
	buffer<<(courant->num_tri+1);
				
	int cpt = 0;
	
	int w, h;
	GetClientSize(&w, &h);
	
	switch(etape)
	{
		case 0 :courant->tab_tri[courant->num_tri].p1.x = event.m_x-w/2;
				courant->tab_tri[courant->num_tri].p1.y = -1*(event.m_y-h/2);
				etape++; break;
				
		case 1 :courant->tab_tri[courant->num_tri].p2.x = event.m_x-w/2;
				courant->tab_tri[courant->num_tri].p2.y = -1*(event.m_y-h/2);
				etape++; break;
				
		case 2 :courant->tab_tri[courant->num_tri].p3.x = event.m_x-w/2;
				courant->tab_tri[courant->num_tri].p3.y = -1*(event.m_y-h/2);
				etape=0;
				
				// Test si le nom est déjà utilisé
				while (est_dans(buffer))
				{
					cpt++;
					buffer = wxT("triangle");
					buffer<<(cpt);
				}
				courant->liste_nom_triangle[courant->num_tri] = buffer;
				courant->num_tri++;
				courant->options_menu->Enable(MENU_TRIANGLE_MANAGEMENT, true);
				break;
				
		default : break;
	}
	
}

void OpenGLCanvas::OnLeftUp(wxMouseEvent& event)
{
}
