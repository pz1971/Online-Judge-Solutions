#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cout << fixed << showpoint << setprecision(3) ;

	double x, y, c ;
	while(cin >> x >> y >> c){
		double lo = 0.0, hi = min(x, y), mid ;

		for(int i = 0 ; i < 64 ; i++){
			mid = (hi + lo) / 2 ;

			double h1 = sqrt( x*x - mid*mid ) ;
			double h2 = sqrt( y*y - mid*mid ) ;
			double val = h1*h2 / (h1+h2) ;

			if(val >= c)
				lo = mid ;
			else 
				hi = mid ;
		}

		cout << mid << endl ;
	}

	return 0;
}