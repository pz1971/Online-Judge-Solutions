#include <bits/stdc++.h>
using namespace std;
 
int main()
{
 
    int t;
    cin>> t;
    string s;
    while(t--)
    {
        int sum{};
        cin>> s;
        for(auto i: s)
        {
            sum += i - '0';
        }
        cout<< sum<< endl;
    }
 
    return 0;
}