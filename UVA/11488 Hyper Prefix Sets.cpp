#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

class Node{
public:
	int cnt ;
	Node *child[2] ;
	Node(){
		cnt = 0 ;
		child[0] = child[1] = nullptr ;
	}
} ;

int insert(Node *root, const string &s){
	int ret = 0 ;
	Node *cur = root ;
	int len = 0 ;
	for(auto i : s){
		if(cur -> child[i - '0'] == nullptr)
			cur -> child[i - '0'] = new Node() ;
		cur = cur -> child[i - '0'] ;
		cur -> cnt++ ;
		ret = max(ret, (++len) * cur -> cnt) ;
	}
	return ret ;
}

void clear(Node *cur){
	if(cur -> child[0]  != nullptr)
		clear(cur -> child[0]) ;
	if(cur -> child[1] != nullptr)
		clear(cur -> child[1]) ;
	delete cur ;
}

int main(){

	int t ;
	cin >> t ;

	while(t--){
		int n ;
		string s ;
		cin >> n ;

		Node *root = new Node() ;
		int mx = 0 ;
		for(int i = 0 ; i < n; i++){
			cin >> s ;
			mx = max(mx, insert(root, s)) ;
		}

		cout << mx << endl ;
		clear(root) ;
	}

	return 0;
}