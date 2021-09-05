#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

bool f ;

class Node{
public:
	int completeCount, childCount ;
	Node *child[10] ;
	Node(){
		completeCount = childCount = 0 ;
		memset(child, 0, sizeof child);
	}
} ;

void insert(Node *cur, string &str){
	if(!f)	return ;

	for(auto i : str){
		cur->childCount++ ;

		if(cur -> child[i - '0'] == nullptr)
			cur -> child[i - '0'] = new Node() ;
		cur = cur -> child[i - '0'] ;
		
		if(cur -> completeCount){
			f = false ;
			return ;
		}
	}
	cur -> completeCount++ ;

	if(cur -> childCount)
		f = false ;
}

void deletePtr(Node *ptr){
	for(int i = 0 ; i < 10 ; i++)
		if(ptr -> child[i] != nullptr)
			deletePtr(ptr -> child[i]) ;
	delete ptr ;
}

int main(){

	int t, n ;
	string str ;

	cin >> t ;
	for(int tc = 1 ; tc <= t ; tc++){
		f = true ;
		cin >> n ;
		
		Node *root = new Node() ;
		while(n--){
			cin >> str ;
			insert(root, str) ;
		}

		deletePtr(root) ;
		cout<< "Case "<< tc<< ": " << (f ? "YES" : "NO") << endl ;
	}

	return 0;
}