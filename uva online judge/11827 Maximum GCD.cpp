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


    char str[30000], *s, *e;
    int t{};
    cin>> t;
    cin.ignore();
    while(t--)
    {
        cin.getline(str, 30000);
        vi num;
        s = str;
        int mx{};
        while(1)
        {
            num.push_back(strtoll(s, &e, 10));
            if(s==e)
                break;
            s = e;
        }
        num.pop_back();
//        for(auto i: num)
//            cout<< i<< endl;
        int l = num.size();
        for(int i=0; i<l-1; i++)
        {
            for(int j=i+1; j<l; j++)
                mx = max(mx, __gcd(num.at(i), num.at(j)));
        }
        cout<< mx<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}
