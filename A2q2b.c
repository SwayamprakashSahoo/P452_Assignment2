//solution of pi by using integral
//value of pi by throwing points
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int MLCG(int x, int a, int m)
{
	int xnew = (a * x) % m;
	return xnew;
}

double monteCarlo(int n, int x, int a, int m)
{
	double sum = 0;
	double temp, random;
	for (int i = 0; i < n; i++)
	{
		temp = MLCG(x, a, m);
		random = ((double)temp / m);
		x = temp;
		double res = 4 * sqrt(1 - random * random);
		sum += res;
	}
	double avg = sum / n;
	return avg;
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
	double pi = monteCarlo(n, x, a, m);
	printf("\nThe final value of pi using MonteCarlo method to solve an integral = \n%f", pi);
}