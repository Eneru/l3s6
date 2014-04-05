import java.net.* ;
import java.rmi.* ;
import java.rmi.registry.* ; 
import java.rmi.registry.LocateRegistry;
import java.lang.Integer;

public class Serveur {
   public static void main(String [] args) {
	if (args.length != 1) {
	    System.out.println("Usage : java Serveur <port du rmiregistry>");
	    System.exit(0);
	}
       try {
		   LocateRegistry.createRegistry(Integer.parseInt(args[0]));
		   OpMatriceImpl objLocal = new OpMatriceImpl ();
		   Naming.rebind("rmi://localhost:"+args[0]+"/Matrice",objLocal) ;
		   System.out.println("Serveur pret");
       }
       catch (Exception re) { System.out.println(re) ; }
  }
}
