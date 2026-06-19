// DIAGONAL SUM OF MATRIX


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
        cout<<"enter element of "<< i <<"th row and "<< j <<"th column : ";
        cin>>matrix[i][j];
    }
   }
cout<<endl<< " ====== MATRIX ======="<<endl;
for(int i = 0; i< rows;i++){
    for(int j = 0 ; j< columns;j++){
      cout<<matrix[i][j]<<"\t";
   }
   cout<<endl;
}

cout<<endl;
int diagonal_sum = 0;
for(int i = 0; i< rows; i++){
    for(int j = 0 ; j< columns; j++){
        if (i == j){
            diagonal_sum = diagonal_sum + matrix[i][j];
        }
    }
}
cout<<" DIAGONAL SUM OF MATRIX IS :- "<< diagonal_sum;
 return 0;
}