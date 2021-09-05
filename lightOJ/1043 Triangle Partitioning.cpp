#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define sf(a) scanf("%d", &a)
#define sff(a, b) scanf("%d %d", &a, &b)
typedef long long ll;
using namespace std;

int main(){

    int t;
    double ab, ac, bc, rat;
    sf(t);
    for(int tc = 1; tc<=t; tc++){
        scanf("%lf %lf %lf %lf", &ab, &ac, &bc, &rat);
        printf("Case %d: %.8lf\n", tc, ab*sqrt(rat/(rat+1)));
    }

    return 0;
}
