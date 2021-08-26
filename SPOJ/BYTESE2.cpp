#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int main(){

	int t ;
	scanf("%d", &t);

	while(t--){
		int n ;
		scanf("%d", &n);

		int in, out ;
		vector<pair<int,int> >	vp ;	// second = 0 if in, else 1

		for(int i = 0 ; i < n ; i++){
			scanf("%d %d", &in, &out);
			vp.push_back({in, 0}) ;
			vp.push_back({out, 1}) ;
		}

		sort(vp.begin(), vp.end()) ;
		
		int cnt = 0 ;	// in +1, out -1 ;
		int mx = 0 ;

		for(auto i : vp){
			if(i.second == 0){
				cnt++ ;
				mx = max(mx, cnt) ;
			}
			else{
				cnt-- ;
			}
		}

		printf("%d\n", mx);
	}

	return 0;
}