#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a{}, b{}, c{};
    while(cin>> a>> b >> c)
    {
        if(a==b && b==c)
            cout<< "*";
        else if(a!=b && a!=c)
            cout<< "A";
        else if(b!=a && b!=c)
            cout<< "B";
        else if(c!=b && c!=a)
            cout<< "C";
        cout<< endl;
    }
    return 0;
}
