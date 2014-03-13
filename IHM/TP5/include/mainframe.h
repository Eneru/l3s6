#ifndef __MAINFRAME_H__
#define __MAINFRAME_H__

#include <wx/string.h>
#include <stdio.h>
#include <stdlib.h>
#include <wx/wx.h>
#include <wx/accel.h>
#include "dialogs.h"
#include "openglcanvas.h"
#include <wx/listctrl.h>
#include <wx/html/helpctrl.h>


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
		
		wxHtmlHelpController help;
		
		//Attributs
		float epaisseurtraitcourante;
		const wxColour * couleurcourante;
		bool is_drawing;
		unsigned int num_tri;
		Triangle tab_tri [5];
		wxString liste_nom_triangle [5];
		unsigned int num_triangle_courant;
		
		//Attributs from OpenGL
		OpenGLCanvas * oglc;
		
		void detogglisation();
		void desauvegardisation();
		void sauvegardisation();
		
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
		void OnHelp(wxCommandEvent& event);
		
		//Toolbar
		wxToolBar *m_toolbar;
}; //MyFrame
#endif
