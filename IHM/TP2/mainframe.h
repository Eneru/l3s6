
#ifndef __MAINFRAME_H__
#define __MAINFRAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <wx/wx.h>
#include <wx/accel.h>
#include "dialogs.h"

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
	TOOLBAR_DRAW,
};

class CMainFrame: public wxFrame 
{
	public:
		CMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
		void CreateMyToolbar(void);
		
		unsigned int epaisseurtraitcourante;
		wxColour * couleurcourante;
		bool is_drawing;
		
	private:
		wxToolBar *m_toolbar;
		
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
}; //MyFrame

#endif
