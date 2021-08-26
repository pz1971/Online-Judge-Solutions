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

string product(string a, string b)
{
    if(a=="0" || b=="0")
        return "0";
    if(a.size() > b.size())
        swap(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int l = a.size() + b.size() + 1;
    string ans(l, '0');
    int start{};

    for(auto i: b)
    {
        int x{}, rem{}, indx{start};
        for(auto j: a)
        {
            x = ((i-'0')*(j-'0')) + rem + ans.at(indx) - '0';
            rem = x/10;
            x %= 10;
            ans.at(indx) = x + '0' ;
            indx++;
        }
        while(rem)
        {
            x = ans.at(indx) - '0' + rem;
            rem = x/10;
            x %= 10;
            ans.at(indx) = x + '0';
            indx++;
        }
        start++;
    }
    while(--l)
    {
        if(ans.at(l)!='0')
            break;
        ans.pop_back();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
string decr(string str)
{
    int i = str.size();
    string s = str;
    for(int l=i-1; l>=0; l--)
    {
        s.at(l)--;
        if(s.at(l) < '0')
        {
            s.at(l) = '9';
        }
        else
            break;
    }
    if(s.at(0)=='0')
    {
        reverse(s.begin(), s.end());
        while(--i)
        {
            if(s.at(i)!='0')
                break;
            s.pop_back();
        }
        reverse(s.begin(), s.end());
    }
    return s;
}
string dbl_incr(string str)
{
    int l = str.size();
    string s(l+1, '0');
    reverse(str.begin(), str.end());
    int rem{2};
    for(int i=0; i<l; i++)
    {
        s.at(i) = str.at(i) + rem;
        if(s.at(i)>'9')
        {
            rem = (s.at(i)-'0')/10;
            s.at(i) -= 10;
        }
        else rem = 0;
    }
    if(rem) s.at(l) = rem + '0';
    while(l)
    {
        if(s.at(l)=='0')
        {
            s.pop_back();
            l--;
        }
        else
            break;
    }
    reverse(s.begin(), s.end());
    return s;
}
int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
///   ///   ///   ///   ///   ///   ///


    string s;
    while(cin>> s)
    {
        if(s.at(0)=='-')      cout<< "0"<< endl;
        else if(s=="0")       cout<< "1"<< endl;
        else if(s=="1")     cout<< "2"<< endl;
        else
        {
            cout<< dbl_incr(product(s, decr(s)))<< endl;
        }
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}