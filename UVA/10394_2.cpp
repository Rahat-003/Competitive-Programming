#include <stdio.h>
#include <math.h>
int boolean[20000000];
int primes[1270607];
int twins[100000];
void getTwins()
{
    int i,j,counter = 0,twinsCou=0;
    for(i = 2 ; i*i<=20000000; i++)
    {
        if(!boolean[i])
        {
            primes[counter++] = i;
            if(counter-1 >0 && i - primes[counter-2] == 2)
            {
                twins[twinsCou++]= i;
            }
            for(j = i*i ; j<20000000 ; j+=i)
            {
                boolean[j] = 1;
            }
        }
    }
    for(i = 4472 ; i < 20000000 ; i++)
    {
        if(!boolean[i])
        {
            primes[counter++] = i;
            if(counter >0 && i -primes[counter-2] == 2)
            {
                twins[twinsCou++]= i;
            }
            if(twinsCou>100000)
                break;
        }
    }
}
int main()
{
    int i;
    getTwins();
    while(scanf("%d", &i)==1)
    {
        printf("(%d, %d)\n", twins[i-1]-2 , twins[i-1]);
    }

    return 0;
}
