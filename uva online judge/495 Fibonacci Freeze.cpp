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
int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
///   ///   ///   ///   ///   ///   ///


    vector<string> fib{"0", "1"};
    for(int i=1; i<5005; i++)
        fib.push_back(add(fib.at(i), fib.at(i-1)));
    int n;
    while(cin>> n)
    {
        cout<< "The Fibonacci number for "<< n<< " is "<< fib.at(n)<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}