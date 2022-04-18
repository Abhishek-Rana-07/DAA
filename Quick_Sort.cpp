#include<iostream>
using namespace std;
void display(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int partition(int a[],int l,int h)
{
    int piv=a[h];
    int i=l-1;

    for(int j=l;j<=h-1;j++)
    {
        if(a[j]<=piv)
        {
            i++;
            int temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
    int temp=a[i+1];
    a[i+1]=a[h];
    a[h]=temp;

    return (i+1);
}
void quick_sort(int a[],int l,int h)
{
    if(l<h)
    {
        int index= partition(a,l,h);
        quick_sort(a,l,index-1);
        quick_sort(a,index+1,h);
    }
}
int main()
{
    int n;
    cout<<"Enter the length of array:"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the elemnts in array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"The entered array is:"<<endl;
    display(a,n);
    quick_sort(a,0,n-1);
    cout<<"Array after sorting is:"<<endl;
    display(a,n);
}
