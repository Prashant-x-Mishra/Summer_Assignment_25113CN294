// SUBTRACT MATRICES 

#include <iostream>
using namespace std;
int main(){
   int rows , columns;
   cout<<" ENTER THE ROWS : ";
   cin>>rows;
   cout<<" ENTER THE COLUMS : ";
   cin>>columns;
   int matrix1[rows][columns],matrix2[rows][columns],matrix3[rows][columns];

   cout<<endl<<"====== ENTER MAXTRIX 1 ELEMENTS ======"<<endl;
   for(int i = 0; i< rows;i++){
    for(int j = 0 ; j< columns;j++){
        cout<<"enter element of "<< i <<"th row and "<< j <<"th column : ";
        cin>>matrix1[i][j];
    }
   }
cout<<endl<<"====== ENTER MAXTRIX 2 ELEMENTS ======"<<endl;
   for(int i = 0; i< rows;i++){
    for(int j = 0 ; j< columns;j++){
        cout<<"enter element of "<< i <<"th row and "<< j <<"th column : ";
        cin>>matrix2[i][j];
    }
   }
 
   for(int i = 0; i< rows;i++){
    for(int j = 0 ; j< columns;j++){
      matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
    }
   }

   cout<<endl<<"========= SUBTRACT MATRICES  OF MATRIX1 AND MATRIX2 ======== "<<endl;

   for(int i = 0; i< rows;i++){
    for(int j = 0 ; j< columns;j++){
     cout<<matrix3[i][j] <<"\t";
    }
    cout<<endl;
   }
   return 0;


}