class TriParallele extends Thread 	
{
	int[] t;
	int m,n;
	
	TriParallele(int[] t, int m, int n)
	{
		this.t=t;
		this.m = m;
		this.n = n;
	}
	
	static void echangerElements(int[] t, int m, int n) 
	{
		int tmp = t[m];
		t[m] = t[n];
		t[n] = tmp;
	}
    
    static int partition(int[] t, int m, int n)
    {
		int v = t[m];                 // valeur pivot
		int i = m-1;
		int j = n+1;                  // indice final du pivot
		
		while (true) 
		{
			do 
			{
				j--;
			} while (t[j] > v);
			
			do 
			{
				i++;
			} while (t[i] < v);
			
			if (i<j)
				echangerElements(t, i, j);
			else
				return j;
		}
	}
    
	static void triRapide(int[] t, int m, int n) 
	{
		if (m<n) 
		{
			int p = partition(t, m, n);
			triRapide(t, m, p);
			triRapide(t, p+1, n);
		}
	}
	
    public void run()
    {
		Thread r1,r2;
		if (((this.m+this.n)/2 - this.m )>2 )
			r1 = new TriParallele(this.t, this.m,(this.m+this.n)/2);
		if (((this.n-(this.m+this.n)/2)+1) > 2 )
			r2 = new TriParallele(this.t, ((this.m+this.n)/2+1), this.n);

		triRapide(t,m,n);
	}
}

public class Tri
{
    public static void main(String args[]) 
    {
		int entree[] = {2,1, 4, 6, 7, 8, 14, 17, 20, 15 , 12 , 13};
		Thread r1= new TriParallele(entree, 0, entree.length-1);
		
		r1.start();
		try
		{
			r1.join();
		}
		catch(Exception e){ }

		for (int i=0; i<entree.length; i++) 
			System.out.print (entree[i] + " ");
		System.out.println(" ");
    }


}
