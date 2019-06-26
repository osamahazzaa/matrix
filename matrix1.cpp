#include<iostream>
#include<string>
#include<sstream>
#include<math.h>


     using namespace std;
     float matrixa[100][100] ;
     float matrixb [100][100] ;
     int x , y , x2 , y2 ,size1 , size2 ;

     void enterA ( string s){
         x=0; y=0; size1=0;  string h ;
     for ( int i =0 ; i< s.length(); i++){
        if (isdigit(s[i])||(s[i]=='-')){ h = s.substr(i);  matrixa[x][y]= atof(h.c_str()); y++;
        while(isdigit(s[i])||(s[i]=='-')||(s[i]=='.')){i++;}

        }
        if(s[i]==';'){x++; size1 = size1 + y; y=0;}
     }
     size1 = size1 + y ;
     }


     void enterB ( string s){
         x2=0; y2=0; size2 = 0; string h ;
     for ( int i =0 ; i<s.length(); i++){
        if (isdigit(s[i])||(s[i]=='-')){h= s.substr(i); matrixb[x2][y2]= atof(h.c_str()); y2++;
        while(isdigit(s[i])||(s[i]=='-')||(s[i]=='.')){i++;}
        }
        if(s[i]==';'){x2++; size2 = size2 + y2; y2=0;}
     }
     size2 = size2 + y2 ;
     }

void operation ( char op ){
for( int i =0 ; i<=x; i++){
    for ( int j =0 ; j<y; j++){
        if(op=='+'){matrixa[i][j] = matrixa[i][j] + matrixb[i][j] ; }
        if(op=='-'){matrixa[i][j] = matrixa[i][j] - matrixb[i][j] ; }
    }
}
}

void multi (){

float mat[x+1][y2];

for(int i = 0; i <=x; i ++){
    for(int j=0;j<y2;j++){

 mat [i][j] = 0 ;
    }

}
for(int i = 0; i <=x; i ++){
    for(int j=0;j<y2;j++){
        for(int k=0;k<=x2;k++){


            mat[i][j] += matrixa[i][k] * matrixb [k][j] ;
        }
    }
}
for(int i = 0; i <=x; i ++){
    for(int j=0;j<y2;j++){
matrixa[i][j] = mat [i][j] ;

    }

}
y=y2;
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
if ((op=='+')||(op=='-')||(op=='*')){ return true ;}else{ return false ;}
}

bool check_size1(){

 if ((size1%y) != 0){return false;}
else{return true;}

}

bool check_size2(){

 if ((size2%y2) != 0){return false;}
else{return true;}

}

bool check_for_add(){
if ((y==0)||(y2==0)){return false;}
else if ((x!=x2)||(size1!=size2)){return false;}
else{return true;}
}

bool check_for_multi(){

if ((y-1)==x2){return true;}
else {return false ;}
}

int main (){
string s,s2 ;
char op ;
getline(cin,s);
if(check_input(s)){enterA(s);}
else {cout << "ERROR\n"; return 0; }
if(check_size1()){ cin.get(op) ; cin.ignore();}
else {cout << "ERROR\n"; return 0; }
if(check_op(op)){
    getline(cin,s2);
if(check_input(s2)){enterB(s2);}
else {cout << "ERROR\n"; return 0; }
if(check_size2()){
        if (op=='*'){
        if(check_for_multi()){multi();}else {cout << "ERROR\n"; return 0; }

        }else{
        if(check_for_add()){operation(op);}else {cout << "ERROR\n"; return 0; }

        }

        }else {cout << "ERROR\n"; return 0; }

}else {cout << "ERROR\n"; return 0; }



//display result
cout << "[" ;
for( int i =0 ; i<=x; i++){
    for ( int j =0 ; j<y; j++){
        cout << matrixa[i][j] ;
        if (j!=(y-1)) cout << " ";
    } if(i!=x)cout <<";";
    }
    cout << "]";
return 0;
}
