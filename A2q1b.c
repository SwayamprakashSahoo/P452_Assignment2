

#include<stdio.h>
#include<math.h>
#include<conio.h>
#define max 20

void gaussEliminationLS(int m, int n, double a[max][max], double x[max])
{
    int i, j, k;
    for (i = 0; i < m - 1; i++)
    {
        //Partial Pivoting
        for (k = i + 1; k < m; k++)
        {
            //If diagonal element(absolute value) is smaller than any of the terms below it
            if (fabs(a[i][i]) < fabs(a[k][i]))
            {
                //Swap the rows
                for (j = 0; j < n; j++)
                {
                    double temp;
                    temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
        //Begin Gauss Elimination
        for (k = i + 1; k < m; k++)
        {
            double  term = a[k][i] / a[i][i];
            for (j = 0; j < n; j++)
            {
                a[k][j] = a[k][j] - term * a[i][j];
            }
        }

    }
    //Begin Back-substitution
    for (i = m - 1; i >= 0; i--)
    {
        x[i] = a[i][n - 1];
        for (j = i + 1; j < n - 1; j++)
        {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }

}


void printMatrix(int m, int n, double matrix[max][max])
{
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%lf\t", matrix[i][j]);
        }
        printf("\n");
    }
}
main()
{
    //no. of data-points
    int N;
    //degree of polynomial
    int n;
    printf("Enter the no. of data-points:\n");
    scanf("%d", &N);
    //arrays to store the c and y-axis data-points
    double x[max], y[max];
    printf("Enter the x-axis values:\n");
    int i, j;
    for (i = 0; i < N; i++)
    {
        scanf("%lf", &x[i]);
    }
    printf("Enter the y-axis values:\n");
    for (i = 0; i < N; i++)
    {
        scanf("%lf", &y[i]);
    }
    printf("Enter the degree of polynomial to be used:\n");
    scanf("%d", &n);
    // an array of size 2*n+1 for storing N, Sig xi, Sig xi^2, ...., etc. which are the independent components of the normal matrix
    double X[max];
    for (i = 0; i <= 2 * n; i++)
    {
        X[i] = 0;
        for (j = 0; j < N; j++)
        {
            X[i] = X[i] + pow(x[j], i);
        }
    }
    //the normal augmented matrix
    double B[max][max];
    // rhs
    double Y[max];
    for (i = 0; i <= n; i++)
    {
        Y[i] = 0;
        //implementing Chebyshev functions
        for (j = 0; j < N; j++)
        {
            if (i == 0)
                Y[i] = Y[i] + y[j];
            else if (i == 1)
                Y[i] = Y[i] + y[j] * (2 * x[j] - 1);
            else if (i == 2)
                Y[i] = Y[i] + y[j] * (8 * x[j] * x[j] - 8 * x[j] + 1);
            else if (i == 3)
                Y[i] = Y[i] + y[j] * (32 * pow(x[j], 3) - 48 * x[j] * x[j] + 18 * x[j] - 1);
        }
    }
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            B[i][j] = X[i + j];
        }
    }
    for (i = 0; i <= n; i++)
    {
        B[i][n + 1] = Y[i];
    }
    double A[max];
    printf("The polynomial fit using Chebyshev functions is given by the equation:\n");
    printMatrix(n + 1, n + 2, B);
    gaussEliminationLS(n + 1, n + 2, B, A);
    for (i = 0; i <= n; i++)
    {
        printf("%lfx^%d+", A[i], i);
    }
}