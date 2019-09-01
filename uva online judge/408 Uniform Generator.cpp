#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y)
{
    if (y == 0)
        return x;

    return gcd(y, x % y);
}

int main()
{
///   ///   ///   ///   ///   ///   ///


    int a{}, b{};
    while(cin>> a>> b)
    {

        printf("%10d%10d    ", a, b);
        gcd(a, b)==1 ? cout<<"Good" : cout<< "Bad";
        cout<< " Choice"<< endl<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}
