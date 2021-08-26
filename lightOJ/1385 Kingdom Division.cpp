#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int t;
	double a, b, c, x, y;
	
    cin>> t;
	cout<< fixed<< showpoint<< setprecision(6);

	for(int tc = 1; tc<=t; tc++){
		cin>> a>> b>> c;
	
    	if(b * b == a * c){
			cout<< "Case "<< tc<< ": -1\n";
			continue;
		}
	
    	y = (b + c) * (a * c) / (b*b - a*c);
		x = y * (b / c) - a;
	
    	if(x + y < 0){
			cout<< "Case "<< tc<< ": -1\n";
			continue;
		}
	
    	cout<< "Case "<< tc<< ": "<< x+y<< endl;
	}

	return 0;
}