#include <stdio.h>
#include <math.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
	{
		long long int n;
		long long int k;
		scanf("%lld %lld", &n, &k);
		long long int arr[n];
		for(long long int j=0;j<n;j++)
		{
			scanf("%lld", &arr[j]);
		}
		long long int c=0;
		for(long long int j=0;j<n;j++)
		{
			if(arr[j]<0)
				c++;
		}
		int mode1=0;int mode2=0;
		if(c==n)
		{
			mode1=1;
		}
		if(k==1)
		{
			mode2=2;
		}
		if(k==0)
		{
			mode2=3;
		}
		if(mode2==3)
		{
			long long int sum=0;
			for(long long int j=0;j<n;j++)
				sum=sum+arr[j];
			printf("%lld \n", sum);
		}
		else if(mode1==1 && mode2==0)
		{
			long long int max=arr[0];
			for(long long int j=0;j<n;j++)
			{
				if(arr[j]>max)
				{
					max=arr[j];
				}
			}
			printf("%lld \n",max);
		}
		else if(mode2==2)
		{
			long long int prearr[n];
			long long int sufarr[n];
			prearr[0]=arr[0];
			sufarr[n-1]=arr[n-1];
			for(long long int j=1;j<n;j++)
			{
				prearr[j]=prearr[j-1]+arr[j];
			}
			for(long long int j=n-2;j>=0;j--)
			{
				sufarr[j]=sufarr[j+1]+arr[j];
			}
			long long int max1=prearr[0];
			long long int max2=sufarr[0];
			long long int pos1=0;
			long long int pos2=0;
			long long int sum;
			for(long long int j=0;j<n;j++)
			{
				if(prearr[j]>max1)
				{
					max1=prearr[j];
					pos1=j;
				}
				if(sufarr[j]>max2)
				{
					max2=sufarr[j];
					pos2=j;
				}
			}
			if(max1>max2)
			{
				sum=prearr[pos1];
			}
			else
			{
				sum=sufarr[pos2];
			}
			printf("%lld \n", sum);
		}
		else
		{
			long long int c=0;
			long long int max=0;
			for(int j=0;j<n;j++)
			{
				c+=arr[j];
				if(c<0)
				{
					c=0;
				}
				if(c>max)
				{
					max=c;
				}
			}
			printf("%lld \n", max);
		}
	}
	return 0;
}








				



