#ifndef __DIALOGS_H__
#define __DIALOGS_H__

#include <iostream>
#include <fstream>
#include <wx/wx.h>
#include <wx/accel.h>
#include <wx/spinctrl.h>
#include <wx/slider.h>
#include <wx/filedlg.h>
#include "triangle.h"

enum
{
	ID_TEXT = 10000,
	SLIDER_EPAISSEUR,
	BOITE_COULEUR,
	LISTE_TRIANGLE,
	B_PROP,
	B_SUPPR,
	T_CONTROLE,
	S_CONTROLE,
	BOITE_COULEUR2
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
		void changeSlider(wxScrollEvent& event);
		
		//Attribut
		wxSlider * item2;
	private :
		DECLARE_EVENT_TABLE()
};

class ColorDialog: public wxDialog
{

	public :
		ColorDialog(wxWindow *parent, wxWindowID id,const wxString &title);
		void changeCouleur(wxCommandEvent& event);
		
		//Attribut
		wxRadioBox * item2;
	private :
		DECLARE_EVENT_TABLE()
};

class ManagementDialog: public wxDialog
{

	public :
		ManagementDialog(wxWindow *parent, wxWindowID id,const wxString &title);
		void OnProp(wxCommandEvent& event);
		void OnSuppr(wxCommandEvent& event);
		
		//Attribut
		wxListBox *list;
	private :
		DECLARE_EVENT_TABLE()
};

class PropDialog: public wxDialog
{

	public :
		PropDialog(wxWindow *parent, wxWindowID id,const wxString &title);
		
		//Attributs
		wxSpinCtrl *epaisseur;
		wxRadioBox *couleur;
		wxTextCtrl *id_triangle;
	private :
		DECLARE_EVENT_TABLE()
};

#endif /* __DIALOGS_H__ */
