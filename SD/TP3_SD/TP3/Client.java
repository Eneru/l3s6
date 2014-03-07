import java.rmi.* ;
import java.rmi.registry.* ; 
import java.rmi.registry.LocateRegistry;
import java.net.MalformedURLException ; 
import java.lang.Integer;

public class Client {
    public static void main(String [] args) {
	if (args.length != 1) {
	    System.out.println("Usage : java Client <machine du Serveur:port du rmiregistry>");
	    System.exit(0);
	}
	try {
	    Registry Naming = LocateRegistry.getRegistry(Integer.parseInt(args[0]));
	    Message b =(Message) Naming.lookup("MessageRMI");
	    System.out.println("Le client recoit : "+ b.messageDistant()); 
	}
	catch (NotBoundException re) { System.out.println(re) ; }
	catch (RemoteException re) { System.out.println(re) ; }
	//catch (MalformedURLException e) { System.out.println(e) ; }
    }
}
