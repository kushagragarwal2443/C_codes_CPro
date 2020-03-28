#include <stdio.h>
#include <math.h>
long long int arr[2100][2100];
long long int columnNumber[1050];
long long int a[1000100];

long long int searchingR(long long int ind, long long int number)
{
	long long int max,min,midterm,answer;

	max=columnNumber[ind];
	min=0;

	while(min<=max)
	{
		midterm=(min+max)/2;
		if(arr[ind][midterm]<=number)
			min=midterm+1;
		else
			max=midterm-1;
	}
	return min;
}

long long int searchingL(long long int ind, long long int number)
{
        long long int max,min,midterm,answer;

        max=columnNumber[ind];
        min=0;

        while(min<=max)
        {
                midterm=(min+max)/2;

                if(arr[ind][midterm]>=number)
                        max=midterm-1;
                else
                        min=midterm+1;
        }
        return min;
}

int main(void)
{

	long long int prog,contests,q,sum,l,r,x,occ11,occ12,occ21,occ22,finalocc1,finalocc2,finalanswer;
	scanf("%lld %lld", &prog, &contests);

	for(int i=1;i<=prog;i++)
	{
		scanf("%lld",&a[i]);
	}

	for(int i=1;i<=prog;i++)
	{
		columnNumber[a[i]]++;
		arr[a[i]][columnNumber[a[i]]]=i;
	}
	//	for(int i=1;i<10;i++)
	//	{	for(int j=1;j<10;j++)
	//		printf("%lld ",arr[i][j]);
	//	printf("\n");
	//	}
	for(int t=0;t<contests;t++)
	{
		sum=0;
		scanf("%lld %lld %lld", &l, &r, &x);
		if(x%2==0)
		{
		for(int i=1;i<(x/2);i++)
		{
			occ11=searchingR(i,r);
			occ21=searchingL(i,l);
			finalocc1=occ11-occ21;
		//	printf("ans1 %d %lld %lld %lld\n",i,occ11,occ21,finalocc1);


			q=x-i;

			occ12=searchingR(q,r);
			occ22=searchingL(q,l);
			finalocc2=occ12-occ22;
		//	printf("ans2 %lld %lld %lld %lld\n",q,occ12,occ22,finalocc2);

			finalanswer=finalocc1*finalocc2;
			sum+=finalanswer;
		}
		
		
		
			occ11=searchingR(x/2,r);
                        occ21=searchingL(x/2,l);
                        finalocc1=occ11-occ21;
			finalanswer=((finalocc1-1)*(finalocc1))/2;
			sum+=finalanswer;
		//	printf("chutiyaap %lld\n",finalanswer);
		}			
		else
		{
			for(int i=1;i<=(x/2);i++)
                {
                        occ11=searchingR(i,r);
                        occ21=searchingL(i,l);
                        finalocc1=occ11-occ21;
                  //      printf("ans1 %d %lld %lld %lld\n",i,occ11,occ21,finalocc1);


                        q=x-i;

                        occ12=searchingR(q,r);
                        occ22=searchingL(q,l);
                        finalocc2=occ12-occ22;
                    //    printf("ans2 %lld %lld %lld %lld\n",q,occ12,occ22,finalocc2);

                        finalanswer=finalocc1*finalocc2;
                        sum+=finalanswer;
                }

		}
		printf("%lld \n", sum);
	}
	return 0;
}
							


				

