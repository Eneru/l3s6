#ifndef __DIALOGS_H__
#define __DIALOGS_H__

#include "wx/wx.h"

enum
{
	ID_TEXT = 10000
};

class VersionDialog: public wxDialog
{

	public :
		VersionDialog(wxWindow *parent, wxWindowID id,const wxString &title);
	private :
		DECLARE_EVENT_TABLE()
};

class EpaisseurDialog: public wxDialog
{

	public :
		EpaisseurDialog(wxWindow *parent, wxWindowID id,const wxString &title);
	private :
		DECLARE_EVENT_TABLE()
};

class ColorDialog: public wxDialog
{

	public :
		ColorDialog(wxWindow *parent, wxWindowID id,const wxString &title);
	private :
		DECLARE_EVENT_TABLE()
};

class ManagementDialog: public wxDialog
{

	public :
		ManagementDialog(wxWindow *parent, wxWindowID id,const wxString &title);
	private :
		DECLARE_EVENT_TABLE()
};

class PropDialog: public wxDialog
{

	public :
		PropDialog(wxWindow *parent, wxWindowID id,const wxString &title);
	private :
		DECLARE_EVENT_TABLE()
};

#endif /* __DIALOGS_H__ */
