
#include<stdio.h>
int main()
{
	double x = 2.5;

	int result = (int)x+1;	
	printf("\nsum = %d\n",result);

	float result1 = (float)x+1;	
	printf("\nsum1 = %f\n",result1);

	double result2 = (double)x+1;	
	printf("\nsum2 = %lf\n",result2);

	long int result3 = (long int)x+1;	
	printf("\nsum3 = %ld\n",result3);

	short int result4 = (short int)x+1;	
	printf("\nsum4 = %hd\n",result4);

	long double result5 = (long double)x+1;	
	printf("\nsum5 = %Lf\n",result5);
    
	return 0;
}