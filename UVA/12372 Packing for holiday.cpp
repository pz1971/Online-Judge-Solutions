#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    while(cin>> t)
    {
        for(int tc=1; tc<=t; tc++)
        {
            int x, y, z;
            cin>> x>> y>> z;
            cout<< "Case "<< tc<< ": ";
            if(x>20 || y>20 || z>20)
                cout<< "bad"<< endl;
            else
                cout<< "good"<< endl;
        }
    }
    return 0;
}
