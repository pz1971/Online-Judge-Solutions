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
 
int bigMod(int a, lu b)
{
    if(b==0)    return 1;
    int x = bigMod(a, b/2)%10;
    x = (x*x)%10;
    if(b%2) x = (x*a)%10;
    return x;
}
 
int main()
{
    int t, a;
    lu b;
    cin>> t;
    while(t--)
    {
        cin>> a>> b;
        cout<< bigMod(a%10, b)<< endl;
    }
    return 0;
}
 