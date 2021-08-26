#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

vector<string> vs;
string a, b;

bool one_diff(string x, string y){
    for(int i=0; i<x.size(); i++){
        if(x[i]!=y[i]){
            for(++i; i<x.size(); i++)
                if(x[i]!=y[i])
                    return false;
        }
    }
    return true;
}

int bfs(){
    if(a == b)  return 0;

    map<string, int> vis;
    vis[a] = 0;
    queue<string> q;
    q.push(a);

    while(!q.empty()){
        string s = q.front();
        q.pop();

        for(string i: vs){
            if(i.size() == s.size()){
                if(!vis.count(i) && one_diff(i, s)){
                    if(i == b)  return vis[s] + 1;
                    q.push(i);
                    vis[i] = vis[s] + 1;
                }
            }
        }
    }

    return 0;
}

int main(){

    int n;
    cin>> n;
    getchar();
    getchar();
    string str;
    stringstream ss;
    while(n--){
        vs.clear();
        while(getline(cin, str) && str!="*")
            vs.push_back(str);
        while(getline(cin, str) && str!=""){
            ss.clear();
            ss << str;
            ss>> a>> b;
            cout<< a<< " "<< b<< " "<< bfs()<< endl;
        }
        if(n)   cout<< endl;
    }

    return 0;
}
