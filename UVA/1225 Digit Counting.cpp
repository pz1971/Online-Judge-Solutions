#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
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

void dig_count(vi &num, int n)
{
    while(n)
    {
        num.at(n%10)++;
        n/=10;
    }
}
int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
///   ///   ///   ///   ///   ///   ///


    int t{}, x{};
    scanf(t);
    vi dig(10, 0);
    while(t--)
    {
        for(auto &i: dig)
            i = 0;
        x = 0;
        scanf(x);
        for(int i=1; i<=x; i++)
        {
            dig_count(dig, i);
        }
        for(int i=0; i<10; i++)
        {
            cout<< dig.at(i);
            if(i!=9)
                cout<< " ";
        }
        cout<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}
