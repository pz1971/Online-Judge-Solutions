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
//double const pi = acos(-1.0);
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
//    ifstream cin{"../i_file.txt"};
//    ofstream cout{"../o_file.txt"};
///   ///   ///   ///   ///   ///   ///


    vb stat(16401, 1);
    for(int i=3; i*i<32802; i+=2)
        if(stat.at(i>>1))
            for(int j=i*i; j<32802; j+=i+i)
                stat.at(j>>1) = 0;
    int n;
    while(cin>>n && n)
    {
        int cnt{};
        if(n==4)    cnt++;
        for(int i=3; i*2<=n; i+=2)
        {
            if(stat.at(i>>1) && stat.at((n-i)>>1))
            {
                cnt++;
//                cout<< i<< " + "<< n-i<< endl;
            }
        }
        cout<< cnt<< endl;
    }


///   ///   ///   ///   ///   ///   ///
    return 0;
}