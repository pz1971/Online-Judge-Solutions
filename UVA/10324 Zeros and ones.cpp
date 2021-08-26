#include <bits/stdc++.h>
#define vi vector<int>
typedef unsigned int ui;
typedef long int li;
typedef unsigned long lu;
typedef long long ll;
typedef unsigned long long llu;
using namespace std;
void scanf(int &n)
{
    bool negative = false;
    char c;
    n = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        n = n*10 + c - 48;
    if (negative)
        n *= -1;
}

int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
///   ///   ///   ///   ///   ///   ///


    string s;
    int a, b, n, t{};
    while(cin>> s)
    {
        cin.ignore();
        t++;
        cout<< "Case "<< t<< ":"<<endl;
        scanf(n);
        while(n--)
        {
            scanf(a); scanf(b);
            if(a>b)
                swap(a, b);
            bool yes{true};
            for( ; a<b; a++)
            {
                if(s.at(a)!=s.at(a+1))
                {
                    yes = false;
                    cout<< "No"<< endl;
                    break;
                }
            }
            if(yes)
                cout<< "Yes"<< endl;
        }
    }


///   ///   ///   ///   ///   ///   ///
return 0;
}
