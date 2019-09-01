#include <bits/stdc++.h>
#define vi vector<int>
typedef unsigned int ui;
typedef long int li;
typedef long long ll;
typedef unsigned long long llu;
typedef unsigned long lu;
using namespace std;

void scanf(ui &n)
{
    bool negative = false;
    char c;
    n = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        n = n*10 + c - 48;
    if (negative)
        n *= -1;
}
 
int main()
{
 
    vi primes{2, 3, 5, 7};
    for(int i=11; i<=31630; i+=2)
    {
        int k;
        k = sqrt(i);
        if(k*k != i)
        {
            bool isprime{true};
            for(auto j: primes)
            {
                if(i%j==0)
                {
                    isprime = false;
                    break;
                }
                if(j > k)
                    break;
            }
            if(isprime)
                primes.push_back(i);
        }
    }
 
    int t{};
    ui m{}, n{};
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        scanf(m), scanf(n);

        if(m==2 || m==1)
            printf("2\n");
        if(m%2==0)
            m++;
        for( ; m<=n; m+=2)
        {
            int k;
            k = sqrt(m);
            if(k*k != m)
            {
                bool isprime{true};
                for(auto i: primes)
                {
                    if(i==m || i>k)
                        break;
                    if(m%i==0)
                    {
                        isprime = false;
                        break;
                    }
                }
                if(isprime)
                    printf("%u\n", m);
            }
        }
        if(t!=0)
            printf("\n");
    }
 
    return 0;
}
 