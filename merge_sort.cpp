#include<iostream>
using namespace std;

void display(int a[] , int n)
{
     for(int i=0;i<n;i++)
      {
             cout<<a[i]<<" ";
      }
      cout<<endl;
}

void merge(int a[],int l,int mid,int h)
{
      int cmp=0;
      int i=l,j=mid+1,k=0;
      int c[h-l+1];
      while(i<=mid  &&  j<=h)
      {      
              cmp++;
               if(a[i] < a[j])
               {
                        c[k++]=a[i++];
                }
                else
                {
                        c[k++]=a[j++];
                  }
      }
     while(i<=mid)
      {
              c[k++]=a[i++];
      }
      while(j<=h)
     {
              c[k++]=a[j++];
     }
      int L=0;
      for(int L=l; i<=h ; i++)
      {
           a[i]=c[L];
           L++;
       }     
}

void merge_sort(int a[],int l,int h)
{
      if(l<h)
      {
             int mid=(l+h)/2;
             merge_sort(a,l,mid);
             merge_sort(a,mid+1,h);
             merge(a,l,mid,h);
       }
       cout<<"After merging the array is: ";
       display(a,h+1);
       cout<<"No. of comparisons ";
       cin>>
}


int main()
{
       int n;
      cout<<" Enter the length of array: "<<endl;
      cin>>n;
      int a[n];
      cout<<"Enter the elemnts in array "<<endl;
      for(int i=0;i<n;i++)
      {
             cin>>a[i];
      }
      cout<<"Array before sorting is : "<<endl;
     display(a,n);

      merge_sort(a, 0, n-1);

}
