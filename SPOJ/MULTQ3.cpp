#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;
 
struct node{
	int prop, zero, one, two;
} tree[400020];
 
void build(int cur, int b, int e){
	tree[cur].zero = (e - b + 1);
	if(b == e)
		return;
	int mid = (b + e) / 2;
	build(cur * 2, b, mid);
	build(cur * 2 + 1, mid + 1, e);
}
 
void update_sum(int cur){
	int temp = tree[cur].two;
	tree[cur].two = tree[cur].one;
	tree[cur].one = tree[cur].zero;
	tree[cur].zero = temp;
}
 
void update_child(int cur){
	int left = cur * 2 ;
	int right = left + 1;
 
	tree[left].prop += tree[cur].prop;
	tree[right].prop += tree[cur].prop;
	tree[cur].prop %= 3;
 
	while(tree[cur].prop){
		tree[cur].prop--;
		update_sum(left);
		update_sum(right);
	}
}
 
void update(int cur, int b, int e, int i, int j){
	if(b > j || e < i)
		return;
	if(b >= i && e <= j){
		update_sum(cur);
		tree[cur].prop = (tree[cur].prop + 1) % 3 ;
		return;
	}
 
	if(tree[cur].prop){
		update_child(cur);
	}
 
	int mid = (b + e) / 2;
	int left = cur * 2;
	int right = left + 1;
 
	update(left, b, mid, i, j);
	update(right, mid + 1, e, i , j);
 
	tree[cur].zero = tree[left].zero + tree[right].zero;
	tree[cur].one = tree[left].one + tree[right].one;
	tree[cur].two = tree[left].two + tree[right].two;
}
 
int query(int cur, int b, int e, int i, int j){
	if(b > j || e < i)
		return 0;
	if(b >= i && e <= j)
		return tree[cur].zero;
 
	if(tree[cur].prop)
		update_child(cur);
	
	int mid = (b + e) / 2;
	int left = cur * 2;
	int right = left + 1;
 
	return query(left, b, mid, i, j) + query(right, mid + 1, e, i, j);
}
 
int main(){
 
	int n, q, i, j, type;
	scanf("%d %d", &n, &q);
	
	build(1, 1, n) ;
	while(q--){
		scanf("%d %d %d", &type, &i, &j);
 
		if(type){
			printf("%d\n", query(1, 1, n, i + 1, j + 1));
		}
		else{
			update(1, 1, n, i + 1, j + 1);
		}
	}
 
	return 0;
}
