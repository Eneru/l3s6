import java.rmi.*; 
import java.util.*; 
import java.rmi.server.UnicastRemoteObject;

public class Supprime
{	
    public static void main(String[] args) 
    {
		Annuaire annuaire;
		
		if (args.length != 1)
		{
			System.err.println("Usage : java Supprime <nom d'une personne>\n");
			System.exit(64);
		}
		
		String nom = args[0];
		
		if (nom.length() > 10)
		{
			System.err.println("Prenom pour l'annuaire superieur a 10 caracteres\n");
			System.exit(1);
		}
		
		
		try {
			annuaire = (Annuaire)Naming.lookup("rmi://localhost:2002/LAnnuaire");
			annuaire.supprime(nom);
		} catch (Exception e) {
			System.err.println(e);
			e.printStackTrace();
		}
    }
}
