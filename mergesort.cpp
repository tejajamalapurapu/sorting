#include<iostream>
#include<vector>
using namespace std;
void merge(int arr[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    vector<int> L(n1),R(n2);
    for(int i=0;i<n1;i++){
      L[i]=arr[l+i];
    }
     for(int j=0;j<n2;j++){
      R[j]=arr[m+1+j];
    }
     int i=0,j=0,k=l;

    while(i<n1&&j<n2){
      if(L[i]<=R[j]){
        arr[k++]=L[i++];
      }
      else{
        arr[k++]=R[j++];
      }
    }

    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
      
}
void mergesort(int arr[],int l,int r){
  if(l<r){
    int m=l+(r-l)/2;
   mergesort(arr,l,m);
   mergesort(arr,m+1,r);
   merge(arr,l,m,r);
}

}
int main(){
  int arr[]={12,11,13,5,6,7};
  int n=sizeof(arr)/sizeof(arr[0]);
  mergesort(arr,0,n-1);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<",";
  }
  return 0;
}
