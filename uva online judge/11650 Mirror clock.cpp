#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t, h, m, mh, mm;
    char c;
    cin >> t;
    for( ; t>0; t--)
    {
        cin >> h >> c >> m;

        if(m==0)
            mm = m;
        else
            mm = 60 - m;
        mh = 12-h;

        if(m!=0)
            mh--;
        if(mh<=0)
            mh+=12;

        printf("%02d:%02d\n", mh, mm);
    }
    return 0;
}

