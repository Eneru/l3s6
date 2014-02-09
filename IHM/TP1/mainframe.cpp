#include <stdio.h>
#include <stdlib.h>
#include <wx/wx.h>
#include <wx/accel.h>

#include "mainframe.h"



BEGIN_EVENT_TABLE(CMainFrame, wxFrame)
END_EVENT_TABLE()



CMainFrame::CMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame((wxFrame *)NULL, -1, title, pos, size) 
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
