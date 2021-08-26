#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const vector<string> letter{
	" " ,
	".,?\"" ,
	"abc" ,
	"def" ,
	"ghi" ,
	"jkl" ,
	"mno" ,
	"pqrs" ,
	"tuv" ,
	"wxyz" ,
} ;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_case ;
	cin >> test_case ;

	int ar[105] ;
	
	while(test_case--){
		int l ;
		cin >> l ;
		for(int i = 0 ; i < l ; i++)
			cin >> ar[i] ;
		
		int p ;
		for(int i = 0 ; i < l ; i++){
			cin >> p ;
			cout << letter[ ar[i] ][ (--p) % (int) letter[ ar[i] ].size() ] ;
		}

		cout << endl ;
	}

	return 0;
}