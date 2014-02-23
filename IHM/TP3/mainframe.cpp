#include "mainframe.h"
#include "dialogs.h"
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
END_EVENT_TABLE()



CMainFrame::CMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame((wxFrame *)NULL, -1, title, pos, size) 
{
	epaisseurtraitcourante = 5;
	couleurcourante = wxRED;
	is_drawing = false;
	num_tri = 0;
} //constructor

void CMainFrame::CreateMyToolbar(void)
{
	m_toolbar=CreateToolBar(wxNO_BORDER | wxTB_HORIZONTAL | wxTB_FLAT | wxTB_TEXT,TOOLBAR_TOOLS);
	
	wxBitmap toolBarBitmaps[4];
	// Initialisation images
	toolBarBitmaps[0] = wxBitmap(wxT("new.bmp"),wxBITMAP_TYPE_BMP);
	toolBarBitmaps[1] = wxBitmap(wxT("open.bmp"),wxBITMAP_TYPE_BMP);
	toolBarBitmaps[2] = wxBitmap(wxT("save.bmp"),wxBITMAP_TYPE_BMP);
	toolBarBitmaps[3] = wxBitmap(wxT("draw.bmp"),wxBITMAP_TYPE_BMP);
	
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
			
			//On crée la couleur de notre triangle
			col[i] = new wxColour(roug[i],ver[i], ble[i]);
			
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
			tab_tri[i] = new Triangle(pt1[i],pt2[i],pt3[i],col[i],larg[i]);
		}
		options_menu->Enable(MENU_TRIANGLE_MANAGEMENT, true);
	}
}

void CMainFrame::OnSave(wxCommandEvent& event)
{
	
}

void CMainFrame::OnQuit(wxCommandEvent& event)
{
	Close(TRUE);
}

void CMainFrame::OnThickness(wxCommandEvent& event)
{
	EpaisseurDialog tdlg(m_toolbar, -1, wxT("Epaisseur"));
	tdlg.ShowModal();
}

void CMainFrame::OnColor(wxCommandEvent& event)
{
	ColorDialog cdlg(m_toolbar, -1, wxT("Couleur"));
	cdlg.ShowModal();
}

void CMainFrame::OnTriangle(wxCommandEvent& event)
{
	wxString strs8[] = { wxT("triangle 1"), wxT("triangle 2")};
	
	ManagementDialog mdlg(m_toolbar, -1, wxT("Gestion de triangles"));
	
	//Suppression des éléments de la liste
	mdlg.list->Clear();
	
	//Ajout de triangle 1 et 2
	mdlg.list->Append(strs8[0]);
	mdlg.list->Append(strs8[1]);
	
	mdlg.list->SetSelection(1);
	
	//Affichage
	mdlg.ShowModal();
}

void CMainFrame::OnVersion(wxCommandEvent& event)
{
	VersionDialog vdlg(m_toolbar, -1, wxT("Version"));
	vdlg.ShowModal();
}

void CMainFrame::OnToolBar(wxCommandEvent& event)
{
	wxToolBar *toolbar = GetToolBar();
	
	if (!event.IsChecked())
		toolbar->Hide();
	else
		toolbar->Show();
}

void CMainFrame::OnDraw(wxCommandEvent& event)
{
	is_drawing = !is_drawing;
	if (is_drawing)
		num_tri = 0;
}



