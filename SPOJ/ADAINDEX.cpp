#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

class node{
public:
	int cnt ;
	node *child[26] ;
	node(){
		cnt = 0 ;
		for(int i = 0 ; i < 26 ; i++)
			child[i] = nullptr ;
	}
};

void insert(node *root, const string &str){
	node *cur = root ;
	for(auto i : str){
		if(cur -> child[i - 'a'] == nullptr)
			cur -> child[i - 'a'] = new node() ;
		cur = cur -> child[i - 'a'] ;
		cur -> cnt++ ;
	}
}

int search(node *root, const string &str){
	node *cur = root ;
	for(auto i : str){
		if(cur -> child[i - 'a'] == nullptr)
			return 0 ;
		cur = cur -> child[i - 'a'] ;
	}
	return cur -> cnt ;
}

int main(){

	node *trie = new node() ;

	int n, q ;
	cin >> n >> q ;
	string str ;

	while(n--){
		cin >> str ;
		insert(trie, str) ;
	}
	
	while(q--){
		cin >> str ;
		cout << search(trie, str) << endl ;
	}

	return 0;
}