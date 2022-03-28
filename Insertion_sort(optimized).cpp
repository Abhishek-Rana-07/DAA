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

void Insertion_Sort(int a[],int n)
{  
    int cmp=0,w=0;
    int j=0;
    for(int i=1;i<n;i++)
    {
       int key=a[i];
       for(j=i-1;j>=0;j--)
       {
           cmp++;
           if(key<a[j])
           {
               w++;
               a[j+1]=a[j];
           }
           else
              break;
       }
       if((j+1)!= i)
       {
           w++;
           a[j+1]=key;
       }
    }
    cout<<"The sorted array is: "<<endl;
    display(a,n);
    cout<<"No. of comparisons done: "<<cmp<<endl;
    cout<<"No. of write operations done: "<<w<<endl;
    
    
 
}

int main()
{
   int n;
   cout<<"Enter the size of array: ";
   cin>>n;
   int a[n];
   cout<<"Enter the elemnts in array : ";
   for(int i=0;i<n;i++)
   {
        cin>>a[i];
   }
   cout<<"Array before sorting: ";
   display(a,n);
   Insertion_Sort(a,n); 
}
