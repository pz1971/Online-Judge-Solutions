#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	LL s;
	while(cin >> s){
		if(!s)	break ;

		LL l, u;
		l = sqrt(s);
		u = l+1;
		l = l*l;
		u = u*u;
		
		if(s == l || s == u){
			if(s%2){
				cout<< 1<< " " <<(int)sqrt(s)<< endl;
			}
			else{
				cout<< (int)sqrt(s)<< " "<< 1<< endl;
			}
			continue;
		}

		if(l%2==0){
			if(s <= (l+1+u)/2){
				cout<< (int)(sqrt(u))<< " "<< s - l<< endl;
			}
			else{
				cout<< u-s+1 <<" "<< (int)(sqrt(u))<< endl;
			}
		}
		else{
			if(s <= (l+1+u)/2){
				cout<< s-l<< " "<< (int)sqrt(u)<< endl;
			}
			else{
				cout<< (int)sqrt(u)<< " "<< u-s+1<< endl;
			}
		}
	}

	return 0;
}