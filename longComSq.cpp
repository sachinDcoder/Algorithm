#include<bits/stdc++.h>
using namespace std;
int lcs(string s1,string s2)
{
    int l1=s1.length();
    int l2=s2.length();
    string s="";
    int l[l1+1][l2+1];
    for(int i=0;i<=l1;i++)
    {
        for(int j=0;j<=l2;j++)
        {
            if(i==0 || j==0)
                l[i][j]=0;
            else if(s1[i-1]==s2[j-1])
            {
                l[i][j]=l[i-1][j-1]+1;
                //s+=s1[i];
            }
            else
                l[i][j]=max(l[i-1][j],l[i][j-1]);
        }
    }
    /*cout<<"   ";
    for(int j=0;j<=l2;j++)
        cout<<" "<<s2[j];
    cout<<endl;
    for(int i=0;i<=l1;i++)
    {
        if(i>=1)
            cout<<s1[i-1]<<" ";
        else
            cout<<"  ";
        for(int j=0;j<=l2;j++)
        {
            cout<<l[i][j]<<" ";
        }
        cout<<endl;
    }*/
    int i=l1,j=l2,c=l[l1][l2];
    while(i>0 && j>0 && c>0)
    {
        if(s1[i-1]==s2[j-1] && l[i-1][j-1]==c-1)
        {
            i=i-1;
            j=j-1;
            //cout<<s1[i]<<endl;
            s+=s1[i];
            c--;
        }
        else if(l[i][j-1]==c)
        {
            j=j-1;
        }
        else if(l[i-1][j]==c)
        {
            i=i-1;
        }
    }
    reverse(s.begin(),s.end());
    cout<<"Longest Common subsequence: "<<s<<endl;
    return l[l1][l2];
}
int main()
{
    string s1,s2;
    cout<<"Enter the first string: ";
    cin>>s1;
    cout<<"Enter the second string: ";
    cin>>s2;
    int l=lcs(s1,s2);
    cout<<"length of lcs: "<<l<<endl;
    return 0;
}
/*abcdaf
acbcf*/
