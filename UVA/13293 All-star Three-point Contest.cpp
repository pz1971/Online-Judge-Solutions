#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

char _tolower(char ch){
	if(ch >= 'A' && ch <= 'Z')
		return ch - 'A' + 'a' ;
	return ch ;
}

bool lessss(const string &a, const string &b){
	string x = a , y = b ;
	for(auto &i : x)
		i = _tolower(i) ;
	for(auto &i : y)
		i = _tolower(i) ;
	return x < y ;
}

class cmp{
public: 
	bool operator () (const pair<string, int> &a, const pair<string, int> &b){
		if(a.second == b.second)
			return (lessss(a.first, b.first)) ;
		return (a.second > b.second) ;
	}
} ;

int main(){

	int tc = 0 ;
	int n ;
	string line ;

	while(cin >> n){
		cin.ignore() ;

		vector<pair<string, int> > player(n) ; 	
		for(int i = 0 ; i < n; i++){
			getline(cin, line) ;
			
			player[i].first = line.substr(0, line.find(';')) ;
			player[i].second = 0 ;
			line = line.substr(player[i].first.size()) ;

			int c = 0 ;
			for(int j = 0 ; j < line.size() ; j++){
				if(line[j] == ' ' || line[j] == ';')	continue ;

				player[i].second += ( (line[j] - '0') * ( c == 4 ? 2 : 1 ) ) ;
				c = (c + 1) % 5 ;
			}
		}

		sort(player.begin(), player.end(), cmp()) ;
		
		cout<< "Case "<< ++tc<< ":" << endl ;
		for(auto &i : player)
			cout << i.first << " " << i.second << endl ;
	}

	return 0;
}