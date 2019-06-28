#include<iostream>
#include<string>
#include<sstream>
#include <vector>


     using namespace std;
     float matrix[100][100] ;

     int x , y , size ;

     void enter ( string s){
         x=0; y=0; size=0;  string h ;
     for ( int i =0 ; i< s.length(); i++){
        if (isdigit(s[i])||(s[i]=='-')){ h = s.substr(i);  matrix[x][y]= atof(h.c_str()); y++;
        while(isdigit(s[i])||(s[i]=='-')||(s[i]=='.')){i++;}

        }
        if(s[i]==';'){x++; size = size + y; y=0;}
     }
     size = size + y ;
     }

void power (int num){

float mat[y][y];
float mat1[y][y];

for(int i = 0; i <y; i ++){
    for(int j=0;j<y;j++){
 mat [i][j] = 0 ;
 mat1 [i][j] =  matrix[i][j];
}}

for(int times=1; times<num ; times++){

for(int i = 0; i <y; i ++){
    for(int j=0;j<y;j++){
 mat [i][j] = 0 ;
}}

for(int i = 0; i <y; i ++){
    for(int j=0;j<y;j++){
          for(int k=0;k<y;k++){
             mat [i][j] += ( mat1[i][k] * matrix[k][j]);

}}}
    for(int i = 0; i <y; i ++){
    for(int j=0;j<y;j++){
 mat1 [i][j] =  mat[i][j];
}}
}
//to display
for(int i = 0; i <y; i ++){
    for(int j=0;j<y;j++){
 matrix[i][j] =  mat [i][j];
}}
}

void transpose (){
  float mat[y][x+1];
for(int i = 0; i <=x; i ++){
    for(int j=0;j<y;j++){
 mat [j][i] = matrix[i][j] ;
}}

for(int i = 0; i <y; i ++){
    for(int j=0;j<=x;j++){
 matrix[i][j] =  mat [i][j];
}}

int s = x+1 ;
x=y-1 ; y = s ;
}

float determinant( vector<vector<float> > m){
float d = 0;
bool sign = true ;

if (m.size() == 2){

     d =  ( m[0][0] * m[1][1] ) - (m[0][1] * m[1][0]) ;
    return d;
}

for(int i = 0; i< m[0].size(); i ++){
vector<vector<float > > h(m.size()) ;
        for(int j=0;j<m.size();j++){for(int k=0;k<m[0].size();k++){ h[j].push_back(m[j][k]);   }}
        for(int j=0;j<h.size();j++){h[j].erase(h[j].begin()+i);}
        h.erase(h.begin()+0);

    if(sign){ d += m[0][i]* determinant(h) ; }
      else { d -= m[0][i]* determinant(h) ;}
      sign=!sign;
    }
    return d ;
}

bool check_square(){

int rows = x+1 ;
if ((size/rows)!=rows){return false;}
else{return true;}
}



bool check_input(string s){
    int i =0 ;
while( i<s.length() ){

    if (isdigit(s[i])||(s[i]=='-')||(s[i]=='.')||(s[i]=='[')||(s[i]==']')||(s[i]==' ')||(s[i]==';')){  i++ ; }
    else {return false; }
}
return true;
}

bool check_op(char op){
if ((op=='T')||(op=='D')||(op=='^')){ return true ;}else{ return false ;}
}

bool check_size(){

 if ((size%y) != 0){return false;}
else{return true;}

}





int main (){
string s,s2 ;
char op ;
getline(cin,s);
if(check_input(s)){enter(s);}
else {cout << "ERROR\n"; return 0; }
if(check_size()){ cin.get(op) ; cin.ignore();}
else {cout << "ERROR\n"; return 0; }
if(check_op(op)){if(op=='^'){
   int num ; cin >> num ;
    if(num<0){cout << "ERROR\n"; return 0;}
else if(num==0){cout << "1\n"; return 0; }
else if(num>1){if(check_square()){power(num);}else {cout << "ERROR\n"; return 0; }}
}
else if(op=='T'){transpose();}
else if(op=='D'){if(check_square()){
    vector<vector<float> > m (y);
    for(int i = 0; i <y; i ++){
    for(int j=0;j<y;j++){
        m[i].push_back(matrix[i][j]);
    }}
    cout << determinant(m) << endl; return 0 ;
}else {cout << "ERROR\n"; return 0; }}
}else {cout << "ERROR\n"; return 0; }




//display result
cout << "[" ;
for( int i =0 ; i<=x; i++){
    for ( int j =0 ; j<y; j++){
        cout << matrix[i][j] ;
        if (j!=(y-1)) cout << " ";
    } if(i!=x)cout <<";";
    }
    cout << "]";
return 0;
}
