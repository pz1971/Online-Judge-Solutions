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

int main(){

//    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    string keyboard = "qwertyuiop[]asdfghjkl;'\\zxcvbnm,./";
    char ch;
    while(scanf("%c", &ch)!=EOF){
        if(ch=='\n' || ch==' '){
            putchar(ch);
        }
        else{
            ch = tolower(ch);
            putchar(keyboard.at(keyboard.find(ch)-2));
        }
    }

    return 0;
}
