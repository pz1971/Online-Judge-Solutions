#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

void add(string a, string b){
	if(a.size() < b.size())
		swap(a, b);
	
	while(a.back() == '0')	a.pop_back();
	while(b.back() == '0')	b.pop_back();

	string sum = "";
	int rem = 0;

	for(int i=0; i<a.size(); i++){
		rem += ((i < b.size()) ? (a[i] + b[i] - '0' - '0') : (a[i] - '0'));
		sum.push_back((rem % 10) + '0');
		rem /= 10;
	}
	while(rem){
		sum.push_back((rem % 10) + '0');
		rem /= 10;
	}
	
	auto i = sum.begin();
	while(*i == '0' && i != sum.end())	i++;
	if(i == sum.end()){
		cout<< 0<< endl;
	}
	else{
		for( ; i != sum.end(); i++)
			cout<< *i;
		cout<< endl;
	}
}

int main(){

	string a, b;
	int n;
	cin>> n;
	while(n--){
		cin>> a>> b;
		add(a, b);
	}

	return 0;
}