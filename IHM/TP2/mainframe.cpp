#include "mainframe.h"
#include "dialogs.h"


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
END_EVENT_TABLE()



CMainFrame::CMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame((wxFrame *)NULL, -1, title, pos, size) 
{
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





