#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

inline int indx(char ch){
	switch (ch){
	case 'A':
		return 0 ;
	case 'C':
		return 1 ;
	case 'G':
		return 2 ;
	default :
		return 3 ;
	}
}

class Node{
public:
	int cnt ;
	Node *child[4] ;

	Node(){
		cnt = 0 ;
		memset(child, 0, sizeof child);
	}
} ;

int ans = 0 ;

void insert(Node *cur, const string &key){
	int len = 0 ;

	for(const auto &i : key){
		if(cur -> child[indx(i)] == nullptr)
			cur -> child[indx(i)] = new Node() ;
		
		cur = cur -> child[indx(i)] ;
		cur -> cnt++ ;

		len++ ;
		ans = max(ans, (cur -> cnt) * len) ;
	}
}

void deletePtr(Node *ptr){
	if(ptr){
		for(int i = 0 ; i < 4 ; i++){
			if(ptr -> child[i])
				deletePtr(ptr -> child[i]) ;
		}
		delete ptr ;
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t ;
	cin >> t ;

	for(int tc = 1 ; tc <= t ; tc++){
		int n ;
		cin >> n ;

		string sample ;
		Node *root = new Node() ;

		ans = 0 ;

		while(n--){
			cin >> sample ;
			insert(root, sample) ;
		}

		cout<< "Case "<< tc<< ": " << ans << endl ;
		deletePtr(root) ;
	}

	return 0;
}