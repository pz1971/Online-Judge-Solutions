#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
typedef unsigned int ui;
typedef long int li;
typedef unsigned long lu;
typedef long long ll;
typedef unsigned long long llu;
using namespace std;
//void scanf(int &n)
//{
//    bool negative = false;
//    char c;
//    n = 0;
//    c = getchar();
//    if (c=='-')
//    {
//        negative = true;
//        c = getchar();
//    }
//    for (; (c>47 && c<58); c=getchar())
//        n = n*10 + c - 48;
//    if (negative)
//        n *= -1;
//}

int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
///   ///   ///   ///   ///   ///   ///


    int t{}, n{}, a{}, b{};
    cin>> t;
    cin.ignore();
    while(t--)
    {
        getchar();
        cin>> n>> a>> b;
        int x = abs(a-b) ;
        bool y{true};
        while(--n)
        {
            cin>> a>> b;
            if(x!= abs(a-b))
                y = false;
        }
        if(y)
            cout<< "yes";
        else
            cout<< "no";
        cout<< endl;
        if(t!=0)
            cout<< endl;
    }


///   ///   ///   ///   ///   ///   ///
return 0;
}
