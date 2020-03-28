#include <stdio.h>
#include <string.h>
char arr[500];
int main(void)
{
	for(int i=0;i<500;i++)
		arr[i]='0';
	scanf("%s",arr);
	int pos1,pos2,pos3;
	for(int i=0;i<500;i++)
	{
		if(arr[i]=='+')
			pos1=i;
		else if(arr[i]=='=')
			pos2=i;
		else if(arr[i]=='0')
		{
			pos3=i;
			break;
		}
	}
	//for(int i=0;i<500;i++)
	//	printf("%c",arr[i]);
	int a=pos1;
	int b=pos2-pos1-1;
	int c=pos3-pos2-2;
	//printf("\n %d %d %d \n",a,b,c);
	if(((a+b)-c)==2)
	{
		a--;
		c++;
	}
	else if(((a+b)-c)==-2)
	{
		a++;
		c--;
	}
	else if(((a+b)-c)==0)
		c=a+b;
	else
		a=-1;
	if(a>0)
	{
	for(int i=1;i<=a;i++)
	{
		printf("|");
	}
	printf("+");
	for(int i=1;i<=b;i++)
        {
                printf("|");
        }
        printf("=");
	for(int i=1;i<=c;i++)
        {
                printf("|");
        }
	}
	else
	{
		printf("Impossible");
	}
        return 0;
}


