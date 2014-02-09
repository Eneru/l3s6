#ifndef __DIALOGS_H__
#define __DIALOGS_H__

#include "wx/wx.h"

enum
{
	ID_TEXT = 10000
}

class VersionDialog: public wxDialog

{

	public :
		VersionDialog(wxWindow *parent, wxWindowID id,const wxString &title);

	private :
		DECLARE_EVENT_TABLE()

};

#endif /* __DIALOGS_H__ */
