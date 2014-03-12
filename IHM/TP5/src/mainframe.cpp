#include "mainframe.h"
using namespace std;


BEGIN_EVENT_TABLE(CMainFrame, wxFrame)
	EVT_MENU(MENU_NEW, CMainFrame::OnNew)
	EVT_MENU(MENU_OPEN, CMainFrame::OnOpen)
	EVT_MENU(MENU_SAVE, CMainFrame::OnSave)
	EVT_MENU(MENU_QUIT, CMainFrame::OnQuit)
	EVT_MENU(MENU_THICKNESS, CMainFrame::OnThickness)
	EVT_MENU(MENU_COLOR, CMainFrame::OnColor)
	EVT_MENU(MENU_TRIANGLE_MANAGEMENT, CMainFrame::OnTriangle)
	EVT_MENU(MENU_VERSION, CMainFrame::OnVersion)
	EVT_MENU(MENU_TOOLBAR, CMainFrame::OnToolBar)
	EVT_TOOL(TOOLBAR_DRAW, CMainFrame::OnDraw)
	EVT_MENU(MENU_AIDE,CMainFrame::OnHelp)
END_EVENT_TABLE()



CMainFrame::CMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame((wxFrame *)NULL, -1, title, pos, size) 
{
	epaisseurtraitcourante = 5;
	couleurcourante = wxRED;
	is_drawing = false;
	num_tri = 0;
	oglc = new OpenGLCanvas (this, wxID_ANY);
} //constructor

void CMainFrame::CreateMyToolbar(void)
{
	m_toolbar=CreateToolBar(wxNO_BORDER | wxTB_HORIZONTAL | wxTB_FLAT | wxTB_TEXT,TOOLBAR_TOOLS);
	
	wxBitmap toolBarBitmaps[4];
	// Initialisation images
	toolBarBitmaps[0] = wxBitmap(wxT("image/new.bmp"),wxBITMAP_TYPE_BMP);
	toolBarBitmaps[1] = wxBitmap(wxT("image/open.bmp"),wxBITMAP_TYPE_BMP);
	toolBarBitmaps[2] = wxBitmap(wxT("image/save.bmp"),wxBITMAP_TYPE_BMP);
	toolBarBitmaps[3] = wxBitmap(wxT("image/draw.bmp"),wxBITMAP_TYPE_BMP);
	
	//Ajustement format image
	m_toolbar->SetToolBitmapSize(wxSize(toolBarBitmaps[0].GetWidth(),toolBarBitmaps[0].GetHeight()));
	
	//Ajout des boutons image
	m_toolbar->AddTool(MENU_NEW, wxT("Nouveau"), toolBarBitmaps[0], wxT("Nouveau dessin"));
	m_toolbar->AddTool(MENU_OPEN, wxT("Ouvrir"), toolBarBitmaps[1], wxT("Ouvrir un fichier existant"));
	m_toolbar->AddTool(MENU_SAVE, wxT("Sauvegarder"), toolBarBitmaps[2], wxT("Sauvegarder le fichier courant"));
	m_toolbar->AddSeparator();
	m_toolbar->AddCheckTool(TOOLBAR_DRAW, wxT("Dessiner"), toolBarBitmaps[3]);
	m_toolbar->Realize();
	SetToolBar(m_toolbar);
	
	return;
}

void CMainFrame::OnNew(wxCommandEvent& event)
{
	epaisseurtraitcourante = 5;
	couleurcourante = wxRED;
	is_drawing = false;
	options_menu->Enable(MENU_TRIANGLE_MANAGEMENT, false);
	num_tri = 0;
	m_toolbar->ToggleTool(TOOLBAR_DRAW, false);
	oglc->Draw();
	oglc->SwapBuffers();
}

