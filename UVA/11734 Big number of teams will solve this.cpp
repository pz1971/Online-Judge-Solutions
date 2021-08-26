#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, t;

    while(cin>> t)
    {
        ///getchar();
        for(j=1; j<=t; j++)
        {
            getchar();
            string s2;
            vector <char> s1;
            vector <char> s3;

            for(i=0; i<23; i++)
            {
                char ch;
                scanf("%c" , &ch);
                if(ch != '\n')
                {
                    s1.push_back(ch);
                    if(ch!=' ')
                        s3.push_back(ch);
                }
                else
                    break;
            }
            cin >> s2;


            ///

//            for(int k=0; k<i; k++)
//                cout<< s1.at(k);
//            cout<< endl;
//            for(int k=0; k<s3.size(); k++)
//                cout<< s3.at(k);
//            cout<< endl;
//            cout<< s2<< endl;

            ///


            bool yes{true};
            int l1, l2, l3;

            l1 = s1.size();
            l2 = s2.size();
            l3 = s3.size();

            if(l1<l2)
                cout<<"Case "<< j<< ": Wrong Answer"<< endl;
            else
            {
                if(l1==l2)
                {
                    for(i=0; i< l1; i++)
                    {
                        if(s1[i]!=s2[i])
                        {
                            yes = false;
                            break;
                        }
                    }
                    if(yes==false)
                        cout<<"Case "<< j<< ": Wrong Answer"<< endl;
                    else
                        cout<<"Case "<< j<< ": Yes"<< endl;
                }
                else if(l1>l2)
                {
                    if(l3 != l2)
                        cout<<"Case "<< j<< ": Wrong Answer"<< endl;
                    else
                    {
                        for(i=0; i<l3; i++)
                        {
                            if(s3[i]!=s2[i])
                            {
                                yes = false;
                                break;
                            }
                        }
                        if(yes == false)
                            cout<<"Case "<< j<< ": Wrong Answer"<< endl;
                        else
                            cout<<"Case "<< j<< ": Output Format Error"<< endl;

                    }
                }
            }
        }
    }
    return 0;
}
