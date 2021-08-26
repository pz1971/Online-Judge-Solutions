#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
typedef unsigned int ui;
typedef long int li;
typedef unsigned long lu;
typedef long long ll;
typedef unsigned long long llu;
using namespace std;
void scanf(int &n)
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
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
///   ///   ///   ///   ///   ///   ///


    int n{}, m{}, c{}, t{}, a{};
    while(1)
    {
        scanf(n),   scanf(m),   scanf(c);
        if(n==0 && m==0 && c==0)
            break;
        vi ar(25, 0);
        vb ar2(25, false);
        int sum{}, mx_sum{};
        for(int i=1; i<=n; i++)
        {
            scanf(a);
            ar.at(i) = a;
        }
        bool blown{false};
        while(m--)
        {
            scanf(a);
            if(!blown)
            {
                if(ar2.at(a))
                {
                    sum -= ar.at(a);
                    ar2.at(a) = false;
                }
                else
                {
                    sum += ar.at(a);
                    ar2.at(a) = true;
                    if(sum > mx_sum)
                        mx_sum = sum;
                }
            }
            if(sum > c)
                blown = true;
        }
        cout<< "Sequence "<< ++t<< endl;
        if(blown)
            cout<< "Fuse was blown."<< endl;
        else
        {
            cout<< "Fuse was not blown."<< endl;
            cout<< "Maximal power consumption was "<< mx_sum<< " amperes."<< endl;
        }
        cout<< endl;
    }



///   ///   ///   ///   ///   ///   ///
return 0;
}
