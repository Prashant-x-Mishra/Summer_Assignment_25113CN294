// MERG ARRAY 

#include <iostream>
using namespace std ;
int main(){
    cout<<"ENTER ARRAY 1 SIZE : ";
    int first_size;
    cin>>first_size;
    int arr1[first_size];
    for(int i = 0 ; i< first_size  ; i++){
        cout<<"ENTER ELEMENT HAVING INDEX "<<i<<" : ";
        int n;
        cin>>n;
        arr1[i] = n;
    }

    cout<<"====== ARRAY 1 ELEMENTS ARE : ======== "<<endl;
    for(int i = 0 ; i < first_size  ; i++){
        cout<<arr1[i]<<" ";
    }

    cout<<endl<<"\nENTER ARRAY 2  SIZE : ";
    int second_size;
    cin>>second_size;
    int arr2[second_size];
    for(int i = 0 ; i< second_size  ; i++){
        cout<<"ENTER ELEMENT HAVING INDEX "<<i<<" : ";
        int n;
        cin>>n;
        arr2[i] = n;
    }

    cout<<endl<<"====== ARRAY 2 ELEMENTS ARE : ======== "<<endl;
    for(int i = 0 ; i < second_size  ; i++){
        cout<<arr2[i]<<" ";
    }

    int third_size = first_size + second_size;

    int arr3[third_size];
    cout<<endl<<"\n\n ====== MERGE ARRAY 1 AND ARRAY 2 ======="<<endl;
    for(int i = 0; i<first_size;i++){
        arr3[i] =arr1[i];
    }
    for(int i = 0 ; i<second_size;i++){
        arr3[first_size + i] = arr2[i];
    }
    for(int i = 0 ; i< third_size ; i++){
        cout<<arr3[i]<<" ";
    }


    return 0;

}