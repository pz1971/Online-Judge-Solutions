#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	cout<< fixed<< showpoint<< setprecision(4);
	int t;
	string s;

	cin>> t;
	cin.ignore();
	getline(cin, s);

	while(t--){
		map<string, double> ar;
		set<string> species;
		double n = 0.0;

		while(getline(cin, s)){
			if(s.empty())	break;

			species.insert(s);
			ar[s]++;	n++;
		}

		for(auto i : species){
			cout<< i<< " "<< ( ( ar[i] / n ) * 100.0 ) << endl;
		}

		if( t )		cout << endl ;
	}

	return 0;
}