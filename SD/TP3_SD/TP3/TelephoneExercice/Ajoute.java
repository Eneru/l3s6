import java.rmi.*; 
import java.util.*; 
import java.rmi.server.UnicastRemoteObject;

public class Ajoute
{	
    public static void main(String[] args) 
    {
		Annuaire annuaire;
		
		if (args.length != 2)
		{
			System.err.println("Usage : java Ajoute <nom d'une personne> <No Telephone>\n");
			System.exit(64);
		}
		
		String nom = args[0];
		String num = args[1];
		
		if (nom.length() > 10)
		{
			System.err.println("Prenom pour l'annuaire superieur a 10 caracteres\n");
			System.exit(1);
		}
		
		if (num.length() > 14)
		{
			System.err.println("Rappel un numero s'ecrit avec 10 chiffres separes par un espace tous les deux chiffres\n");
			System.exit(1);
		}
		
		
		try {
			annuaire = (Annuaire)Naming.lookup("rmi://localhost:2002/LAnnuaire");
			annuaire.ajout(nom,num);
		} catch (Exception e) {
			System.err.println(e);
			e.printStackTrace();
		}
    }
}
