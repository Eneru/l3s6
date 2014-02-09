
#ifndef __MAINFRAME_H__
#define __MAINFRAME_H__

#include "wx/wx.h"

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

class CMainFrame: public wxFrame {
public:
	CMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	void CreateMyToolbar(void);
private:

	wxToolBar *m_toolbar;
	DECLARE_EVENT_TABLE();


}; //MyFrame

#endif
