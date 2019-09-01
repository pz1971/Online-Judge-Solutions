#include <bits/stdc++.h>
#define vi vector<int>
typedef long long ll;
typedef unsigned long long llu;
typedef unsigned int ui;
typedef unsigned long lu;
using namespace std;
void scanf(ui &n)
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
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
///   ///   ///   ///   ///   ///   ///


    ui t, n{}, i{};
    double tax{};
    scanf(t);
    while(++i <= t)
    {
        scanf(n);
        tax = 0;
        cout<< "Case "<< i<< ": ";
        if(n>1180000)
        {
            tax += (n-1180000)/4.0;
            n = 1180000;
        }
        if(n>880000)
        {
            tax += (n-880000)/5.0;
            n = 880000;
        }
        if(n>480000)
        {
            tax += (n-480000)*(15/100.0);
            n = 480000;
        }
        if(n>180000)
        {
            tax += (n-180000)/10.0;
            n = 0;
        }
        if(tax>0.0 && tax<2000.0)
            tax = 2000;
        cout<< static_cast<int>(ceil(tax))<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}
