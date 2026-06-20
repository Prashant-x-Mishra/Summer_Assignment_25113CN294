// ROW WISE SUM 
#include <iostream>
using namespace std;
int main(){
int rows , columns;  
cout<<" ENTER THE ROWS : ";
cin>>rows;
cout<<" ENTER THE COLUMS : ";
cin>>columns;
int matrix[rows][columns];

cout<<endl<<"====== ENTER MAXTRIX ELEMENTS ======"<<endl;
for(int i = 0; i< rows;i++){
    for(int j = 0 ; j< columns;j++){
        cout<<"enter element of "<< i + 1 <<" row and "<< j + 1  <<" column : ";
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

cout<<endl<<" ===== ROW  WISE SUM OF MATRIX ====="<<endl;
for(int i = 0 ; i<rows; i++){
    int sum = 0 ;
    for(int j = 0 ; j<columns ; j++){
        sum = sum + matrix[i][j];
    }
    cout<<" SUM OF "<< i + 1 <<" ROW IS "<< sum ;
    cout<<endl;
}
return 0;

}
