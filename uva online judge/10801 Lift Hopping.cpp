#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int vis[105], T[105];
VI lift_goes[105], floor_has[105];

void clearALL(){
	for(int i=0; i<105; i++){
		lift_goes[i].clear();
		floor_has[i].clear();
		T[i] = 0;
		vis[i] = INT_MAX;
	}
}

struct node{
	int time, floor, lift;
	node(int _time, int _floor, int _lift){
		time = _time;
		floor = _floor;
		lift = _lift;
	}
};

struct cmp{
	bool operator()(const node &n1, const node &n2){
		return (n1.time > n2.time );
	}
};

int n, k;

int djakstra(){
	priority_queue<node, vector<node>, cmp> pq;
	for(auto i: floor_has[0]){
		pq.push(node(0, 0, i));
	}
	vis[0] = 0;

	while(!pq.empty()){
		node cur = pq.top();
		pq.pop();
		
		if(cur.floor == k)
			return cur.time;

		for(auto L : floor_has[cur.floor]){
			for(auto F : lift_goes[ L ]){
				if(L == cur.lift){
					if(vis[F] > cur.time + abs(F - cur.floor) * T[L]){
						vis[F] = cur.time + abs(F - cur.floor) * T[L] ;
						pq.push( node(vis[F] , F, L) );
					}
				}

				else{
					if(vis[F] > cur.time + abs(F - cur.floor) * T[L] + 60){
						vis[F] = cur.time + abs(F - cur.floor) * T[L] + 60 ;
						pq.push( node(vis[F] , F, L) );
					}
				}
			}
		}
	}

	return INT_MAX;
}

int main(){

	stringstream ss;
	string s;
	int v, ans;

	while(cin >> n>> k){
		clearALL();

		for(int i=1; i<=n; i++)
			cin>> T[i];
		cin.ignore();

		for(int i=1; i<=n; i++){
			getline(cin, s);
			ss.clear();
			ss << s;

			while (ss >> v)
			{
				lift_goes[i].push_back(v);
				floor_has[v].push_back(i);
			}	
		}

		ans = djakstra();
		if(ans == INT_MAX)
			cout<<  "IMPOSSIBLE"<< endl;
		else 
			cout<< ans<< endl;
	}

	return 0;
}