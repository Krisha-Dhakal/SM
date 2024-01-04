#include<stdio.h>
#include<conio.h>
int main()
{
	int xo,x1, choice; /*xo=seed, x1=next random number that we will generate */
	int a,c,m; /*a=constant multiplier, c=increment, m=modulus */
	int i,n; /*i for loopcontrol, n for how many random numbers */
	float r, array[20]; /*to store the random numbers generated */

    printf("Enter your choice:\n1.Additive\n2.Multiplicative\n3.Mixed?: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            a=1;
            printf("Enter the seed value xo: ");
            scanf("%d",&xo);
            printf("The constant multiplier a=%d\n", a);
            printf("Enter the increment c: ");
            scanf("%d",&c);
            printf("Enter the modulus m: ");
            scanf("%d",&m);
            printf("How many random numbers you want to generate: ");
            scanf("%d",&n);
            for(i=0;i<n;i++) /* loop to generate random numbers */
            {
                x1=(a*xo+c) %m;
                r=1.0*x1/m;
                xo=x1;
                array[i]=r;      
            }
            printf("The generated random numbers are: ");
            for(i=0;i<n;i++)
            {
                printf("%.3lf",array[i]);
                printf("\t");
            }
            break;

        case 2:
            c=0;
            printf("Enter the seed value xo: ");
            scanf("%d",&xo);
            printf("The increment c=%d\n", c);
            printf("Enter the constant multiplier a: ");
            scanf("%d",&a);
            printf("Enter the modulus m: ");
            scanf("%d",&m);
            printf("How many random numbers you want to generate: ");
            scanf("%d",&n);
            for(i=0;i<n;i++) /* loop to generate random numbers */
            {
                x1=(a*xo+c) %m;
                r=1.0*x1/m;
                xo=x1;
                array[i]=r;      
            }
            printf("The generated random numbers are: ");
            for(i=0;i<n;i++)
            {
                printf("%.3lf",array[i]);
                printf("\t");
            }
            break;
        case 3:
            printf("Enter the seed value xo: ");
            scanf("%d",&xo);
            printf("Enter the constant multiplier a: ");
            scanf("%d",&a);
            printf("Enter the increment c: ");
            scanf("%d",&c);
            printf("Enter the modulus m: ");
            scanf("%d",&m);
            printf("How many random numbers you want to generate: ");
            scanf("%d",&n);
            for(i=0;i<n;i++) /* loop to generate random numbers */
            {
                x1=(a*xo+c) %m;
                r=1.0*x1/m;
                xo=x1;
                array[i]=r;      
            }
            printf("The generated random numbers are: ");
            for(i=0;i<n;i++)
            {
                printf("%.3lf",array[i]);
                printf("\t");
            }
            break;

    }
	getch();
	return(0);

}
