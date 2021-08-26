#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
typedef unsigned int ui;
typedef long int li;
typedef unsigned long lu;
typedef long long ll;
typedef unsigned long long llu;
using namespace std;
//double const pi = acos(-1.0);

//void scanf(ll &n)
// {
//     bool negative = false;
//     char c;
//     n = 0;
//     c = getchar();
//     if (c=='-')
//     {
//         negative = true;
//         c = getchar();
//     }
//     for (; (c>47 && c<58); c=getchar())
//         n = n*10 + c - 48;
//     if (negative)
//         n *= -1;
// }

ll bigmod(ll b, ll p, ll m)
{
    if(p==0)  return 1;
    if(p%2==0)
    {
        ll x = bigmod(b,p/2,m);
        return (x%m * x%m)%m;
    }
    else return ((b%m)*bigmod(b,p-1,m)%m)%m;
}
int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
///   ///   ///   ///   ///   ///   ///


//    ifstream cin{"../i_file.txt"};
//    ofstream cout{"../o_file.txt"};
    vb stat(65000/2+1, 1);
    for(int i=3; i*i<=65000; i+=2)
    {
        if(stat.at(i>>1))
        {
            for(int j=i*i; j<65000; j+= 2*i)
                stat.at(j>>1) = 0;
        }
    }
    int n;
    while(cin>> n && n)
    {
//        if(!stat.at(n>>1)   &&    bigmod(2, n, n)==2)
//            cout<< "The number "<< n<< " is a Carmichael number."<< endl;
//        else
//            cout<< n<< " is normal."<< endl;
        if(!stat.at(n>>1))
        {
            bool yeah{true};
            for(int i=2; i<n; i++)
            {
                if(bigmod(i, n, n)!=i)
                {
                    yeah = false;
                    break;
                }
            }
            if(yeah)
                cout<< "The number "<< n<< " is a Carmichael number."<< endl;
            else
                cout<< n<< " is normal."<< endl;
        }
        else
            cout<< n<< " is normal."<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}