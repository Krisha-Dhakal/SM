#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define SEED 35791246

int main()
{
   int n=0;
   double x,y;
   int i,count=0; /* # of points in the 1st quadrant of unit circle */
   double z;
   double pi;

   printf("Enter the number of iterations used to estimate pi: ");
   scanf("%d",&n);

   /* initialize random numbers */
   srand(SEED);
   count=0;
   for ( i=0; i<n; i++) {
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
      z = x*x+y*y;
      if (z<=1) count++;
      }
   pi=(double)count/n*4;
   printf("Number of trials= %d \nEstimate of pi is: %g \n",n,pi);
}
