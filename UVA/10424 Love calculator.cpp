#include<bits/stdc++.h>
using namespace std;
int main(){

	string s, s2;
	cout<< fixed<< showpoint << setprecision(2);
	while(getline(cin, s)){
		getline(cin, s2);
		int n = 0, n2 = 0;
		for(int i=0; i<s.size(); i++){
			if(s[i] >= 'A' && s[i] <= 'Z'){
				n += s[i] - 'A' + 1;
			}
			else if(s[i] >= 'a' && s[i] <= 'z'){
				n += s[i] - 'a' + 1;
			}
		}

		for(int i=0; i<s2.size(); i++){
			if(s2[i] >= 'A' && s2[i] <= 'Z'){
				n2 += s2[i] - 'A' + 1;
			}
			else if(s2[i] >= 'a' && s2[i] <= 'z'){
				n2 += s2[i] - 'a' + 1;
			}
		}
		n = (n - 1) % 9 + 1;
		n2 = (n2 - 1) % 9 + 1;
		if(n > n2) swap(n, n2);
		cout<< (double)n / (double) n2 * 100.00 << " %"<< endl;
	}

	return 0;
}
