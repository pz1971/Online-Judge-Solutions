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
//void scanf(int &n)
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
//    ifstream cin{"../i_file.txt"};
//    ofstream cout{"../o_file.txt"};
///   ///   ///   ///   ///   ///   ///


    vb stat(501, 1);
    for(int i=3; i*i<1002; i+=2)
        if(stat.at(i>>1))
            for(int j=i*i; j<1002; j+=i+i)  stat.at(j>>1) = 0;
    vi primes{0, 1, 2};
    vi cnt{0, 1, 2};
    int c{2};
    for(int i=3; i<1002; i+=2)
    {
        if(stat.at(i>>1))
        {
            c++;
            primes.push_back(i);
        }
        cnt.push_back(c);
        cnt.push_back(c);
    }
    primes.push_back(1000000);
    int n, x;
    while(cin>> n>> c)
    {
        cout<< n<< " "<< c<< ":";

        x = cnt.at(n);
        if(x%2) c = (c*2) - 1;
        else    c *= 2;
        x = (x-c)/2;
        if(x<0) x = 0;
        if(x==0)    for(int i=1; ; i++)
            {
                if(primes.at(i)>n)  break;
                cout<< " "<< primes.at(i);
            }
        else
            for(int i=x+1; i<=x+c; i++) cout<< " "<<primes.at(i);

        cout<< endl<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}