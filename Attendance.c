#include <stdio.h>
#include <math.h>
int main(void)
{
	int H;
	scanf("%d", &H);
	for(int i=1;i<=H;i++)
	{
		long long int N,M,T;
		scanf("%lld %lld %lld", &N, &M, &T);
		long long int P[N];
		long long int Q[M];
		for(long long int j=0;j<N;j++)
		{
			scanf("%lld", &P[j]);
		}
		for(long long int j=0;j<M;j++)
                {
                        scanf("%lld", &Q[j]);
                }
		long long int P1[N];
		long long int Q1[M];
		for(long long int l=0;l<N;l++)
		{
			long long int c=1;
			for(long long int k=(l+1);k<N;k++)
			{
				if(P[l]==P[k])
					c++;
				else
					break;
			}
			P1[l]=c;
		}
		for(long long int l=0;l<M;l++)
                {
                        long long int c=1;
                        for(long long int k=(l+1);k<M;k++)
                        {
                                if(Q[l]==Q[k])
                                        c++;
                                else
                                        break;
                        }
                        Q1[l]=c;
                }
		long long int max=0;long long int f=0;
		for(long long int x=0;x<N;x++)
		{
			long long int c=0;
			long long int max1=0,max2=0;
			for(long long int y=0;y<M;y++)
			{
				if(Q[y]==P[x])
					c=Q1[y];
				if(c>max2)
					max2=c;
			}
			c=0;
			for(long long int y=0;y<N;y++)
                        {
                                if(P[y]==P[x])
                                       c=P1[y];
                                if(c>max1)
                                        max1=c;
			}
			if(max1>max2)
			f=max2;
			else
			f=max1;
			if(f>max)
			max=f;
		}
		printf("%lld \n", T*max);
	}
	return 0;
}







