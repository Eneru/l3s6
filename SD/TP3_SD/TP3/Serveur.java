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
	   Registry Naming = LocateRegistry.createRegistry(Integer.parseInt(args[0]));
	   MessageImpl objLocal = new MessageImpl();
	   Naming.rebind("MessageRMI",objLocal) ;
	   System.out.println("Serveur pret"); 
       }
       catch (RemoteException re) { System.out.println(re) ; }
       //catch (MalformedURLException e) { System.out.println(e) ; }
  }
}
