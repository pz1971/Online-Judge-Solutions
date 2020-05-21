#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

vector<pair<string, string> > get_dictionary(string &s){
	vector<pair<string, string> > ret ;
	string key, val ;
	s.back() = ',' ;

	for(int i = 1 ; i < s.size() ; i++){
		if(s[i] == ':'){
			key = val ;
			val.clear() ;
		}
		else if(s[i] == ','){
			if(!key.empty())
				ret.push_back({key, val}) ;
			key.clear(), val.clear() ;
		}
		else {
			val.push_back(s[i]) ;
		}
	}
	
	return ret ; 
} 

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int test_cases ;
	cin >> test_cases ;
	cin.ignore() ;
	
	for(int tc = 1 ; tc <= test_cases ; tc++){
		string line ;
		getline(cin, line) ;
		vector<pair<string, string> > dic1 = get_dictionary(line) ;
		getline(cin, line) ;
		vector<pair<string, string> > dic2 = get_dictionary(line) ;

		map<string, string> mp1, mp2 ;
		for(auto &i : dic1)
			mp1[i.first] = i.second ;
		for(auto &i : dic2)
			mp2[i.first] = i.second ;
		
		vector<string> added, cleared, changed ;
		for(auto &i : dic2){
			if(!mp1.count(i.first)){
				added.push_back(i.first) ;
			}
			else if(mp1[i.first] != i.second){
				changed.push_back(i.first) ;
			}
		}
		for(auto &i : dic1){
			if(!mp2.count(i.first)){
				cleared.push_back(i.first) ;
			}
		}
		
		bool f = 0 ;
		sort(added.begin(), added.end()) ;
		for(auto &i : added){
			if(f)	cout << ',' << i ;
			else {
				f = 1 ;
				cout << '+' << i ;
			}
		}
		if(f)	cout << endl ;
		f = 0 ;
		sort(cleared.begin(), cleared.end()) ;
		for(auto &i : cleared){
			if(f)	cout << ',' << i ;
			else {
				f = 1 ;
				cout << '-' << i ;
			}
		}
		if(f)	cout << endl ;
		f = 0 ;
		sort(changed.begin(), changed.end()) ;
		for(auto &i : changed){
			if(f)	cout << ',' << i ;
			else {
				f = 1 ;
				cout << '*' << i ;
			}
		}
		if(f)	cout << endl ;

		if(added.empty() && changed.empty() && cleared.empty()){
			cout << "No changes" << endl ;
		}
		cout << endl ;
	}

	return 0;
}