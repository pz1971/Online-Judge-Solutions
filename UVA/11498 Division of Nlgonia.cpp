#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    while(cin>> q, q)
    {
        int x{}, y{};
        cin>> x>> y;
        while(q--)
        {
            int a{}, b{};
            cin>> a>> b;
            a -= x;
            b -= y;
            if(a==0 || b==0)
                cout<< "divisa";
            else if(a>0 && b>0)
                cout<< "NE";
            else if(a<0 && b>0)
                cout<< "NO";
            else if(a<0 && b<0)
                cout<< "SO";
            else
                cout<< "SE";
            cout<< endl;
        }
    }
    return 0;
}
