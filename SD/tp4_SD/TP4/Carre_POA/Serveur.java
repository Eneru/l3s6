import org.omg.CORBA.*;
import org.omg.PortableServer.*;

public class Serveur {

    public static void main(String[] args) 
    {
		//init ORB
        ORB orb = ORB.init( args, null );
        IcarreImpl myobj = new IcarreImpl();
		
		try
		{
			POA poa = POAHelper.narrow(orb.resolve_initial_references( "RootPOA" ));
			poa.the_POAManager().activate();
			org.omg.CORBA.Object poaobj = poa.servant_to_reference( myobj );
			String ior = orb.object_to_string( poaobj );
			System.out.println( ior );
		}
        catch(Exception e)
        {
			System.out.println("Erreur " + e.toString());
			e.printStackTrace();
        }
		orb.run();
	}
}
