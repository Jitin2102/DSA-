
#include<stdio.h>
int secondMax(int arr[],int n){
    int m2=arr[0],m1 = arr[1];
    for(int i = 2;i < n;i++){
        if(m1 < arr[i]){
            m2 = m1;
            m1 = arr[i];
        }
        else if(m1 > arr[i] && m2 != arr[i]) m2 = arr[i];
    }
    return m2;
}
int main(){
    int arr[] = {23,45,13,56,35,16,89,56,78,90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = secondMax(arr,n);
    printf("Second maximum in array is :  %d",res);
    return 0;
}
