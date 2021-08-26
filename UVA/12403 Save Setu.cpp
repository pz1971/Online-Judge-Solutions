#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    while(cin>> t)
    {
        int sum{0};
        while(t--)
        {
            string s;
            cin>> s;
            if(s.compare("donate")==0)
            {
                int x;
                cin>> x;
                sum += x;
            }
            else
                cout<< sum<< endl;
        }
    }
    return 0;
}
