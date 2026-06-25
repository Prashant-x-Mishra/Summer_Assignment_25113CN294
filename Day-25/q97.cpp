// MERGE TWO SHORTED ARRAY 

#include <iostream>
using namespace std;
int main(){

    int arr1[] = {1,3,5,7};
    int arr2[] = {2,4,6,8,10};

    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    int size3 = size1 + size2;
    int arr3[size3];

    int i = 0 ; 
    int j = 0;
    int k = 0 ;

    while(i < size1 &&  j < size2){
        if(arr1[i] < arr2[j]){
            arr3[k] = arr1[i];
            i++;
        }
        else { 
            arr3[k] = arr2[j];
            j++;

        }

        k++;
    }

    while(i<size1){
        arr3[k] = arr1[i];
        i++;
        k++;
    }

    while(j<size2){
        arr3[k] = arr2[j];
        j++;
        k++;
    }


    cout<<endl<<"FIRST SHORTED ARRAY ========="<<endl;
    for(int x = 0 ; x<size1; x++){
        cout<<arr1[x]<<" ";
    }

    

    cout<<endl<<"SECOND SHORTED ARRAY ========="<<endl;
    for(int x = 0 ; x<size1; x++){
        cout<<arr2[x]<<" ";
    }

    cout<<endl<<"==================================="<<endl;
    cout<<"MERGE SHORTED ARRAY "<<endl;
    for(int x = 0; x < size3 ; x++ ){
        cout<<arr3[x]<<" ";
    }

    return 0;

}