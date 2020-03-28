#include <stdio.h>
int main(void)
{
	int l=0;
	for(int i=1;i<=1000000;i++)
	{
		int c=0,k=0;
		for(int j=1;j<=i/2;j++)
		{
			if(i%j==0)
				c++;
		}

		for(int j=1;j<=(i+1)/2;j++)
		{
			if((i+1)%j==0)
				k++;
		}
		if(c==k)
			l++;
	}
	printf("%d", l);
	return 0;
}
