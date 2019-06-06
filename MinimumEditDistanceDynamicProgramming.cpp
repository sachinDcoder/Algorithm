#include<bits/stdc++.h>
using namespace std;

int minEdit(string s1, string s2)
{
    int l1=s1.length(), l2=s2.length();
    int table[l2+1][l1+1];

    for(int i=0;i<=l1;i++)
        table[0][i]=i;
    for(int i=0;i<=l2;i++)
        table[i][0]=i;

    for(int i=1;i<=l2;i++)
    {
        for(int j=1;j<=l1;j++)
        {
            if(s1[j-1]==s2[i-1])
                table[i][j]=table[i-1][j-1];
            else
                table[i][j]=1+min(table[i-1][j-1], min(table[i-1][j], table[i][j-1]));
        }
    }
    /*for(int i=0;i<=l2;i++)
    {
        for(int j=0;j<=l1;j++)
            cout<<table[i][j]<<" ";
        cout<<endl;
    }*/
    return table[l1][l2];
}

int main()
{
    string s1,s2;
    //cout<<"Enter 1st String : ";
    cin>>s1;
    //cout<<"Enter 2nd String : ";
    cin>>s2;
    //cout<<s1<<" "<<s2<<endl;
    cout<<minEdit(s1, s2);
    return 0;
}
/*
abcdef
azced
*/
