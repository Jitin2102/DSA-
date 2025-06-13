#include<iostream>
using namespace std;

void towerOfHanoi(int n,char from ,char to ,char aux){
    if (n == 1){

        cout<<"Move Disk 1 from "<< from <<" to "<< to << endl ;
        return ;
    }
    towerOfHanoi(n-1,from , aux , to );
    cout<<"Move Disk 1 from "<< from <<" to "<< to << endl ;
    towerOfHanoi(n-1,aux,to,from);
}

int main(){
    
    towerOfHanoi(3,'A','B','C');
    return 0;
}