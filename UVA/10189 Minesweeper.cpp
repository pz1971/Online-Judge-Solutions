#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int n, m ;
int cnt[105][105] ;
string g[105] ;

bool valid(int x, int y){
	return (x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '*') ;
}

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1} ;
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1} ;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int fieldCnt = 0 , flag = 0;
	while(cin >> n >> m){
		if((n | m) == 0)	break ;
		if(flag)	cout << "\n" ;
		else 		flag = 1 ;

		for(int i = 0 ; i < n ; i++)
			cin >> g[i] ;
		
		memset(cnt, 0, sizeof cnt);

		for(int i = 0 ; i < n; i++){
			for(int j = 0 ; j < m ; j++){
				if(g[i][j] == '*'){
					cnt[i][j] = -1 ;

					for(int k = 0 ; k < 8 ; k++){
						if(valid(i + dx[k], j + dy[k]))
							cnt[ i + dx[k] ][ j + dy[k] ]++ ;
					}
				}
			}
		}

		cout << "Field #" << ++fieldCnt << ":\n";
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				if(cnt[i][j] == -1)
					cout << '*' ;
				else 
					cout << cnt[i][j] ;
			}
			cout << "\n" ;
		}
	}

	return 0;
}
