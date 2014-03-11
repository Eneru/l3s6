#include "mainframe.h"

class MyApp: public wxApp 
{
	virtual bool OnInit();
	
	//Attribut
	CMainFrame *m_MainFrame;
};


IMPLEMENT_APP(MyApp)


bool MyApp::OnInit() 
{
	//Fenetre principale
	m_MainFrame = new CMainFrame( wxString("Fenetre", wxConvUTF8), wxPoint(50,50), wxSize(450,340));
	//Barre de menus
	m_MainFrame->menu_bar = new wxMenuBar;
	//Menu
	m_MainFrame->file_menu = new wxMenu;
	m_MainFrame->display_menu = new wxMenu;
	m_MainFrame->options_menu = new wxMenu;
	m_MainFrame->help_menu = new wxMenu;
	
	//Ajout d'élément dans la barre de menus
	m_MainFrame->menu_bar->Append(m_MainFrame->file_menu, wxT("Fichier"));
	m_MainFrame->menu_bar->Append(m_MainFrame->display_menu, wxT("Affichage"));
	m_MainFrame->menu_bar->Append(m_MainFrame->options_menu, wxT("Options"));
	m_MainFrame->menu_bar->Append(m_MainFrame->help_menu, wxT("Aide"));
	
	//Menu de fichiers
	m_MainFrame->file_menu->Append(MENU_NEW, wxT("Nouveau\tCtrl-N"));
	m_MainFrame->file_menu->AppendSeparator();
	m_MainFrame->file_menu->Append(MENU_OPEN, wxT("Ouvrir\tCtrl-O"));
	m_MainFrame->file_menu->Append(MENU_SAVE, wxT("Sauvegarder\tCtrl-S"));
	m_MainFrame->file_menu->AppendSeparator();
	m_MainFrame->file_menu->Append(MENU_QUIT, wxT("Quitter\tCtrl-X"));
	
	//Menu d'options
	m_MainFrame->options_menu->Append(MENU_THICKNESS, wxT("Epaisseur de trait\tCtrl-E"));
	m_MainFrame->options_menu->Append(MENU_COLOR, wxT("Couleur"));
	m_MainFrame->options_menu->Append(MENU_TRIANGLE_MANAGEMENT, wxT("Gestion des triangles"));
	m_MainFrame->options_menu->Enable(MENU_TRIANGLE_MANAGEMENT, false);

	//Menu d'aide
	m_MainFrame->help_menu->Append(MENU_VERSION, wxT("Version"));
	m_MainFrame->help_menu->Append(MENU_AIDE, wxT("Ouvrir l'aide\tCtrl-H"));
	
	//Menu d'affichage
	m_MainFrame->display_menu->AppendCheckItem(MENU_TOOLBAR, wxT("Barre d'outils\tCtrl-B"));
	m_MainFrame->display_menu->Check(MENU_TOOLBAR,true);

	const wxString path = wxT("help/HELP");
	
	m_MainFrame->help.SetFrameParameters(wxT("Aide"),wxSize(-1,-1),wxDefaultPosition,false);
	
	if ( !m_MainFrame->help.Initialize(path) )
	{
		wxLogError(wxT("Cannot initialize the help system, aborting."));
		return false;
	}

	//Affichage
	m_MainFrame->SetMenuBar(m_MainFrame->menu_bar);
	m_MainFrame->CreateMyToolbar();
	m_MainFrame->Show(TRUE);
	
	
	return TRUE;
} 


