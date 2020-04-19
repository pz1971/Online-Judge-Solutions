#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt{}, tc{};
    cin>> tt;
    for(tc=1; tc<=tt; tc++)
    {
        int n{}, b{}, w{}, t{}, a{};
        string s;
        cin>> n;
        getchar();
        cin>> s;
        int l = s.size();
        for(int i=0; i<l; i++)
        {
            if(s.at(i)=='B')
                b++;
            else if(s.at(i)=='W')
                w++;
            else if(s.at(i)=='T')
                t++;
            else if(s.at(i)=='A')
                a++;
        }
        cout<< "Case "<< tc<< ": ";

        if(a==n)
            cout<< "ABANDONED";
        else if(b==n-a)
            cout<< "BANGLAWASH";
        else if(w==n-a)
            cout<< "WHITEWASH";
        else if(b>w)
            cout<< "BANGLADESH "<< b<< " - "<< w;
        else if(w>b)
            cout<< "WWW "<< w<< " - "<< b;
        else
            cout<< "DRAW "<< b<< " "<< t;

        cout<< endl;
    }
    return 0;
}
