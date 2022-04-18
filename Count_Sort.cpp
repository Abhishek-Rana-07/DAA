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
int maximum(int a[],int n)
{
    int max=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    return max;
}
void count_sort(int a[],int n)
{
    int c[n];
    int max=maximum(a,n);
    int b[max+1];

    //initializing b[] with 0
    for(int i=0;i<=max;i++)
    {
        b[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        b[a[i]]++;
    }

    //finding cummulative sum
    for(int i=1;i<=max;i++)
    {
        b[i]=b[i]+b[i-1];
    }
     //scan the array from n-1 to 0
     for(int i=n-1;i>=0;i--)
     {
          int pos=b[a[i]];
          c[pos-1]=a[i];
          b[a[i]]--;
     }

     for(int i=0;i<n;i++)
          a[i]=c[i];
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
    count_sort(a,n);
    cout<<"Array after sorting is:"<<endl;
    display(a,n);
}
