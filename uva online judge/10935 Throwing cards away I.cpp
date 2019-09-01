#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

VI discarded[52];
int remained[52];

void generate(){
	VI ar;

	for(int n=1; n < 52; n++){
		ar.push_back(n);
		VI temp{ar};
		
		bool x = true;
		for(int i=0; i + 1 < temp.size(); i++){
			if(x){
				discarded[n].push_back(temp[i]);
				x = false;
			}
			else{
				temp.push_back(temp[i]);
				x = true;
			}
		}
		
		remained[n] = temp.back();
	}
}

int main(){

	generate();

	int n;
	while(cin>> n && n != 0){
		cout<< "Discarded cards:";
		if(!discarded[n].empty()){
			cout<< " "<< discarded[n][0];
			for(int i=1; i < discarded[n].size(); i++)
				cout<< ", "<< discarded[n][i];
		}
		cout<< endl<< "Remaining card: "<< remained[n]<< endl;
	}

	return 0;
}