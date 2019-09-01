#include <bits/stdc++.h>
#define vi vector<int>
typedef long long ll;
typedef unsigned long long llu;
typedef unsigned int ui;
typedef unsigned long lu;
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
///   ///   ///   ///   ///   ///   ///
    int n{};
    while(cin>> n)
    {
        while(n--)
        {
            int a{};
            cin>> a;
            string s;
            vector <bool> lft;
            int pos{};
            for(int i=0; i<a; i++)
            {
                cin>> s;
                if(s=="SAME")
                {
                    cin>> s;
                    int x{};
                    cin>> x;
                    bool m{lft.at(x-1)};
                    lft.push_back(m);
                    if(lft.at(x-1))
                        pos--;
                    else
                        pos++;
                }
                else if(s=="LEFT")
                {
                    pos--;
                    lft.push_back(true);
                }
                else
                {
                    pos++;
                    lft.push_back(false);
                }
            }
            cout<< pos<< endl;
        }
    }
///   ///   ///   ///   ///   ///   ///
    return 0;
}
