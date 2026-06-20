// MULTIPLY MATRICES 


#include <iostream>
using namespace std;
int main(){
    int x , y , z;
    cout<<" ENTER THE ROW OF MATRIX A : ";
    cin>>x;
    cout<<" ENTER THE COMMON VALUE OF  COLUMS AND ROW OF MATRIX A AND B : ";
    cin>>y;
    cout<<" ENTER THE COLUMN OF MATRIX B : ";
    cin>>z;
    int matrixA[x][y],matrixB[y][z],matrixC[x][z];
    cout<<endl<<"====== ENTER ELEMENTS OF MATRIX A ====== "<<endl;

    for(int i = 0 ; i < x ; i++){
        for(int j = 0 ; j < y ; j++){
            cout<<" ENTER THE ELEMENT OF " <<i + 1 <<" row  and "<<j + 1<<" column : ";
            cin>>matrixA[i][j];
        }
    }

    cout<<endl<<"====== ENTER ELEMENTS OF MATRIX B ====== "<<endl;

    for(int i = 0 ; i < y ; i++){
        for(int j = 0 ; j < z ; j++){
            cout<<" ENTER THE ELEMENT OF " <<i + 1 <<" row and "<<j + 1 <<" column : ";
            cin>>matrixB[i][j];
        }
    }

    for(int i = 0; i<x;i++){
        for(int j = 0; j<z;j++){
            matrixC[i][j] = 0;
        }
    }

    for(int i = 0 ; i< x ; i++){
        for(int j = 0 ; j< z ; j++){
            for(int k = 0 ; k< y ; k++){

                matrixC[i][j] = matrixC[i][j] + matrixA[i][k]*matrixB[k][j];

            }
        }
    }

    cout<<endl<<"======== MATRIX C (MULTIPLY MATRIX OF MATRIX A AND B ) ========"<<endl;

    for(int i = 0 ; i<x;i++){
        for(int j = 0 ; j<z;j++){
            cout<<matrixC[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}