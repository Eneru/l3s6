#include "mainframe.h"
#include "dialogs.h"

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
	m_MainFrame = new CMainFrame( wxString("Fenetre", wxConvUTF8), wxPoint(50,50), wxSize(450,340) );
	//Barre de menus
	wxMenuBar *menu_bar = new wxMenuBar;
	//Menu
	wxMenu *file_menu = new wxMenu;
	wxMenu *display_menu = new wxMenu;
	wxMenu *options_menu = new wxMenu;
	wxMenu *help_menu = new wxMenu;
	
	//Ajout d'élément dans la barre de menus
	menu_bar->Append(file_menu, wxT("Fichier"));
	menu_bar->Append(display_menu, wxT("Affichage"));
	menu_bar->Append(options_menu, wxT("Options"));
	menu_bar->Append(help_menu, wxT("Aide"));
	
	//Menu de fichiers
	file_menu->Append(MENU_NEW, wxT("Nouveau\tCtrl-N"));
	file_menu->AppendSeparator();
	file_menu->Append(MENU_OPEN, wxT("Ouvrir\tCtrl-O"));
	file_menu->Append(MENU_SAVE, wxT("Sauvegarder\tCtrl-S"));
	file_menu->AppendSeparator();
	file_menu->Append(MENU_QUIT, wxT("Quitter\tCtrl-X"));
	
	//Menu d'options
	options_menu->Append(MENU_THICKNESS, wxT("Epaisseur de trait"));
	options_menu->Append(MENU_COLOR, wxT("Couleur"));
	options_menu->Append(MENU_TRIANGLE_MANAGEMENT, wxT("Gestion des triangles"));
	options_menu->Enable(MENU_TRIANGLE_MANAGEMENT, true);

	//Menu d'aide
	help_menu->Append(MENU_VERSION, wxT("Version"));
	
	//Menu d'affichage
	display_menu->AppendCheckItem(MENU_TOOLBAR, wxT("Barre d'outils"));
	display_menu->Check(MENU_TOOLBAR,true);

	//Affichage
	m_MainFrame->SetMenuBar(menu_bar);
	m_MainFrame->CreateMyToolbar();
	m_MainFrame->Show(TRUE);
	
	
	return TRUE;
} 


