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
 
int main(){
 
    fastIO;
    int t;
    cin>> t;
    while(t--){
        int n;
        cin>> n;
        n++;
        
        int ar[n+1], br[n+1];
        for(int i=1; i<=n; i++) cin>> ar[i];
        for(int i=1; i<=n; i++) cin>> br[i];
        
        ll ans[2*n];
        memset(ans, 0, sizeof(ll)*2*n);
        
        int start = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                ans[start+j] += ar[i]*br[j];
            }
            start++;
        }
        
        n = 2*n;
        cout<< ans[1];
        for(int i=2; i<n; i++)
            cout<< " "<< ans[i];
        cout<< endl;
    }
 
    return 0;
}
