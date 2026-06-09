//REVERSE NUMBER TRIANGLE
#include <iostream>
using namespace std;
int main(){
    cout<<"TO GET REVERSE STAR PATTERN ENTER THR NUMBER OF ROWS : ";
    int n;
    cin>>n;
    int temp = n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=temp;j++){
            cout<< j ;
            cout<<" ";
        }
        cout<<endl;
        temp--;
    }
    return 0;
}