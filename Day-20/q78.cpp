// CHECK SYMMETRIC MATRIX 

#include <iostream>
using namespace std;
int main(){
    int rows , columns;  
cout<<" ENTER THE ROWS : ";
cin>>rows;
cout<<" ENTER THE COLUMS : ";
cin>>columns;
int matrix[rows][columns];
int trans[columns][rows];

cout<<endl<<"====== ENTER MAXTRIX ELEMENTS ======"<<endl;
for(int i = 0; i< rows;i++){
    for(int j = 0 ; j< columns;j++){
        cout<<"enter element of "<< i + 1 <<" row and "<< j + 1  <<" column : ";
        cin>>matrix[i][j];
    }
   }

cout<<endl<< " ====== ORIGINAL MATRIX ======="<<endl;
for(int i = 0; i< rows;i++){
    for(int j = 0 ; j< columns;j++){
      cout<<matrix[i][j]<<"\t";
   }
   cout<<endl;
}
   
for(int i = 0; i<rows;i++){
    for(int j = 0 ; j< columns;j++){
      trans[j][i] = matrix[i][j];
   }
}
cout<<endl<< " ====== TRANSPOSE MATRIX ======="<<endl;
for(int i = 0; i<columns;i++){
    for(int j = 0 ; j< rows;j++){
      cout<<trans[i][j]<<"\t";

   }
   cout<<endl;
  }

 for (int i = 0 ; i< rows ; i++){
    for (int j = 0; j< columns; j++){
        if(matrix[i][j] != trans[i][j]){
            cout<<" MATRIX IS NOT SYMMETRIC MATRIX ";
            return 0;
        }
    }
 }

 cout<<endl<<" MATRIX IS SYMMETRIC MATRIX ";
 
 return 0;

}