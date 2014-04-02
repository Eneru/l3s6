import java.rmi.server.UnicastRemoteObject ;
import java.rmi.RemoteException ;

public class OpMatriceImpl extends UnicastRemoteObject implements OpMatrice
{    
    public OpMatriceImpl () throws RemoteException {super();};
    public int[][] multiplicationMatrice (int [][]a, int [][]b)throws RemoteException 
    { 
		int [][] res = new int [a.length][a[0].length];
		
		for(int i = 0 ; i<a.length ; i++)
			for(int j = 0 ; j<a.length ; j++)
			{
				res[i][j] = 0;
				for(int k = 0 ; k<a.length ; k++)
					res[i][j]+= (a[i][k]*b[k][j]);
			}
		return res;
    }
    
    public void AffichageMatrice (int [][] a)throws RemoteException
    {
		System.out.print("Reponse :");
		for(int i = 0 ; i<a.length ; i++)
		{
			System.out.println(" ");
			for(int j = 0 ; j<a.length ; j++)
				System.out.print(a[i][j]+" ");
			System.out.println(" ");
		}
		System.out.println(" ");
	}
}
