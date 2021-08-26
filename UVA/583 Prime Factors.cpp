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

int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
///   ///   ///   ///   ///   ///   ///


//    ifstream cin{"../i_file.txt"};
//    ofstream cout{"../o_file.txt"};
    vector<li> primes{2};
    vb stat(32800, 1);
    stat.at(0) = 0;
    for(int i=3; i*i<65600; i+=2)
    {
        if(stat.at(i>>1))
        {
            for(int j=i*i; j<65600; j+= 2*i)
                stat.at(j>>1) = 0;
        }
    }
    for(int i=3; i<65600; i+=2)
    {
        if(stat.at(i>>1))
            primes.push_back(i);
    }
    stat.clear();
    li n;
    while(cin>> n && n!=0)
    {
        cout<< n<< " = ";
        bool c{false};
        if(n==-1 || n==1)
        {
            cout<< n << endl;
            continue;
        }
        else if(n<-1)
        {
            cout<< -1;
            c = true;
            n *= -1;
        }
        while(n!=1)
        {
            if(c)
                cout<< " x ";
            else
                c = true;
            bool ip{true};
            li sq = sqrt(n);
            for(auto i: primes)
            {
                if(n%i==0)
                {
                    cout<< i;
                    ip = false;
                    n /= i;
                    break;
                }
                if(i>sq)
                    break;
            }
            if(ip)
            {
                cout<< n;
                n = 1;
            }
        }
        cout<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}