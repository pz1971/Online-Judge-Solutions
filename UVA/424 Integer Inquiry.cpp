#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <vector<int>> bigint;
    vector <int> sum;
    int m = 0;

    for(int i=0; i<100; i++)
    {
        char ch;
        vector <int> row;
        while(1)
        {
            ch = getchar();
            if(ch!= '\n')
            {
                int num = ch-48;
                row.push_back(num);
            }
            else
                break;
        }

        int l = row.size();
        if(l>m)
            m = l;
        if(l==1 && row[0] == 0)
            break;
        else
        {
            reverse(row.begin(), row.end());
            bigint.push_back(row);
        }

    }

    int l = bigint.size();
    for(int i=0; i < m; i++)
    {
        int s{0};
        for(int j=0; j<l; j++)
        {
            int k = bigint[j].size();
            if( i < k )
            {
                s += bigint[j][i];
            }
        }
        sum.push_back(s);
    }

    l = sum.size();
    int carry {0};
    for(int i=0; i<l; i++)
    {
        sum[i]+= carry;
        carry = 0;
        if(sum[i]>9)
        {
            carry += sum[i] /10;
            sum[i] %= 10;
        }
    }
    while(carry>0)
    {
        int x = carry % 10;
        sum.push_back(x);
        carry /= 10;
        l++;
    }

    reverse(sum.begin(), sum.end());

    for(int i=0; i<l; i++)
    {
        cout<< sum.at(i);
    }
    cout<< endl;
    return 0;
}