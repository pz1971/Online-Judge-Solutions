#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int ar[100005];

struct node{
	int leftElem, rightElem;
	int leftCnt, rightCnt, freq;
}tree[400020];

void build(int cur, int b, int e){
	if(b == e){
		tree[cur].freq = tree[cur].leftCnt = tree[cur].rightCnt = 1;
		tree[cur].rightElem = tree[cur].leftElem = ar[e] ;
		return;
	}

	int mid = (b + e) / 2;
	int left = cur * 2;
	int right = cur * 2 + 1;

	build(left, b, mid);
	build(right, mid + 1, e);

	tree[cur].leftElem = tree[left].leftElem;
	tree[cur].rightElem = tree[right].rightElem;
	tree[cur].leftCnt = tree[left].leftCnt;
	tree[cur].rightCnt = tree[right].rightCnt;
	tree[cur].freq = max(tree[left].freq, tree[right].freq);

	if(tree[left].rightElem == tree[right].leftElem){
		tree[cur].freq = max(tree[cur].freq, tree[left].rightCnt + tree[right].leftCnt);
		if(tree[left].rightElem == tree[left].leftElem)
			tree[cur].leftCnt += tree[right].leftCnt;
		if(tree[right].rightElem == tree[right].leftElem)
			tree[cur].rightCnt += tree[left].rightCnt;
	}
}

int query(int cur, int b, int e, int i, int j){
	if(b > j || e < i)
		return 0;
	if(b >= i && e <= j)
		return tree[cur].freq;
	
	int mid = (b + e) / 2;
	int left = cur * 2;
	int right = cur * 2 + 1;

	int ret = query(left, b, mid, i, j);
	ret = max(ret, query(right, mid + 1, e, i, j));

	if(tree[left].rightElem == tree[right].leftElem){
		ret = max(ret, (min(mid - i + 1, tree[left].rightCnt) + min(j - mid, tree[right].leftCnt)) );
	}

	return ret;
}

int main(){

	int n, q, i, j;
	while(scanf("%d", &n) != EOF && n){
		scanf("%d", &q);
		for(int i=1; i<=n; i++)
			scanf("%d", &ar[i]);
		build(1, 1, n);
		while(q--){
			scanf("%d %d", &i, &j);
			printf("%d\n", query(1, 1, n, i, j));
		}
	}

	return 0;
}