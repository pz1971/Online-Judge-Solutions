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

string product(string s, int n)
{
    reverse(s.begin(), s.end());
    int l = s.size();
    string p(l+6, '0');

    int start{}, rem{}, a{};
    while(n)
    {
        a = n%10;
        if(a)
        {
            int idx{start};
            for(auto i: s)
            {
                rem += (i-'0')*a + p.at(idx)-'0';
                p.at(idx) = rem%10 + '0';
                rem /= 10;
                idx++;
            }
            while(rem)
            {
                rem += p.at(idx) - '0';
                p.at(idx) = rem%10 + '0';
                rem /= 10;
                idx++;
            }
        }
        start++;
        n/=10;
    }

    while(p.back()=='0')    p.pop_back();
    reverse(p.begin(), p.end());
    return p;
}
int dig_sum(string s)
{
    int sum{};
    for(auto i: s)
        sum += i - '0';
    return sum;
}
int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
//    ifstream cin{"../i_file.txt"};
//    ofstream cout{"../o_file.txt"};
///   ///   ///   ///   ///   ///   ///


    vi sum{1};
    string s{"1"};
    int n = 1;
    while(n<1001)
    {
        s = product(s, n);
        sum.push_back( dig_sum(s) );
        n++;
    }

    while(cin>> n)
    {
        cout<< sum.at(n)<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}
