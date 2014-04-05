import java.awt.*; 
import java.rmi.*; 
import java.applet.Applet;
import java.awt.event.*;
import java.net.InetAddress.* ;
import java.net.* ;

public class Lister extends Applet
{
    Annuaire annuaire;
    java.awt.List list = new List(3);

    public void init()
    {
		try {
			String hostname = super.getParameter("serveur");
			annuaire = (Annuaire)Naming.lookup("rmi://"+hostname+"/LAnnuaire");
			list = annuaire.affiche();
			//add list
			add(list);
		} catch (Exception e) {
			System.err.println(e);
			e.printStackTrace();
		}
    }
}
