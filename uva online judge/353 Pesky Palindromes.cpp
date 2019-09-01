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
double const pi = acos(-1.0);

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

bool is_palin(string s)
{
    string s2{s};
    reverse(s2.begin(), s2.end());
    if(s==s2)   return true;
    return false;
}
int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
//    ifstream cin{"../i_file.txt"};
//    ofstream cout{"../o_file.txt"};
///   ///   ///   ///   ///   ///   ///


    string s, tem;
    vector<string> vs;
    int cnt{}, l;
    while(cin>> s)
    {
        cnt = 0;
        int len = s.size();
        for(int l=len; l>0; l--)
        {
            for(int i=0; i+l<=len; i++)
            {
                tem = s.substr(i, l);
                if(is_palin(tem))
                {
                    bool yeah{true};
                    for(auto j: vs)
                    {
                        if(j==tem)
                        {
                            yeah = false;
                            break;
                        }
                    }
                    if(yeah)
                    {
                        cnt++;
                        vs.push_back(tem);
                    }
                }
            }
            vs.clear();
        }
        cout<< "The string '"<< s<< "' contains "<< cnt<< " palindromes."<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}