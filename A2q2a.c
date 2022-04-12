//value of pi by throwing points
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int MLCG(int x, int a, int m)
{
	int xnew = (a * x) % m;
	return xnew;
}

void main()
{
	int n = 10000;
	//taking necessary inputs
	int a, m, x;
	printf("Enter the value of a for the number generator :\n");
	scanf("%d", &a);
	printf("Enter the value of m for the number generator :\n");
	scanf("%d", &m);
	printf("Enter the seed for the number generator :\n");
	scanf("%d", &x);
	
	double rx, ry;
	int sq = 0, circ = 0;
	int temp = MLCG(x, a, m);
	for (int i = 0; i < (n * n); i++)
	{
		temp = MLCG(x, a, m);
		rx = ((double)temp / m) * 2 - 1;
		x = temp;
		temp = MLCG(x, a, m);
		ry = ((double)temp / m) * 2 - 1;
		x = temp;

		double dist = rx * rx + ry * ry;
		if (dist <= 1.0)
			circ++;
		sq++;
	}
	double pi = (double)(4 * circ) / sq;
	printf("\nThe final value of pi using MonteCarlo method = \n%f", pi);
}