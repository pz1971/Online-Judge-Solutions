#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define sf(a) scanf("%d", &a)
#define sff(a, b) scanf("%d %d", &a, &b)
typedef long long ll;
using namespace std;
 
string s;
ll common(){
    int l = s.size();
    int ar[l+1];
    ar[0] = 0;
    int c = 0;
    for(int i=1; i<l; ){
        if(s[c]==s[i])
            ar[i++] = ++c;
        else if(!c)
            ar[i++] = 0;
        else
            c = ar[c-1];
    }
    return c;
}
 
int main(){
 
    fastIO;
    int t;
    ll k, sz, ans;
    cin>> t;
    while(t--){
        cin>> s>> k;
        sz = s.size();
        ans = sz*k - common()*(k-1);
        cout<< ans<< endl;
    }
 
    return 0;
}