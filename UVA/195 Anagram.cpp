#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

bool cmp(char a, char b){
	if(tolower(a) == tolower(b)){
		return a<b;
	}
	return tolower(a) < tolower(b);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t ;
	cin >> t ;
	while(t--){
		string s ;
		cin >> s ;

		sort(s.begin(), s.end(), cmp) ;
		cout << s << endl ;
		while(next_permutation(s.begin(), s.end(), cmp)){
			cout << s << endl ;
		}
	}

	return 0;
}