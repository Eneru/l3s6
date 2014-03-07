import java.rmi.* ; 
import java.net.MalformedURLException ; 

public class Client {
    public static void main(String [] args) {
	if (args.length != 1) {
	    System.out.println("Usage : java Client <machine du Serveur:port du rmiregistry>");
	    System.exit(0);
	}
	try {
	    Message b =(Message) Naming.lookup( ??? );
	    System.out.println("Le client recoit : "+ ???); 
	}
	catch (NotBoundException re) { System.out.println(re) ; }
	catch (RemoteException re) { System.out.println(re) ; }
	catch (MalformedURLException e) { System.out.println(e) ; }
    }
}
