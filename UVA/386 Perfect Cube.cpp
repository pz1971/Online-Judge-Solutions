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


    int a{}, b{}, c{}, d{};
    for(a=6; a<=200; a++)
    {
        for(b=2; b<a; b++)
        {
            for(c=b+1; c<a; c++)
            {
                for(d=c+1; d<a; d++)
                {
                    if(a*a*a==b*b*b + c*c*c + d*d*d)
                    {
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
                    }
                }
            }
        }
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}
