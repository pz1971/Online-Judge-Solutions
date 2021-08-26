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
///   ///   ///   ///   ///   ///   ///


    int t{};
    cin>> t;
    li n;
    for(int tc=1; tc<=t; tc++)
    {
        cin>> n;
        cout<< "Case #"<< tc<< ": ";
        vc num;
        if(n==0)
            cout<< "0"<< endl;
        else
        {
            while(n)
            {
                if(n==1)
                {
                    num.push_back('1');
                    n = 0;
                    break;
                }
                li i;
                if(n<0)
                {
                   for(i=1; ;i++)
                   {
                       if(i*-2 <= n)
                       {
                           num.push_back(n-(i*-2) + '0');
                           n = i;
                           break;
                       }
                   }
                }
                else
                {
                    num.push_back(n%2 + '0');
                    n = -1 * (n/2);
                }
            }
            auto i = num.rbegin();
            while(i!=num.rend())
            {
                cout<< *i;
                i++;
            }
            cout<< endl;
        }
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}
