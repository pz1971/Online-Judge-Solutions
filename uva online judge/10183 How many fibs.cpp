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
string add(string a, string b)
{
    reverse(a.begin(), a.end());    reverse(b.begin(), b.end());
    if(a.size()<b.size())
        swap(a, b);
    int l = a.size(), l2 = b.size();
    while(l2<l)
    {
        b.push_back('0');   l2++;
    }
    string sum{""};
    int i, rem{};
    for(i=0; i<l; i++)
    {
        rem += a.at(i)-'0' + b.at(i)-'0';
        sum.push_back(rem%10 + '0');
        rem /= 10;
    }
    while(rem)
    {
        sum.push_back(rem%10 + '0');
        rem/=10;
    }
    reverse(sum.begin(), sum.end());
    return sum;
}
bool larger(string a, string b)
{
    if(a.size() > b.size())   return true;
    else if(a.size() < b.size())    return false;
    auto j = b.begin();
    for(auto i: a)
    {
        if(i != *(j))
        {
            if(i > *(j))
                return true;
            else
                return false;
        }
        j++;
    }
    return true;
}

int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
///   ///   ///   ///   ///   ///   ///


    vector<string> fib{"1", "2"};
    for(int i=1; i<=500; i++)   fib.push_back(add(fib.at(i), fib.at(i-1)));
    string a, b;
    while(cin>> a>> b)
    {
        if(a=="0" && b=="0")    break;
        int cnt{};
        for(auto i: fib)
        {
            if(larger(i, a))
            {
                if(i==b || !larger(i, b))   cnt++;
                else    break;
            }
        }
        cout<< cnt<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}