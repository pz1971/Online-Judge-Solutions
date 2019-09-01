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
void d2h(string s)
{
    cout<< "0x";
    lu n{};
    for(auto &i: s)
        n = n*10 + (i - '0');
    vc ans;
    int x{};
    while(n)
    {
        x = n%16;
        if(x>9)
            ans.push_back(x-10+'A');
        else
            ans.push_back(x + '0');
        n /= 16;
    }
    reverse(ans.begin(), ans.end());
    for(auto &i: ans)
        cout<< i;
    if(ans.size()==0)
        cout<< "0";
    cout<< endl;
}
void h2d(string s)
{
    int l = s.size(), p{};
    lu sum{}, x{};
    for(int i=l-1; i>1; i--)
    {
        x = pow(16, p);
        p++;
        if(isalpha(s.at(i)))
            x *= s.at(i)-'A' + 10;
        else
            x *= s.at(i)-'0';
        sum += x;
    }
    cout<< sum<< endl;
}

int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
///   ///   ///   ///   ///   ///   ///


    string s;
    while(cin>> s)
    {
        if(s.at(0)=='-')
            break;
        else if(s.size()>2)
        {
            if(s.at(0)=='0' && s.at(1)=='x')
            {
                h2d(s);
            }
            else
                d2h(s);
        }
        else
            d2h(s);
    }



///   ///   ///   ///   ///   ///   ///
    return 0;
}
