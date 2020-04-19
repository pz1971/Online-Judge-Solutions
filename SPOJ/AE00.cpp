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
 
int main()
{

    int n, sum{};
    cin>> n;
    if(n<4)
    {
        cout<< n<< endl;
        return 0;
    }
 
    for(int i=1; i*i <= n; i++)
    {
        sum +=  (n - i * i) / i + 1 ;
    }
 
    cout<< sum << endl;

    return 0;
} 