#include <bits/stdc++.h>
#define vi vector<int>
#define sf(a) scanf("%d", &a)
#define sff(a, b) scanf("%d %d", &a, &b)
typedef long long ll;
using namespace std;

vi ar;
void add(){
    int n; sf(n);
    for(int &i: ar)
        i += n;
}
void mult(){
    int n; sf(n);
    for(int &i: ar)
        i *= n;
}
void divide(){
    int n; sf(n);
    for(int &i: ar)
        i /= n;
}
void swp(){
    int x, y;   sff(x, y);
    swap(ar.at(x), ar.at(y));
}

int main(){

    int t, x;
    sf(t);

    for (int tc = 1; tc<=t; tc++){
        int n, m;
        sff(n, m);
    
        while (n--){
            sf(x);
            ar.push_back(x);
        }
    
        char op;
        while(m--){
            getchar();
            op = getchar();
            switch (op)
            {
            case 'S':
                add();
                break;
            case 'M':
                mult();
                break;
            case 'D':
                divide();
                break;
            case 'P':
                swp();
                break;
            default:
                reverse(ar.begin(), ar.end());
                break;
            }
        }

        x = ar.size()-1;
        printf("Case %d:\n", tc);

        for(int i=0; i<x; i++)
            printf("%d ", ar.at(i));
        
        printf("%d\n", ar.back());
        ar.clear();
    }

    return 0;
}
