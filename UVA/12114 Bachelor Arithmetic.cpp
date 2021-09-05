#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int tc = 0 ;
	double b, s ;
	while(cin >> b >> s){
		if(b == 0 && s == 0)	break ;
		
		cout<< "Case "<< ++tc<< ": ";

		if(b == 1)
			cout << R"(:-\)" << endl ;		// R"( )" is raw string
		else if(s / b > (s - 1.0) / (b - 1.0))
			cout << R"(:-()" << endl ;
		else
			cout << R"(:-|)" << endl ;
	}

	return 0;
}