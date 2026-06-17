// UNION OF ARRAY 

#include <iostream>
using namespace std;
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
    for(int i = 0; i<first_size;i++){
        arr3[i] =arr1[i];
    }
    for(int i = 0 ; i<second_size;i++){
        arr3[first_size + i] = arr2[i];
    }
    

    cout<<endl<<"\n\n ======= MERGE ARRAY WITHOUT DUPLICATES ======="<<endl;
    for(int i = 0 ; i< third_size ; i++){
        if(arr3[i] == -1){
            continue;
        }
        cout<<arr3[i]<<" ";
        for(int j = i+1 ; j< third_size;j++){
            if(arr3[i] == arr3[j]){
                arr3[j] = -1;
            }
        }
    }
    return 0;
}