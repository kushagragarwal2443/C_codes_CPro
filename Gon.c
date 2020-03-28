#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int maze[105][105];


int findme(int N,int M,int iniX,int iniY,int finX,int finY,int count)
{
	int min;
	if(iniX==finX && iniY==finY)
		return count;
	else
	{
	long long int left=-1,right=-1,top=-1,bottom=-1;
	maze[iniX][iniY]=0;

	if(maze[iniX+1][iniY]==1&&(iniX+1<N)&&(iniY<M)&&(iniX+1>=0)&&(iniY>=0))
	right=findme(N,M,iniX+1,iniY,finX,finY,count+1);
	if(maze[iniX-1][iniY]==1&&(iniX-1<N)&&(iniY<M)&&(iniX-1>=0)&&(iniY>=0))
	left=findme(N,M,iniX-1,iniY,finX,finY,count+1);
	if(maze[iniX][iniY+1]==1&&(iniX<N)&&(iniY+1<M)&&(iniX>=0)&&(iniY+1>=0))
	top=findme(N,M,iniX,iniY+1,finX,finY,count+1);
	if(maze[iniX][iniY-1]==1&&(iniX<N)&&(iniY-1<M)&&(iniX>=0)&&(iniY-1>=0))
	bottom=findme(N,M,iniX,iniY-1,finX,finY,count+1);
	
	maze[iniX][iniY]=1;


	if(right==-1&&left==-1&&top==-1&&bottom==-1)
		return -1;
	
	else
	{
		if(left>0)
		{
			min=left;
			if(min>right && right>0)
				min=right;
			if(min>top && top>0)
                                min=top;
			if(min>bottom&& bottom>0)
                                min=bottom;
		}
		else  if(right>0)        
                {
                        min=right;
                        if(min>top && top>0)
                                min=top;
                        if(min>bottom&& bottom>0)
                                min=bottom;
                }  
		else if(top>0)
                {
                        min=top;
                        if(min>bottom&& bottom>0)
                                min=bottom;
                }  
  		else if(bottom>0)
                {
                        min=bottom;
		}

		return min;

	}
	}
}
int main(void)
{
	int T;
	scanf("%d", &T);
	int initialX,initialY,finalX,finalY;

	for(int i=1;i<=T;i++)
	{
		int N,M;
		scanf("%d %d",&N,&M);

		for(int j=0;j<N;j++)
		{
			for(int k=0;k<M;k++)
			{
				scanf("%d", &maze[j][k]);
			}
		}

		scanf("%d %d", &initialX, &initialY);
		scanf("%d %d", &finalX,&finalY);
		int answer;
		answer=findme(N,M,initialX,initialY,finalX,finalY,0);
		printf("%d \n", answer);


	}
	return 0;
}




