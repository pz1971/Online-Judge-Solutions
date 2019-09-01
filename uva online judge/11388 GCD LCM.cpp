#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
typedef unsigned int ui;
typedef long int li;
typedef unsigned long lu;
typedef long long ll;
typedef unsigned long long llu;
using namespace std;
// const ll mod = 998244353;
// const double pi = acos(-1.0);

int main()
{
    // std::ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // ifstream cin{"../i_file.txt"};
    // ofstream cout{"../o_file.txt"};

    int t;
    ll l, g;
    bool no;
    cin>> t;
    while(t--)
    {
        cin>> g>> l;
        if(l%g)
            cout<< "-1\n";
        else
            cout<< g<< " "<< l<< endl;
    }

    return 0;
}
