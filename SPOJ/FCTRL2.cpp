#include <bits/stdc++.h>
using namespace std;
 
string product(string a, string b)      // product of 2 big INTs represented as string
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

string decr(string str)     // decrement of bigInt represented as string
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

string fact(string s)
{
    if(s=="1")
        return s;
    else
        return product(s, fact(decr(s)));
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    string s;
    cin>> t;
    while(t--)
    {
        cin>> s;
        cout<< fact(s)<< endl;
    }

    return 0;
}
 