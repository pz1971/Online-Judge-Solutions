#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
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


    int n{}, a{}, b{};
    scanf(n);
    cout<< "Lumberjacks:"<< endl;
    while(n--)
    {
        bool incr{false}, decr{false};
        scanf(b);
        for(int i=0; i<9; i++)
        {
            scanf(a);
            if(a > b)
                incr = true;
            else if(a < b)
                decr = true;
            b = a;
        }
        if((!incr && !decr) || (incr && decr))
            cout<< "Unordered";
        else
            cout<< "Ordered";

        cout<< endl;
    }


///   ///   ///   ///   ///   ///   ///
return 0;
}
