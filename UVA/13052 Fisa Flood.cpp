#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int main(){

	cout << fixed << showpoint << setprecision(3) ;

	int test_case ;
	cin >> test_case ;
	
	for(int tc = 1 ; tc <= test_case ; tc++){
		int a, b ;
		cin >> a >> b ;
		if(!a && !b)
			cout<< "Case "<< tc<< ": " << 0.0 << " " << 0.0 << endl ;
		else{
			if(!b)
				cout<< "Case "<< tc<< ": " << 1.0 << " " << 0.0 << endl ;
			else if(b & 1)
				cout<< "Case "<< tc<< ": " << 0.0 << " " << 1.0 << endl ;
			else 
				cout<< "Case "<< tc<< ": " << 1.0 << " " << 0.0 << endl ;
		}
	}

	return 0;
}