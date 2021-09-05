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

    int t{};
    cin>> t;
    getchar();
    while(t--)
    {
        vi d;
        char ch{};
        while(1)
        {
            ch = getchar();
            if(isdigit(ch))
            {
                d.push_back(ch - '0');
            }
            else
                break;
        }
        int l{d.size()};
        bool done{false};
        int m{l/2};
        for(int i=0; i<m; i++)
        {
            if(d.at(i)!=d.at(l-i-1))
            {
                if(d.at(i)>d.at(l-i-1))
                    done = true;
                else
                    done = false;
                d.at(l-i-1) = d.at(i);
            }
        }
        if(!done)
        {
            bool carry{false};
            if(m*2==l)
                m--;
            while(m>=0)
            {
                if(d.at(m)==9)
                {
                    d.at(m) = d.at(l-m-1) = 0;
                    carry = true;
                }
                else
                {
                    d.at(m)++;
                    if(m!=l-m-1)
                        d.at(l-m-1)++;
                    carry = false;
                    break;
                }
                m--;
            }
            if(carry)
            {
                cout<< "1";
                d.at(l-1) = 1;
            }
        }
 
 
        ///
        for(auto i: d)
            cout<< i;
        cout<< endl;
    }

    return 0;
}