#include <iostream>

using namespace std;
 float ruslt[100][100];
 void insert_m (float matrix[][100],int &x,int &y , string input){
 x=0;y=0;
while (input.length()!=0){
if (input[0]=='['||input[0]==']'||input[0]==' '){  input.erase(0,1); continue;}
if ( input[0]==';'){ x++;  y=0;
input.erase(0,1); continue; }
string::size_type sz;
matrix[x][y] = stod(input,&sz);
input.erase(0,sz);
cout  << endl;
y++;
}
x=x+1;
 }

 void display( float  m[][100] ,int x ,int y){
	for (int n = 0; n < x; n++){
            cout << "|  " ;
		for (int j =0 ; j < y ; j++ ){

string intstr = to_string( m[n][j]);
cout << m[n][j] ;
cout << string((10 -intstr.length()), ' ');

		}
		cout << "|" << endl ;
	}}

void add ( float mat1[][100] , float mat2[][100] , int x , int y ){

for (int n = 0; n < x; n++){
		for (int j =0 ; j < y ; j++ ){
ruslt[n][j] = mat1[n][j] + mat2[n][j] ;

		}}}

void min ( float mat1[][100] , float mat2[][100] , int x , int y ){

for (int n = 0; n < x; n++){
		for (int j =0 ; j < y ; j++ ){
ruslt[n][j] = mat1[n][j] - mat2[n][j] ;

		}}}

void multi ( float mat1[][100] , float mat2[][100] , int x , int y ){

for (int n = 0; n < x; n++){
		for (int j =0 ; j < y ; j++ ){
ruslt[n][j] = mat1[n][j] * mat2[n][j] ;

		}}}

void sub ( float mat1[][100] , float mat2[][100] , int x , int y ){

for (int n = 0; n < x; n++){
		for (int j =0 ; j < y ; j++ ){
ruslt[n][j] = mat1[n][j] / mat2[n][j] ;

		}}}

int main (){

int x,y ;
char operat ;
string input;
float matrix[100][100];
getline(cin,input);
insert_m(matrix,x,y,input);
display(matrix,x,y);
cin >> operat ;
cin.ignore();
input.clear();

int x1,y1;
float matrix2[100][100];
getline(cin,input);
insert_m(matrix2,x1,y1,input);

if(x1==x&&y1==y){

switch (operat){

case '+': {   add(matrix,matrix2,x,y); display(ruslt,x,y); break;}
case '-' : {  min(matrix,matrix2,x,y); display(ruslt,x,y); break; }

case '/' : { sub(matrix,matrix2,x,y); display(ruslt,x,y); break;}
case '*' : {multi(matrix,matrix2,x,y); display(ruslt,x,y); break;}
}

}else{ cout << "erorr";}
return 0;
}
