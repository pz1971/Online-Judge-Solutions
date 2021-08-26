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

//void scanf(lu &n)
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
int josephus(int n, int m)
{
    deque <int> ar;
    for(int i=1; i<=n; i++)  ar.push_back(i);
    while(ar.size()>1)
    {
        ar.pop_front();
        for(int i=1; i<m; i++)
        {
            ar.push_back(ar.front());
            ar.pop_front();
        }
    }
    return ar.front();
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
///   ///   ///   ///   ///   ///   ///


    int n;
    while(cin>> n && n)
    {
        if(n==13)   cout<< "1"<< endl;
        else
        {
            for(int i=2; i<=n; i++)
            {
                if(josephus(n, i)==13)
                {
                    cout<< i<< endl;
                    break;
                }
            }
        }
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}
