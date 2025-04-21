#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;
    int  l[n1];
    int m[n2];
    for ( int i = 0; i < n1; i++) l[i]=arr[p+i];
    for(int i=0;i<n1;i++) cout<<l[i]<<" "; cout<<"     ";
    for ( int i = 0; i < n2; i++) m[i]=arr[q+i+1];
    for(int i=0;i<n2;i++) cout<<m[i]<<" "; cout<<"\n";
    int i=0,j=0,k=p;
    while(i<n1&&j<n2){
        if(l[i]<=m[j]){arr[k]=l[i]; i++;}
        else{arr[k]=m[j];j++;}
        k++;
    }
    
    while(i<n1){arr[k]=l[i]; i++; k++;}
    while(j<n2){arr[k]=m[j]; j++; k++;}
}
void mergeSort(int arr[], int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    } 
int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
