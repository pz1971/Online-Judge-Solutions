#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;
 
bool divisible(string a, int b){
    int mod = 0;
    for(char ch : a){
        mod = ( mod * 10 ) + ( ch - '0' ) ;
        mod %= b;
    }
    return (mod == 0);
}
 
string bfs(int n){
    queue<string> q;
    q.push("1");
    string s;
    while(!q.empty()){
        s = q.front();  q.pop();
        if(divisible(s + "0", n))
            return s + "0";
        if(divisible(s + "1", n))
            return s + "1";
        q.push(s+"0");
        q.push(s+"1");
    }
}
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t, n;
    cin>> t;
    while(t--){
        cin>> n;
        cout<< bfs(n)<< endl;
    }
 
    return 0;
} 