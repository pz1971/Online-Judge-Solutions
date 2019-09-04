#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int t;
	cin >> t ;

	for(int tc = 1 ; tc <= t ; tc++){
		LL ax, ay, bx, by ;
		cin >> ax >> ay >> bx >> by ;
		
		LL mx = (ax - bx) , my = (ay - by) ;
		LL g = __gcd(mx, my) ;
		if(g < 0LL)
			g = 0LL - g ;

		cout<< "Case "<< tc<< ": "<< g + 1<< "\n";
	}

	return 0;
}