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

//void scanf(int &n)
// {
//     bool negative = false;
//     char c;
//     n = 0;
//     c = getchar();
//     if (c=='-')
//     {
//         negative = true;
//         c = getchar();
//     }
//     for (; (c>47 && c<58); c=getchar())
//         n = n*10 + c - 48;
//     if (negative)
//         n *= -1;
// }

int main()
{
//    std::ios::sync_with_stdio(false);
//    cin.tie(0);
///   ///   ///   ///   ///   ///   ///


    vector <llu> fib{1, 2};
    while(fib.back()< 10000000000)
        fib.push_back(fib.back()+ *(fib.end()-2));
//    for(auto i: fib)
//        cout<< i<< endl;
    int n{};
    while(cin>> n)
    {
        if(n<0)
            return 0;
        cout<< fib.at(n)-1<< " "<< fib.at(n+1)-1<< endl;
    }

///   ///   ///   ///   ///   ///   ///
    return 0;
}
