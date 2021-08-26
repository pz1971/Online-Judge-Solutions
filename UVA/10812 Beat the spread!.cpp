#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    while(cin>> t)
    {
        while(t--)
        {
            int s, d;
            cin>> s>> d;
            if(d>s || (d+s)%2 != 0)
                cout<< "impossible"<< endl;
            else
            {
                cout<< (d+s)/2 << " "<< s - ((d+s)/2)<< endl;
            }
        }
    }
    return 0;
}
