#include<iostream>
using namespace std;
int main() {
 int arr[10],n,x;
 cout<<"Enter the size of the array:";
 cin>>n;
 cout<<"Enter the elements of the array:";
 for(int i=0;i<n;i++) {
 cin>>arr[i]; }
 for(int i=0;i<n;i++) {
 for(int j=i+1;j<n;j++) {
 if(arr[i]<arr[j]) {
 x=arr[i];
 arr[i]=arr[j];
 arr[j]=x ;} } }
 cout<<"Second minimum element of the array:"<<arr[1]<<endl;
 cout<<"Second maximum element of the array:"<<arr[n-2];
 return 0;
}
