import org.omg.CORBA.*;
import java.io.*;
import org.omg.PortableServer.*;

public class Serveur
{
    public static void main(String[] args)
    {
        ORB orb = ORB.init( args, null);
        try
        {
            AnnuaireImpl annuaire = new AnnuaireImpl();
            POA poa = POAHelper.narrow(orb.resolve_initial_references( "RootPOA" ));
            poa.the_POAManager().activate();
            org.omg.CORBA.Object poaobj = poa.servant_to_reference( annuaire );
            String ior = orb.object_to_string( poaobj );

            FileOutputStream file = new FileOutputStream( iorfile.value );
            PrintWriter out = new PrintWriter(file);
            out.println( ior );
            out.flush();
            file.close();
        }
        
        catch(org.omg.CORBA.SystemException ex)
        {
            System.err.println( "Error" );
            ex.printStackTrace();
        }
        catch(FileNotFoundException fnfe)
        {
            System.err.println(fnfe.getMessage());
        }
        catch(IOException io)
        {
            System.err.println(io.getMessage());
        }
        catch(Exception e)
        {
            System.err.println(e.getMessage());
        }
        orb.run();
    }
}
