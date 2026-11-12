#include<iostream>
using namespace std;
int LinearSearch(int arr[],int len,int target){
    int i;
    for (int i=0;i < len ; i++){
        if(arr[i]==target){
            return i;
        }
    }
}
int main(){
    int arr[]={45,90,135,34,56,89};
    int len=sizeof arr/sizeof arr[0];
    int target=89;
    int result= LinearSearch(arr,len,target);
    cout<<"Target Value : "<<target<< " is found at index "<<result <<endl;
    return 0;
}