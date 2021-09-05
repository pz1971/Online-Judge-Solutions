#include <bits/stdc++.h>
#define vi vector<int>
#define sf(a) scanf("%d", &a)
#define sff(a, b) scanf("%d %d", &a, &b)
typedef long long ll;
using namespace std;

int main(){
//     std::ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);

    unsigned int a, b;
    while(cin>> a>> b){
        cout<< (a^b) << endl;
    }

    return 0;
}