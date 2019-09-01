#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define clr(a) memset(a, 0, sizeof a)
#define sf(a) scanf("%d", &a)
#define sff(a, b) scanf("%d %d", &a, &b)
typedef long long ll;
using namespace std;

string keyboard = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
char key[500];

int main(){

    for(int i=1; i<keyboard.size(); i++){
        key[keyboard[i]] = keyboard[i-1];
    }

    string s;
    while(getline(cin, s)){
        for(char ch: s){
            if(ch==' ')
                cout<< ch;
            else
                cout<< key[(int)ch];
        }
        cout<< endl;
    }

    return 0;
}
