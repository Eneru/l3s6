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
		int[][] a = { {1, 0, 0}, {0, 2, 0}, {0, 0, 3} };
		int[][] b = { {1, 2, 3}, {1, 2, 3}, {1, 2, 3} };
		
		int[][] res;
		
	    OpMatrice op =(OpMatrice) Naming.lookup("rmi://"+args[0]+"/Matrice");
	    res = op.multiplicationMatrice(a,b);
	    op.AffichageMatrice(res);
	}
	catch (NotBoundException re) { System.out.println(re) ; }
	catch (RemoteException re) { System.out.println(re) ; }
	catch (MalformedURLException e) { System.out.println(e) ; }
    }
}
