#include<iostream>
using namespace std;
/*void fun(int dmy)
{
    if(dmy==0)
        return;
    fun(dmy>>1);
    if((dmy & 1) == 0)
            cout<<0;
    else
        cout<<1;
    //dmy=dmy>>1;
}*/
int main()
{
    //int x=pow(2,32)-1;
    int num;
    cin>>num;
    int dmy=num;
    fun(dmy);
    while(dmy!=0)
    {
        //cout<<"(dmy & 1) :"<<(dmy & 1)<<endl;
        if((dmy & 1) == 0)
            cout<<0;
        else
            cout<<1;
        dmy=dmy>>1;
    }

    return 0;
}
