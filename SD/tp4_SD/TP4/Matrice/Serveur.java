import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.FileNotFoundException;
import org.omg.CORBA.*;
import org.omg.PortableServer.*;

public class Serveur
{
    public static void main(String[] args)
    {
            ORB orb = ORB.init( args, null);
            OpMatriceImpl myobj= new OpMatriceImpl();
            try
            {
                POA poa = POAHelper.narrow(orb.resolve_initial_references( "RootPOA" ));
                poa.the_POAManager().activate();
                org.omg.CORBA.Object poaobj = poa.servant_to_reference( myobj );
                
                String ior = orb.object_to_string( poaobj );
                FileOutputStream file = new FileOutputStream(iorfile.value);
				PrintWriter out = new PrintWriter(file);
				out.println(ior);
				out.flush();
				file.close();
            }
            catch(Exception e)
            {
                System.err.println("Erreur " + e.toString());
            }
            orb.run();
    }
}
