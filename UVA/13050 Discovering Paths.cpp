#include <bits/stdc++.h>
using   namespace  std ;
typedef long   long LL ;

const int mx = 2005 ;
const int mod = 912 ;

const int limNcr = mx ;
int NCR[limNcr][limNcr];

void preprocess(){
    NCR[0][0] = 1;
    for(int i=1; i<limNcr; i++){
        for(int j = 0; j<limNcr ; j++){
            if(j > i)   NCR[i][j] = 0 ;
            else if(j == i || j == 0)   NCR[i][j] = 1 ;
            else NCR[i][j] = (NCR[i-1][j-1] + NCR[i-1][j]) % mod;
        }
	}
}

int count_way(int x1, int y1, int x2, int y2){
	return NCR[ abs(x2-x1) + abs(y2-y1) ][ abs(y2-y1) ] % mod ;
}

int query(int R, int C, int a, int b, int c, int d){
	int ret = 0 ;

	int x = c + 1, y = b - 1 ;
	while(x < R && y >= 0){
		ret = (ret + count_way(0, 0, x, y) * count_way(x, y, R-1, C-1)) % mod ; 
		x++ ; y-- ;	
	}

	x = a - 1, y = d + 1 ;
	while(x >= 0 && y < C){
		ret = (ret + count_way(0, 0, x, y) * count_way(x, y, R-1, C-1)) % mod ; 
		x-- ; y++ ;
	}

	return ret ;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	preprocess() ;

	int test_case ;
	cin >> test_case ;
	
	for(int tc = 1 ; tc <= test_case ; tc++){
		int R, C, q ;
		cin >> R >> C >> q ;

		cout << "Case " << tc << endl ;
		for(int qq = 1 ; qq <= q ; qq++){
			int a, b, c, d ;
			cin >> a >> b >> c >> d ;
			cout << "   Query " << qq << ": " << query(R, C, a, b, c, d) << endl ;
		}
	}

	return 0;
}