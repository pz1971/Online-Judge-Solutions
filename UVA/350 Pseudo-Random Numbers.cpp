#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

int z, i, m, l ;

inline int next_rand(int cur){
	return ((z * cur) + i) % m ;
}

int main(){

	int tc = 0 ;
	
	while(cin >> z >> i >> m >> l){
		if((z | i | m | l) == 0)
			break ;
		
		map<int,int> mp ;
		int cur = l, nxt, id = 1 ;
		mp[cur] = id++ ;

		while(1){
			nxt = next_rand(cur) ;
			
			if(mp[nxt]){
				cout<< "Case " << ++tc << ": " << id - mp[nxt] << endl ;
				break ;
			}

			mp[nxt] = id++ ;
			cur = nxt ;
		}
	}

	return 0;
}