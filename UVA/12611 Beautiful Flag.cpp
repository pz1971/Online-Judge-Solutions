#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t ;
	cin >> t ;
	cout << fixed << noshowpoint << setprecision(0) ;

	for(int tc = 1 ; tc <= t ; tc++){
		double r ;
		cin >> r ;
		cout<< "Case "<< tc<< ":\n";

		double l = r / 20.0 * 100.0 ;
		double w = l / 100.0 * 60.0 ;

		cout << -(l / 100.0 * 45.0) << " " << w/2.0 << endl ;
		cout << (l / 100.0 * 55.0) << " " << w/2.0 << endl ;
		cout << (l / 100.0 * 55.0) << " " << -w/2.0 << endl ;
		cout << -(l / 100.0 * 45.0) << " " << -w/2.0 << endl ;
	}

	return 0;
}