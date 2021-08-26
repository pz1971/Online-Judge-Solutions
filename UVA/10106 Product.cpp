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
//{
//    bool negative = false;
//    char c;
//    n = 0;
//    c = getchar();
//    if (c=='-')
//    {
//        negative = true;
//        c = getchar();
//    }
//    for (; (c>47 && c<58); c=getchar())
//        n = n*10 + c - 48;
//    if (negative)
//        n *= -1;
//}
vc product(string a, string b)
{
    if(a.size() > b.size())
        swap(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int l = a.size() + b.size() + 5;
    vc ans(l, '0');
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

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
///   ///   ///   ///   ///   ///   ///


    string a, b;
    while(cin>> a>> b)
    {
        if(a=="0" || b=="0")
            cout<< "0";
        else
        {
            vc x;
            x = product(a, b);
            bool lz{true};
            for(auto i: x)
            {
                if(lz)
                {
                    if(i!='0')
                    {
                        cout<< i;
                        lz = false;
                    }
                }
                else
                    cout<< i;
            }
        }
        cout<< endl;
    }


///   ///   ///   ///   ///   ///   ///
return 0;
}
