#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int l, i, t;
    while(cin>> t)
    {
        while(t--)
        {
            cin>> s;
            l = s.size();
            l /= 2;
            for(i=0; i<l; i+=2)
                cout<< s[i];
            cout<< endl;
        }
    }
    return 0;
}
 