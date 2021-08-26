#include<bits/stdc++.h>
using   namespace      std;
typedef long long      LL;
typedef vector<int>    VI;
typedef pair<int,int>  PII;

int main(){

	int t;
	cin>> t;
	cin.ignore();
	string command, link{"http://www.lightoj.com/"};

	for(int tc = 1; tc<=t; tc++){
		cout<< "Case "<< tc<< ":"<< endl;
		
		stack<string> back, forward;
		
		while(getline(cin, command)){
			if(command == "QUIT"){
				back = stack<string> ();
				forward = stack<string> ();
				link = "http://www.lightoj.com/";
				break;
			}
			
			if(command == "BACK"){
				if(back.empty()){
					cout<< "Ignored"<< endl;
				}
				else{
					forward.push(link);
					link = back.top();
					back.pop();
					cout<< link<< endl;
				}
			}

			else if(command == "FORWARD"){
				if(forward.empty()){
					cout<< "Ignored"<< endl;
				}
				else{
					back.push(link);
					link = forward.top();
					forward.pop();
					cout<< link<< endl;
				}
			}

			else{
				back.push(link);
				link = command.substr(6);
				forward = stack<string> () ;
				cout<< link<< endl;
			}
		}
	}

	return 0;
}