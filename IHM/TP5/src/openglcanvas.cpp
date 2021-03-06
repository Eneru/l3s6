#include "openglcanvas.h"

BEGIN_EVENT_TABLE(OpenGLCanvas, wxGLCanvas)
	EVT_PAINT(OpenGLCanvas::OnPaint)
	EVT_SIZE(OpenGLCanvas::OnSize)
	EVT_ERASE_BACKGROUND(OpenGLCanvas::OnEraseBackground)
	EVT_MOTION(OpenGLCanvas::OnMouseMove)
	EVT_LEFT_UP(OpenGLCanvas::OnLeftUp)
	EVT_LEFT_DOWN(OpenGLCanvas::OnLeftDown)
	EVT_RIGHT_DOWN(OpenGLCanvas::OnRightDown)
	EVT_MENU(CTX_PPTE, OpenGLCanvas::OnContextPptes)
	EVT_MENU(CTX_SUPPR, OpenGLCanvas::OnContextSuppr)
END_EVENT_TABLE()

OpenGLCanvas::OpenGLCanvas(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name): wxGLCanvas(parent, id, pos, size, style, name)
{
	etape=0;
	//Init clique out
	submenu1 = new wxMenu;
	submenu2 = new wxMenu;
	submenu3 = new wxMenu;
			
	submenu1->Append(MENU_OPEN, wxT("Ouvrir fichier"));
	submenu1->Append(MENU_SAVE, wxT("Sauvegarder fichier"));
	submenu2->Append(MENU_TRIANGLE_MANAGEMENT, wxT("Gestion des triangles"));
	submenu3->Append(MENU_COLOR, wxT("Couleurs courantes"));
	submenu3->Append(MENU_THICKNESS, wxT("Epaisseur courante"));
	
	popup.Append(POPUP_SUB1, wxT("Fichier"),submenu1);
	popup.Append(POPUP_SUB2, wxT("Gestion"),submenu2);
	popup.Append(POPUP_SUB3, wxT("Valeurs courantes"),submenu3);
	
	//Init clique in
	propri = new wxMenuItem(&popup_tri,CTX_PPTE, wxT("Proprietes de ce triangle"),wxEmptyString, wxITEM_NORMAL,NULL);
	supprim = new wxMenuItem(&popup_tri,CTX_SUPPR, wxT("Suppression de ce triangle"),wxEmptyString, wxITEM_NORMAL,NULL);
			
	popup_tri.Append(propri);
	popup_tri.Append(supprim);
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
	glViewport(0, 0, (GLint) w, (GLint) h);
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
		SwapBuffers();
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
				break;
				
		case 2 :courant->tab_tri[courant->num_tri].colour = courant->couleurcourante;
				float r,g,b;
				r = courant->tab_tri[courant->num_tri].colour->Red();
				g = courant->tab_tri[courant->num_tri].colour->Green();
				b = courant->tab_tri[courant->num_tri].colour->Blue();
				glColor3f(r,g,b);
				glBegin(GL_TRIANGLES);
					glVertex2f(courant->tab_tri[courant->num_tri].p1.x,courant->tab_tri[courant->num_tri].p1.y);
					glVertex2f(courant->tab_tri[courant->num_tri].p2.x,courant->tab_tri[courant->num_tri].p2.y);
					glVertex2f(event.m_x-w/2,-1*(event.m_y-h/2));
				glEnd();
				glColor3ui(0,0,0);
				glLineWidth(courant->tab_tri[courant->num_tri].thickness);
				glBegin(GL_LINES);
					glVertex2f(courant->tab_tri[courant->num_tri].p1.x,courant->tab_tri[courant->num_tri].p1.y);
					glVertex2f(courant->tab_tri[courant->num_tri].p2.x,courant->tab_tri[courant->num_tri].p2.y);
					glVertex2f(courant->tab_tri[courant->num_tri].p2.x,courant->tab_tri[courant->num_tri].p2.y);
					glVertex2f(event.m_x-w/2,-1*(event.m_y-h/2));
					glVertex2f(courant->tab_tri[courant->num_tri].p1.x,courant->tab_tri[courant->num_tri].p1.y);
					glVertex2f(event.m_x-w/2,-1*(event.m_y-h/2));
				glEnd();
				break;
	}
	glFlush();
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

void OpenGLCanvas::OnRightDown(wxMouseEvent& event)
{
	CMainFrame * courant = (CMainFrame *)GetParent();
	int w, h;
	GetClientSize(&w, &h);
	
	selected_tri = Est_dans_triangle(event.m_x-w/2, -1*(event.m_y-h/2));
	
	if (selected_tri == -1)
	{	
		if (courant->num_tri > 0)
			submenu2->Enable(MENU_TRIANGLE_MANAGEMENT,true);
		else
			submenu2->Enable(MENU_TRIANGLE_MANAGEMENT,false);
			
		PopupMenu(&popup, event.GetX(), event.GetY());
	}
	else
		PopupMenu(&popup_tri, event.GetX(), event.GetY());
}

//Je préfère sélectionner le dernier triangle de la liste sur le clique car il est au-dessus
//On risquerait sinon de supprimer un triangle sans s'en rendre compte car caché
int OpenGLCanvas::Est_dans_triangle (int x, int y)
{
	CMainFrame * courant = (CMainFrame *)GetParent();
	
	for (int i = courant->num_tri-1; i>=0; i--)
	{
		if(courant->tab_tri[i].IsPointInTriangle(x,y))
			return i;
	}
	return -1;
}

void OpenGLCanvas::OnContextPptes(wxCommandEvent& event)
{
	CMainFrame * courant = (CMainFrame *)GetParent();
	wxCommandEvent evt( wxEVT_COMMAND_BUTTON_CLICKED, B_PROP);
	
	ManagementDialog mdlg(courant, -1, wxT("Gestion de triangles"));
	
	mdlg.list->Clear();
	
	
	for (int i=0; i<courant->num_tri; i++)
	{
		mdlg.list->Append(courant->liste_nom_triangle[i]);
	}
	
	mdlg.list->SetSelection(selected_tri);
	//Affichage (Je ne sais pas comment faire apparaître la propriété dans la fenêtre par contre)
	mdlg.GetEventHandler()->ProcessEvent(evt);
}

void OpenGLCanvas::OnContextSuppr(wxCommandEvent& event)
{
	CMainFrame * courant = (CMainFrame *)GetParent();
	
	//On décalle les triangles dans les tableaux
	for (int i = selected_tri; i<courant->num_tri-1; i++)
	{
		courant->tab_tri[i]=courant->tab_tri[i+1];
		courant->liste_nom_triangle[i]=courant->liste_nom_triangle[i+1];
	}
	
	//On diminue le nombre de triangles
	courant->num_tri-=1;
	
	if (courant->num_tri == 0)
	{
		courant->options_menu->Enable(MENU_TRIANGLE_MANAGEMENT, false);
	}
	Draw();
	SwapBuffers();
}














