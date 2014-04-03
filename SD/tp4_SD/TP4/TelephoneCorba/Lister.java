import org.omg.CORBA.*;
import java.io.*;

public class Lister 
{
    public static void main(String [] args) 
    {
        if (args.length != 0) 
            System.out.println("Usage : java Lister");
        else 
        {
            try
            {
                ORB orb = ORB.init(args , null);
                FileReader file= new FileReader(iorfile.value);
                BufferedReader in= new BufferedReader(file);
                String ior = in.readLine();
                file.close();
                
                org.omg.CORBA.Object obj = orb.string_to_object(ior);
                Annuaire annuaire = AnnuaireHelper.narrow(obj);
                org.omg.CORBA.StringHolder str = new org.omg.CORBA.StringHolder();
                annuaire.listerNoms( str );
                System.out.println(str.value);
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
        }
    }
}
