#include <bits/stdc++.h>
#define vi vector<int>
typedef unsigned int ui;
typedef long int li;
typedef unsigned long lu;
typedef long long ll;
typedef unsigned long long llu;
using namespace std;
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
///   ///   ///   ///   ///   ///   ///
 
 
    int n;
    bool yeah{true};
    while(cin>> n)
    {
        if(yeah)
        {
            if(n!=42)
                cout<< n<< endl;
            else
                yeah = false;
        }
    }
 
 
///   ///   ///   ///   ///   ///   ///
    return 0;
}