#include<bits/stdc++.h>
using namespace std;
bool f(long a[],int l,int r,long k) //tìm kiếm nhị phân số k trong mảng a từ vị trí r đến l
{
    long i;
    while (l <= r)
    {
        i= (l+ r) / 2;
        if (a[i] == k) return true; // tìm thấy k, trả về m là vị trí của x trong mảng A
        if (a[i] > k) r = i - 1; // Giới hạn khoảng tìm kiếm lại là nửa khoảng trước
        else if (a[i] < k)   l = i + 1; // Giới hạn khoảng tìm kiếm lại là nửa khoảng sau
    }
    return false; // không tìm thấy x
}
int main()
{
    int n,i,d=0,x;
    cin>>n;
    long a[n+1],b[n+1];
    b[0]=0;
    for(i=1;i<=n;i++){cin>>a[i];b[i]=b[i-1]+a[i];}
    for(i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
    {
        if(d<(j-i+1))  //khoảng cách lớn nhất
        {x=b[i-1]+b[j]; //tổng từ i đến j
         if((x%2==0)&&(f(b,i,j,x/2)==1))  d=j-i+1;}//nếu tổng chẵn và tìm thấy tổng /2 trong mảng b
    }

    cout<<d;
}
