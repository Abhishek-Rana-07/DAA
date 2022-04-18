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

void swap(int *x,int *y)
{
    int temp= *x;
    *x= *y;
    *y=temp;
}

void Selection_Sort(int a[],int n)
{
    int i,j,min_index;

    for(i=0;i<n-1;i++)
    {
        min_index=i;

        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min_index])
            {
                min_index=j;
            }
        }
        swap(&a[min_index],&a[i]);
    }
    cout<<"Array after sorting"<<endl;
    display(a,n);
}

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elemnts in array: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Array before sorting is: ";
    display(a,n);
    Selection_Sort(a,n);
}
