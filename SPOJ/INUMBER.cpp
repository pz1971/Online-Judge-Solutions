#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

class Node{
public: 
	string num ;
	int sod, rem ;

	Node(const string &num, int sod, int rem){
		this -> num = num ;
		this -> sod = sod ;
		this -> rem = rem ;
	}
} ;

string BFS(const int n){
	vector<vector<int> > mark (n + 1, vector<int> (n + 1, 0)) ;
	
	queue<Node> q ;
	Node cur("", 0, 0) ;
	q.push(cur) ;
	mark[cur.sod][cur.rem] = 1 ;

	while(!q.empty()){
		cur = q.front() ;
		q.pop() ;

		for(int i = 0 ; i < 10 ; i++){
			int t_sod = cur.sod + i ;
			int t_rem = (cur.rem * 10 + i) % n ;
			
			if(t_sod > n || mark[t_sod][t_rem] == 1)
				continue ;
			
			string t_num = cur.num + (char) (i + '0') ;

			if(t_sod == n && t_rem == 0)
				return t_num ;

			q.push(Node(t_num, t_sod, t_rem)) ;
			mark[t_sod][t_rem] = 1 ;

		}
	}
	
	return "0" ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_case ;
	cin >> test_case ;
	
	while(test_case--){
		int n ;
		cin >> n ;
		cout << BFS(n) << endl ;
	}

	return 0;
}