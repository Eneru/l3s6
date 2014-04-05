import java.net.* ;
import java.rmi.* ;
import java.rmi.registry.LocateRegistry;

public class Serveur {
   public static void main(String [] args) {
       try {
		   LocateRegistry.createRegistry(2002);
		   MessageImpl objLocal = new MessageImpl ();
		   Naming.rebind("rmi://localhost:2002/Message",objLocal) ;
		   System.out.println("Serveur pret"); 
       }
       catch (RemoteException re) { System.out.println(re) ; }
       catch (MalformedURLException e) { System.out.println(e) ; }
  }
}

//Exercice 3 question 2 : car le CLASSPATH du RMIREGISTRY n'est pas le bon.
