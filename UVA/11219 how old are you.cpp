#include<iostream>
using namespace std;
int main()
{
    int t, i, m1, m2, d1, d2, y1, y2, m, d, y;
    char c;
    while(cin>>t)
    {
        getchar();
        for(i=1; i<=t; i++)
        {
            getchar();
            scanf("%d/%d/%d%d/%d/%d", &d1, &m1, &y1, &d2, &m2, &y2);
            d = d1 - d2;
            m = m1 - m2;
            y = y1 - y2;

            if(d < 0)
                m--;
            if(m<0)
                y--;

            cout<< "Case #"<< i<< ": ";
            if(y<0)
                cout<<"Invalid birth date"<< endl;
            else if(y>130)
                cout<< "Check birth date"<< endl;
            else
                cout<< y<< endl;

        }
    }
    return 0;
}
