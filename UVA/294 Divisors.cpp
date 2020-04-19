#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        while(n--)
        {
            unsigned long long l, l2, u, i, j, num{2};
            int m{2};
            cin>> l >> u;
            l2 = l;
            if(l%2!=0)
                l2++;

            if(l==u)
            {
                if(l==1)
                {
                    m = 1;
                    num = 1;
                }
                else
                {
                    int r = sqrt(l), cnt{2};
                    if(r*r==l)
                    {
                        r--;
                        cnt++;
                    }
                    for(i=2; i<=r; i++)
                    {
                        if(l%i==0)
                            cnt+=2;
                    }
                    num = l;
                    m = cnt;
                }
            }
            else
            {
                for(i=l2; i<=u; i+=2)
                {
                    int cnt{2};
                    int r = sqrt(i);
                    if(i == r*r)
                    {
                        r--;
                        cnt++;
                    }
                    for(j=2; j<=r; j++)
                    {
                        if(i%j == 0)
                            cnt+=2;
                    }
                    if(cnt>m)
                    {
                        m = cnt;
                        num = i;
                    }
                }
            }
            cout<< "Between "<< l << " and "<< u<< ", "<< num << " has a maximum of "<< m<< " divisors."<< endl;
        }
    }
    return 0;
}