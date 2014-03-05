#ifndef __MAINFRAME_H__
#define __MAINFRAME_H__

#include <wx/string.h>
#include <stdio.h>
#include <stdlib.h>
#include <wx/wx.h>
#include <wx/accel.h>
#include "dialogs.h"
#include <wx/listctrl.h>

enum
{
	MENU_NEW,
	MENU_OPEN,
	MENU_SAVE,
	MENU_QUIT,
	MENU_THICKNESS,
	MENU_COLOR,
	MENU_TRIANGLE_MANAGEMENT,
	MENU_TOOLBAR,
	MENU_VERSION,
	TOOLBAR_TOOLS,
	TOOLBAR_DRAW
};

class CMainFrame: public wxFrame 
{
	public:
		CMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
		void CreateMyToolbar(void);
		
		//Attributs de base du main
		wxMenuBar *menu_bar;
		wxMenu *file_menu;
		wxMenu *display_menu;
		wxMenu *options_menu;
		wxMenu *help_menu;
		
		//Attributs
		unsigned int epaisseurtraitcourante;
		const wxColour * couleurcourante;
		bool is_drawing;
		unsigned int num_tri;
		Triangle * tab_tri [5];
		wxString liste_nom_triangle [5];
		unsigned int num_triangle_courant;
		
	private:		
		DECLARE_EVENT_TABLE();
		
		void OnNew(wxCommandEvent& event);
		void OnOpen(wxCommandEvent& event);
		void OnSave(wxCommandEvent& event);
		void OnQuit(wxCommandEvent& event);
		void OnThickness(wxCommandEvent& event);
		void OnColor(wxCommandEvent& event);
		void OnTriangle(wxCommandEvent& event);
		void OnVersion(wxCommandEvent& event);
		void OnToolBar(wxCommandEvent& event);
		void OnDraw(wxCommandEvent& event);
		
		//Attributs
		wxToolBar *m_toolbar;
}; //MyFrame
#endif
