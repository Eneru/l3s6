import org.omg.CORBA.*;

public class IcarreImpl extends _IcarreImplBase 
{
    public void carre (int source, org.omg.CORBA.IntHolder resultat) 
    {
		System.out.println( "carre : requete recue pour le nombre : " + source );
		resultat.value = source*source;
    }
}
