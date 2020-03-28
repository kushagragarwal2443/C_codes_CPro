#include <stdio.h>
long long int gcd(long long int x,long long int y) //to find the gcd of x and y
{
	if(y==0)
		return x;
	return gcd(y,x%y);
}
int main(void)
{
	int T;
	scanf("%d", &T);

	for(int test=1;test<=T;test++)
	{
		long long int A,B,C;
		long long int low;
		scanf("%lld %lld %lld", &A,&B,&C);

		//finding gcd of A and B
		
		long long int GCD=gcd(A,B);

		if(C%GCD==0)
			printf("YES \n");
		else
			printf("NO \n");
	}
	return 0;
}


