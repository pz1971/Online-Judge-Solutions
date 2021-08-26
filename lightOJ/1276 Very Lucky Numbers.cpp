#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

const LL MX = 1e12 ;
vector<LL> very_lucky ;
vector<LL> lucky ;
vector<LL> temp_v ;

void generate_very_lucky(int idx, LL num){
	if(idx >= lucky.size())
		return ;
	
	for(int i = idx ; i < lucky.size() ; i++){
		LL val = lucky[i] * num ;
		if(val <= 0 || val > MX)	return ;
		temp_v.push_back(val) ;
		generate_very_lucky(i, val) ;
	}
}

void generate(){
	queue<LL> q ;
	
	q.push(4);	q.push(7) ;
	lucky.push_back(4) ;
	lucky.push_back(7) ;

	while(!q.empty()){
		LL cur = q.front() ;
		q.pop() ;
		
		if(cur * 10 + 4 <= MX){
			q.push(cur * 10 + 4) ;
			lucky.push_back(cur * 10 + 4) ;
		}
		if(cur * 10 + 7 <= MX){
			q.push(cur * 10 + 7) ;
			lucky.push_back(cur * 10 + 7) ;
		}
	}


	sort(lucky.begin(), lucky.end()) ;
	
	generate_very_lucky(0, 1) ;
	sort(temp_v.begin(), temp_v.end()) ;

	very_lucky.push_back(temp_v.front()) ;
	for(auto i: temp_v){
		if(i > very_lucky.back())
			very_lucky.push_back(i) ;
	}
}

int _lower_bound(LL x){
	int l = 0, u = very_lucky.size()-1, mid, ret = -1 ;
	
	while(l <= u){
		mid = (l + u) >> 1 ;
		
		if(very_lucky[mid] >= x){
			ret = mid ;
			u = mid - 1 ;
		}
		else{
			l = mid + 1 ;
		}
	}

	return ret ;
}

int _upper_bound(LL x){
	int l = 0, u = very_lucky.size()-1, mid, ret = -1 ;
	
	while(l <= u){
		mid = (l + u) >> 1 ;
		
		if(very_lucky[mid] <= x){
			ret = mid ;
			l = mid + 1 ;
		}
		else{
			u = mid - 1 ;
		}
	}

	return ret ;
}

int main(){

	generate() ;

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t ;
	cin >> t ;

	for(int tc = 1 ; tc <= t ; tc++){
		LL a, b;
		cin >> a >> b ;

		int l = _lower_bound(a) ;
		int u = _upper_bound(b) ;

		if(l == -1 || u == -1 || l > u){
			cout<< "Case "<< tc<< ": 0" << endl ;
		}
		else{
			cout<< "Case "<< tc<< ": "<< u - l + 1 << endl;
		}
	}

	return 0;
}
