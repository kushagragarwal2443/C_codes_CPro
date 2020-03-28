#include <stdio.h>
#include <math.h>
long long int arr[1000005];
long long int pre[1000005];
int main(void)
{
	int N;
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
	{
		for(long long int c=0;c<1000005;c++)
		{
			arr[c]=0;
			pre[c]=0;
		}
		long long int books;
		long long int students;
		scanf("%lld %lld", &books, &students);
		for(int j=1;j<=students;j++)
		{
			long long int L;
			long long int R;
			long long int X;
			scanf("%lld %lld %lld", &L, &R, &X);
			arr[L-1]+=X;
			arr[R]-=X;
		}
		long long int sum=0;
		for(int j=0;j<books;j++)
		{
			sum+=arr[j];
			pre[j]=sum;
		}
		long long int min=pre[0];
		long long int pos=0;
		for(int j=0;j<books;j++)
		{
			if(pre[j]<min)
			{
				min=pre[j];
				pos=j;
			}
		}
		printf("%lld \n", pos+1);
	}
	return 0;
}


	
