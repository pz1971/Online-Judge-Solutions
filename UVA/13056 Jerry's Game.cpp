#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const double pi = acos(-1.0) ;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cout << fixed << showpoint << setprecision(8) ;

	int test_case ;
	cin >> test_case ;
	
	for(int tc = 1 ; tc <= test_case ; tc++){
		double R, V ;
		cin >> R >> V ;
		cout<< "Case "<< tc<< ": " << pi * R / (2.0 * V) << endl ;
	}

	return 0;
}