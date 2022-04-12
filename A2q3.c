//Use monte-carlo method to determine the volume of a Steinmetz solid
//Here we are taking the solid as an intersection of two cylinders oriented along the 
//x and z axis with radius 1 unit. 

#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <time.h>

double volume(int N, int seed, int a, int m);

int MLCG(int x, int a, int m)
{
	int xnew = (a * x) % m;
	return xnew;
}

void main()
{
	int n = 50000;
	//taking necessary inputs
	int a, m, seed;
	printf("Enter the value of a for the number generator :\n");
	scanf("%d", &a);
	printf("Enter the value of m for the number generator :\n");
	scanf("%d", &m);
	printf("Enter the seed for the number generator :\n");
	scanf("%d", &seed);

	double V = volume(n, seed, a, m);
	printf("\nThe final volume of Steinmetz solid using MonteCarlo method = \n%f", V);

}


double volume(int N, int seed, int a, int m)
{
	double r = 1.0;
	int hits = 0;
	double x, y, z;
	int temp = MLCG(seed, a, m);

	for (int i = 0; i < N; i++)
	{
		//generating coordinates
		temp = MLCG(seed, a, m);
		x = ((double)temp / m) * 2 - 1;
		seed = temp;
		temp = MLCG(seed, a, m);
		y = ((double)temp / m) * 2 - 1;
		seed = temp;
		temp = MLCG(seed, a, m);
		z = ((double)temp / m) * 2 - 1;
		seed = temp;
		double p = x * x + y * y;
		double q = y * y + z * z;
		if (p <= 1.0 && q <= 1.0)
			hits++;
	}

	double V = 8.0 * ((double)hits / (double)N); //Volume
		//returning calculated volume
	return V;
}
