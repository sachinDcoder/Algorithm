#include<stdio.h>
void addSub(int n,int a[][n],int b[][n],int t[][n],const int f)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(f==1)
                t[i][j]=a[i][j]+b[i][j];
            else
                t[i][j]=a[i][j]-b[i][j];
}
void strassenMultiply(int n,int a[][n],int b[][n],int c[][n])
{
    int i,j;
    if(n<=2)
    {
        int p,q,r,s,t,u,v,c11,c12,c21,c22;
        p=(a[0][0]+a[1][1])*(b[0][0]+b[1][1]);//p=(a11+a22)*(b11+b22);
        q=(a[1][0]+a[1][1])*b[0][0];//q=(a21+a22)*b11;
        r=a[0][0]*(b[0][1]-b[1][1]);//r=a11*(b12-b22);
        s=a[1][1]*(b[1][0]-b[0][0]);//s=a22*(b21-b11);
        t=(a[0][0]+a[0][1])*b[1][1];//t=(a11+a12)*b22;
        u=(a[1][0]-a[0][0])*(b[0][0]+b[0][1]);//u=(a21-a11)*(b11+b12);
        v=(a[0][1]-a[1][1])*(b[1][1]+b[1][0]);//v=(a12-a22)*(b22+b21);
        c[0][0]=p+s-t+v;//c11=p+s-t+v;
        c[0][1]=r+t;//c12=r+t;
        c[1][0]=q+s;//c21=q+s;
        c[1][1]=p+r-q+u;//c22=p+r-q+u;
    }
    else
    {
        int m=n/2;
        int a11[m][m],a12[m][m],a21[m][m],a22[m][m];
        int b11[m][m],b12[m][m],b21[m][m],b22[m][m];
        int c11[m][m],c12[m][m],c21[m][m],c22[m][m];
        int p[m][m],q[m][m],r[m][m],s[m][m],t[m][m],u[m][m],v[m][m];
        int t1[m][m],t2[m][m];

        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                a11[i][j]=a[i][j];
                a12[i][j]=a[i+m][j];
            }
        }
        addSub(m,a11,a22,t1,1);
        addSub(m,b11,b22,t2,1);
        strassenMultiply(m,t1,t2,p);//p=(a11+a22)*(b11+b22);

        addSub(m,a21,a22,t1,1);
        strassenMultiply(m,t1,b11,p);//q=(a21+a22)*b11;

        addSub(m,b12,b22,t1,0);
        strassenMultiply(m,a11,t1,p);//r=a11*(b12-b22);

        addSub(m,b21,b11,t1,0);
        strassenMultiply(m,a22,t1,p);//s=a22*(b21-b11);

        addSub(m,a11,a12,t1,1);
        strassenMultiply(m,t1,b22,p);//t=(a11+a12)*b22;
    }
}
int main()
{

}
