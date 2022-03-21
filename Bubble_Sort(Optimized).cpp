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

void Bubble_Sort(int a[],int n)
{
    int cmp=0,sw=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            cmp++;
            if(a[j]>a[j+1])
            {
                int temp;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                sw++;
            }
        }
    }
    cout<<"Array after being sorted: "<<endl;
    display(a,n);
    cout<<endl<<"No. of comparisons done: ";
    cout<<cmp;
    cout<<endl<<"No. of swapping done: ";
    cout<<
    sw;

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
    Bubble_Sort(a,n);
}
