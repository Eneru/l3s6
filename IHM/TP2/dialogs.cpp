#include "dialogs.h"
#include "mainframe.h"

BEGIN_EVENT_TABLE(VersionDialog, wxDialog)
END_EVENT_TABLE ()

VersionDialog::VersionDialog( wxWindow *parent, wxWindowID id, const wxString &title) : wxDialog( parent, id, title)
{
	//Initialisation
	wxBoxSizer *item0 = new wxBoxSizer( wxVERTICAL );
	wxStaticText *item1 = new wxStaticText( this, ID_TEXT, wxT("Version 1.0"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	wxButton *item2 = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition);
	
	//Ajout texte + boutton
	item0->Add( item1, 0, wxALIGN_CENTRE|wxALL, 5 );
	item0->Add( item2, 0, wxALIGN_CENTRE|wxALL, 5 );
	
	//Affichage
	this->SetAutoLayout( TRUE );
	this->SetSizer( item0 );
	item0->Fit( this );
	item0->SetSizeHints( this );
}

BEGIN_EVENT_TABLE(EpaisseurDialog, wxDialog)
	EVT_COMMAND_SCROLL(SLIDER_EPAISSEUR, changeSlider)
END_EVENT_TABLE ()

EpaisseurDialog::EpaisseurDialog( wxWindow *parent, wxWindowID id, const wxString &title) : wxDialog( parent, id, title)
{
	wxBoxSizer *item0 = new wxBoxSizer( wxVERTICAL );
	wxStaticText *item1 = new wxStaticText( this, ID_TEXT, wxT("Choisir la nouvelle epaisseur de trait"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	wxSlider *item2 = new wxSlider(this, SLIDER_EPAISSEUR, 1, 1, 10, wxPoint(-1,-1), wxSize(125, 50), wxSL_LABELS | wxSL_HORIZONTAL, wxDefaultValidator, wxT("slider"));
	wxButton *item3 = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition);
	
	item0->Add( item1, 0, wxALIGN_CENTRE|wxALL, 5 );
	item0->Add( item2, 0, wxALIGN_CENTRE|wxALL, 5 );
	item0->Add( item3, 0, wxALIGN_CENTRE|wxALL, 5 );
	
	this->SetAutoLayout( TRUE );
	this->SetSizer( item0 );
	item0->Fit( this );
	item0->SetSizeHints( this );
}

void EpaisseurDialog::changeSlider(wxCommandEvent& event)
{
	
}

BEGIN_EVENT_TABLE(ColorDialog, wxDialog)
END_EVENT_TABLE ()

ColorDialog::ColorDialog( wxWindow *parent, wxWindowID id, const wxString &title) : wxDialog( parent, id, title)
{
	//RadioBox choices
	wxString strs8[] = { wxT("Rouge"), wxT("Vert"), wxT("Bleu")};
	
	//Initialisation
	wxBoxSizer *item0 = new wxBoxSizer( wxVERTICAL );
	wxStaticText *item1 = new wxStaticText( this, ID_TEXT, wxT("Choisir la nouvelle couleur"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	wxRadioBox *item2 = new wxRadioBox( this, BOITE_COULEUR, wxT("Couleur"), wxPoint(-1, -1), wxSize(-1, -1), 3, strs8, 0, wxRA_SPECIFY_ROWS, wxDefaultValidator, wxT("radioBox"));
	wxButton *item3 = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition);
	
	//Ajout texte+radiobox+boutton
	item0->Add( item1, 0, wxALIGN_CENTRE|wxALL, 5 );
	item0->Add( item2, 0, wxALIGN_CENTRE|wxALL, 5 );
	item0->Add( item3, 0, wxALIGN_CENTRE|wxALL, 5 );
	
	//Affichage
	this->SetAutoLayout( TRUE );
	this->SetSizer( item0 );
	item0->Fit( this );
	item0->SetSizeHints( this );
}

BEGIN_EVENT_TABLE(ManagementDialog, wxDialog)
	EVT_BUTTON(B_PROP, ManagementDialog::OnProp)
	EVT_BUTTON(B_SUPPR, ManagementDialog::OnSuppr)
END_EVENT_TABLE ()

ManagementDialog::ManagementDialog( wxWindow *parent, wxWindowID id, const wxString &title) : wxDialog( parent, id, title)
{
	//List choices
	wxString strs8[] = { wxT("triangle 0"), wxT("triangle 1"), wxT("triangle 2")};
	
	//Boites
	wxBoxSizer *main = new wxBoxSizer( wxHORIZONTAL );
	wxBoxSizer *gtriangle = new wxBoxSizer( wxVERTICAL );
	wxBoxSizer *boutton = new wxBoxSizer( wxVERTICAL );
	
	//Texte
	wxStaticText *texte = new wxStaticText( this, ID_TEXT, wxT("Liste des triangles"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
	
	//Liste
	list = new wxListBox( this, LISTE_TRIANGLE, wxDefaultPosition, wxSize(-1,-1), 3, strs8, wxLB_SORT, wxDefaultValidator, wxT("listBox"));
	
	//Bouttons
	wxButton *prop = new wxButton( this, B_PROP, wxT("Proprietes"), wxDefaultPosition);
	wxButton *del = new wxButton( this, B_SUPPR, wxT("Supprimer"), wxDefaultPosition);
	wxButton *okay = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition);
	boutton->Add( prop, 0, wxALIGN_CENTRE|wxALL, 5 );
	boutton->Add( del, 0, wxALIGN_CENTRE|wxALL, 5 );
	boutton->Add( okay, 0, wxALIGN_CENTRE|wxALL, 5 );
	
	//Liste + nom liste
	gtriangle->Add( texte, 0, wxALIGN_CENTRE|wxALL, 5 );
	gtriangle->Add( list, 0, wxALIGN_CENTRE|wxALL, 5 );
	
	//Partie basse + haute
	main->Add( gtriangle, 0, wxALIGN_CENTRE|wxALL, 5 );
	main->Add( boutton, 0, wxALIGN_CENTRE|wxALL, 5 );
	
	//Affichage
	this->SetAutoLayout( TRUE );
	this->SetSizer( main );
	main->Fit( this );
	main->SetSizeHints( this );
}

void ManagementDialog::OnProp(wxCommandEvent& event)
{
	PropDialog pdlg(this, -1, wxT("Proprietes"));		
	pdlg.ShowModal();
}

void ManagementDialog::OnSuppr(wxCommandEvent& event)
{
	
}

BEGIN_EVENT_TABLE(PropDialog, wxDialog)
END_EVENT_TABLE ()

PropDialog::PropDialog( wxWindow *parent, wxWindowID id, const wxString &title) : wxDialog( parent, id, title)
{
	//RadioBox choices
	wxString strs8[] = { wxT("Rouge"), wxT("Vert"), wxT("Bleu")};
	
	//Textes
	wxStaticText *id_texte = new wxStaticText( this, ID_TEXT, wxT("Identifiant du triangle"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	wxStaticText *epaisseur_texte = new wxStaticText( this, ID_TEXT, wxT("Epaisseur trait"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	
	//Boites
	wxBoxSizer *main = new wxBoxSizer( wxVERTICAL );
	wxBoxSizer *prop = new wxBoxSizer( wxVERTICAL );
	wxBoxSizer *prop_color = new wxBoxSizer( wxHORIZONTAL );
	
	//Prop
	wxTextCtrl *id_triangle = new wxTextCtrl( this, T_CONTROLE, wxT(""), wxPoint(-1, -1), wxSize(-1, -1), wxTE_PROCESS_TAB | wxTE_LEFT, wxDefaultValidator, wxT("textctrl"));
	epaisseur = new wxSpinCtrl( this, S_CONTROLE, wxT("Epaisseur trait"), wxPoint(-1, -1), wxSize(-1, -1), wxSP_ARROW_KEYS | wxSP_WRAP, 0, 100, 2, wxT("spinctrl"));
	prop->Add( id_texte, 0, wxALIGN_CENTRE|wxALL, 2 );
	prop->Add( id_triangle, 0, wxALIGN_CENTRE|wxALL, 2 );
	prop->Add( epaisseur_texte, 0, wxALIGN_CENTRE|wxALL, 2 );
	prop->Add( epaisseur, 0, wxALIGN_CENTRE|wxALL, 2 );
	
	//Prop + Couleur
	couleur = new wxRadioBox( this, BOITE_COULEUR2, wxT("Couleur"), wxPoint(-1, -1), wxSize(-1, -1), 3, strs8, 0, wxRA_SPECIFY_ROWS, wxDefaultValidator, wxT("radioBox"));
	prop_color->Add( prop, 0, wxALIGN_CENTRE|wxALL, 5 );
	prop_color->Add( couleur, 0, wxALIGN_CENTRE|wxALL, 5 );
	
	//Prop_color + ok
	wxButton *okay = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition);
	main->Add( prop_color, 0, wxALIGN_CENTRE|wxALL, 6 );
	main->Add( okay, 0, wxALIGN_CENTRE|wxALL, 6 );
	
	//Affichage
	this->SetAutoLayout( TRUE );
	this->SetSizer( main );
	main->Fit( this );
	main->SetSizeHints( this );
}