void CMainFrame::OnOpen(wxCommandEvent& event)
{
	//Fichier à ouvrir
	wxString utility[] = {wxT("Choisir le fichier à ouvrir"), wxEmptyString, wxT("TRI files (*.tri)|*.tri")};
	
	wxFileDialog dial(this, utility[0], utility[1], utility[1], utility[2], wxOPEN | wxFILE_MUST_EXIST);
	
	if (dial.ShowModal() == wxID_OK)
	{
		ifstream fo(dial.GetPath().fn_str(), ios::in);
	
		//Si l'ouverture du fichier a raté
		if (!fo)
		{
			wxString errormsg, caption;
			errormsg.Printf(wxT("Unable to open file "));
			errormsg.Append(dial.GetPath());
			caption.Printf(wxT("Erreur"));
			wxMessageDialog msg(this, errormsg, caption, wxOK | wxCENTRE | wxICON_ERROR);
			msg.ShowModal();
			return ;
		}

		//On ajoute le nombre de triangles du fichier
		fo >> num_tri;
		
		//Si le nombre de triangles dépasse 5 on relève l'erreur
		if (num_tri > 5)
		{
			wxString errormsg, caption;
			errormsg.Printf(wxT("Il y a une limite de 5 triangles par fichier"));
			caption.Printf(wxT("Erreur"));
			wxMessageDialog msg(this, errormsg, caption, wxOK | wxCENTRE | wxICON_ERROR);
			msg.ShowModal();
			return ;
		}
	
		point pt1[num_tri], pt2[num_tri], pt3[num_tri];
		int roug[num_tri], ver[num_tri], ble[num_tri];
		wxColour * col[num_tri];
		float larg[num_tri];
	
		//On parcourt cette boucle pour chaque triangle à créer
		for (int i = 0; i<num_tri ;i++)
		{
			//On ajoute les points
			fo >> pt1[i].x >> pt1[i].y >> pt2[i].x >> pt2[i].y >> pt3[i].x >> pt3[i].y;
			//On ajoute les taux de RGB
			fo >> roug[i] >> ver[i] >> ble[i];
			//On ajoute l'épaisseur
			fo >> larg[i];
			
			//On teste si une couleur est mauvaise pour toute de suite arrêter de lire le fichier corrompu
			if (roug[i] < 0 || roug[i] > 255 || ver[i] < 0 || ver[i] > 255 || ble[i] < 0 || ble[i] > 255)
			{
				wxString errormsg, caption;
				errormsg.Printf(wxT("Le format des couleurs est mauvais (entre 0 et 255)"));
				caption.Printf(wxT("Erreur"));
				wxMessageDialog msg(this, errormsg, caption, wxOK | wxCENTRE | wxICON_ERROR);
				msg.ShowModal();
				return ;
			}
		}
		
		for (int i = 0; i<num_tri ;i++)
		{	
			//On crée le triangle
			tab_tri[i].p1 = pt1[i];
			tab_tri[i].p2 = pt2[i];
			tab_tri[i].p3 = pt3[i];
			if (roug[i] == 255)
				tab_tri[i].colour = wxRED;
			else if (ver[i] == 255)
				tab_tri[i].colour = wxGREEN;
			else if (ble[i] == 255)
				tab_tri[i].colour = wxBLUE;
			tab_tri[i].thickness = (float)larg[i];
			liste_nom_triangle[i] = wxT("triangle");
			liste_nom_triangle[i]<<(i+1);			
		}
		
		if (num_tri>0)
		{
			options_menu->Enable(MENU_TRIANGLE_MANAGEMENT, true);
		}
		detogglisation();
		is_drawing = false;
	}
}

