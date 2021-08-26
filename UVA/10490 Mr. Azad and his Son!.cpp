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


//    ofstream cout{"../o_file.txt"};
    vb p1(32, 1);
    for(int i=4; i<32; i+=2)    p1.at(i) = 0;
    for(int i=3; i*i<32; i+=2)
        if(p1.at(i))
        {
            for(int j=i*i; j<32; j+=i*2)
                p1.at(j) = 0;
        }
    vb p2(32, 1);
    for(int i=2; i<32; i++)
    {
        li x = pow(2.0, i*1.0) - 1.0;
        li y = sqrt(x);
        if(y*y==x || x%2==0)
            p2.at(i) = 0;
        else
        {
            for(li j=3; j<=y ; j+=2)
            {
                if(x%j==0)
                {
                    p2.at(i) = 0;
                    break;
                }
            }
        }
    }
    int n;
    while(cin>> n && n!=0)
    {
        if(p2.at(n))
        {
            cout<< "Perfect: ";
            llu ans = pow(2.0, n*1.0-1.0) * (pow(2.0, n*1.0) - 1.0);
            cout<< ans<< "!"<< endl;
        }
        else if(p1.at(n))
            cout<< "Given number is prime. But, NO perfect number is available."<< endl;
        else
            cout<< "Given number is NOT prime! NO perfect number is available."<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}