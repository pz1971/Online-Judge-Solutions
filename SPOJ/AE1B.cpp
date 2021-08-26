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
 
    int n, k, s;
    cin>> n>> k>> s;
    k *= s;
    vi ar;
    while(n--)
    {
        cin>> s;
        ar.push_back(s);
    }
    sort(ar.begin(), ar.end(), greater<int>());
    s = 0;
    for(auto i: ar)
    {
        if(k<=0)    break;
        k -= i;
        s++;
    }
    cout<< s<< endl;

    return 0;
}
 