void CMainFrame::OnSave(wxCommandEvent& event)
{
	//Fichier à sauvegarder
	wxString utility[] = {wxT("Entrer le nom du fichier de sauvegarde"), wxEmptyString, wxT("TRI files (*.tri)|*.tri")};
	
	wxFileDialog dial(this, utility[0], utility[1], utility[1], utility[2], wxSAVE | wxOVERWRITE_PROMPT);
	
	if (dial.ShowModal() == wxID_OK)
	{
		ofstream fs((char *)dial.GetPath().char_str(), ios::out);
	
		//Si la sauvgarde du fichier a raté
		if (!fs)
		{
			wxString errormsg, caption;
			errormsg.Printf(wxT("Unable to save file "));
			errormsg.Append(dial.GetPath());
			caption.Printf(wxT("Erreur"));
			wxMessageDialog msg(this, errormsg, caption, wxOK | wxCENTRE | wxICON_ERROR);
			msg.ShowModal();
			return ;
		}
		
		//Si le nombre de triangles dépasse 5 on relève l'erreur
		if (num_tri > 5)
		{
			wxString errormsg, caption;
			errormsg.Printf(wxT("Il y a une limite de 5 triangles par fichier"));
			caption.Printf(wxT("Erreur"));
			wxMessageDialog msg(this, errormsg, caption, wxOK | wxCENTRE | wxICON_ERROR);
			msg.ShowModal();
			return ;
		}
		
		//On ajoute le nombre de triangles du fichier
		fs << num_tri << endl << endl;
	
		int r,g,b, largeu;
		
		//On parcourt cette boucle pour chaque triangle à sauvegarder
		for (int i = 0; i<num_tri ;i++)
		{
			//On ajoute les points
			fs << tab_tri[i].p1.x << " " << tab_tri[i].p1.y << " " << tab_tri[i].p2.x << " " << tab_tri[i].p2.y << " " << tab_tri[i].p3.x << " " << tab_tri[i].p3.y << endl;
			//On ajoute les taux de RGB
			r = (int)tab_tri[i].colour->Red();
			g = (int)tab_tri[i].colour->Green();
			b = (int)tab_tri[i].colour->Blue();
			
			fs << r << " " << g << " " << b << endl;
			
			//On ajoute l'épaisseur
			largeu = (int)tab_tri[i].thickness;
			fs << largeu << endl << endl;
		}
		fs.close();
		detogglisation();
		is_drawing = false;
	}
}

void CMainFrame::OnQuit(wxCommandEvent& event)
{
	Close(TRUE);
}

void CMainFrame::OnThickness(wxCommandEvent& event)
{
	EpaisseurDialog tdlg(this, -1, wxT("Epaisseur"));
	tdlg.ShowModal();
}

void CMainFrame::OnColor(wxCommandEvent& event)
{
	ColorDialog cdlg(this, -1, wxT("Couleur"));
	cdlg.ShowModal();
}

void CMainFrame::OnTriangle(wxCommandEvent& event)
{	
	ManagementDialog mdlg(this, -1, wxT("Gestion de triangles"));
	
	mdlg.list->Clear();
	
	
	for (int i=0; i<num_tri; i++)
	{
		mdlg.list->Append(liste_nom_triangle[i]);
	}
	
	mdlg.list->SetSelection(0);
	
	//Affichage
	mdlg.ShowModal();
}

void CMainFrame::OnVersion(wxCommandEvent& event)
{
	VersionDialog vdlg(this, -1, wxT("Version"));
	vdlg.ShowModal();
}

void CMainFrame::OnToolBar(wxCommandEvent& event)
{
	wxToolBar *toolbar = GetToolBar();
	
	if (!event.IsChecked())
	{
		toolbar->Hide();
		SendSizeEvent(); // permet d'éviter le décalage de la disparition de la barre
	}
	else
	{
		toolbar->Show();
		SendSizeEvent(); // permet d'éviter le décalage de la barre
	}
}

void CMainFrame::OnDraw(wxCommandEvent& event)
{
	if (num_tri>=5)
	{
		detogglisation();
		is_drawing = false;
	}
	else
		is_drawing = !is_drawing;
	oglc->Draw();
	oglc->SwapBuffers();
}

void CMainFrame::detogglisation()
{
	m_toolbar->ToggleTool(TOOLBAR_DRAW, false);
}

void CMainFrame::OnHelp(wxCommandEvent& event)
{
	help.DisplayContents();
}







