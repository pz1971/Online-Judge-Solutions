#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

deque<string> firstHalf, secondHalf;
map<string, int> cnt;

int main(){

	int t, n;
	string s;

	cin>> t;
	while(t--){
		cnt.clear();
		firstHalf.clear();
		secondHalf.clear();

		cin>> n;
		while(n--){
			cin>> s;
			cnt[s]++;
		}

		while(cnt["aa"] > 1){
			cnt["aa"] -= 2;
			firstHalf.push_back("aa");
			secondHalf.push_front("aa");
		}
		
		while(cnt["ab"] > 0 && cnt["ba"] > 0){
			cnt["ab"]--;	cnt["ba"]--;
			firstHalf.push_back("ab");
			secondHalf.push_front("ba");
		}
		
		while(cnt["bb"] > 1){
			cnt["bb"] -= 2;
			firstHalf.push_back("bb");
			secondHalf.push_front("bb");
		}

		if(cnt["aa"] > 0){
			firstHalf.push_back("aa");
		}
		else if(cnt["bb"] > 0){
			firstHalf.push_back("bb");
		}

		for(auto i: firstHalf)
			cout<< i;
		for(auto i: secondHalf)
			cout<< i;
		cout<< endl;
	}

	return 0;
}
