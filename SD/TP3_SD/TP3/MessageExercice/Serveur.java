import java.net.* ;
import java.rmi.* ;

public class Serveur {
   public static void main(String [] args) {
	if (args.length != 1) {
	    System.out.println("Usage : java Serveur <port du rmiregistry>");
	    System.exit(0);
	}
       try {
	   MessageImpl objLocal = new MessageImpl ();
	   Naming.rebind( args[0] ,objLocal) ;
	   System.out.println("Serveur pret"); 
       }
       catch (RemoteException re) { System.out.println(re) ; }
       catch (MalformedURLException e) { System.out.println(e) ; }
  }
}

//Message hérite de Remote, utilise RemoteException
//MessageImpl_Stub hérite de java.rmi.server.RemoteStub, implémente Message et java.rmi.Remote et utilise java.lang.reflect.Method
//MessageImpl hérite de UnicastRemoteObject, implémente Message
//Client utilise Message
//Serveur utilise MessageImpl
