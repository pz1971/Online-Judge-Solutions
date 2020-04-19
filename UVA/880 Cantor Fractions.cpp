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


    llu n;
    while(cin>> n)
    {
        llu idx{}, val{};
        for(llu i=1; ; i++)
        {
            if(n <= i*(i+1)/2)
            {
                idx = i;
                val = i*(i+1)/2;
                break;
            }
        }
        llu dis = val-n;
        cout<< dis+1 << "/"<< idx-dis<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}
