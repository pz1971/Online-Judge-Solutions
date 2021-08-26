#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;
 
int n, q;
int ar[100005];
int tree[3 * 100005];
 
void init(int node, int b, int e){
    if(b == e){
        tree[node] = ar[b];
        return;
    }
 
    int mid = (b + e) / 2;
    init(node*2,  b, mid);
    init(node*2 + 1, mid + 1, e);
 
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
 
int query(int node, int b, int e, int i, int j){
    if(i <= b && j >= e){
        return tree[node];
    }
    if(i > e || j < b)
        return INT_MAX;
   
    int mid = (b + e) / 2;
    int x = query(node * 2, b, mid, i, j);
    int y = query(node * 2 + 1, mid + 1, e, i, j);
 
    return min(x, y);
}
 
int main(){
 
    int t, I, J;
    scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++){
        scanf("%d %d", &n, &q);
        for(int i=1; i<=n; i++){
            scanf("%d", &ar[i]);
        }
 
        init(1, 1, n);
        printf("Case %d:\n", tc);
 
        while(q--){
            scanf("%d %d", &I, &J);
            printf("%d\n", query(1, 1, n, I, J));
        }
    }
 
    return 0;
}
