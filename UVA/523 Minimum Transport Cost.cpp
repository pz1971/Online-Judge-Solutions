#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int n, mat[505][505], tax[505];
int nxt[505][505];

void floyd_warshall(){
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			nxt[i][j] = j;
			nxt[j][i] = i;
		}
	}

	for(int k=0; k< n; k++){
		for(int i=0; i<n; i++){
			if(mat[i][k] == INT_MAX)
				continue;
			
			for(int j=i; j<n; j++){
				if(mat[k][j] == INT_MAX)
					continue;
				
				if(mat[i][j] > mat[i][k] + mat[k][j] + tax[k]){
					mat[i][j] = mat[i][k] + mat[k][j] + tax[k];
					nxt[i][j] = nxt[i][k];

					mat[j][i] = mat[i][j];
					nxt[j][i] = nxt[j][k];
				}
			}
		}
	}
}

void printPath(int i, int j){
	cout << i + 1;
	while(i != j){
		i = nxt[i][j];
		cout<< "-->"<< i + 1;
	}
	cout<< endl;
}

int main(){

	int test, u, v;
	bool fst = false;
	string line ;
	stringstream ss ;

	cin>> test;
	cin.ignore();
	getline(cin, line) ;

	while(test--){

		getline(cin, line) ;
		ss.clear();
		ss << line ;
		n = 0;

		while(ss >> mat[0][n]){
			if(mat[0][n] == -1)
				mat[0][n] = INT_MAX;
			n++;
		}
		
		for(int i=1; i<n; i++){
			for(int j=0; j<n; j++){
				cin>> mat[i][j] ;
				if(mat[i][j] == -1)
					mat[i][j] = INT_MAX;
			}
		}


		for(int i=0; i<n; i++)
			cin>> tax[i] ;
		cin.ignore();

		floyd_warshall() ;

		while(getline(cin, line)){
			if(line.empty())
				break;

			ss.clear();
			ss<< line;
			ss >> u >> v ;
			
			if(fst)	cout<< endl;
			else 	fst = true ;

			cout<< "From "<< u<<" to "<< v<< " :"<< endl;
			cout<< "Path: ";
			printPath(u-1, v-1);
			cout<< "Total cost : " << mat[u-1][v-1]<< endl;
		}
	}

	return 0;
}