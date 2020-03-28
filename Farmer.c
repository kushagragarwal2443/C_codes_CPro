#include <stdio.h>
#include <math.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	for(int testcases=0;testcases<N;testcases++)
	{
		long long int n,m,a,b,mod;
		scanf("%lld %lld %lld %lld %lld",&n, &m, &a, &b, &mod);
		long long int area[m];

		//base conditions of a recursive function
		area[0]=1;
		area[1]=2;

		// Filling the array with area of fields
		for(long long int i=2;i<m;i++)
		{
			area[i]=((area[i-1]*a)+(a*b)+(area[i-2]*b))%mod +b;
		}

		//To Binary Search on Time, we need to find the Minimum and Maximum Time possible
		long long int mintime;
		long long int maxtime=0;
		mintime=area[0];
		for(long long int i=0;i<m;i++)
		{
			maxtime+=area[i];
			if(area[i]>mintime)
			{
				mintime=area[i];
			}
		}

		//if originally mintime==maxtime-1, means ek farmer kam hai
		if(n>m)
		{
			printf("%lld \n", mintime);
		}
		else if(mintime==maxtime-1)
                {
                        if(n==m)
                                printf("%lld \n",mintime);
                        else
                                printf("%lld \n", maxtime);
                }


		//for other cases
		else
		{

		//binary search on time
		long long int c;
		int flag=0;   //yeh denote karega ki execution kitna complete hua hai
		long long int answer;
		while(mintime<maxtime)
		{
			c=(mintime+maxtime)/2;
			long long int sum=0;
			long long int f=1;
			//calculating farmers required for this time
			for(long long int i=0;i<m;i++)
			{
				sum+=area[i];
				if(sum>c)
				{
					f++;      //increment number of farmers required
					sum=0;   
					i--;      // read this field in next farmers time
				}
			}
			
			//if mintime==maxtime-1, we need to check but if we dont break then infinte loop banjayga hence we break and check for the two cases separately
			//if(mintime==maxtime-1)
			//{
			//	flag=1;
			//	break;
		//	}
			if(f<=n)
			{
				maxtime=c;
			}
			else
			{
				mintime=c+1;
			}
		}
	//	long long int sum=0;
	//	long long int f=0;
	//	if(flag==1)
	//	{
	//		for(long long int i=0;i<m;i++)
          //              {
            //                    sum+=area[i];
              //                  if(sum>mintime)
                //                {
                  //                      f++;
                    //                    sum=0;
                      //                  i--;
                        //        }
                       // }
		//	if(f<=n)
		//		printf("%lld \n", mintime);
		//	else
		//		printf("%lld \n", maxtime);
	//
	//	}
	printf("%lld \n", maxtime);
	}
	}
	return 0;
}



					
