#include <stdio.h>
#include <stdlib.h>
#include <wx/wx.h>
#include <wx/accel.h>

#include "mainframe.h"



BEGIN_EVENT_TABLE(CMainFrame, wxFrame)
	EVT_MENU(MENU_NEW, CMainFrame::OnNew)
	EVT_MENU(MENU_OPEN, CMainFrame::OnOpen)
	EVT_MENU(MENU_SAVE, CMainFrame::OnSave)
	EVT_MENU(MENU_QUIT, CMainFrame::OnQuit)
	EVT_MENU(MENU_THICKNESS, CMainFrame::OnThickness)
	EVT_MENU(MENU_COLOR, CMainFrame::OnColor)
	EVT_MENU(MENU_TRIANGLE_MANAGEMENT, CMainFrame::OnTriangle)
	EVT_MENU(MENU_VERSION, CMainFrame::OnVersion)
	EVT_MENU(TOOLBAR_TOOLS, CMainFrame::OnToolBar)
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
	
}

void CMainFrame::OnColor(wxCommandEvent& event)
{
	
}

void CMainFrame::OnTriangle(wxCommandEvent& event)
{
	
}

void CMainFrame::OnVersion(wxCommandEvent& event)
{
	
}

void CMainFrame::OnToolBar(wxCommandEvent& event)
{
	
}





