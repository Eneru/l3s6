#include <wx/wx.h>
#include <wx/accel.h>

#include "dialogs.h"

BEGIN_EVENT_TABLE(VersionDialog, wxDialog)
END_EVENT_TABLE ()

VersionDialog::VersionDialog( wxWindow *parent, wxWindowID id, const wxString &title) : wxDialog( parent, id, title)
{
	wxBoxSizer *item0 = new wxBoxSizer( wxVERTICAL );
	wxStaticText *item1 = new wxStaticText( this, ID_TEXT, wxT("Version 1.0"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	wxButton *item2 = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition);
	
	item0->Add( item1, 0, wxALIGN_CENTRE|wxALL, 5 );
	item0->Add( item2, 0, wxALIGN_CENTRE|wxALL, 5 );
	
	this->SetAutoLayout( TRUE );
	this->SetSizer( item0 );
	item0->Fit( this );
	item0->SetSizeHints( this );
}

//~ BEGIN_EVENT_TABLE(EpaisseurDialog, wxDialog)
//~ END_EVENT_TABLE ()
//~ 
//~ EpaisseurDialog::EpaisseurDialog( wxWindow *parent, wxWindowID id, const wxString &title) : wxDialog( parent, id, title)
//~ {
	//~ wxBoxSizer *item0 = new wxBoxSizer( wxVERTICAL );
	//~ wxStaticText *item1 = new wxStaticText( this, ID_TEXT, wxT("Choisir la nouvelle epaisseur de trait"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	//~ wxSlider *item2 = new wxSlider(this, wxID_ANY, 1, 1, 10, wxPoint(-1,-1), wxSL_LABELS | wxSL_HORIZONTAL | wxSL_LEFT, wxDefaultValidator, wxT("slider"));
	//~ wxButton *item3 = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition);
	//~ 
	//~ item0->Add( item1, 0, wxALIGN_CENTRE|wxALL, 5 );
	//~ item0->Add( item2, 0, wxALIGN_CENTRE|wxALL, 5 );
	//~ item0->Add( item3, 0, wxALIGN_CENTRE|wxALL, 5 );
	//~ 
	//~ this->SetAutoLayout( TRUE );
	//~ this->SetSizer( item0 );
	//~ item0->Fit( this );
	//~ item0->SetSizeHints( this );
//~ }

BEGIN_EVENT_TABLE(ColorDialog, wxDialog)
END_EVENT_TABLE ()

ColorDialog::ColorDialog( wxWindow *parent, wxWindowID id, const wxString &title) : wxDialog( parent, id, title)
{
	//RadioBox choices
	wxString strs8[] = { wxT("Rouge"), wxT("Vert"), wxT("Bleu")};
	
	wxBoxSizer *item0 = new wxBoxSizer( wxVERTICAL );
	wxStaticText *item1 = new wxStaticText( this, ID_TEXT, wxT("Choisir la nouvelle couleur"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	wxRadioBox *item2 = new wxRadioBox( this, wxID_ANY, wxT("Couleur"), wxPoint(-1, -1), wxSize(-1, -1), 3, strs8, 0, wxRA_SPECIFY_ROWS, wxDefaultValidator, wxT("radioBox"));
	wxButton *item3 = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition);
	
	item0->Add( item1, 0, wxALIGN_CENTRE|wxALL, 5 );
	item0->Add( item2, 0, wxALIGN_CENTRE|wxALL, 5 );
	item0->Add( item3, 0, wxALIGN_CENTRE|wxALL, 5 );
	
	this->SetAutoLayout( TRUE );
	this->SetSizer( item0 );
	item0->Fit( this );
	item0->SetSizeHints( this );
}

BEGIN_EVENT_TABLE(ManagementDialog, wxDialog)
END_EVENT_TABLE ()

ManagementDialog::ManagementDialog( wxWindow *parent, wxWindowID id, const wxString &title) : wxDialog( parent, id, title)
{
	//List choices
	wxString strs8[] = { wxT("triangle 0"), wxT("triangle 1"), wxT("triangle 2")};
	
	wxBoxSizer *main = new wxBoxSizer( wxVERTICAL );
	wxBoxSizer *partie_basse = new wxBoxSizer( wxHORIZONTAL );
	wxBoxSizer *boutton = new wxBoxSizer( wxVERTICAL );
	
	//Texte
	wxStaticText *texte = new wxStaticText( this, ID_TEXT, wxT("Liste des triangles"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
	
	//Liste
	wxListBox *list = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), 3, strs8, wxLB_SORT, wxDefaultValidator, wxT("listBox"));
	
	//Bouttons
	wxButton *prop = new wxButton( this, wxID_ANY, wxT("Proprietes"), wxDefaultPosition);
	wxButton *del = new wxButton( this, wxID_ANY, wxT("Supprimer"), wxDefaultPosition);
	wxButton *okay = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition);
	boutton->Add( prop, 0, wxALIGN_CENTRE|wxALL, 5 );
	boutton->Add( del, 0, wxALIGN_CENTRE|wxALL, 5 );
	boutton->Add( okay, 0, wxALIGN_CENTRE|wxALL, 5 );
	
	//Liste + bouttons
	partie_basse->Add( prop, 0, wxALIGN_CENTRE|wxALL, 5 );
	partie_basse->Add( boutton, 0, wxALIGN_CENTRE|wxALL, 5 );
	
	//Partie basse + haute
	main->Add( texte, 0, wxALIGN_CENTRE|wxALL, 5 );
	main->Add( partie_basse, 0, wxALIGN_CENTRE|wxALL, 5 );
	this->SetAutoLayout( TRUE );
	this->SetSizer( main );
	main->Fit( this );
	main->SetSizeHints( this );
}
	
