#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int place[55][2];
int main(void)
{
	int N,Q;
	scanf("%d", &N);
	scanf("%d", &Q);
	int leastdist=100000,resultX,resultY,count=-1;
	int X,Y;
	int flag=1;
	char arr[10];
	int dist;
	for(int i=1;i<=Q;i++)
	{
		scanf("%s %d %d",arr,&X,&Y);

		char ch=arr[0];
		if(ch=='F')
			flag=1;
		else
			flag=2;

		if(flag==1)
		{
			if(count==-1)
			{
				resultX=-1;
				resultY=-1;
			}
			else
			{ leastdist=1000000;
				for(int j=0;j<=count;j++)
				{
					dist=abs(X-place[j][0])+abs(Y-place[j][1]);
					if(dist<leastdist)
					{
						leastdist=dist;
						resultX=place[j][0];
						resultY=place[j][1];
					}
					else if(dist==leastdist)
					{
						if(resultX>place[j][0])
						{
							resultX=place[j][0];
							resultY=place[j][1];
						}
						else if(resultX==place[j][0])
						{
							if(resultY>place[j][1])
							{
								resultX=place[j][0];
								resultY=place[j][1];
							}
						}
					}
				}
			}
		//	printf("%d %d\n",leastdist,dist);

			printf("%d %d \n",resultX,resultY);
		}
		else
		{
			count++;
			place[count][0]=X;
			place[count][1]=Y;
		}
	}
	return 0;
}


