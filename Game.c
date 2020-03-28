#include <stdio.h>
#include <math.h>
int main(void)
{
	int T;
	int hero;
	scanf("%d", &T);

	for(int test=1;test<=T;test++)
	{
		int n,m,mod;
		scanf("%d %d %d",&n,&m,&mod);

		int arr[m+1];

		for(int i=0;i<=m;i++)
			arr[i]=0;

		arr[0]=1;

		for(int rows=1;rows<=n;rows++)
		{
			if((rows-m)<0)
				hero=rows;
			else
				hero=m;

			for(;hero>0;hero--)
				arr[hero]=(arr[hero]%mod+arr[hero-1]%mod)%mod;
		}

		printf("%d \n", arr[m]);
	}
	return 0;
}
