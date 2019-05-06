#include<iostream>
#include<string>
#include<cstdlib>
#include<sstream>
#include<vector>

using namespace std;
vector<vector<float>>matrixa;
vector<vector<float>>matrixb;

int error() {
	int flag = 0;
	for (int i = 0; i < matrixa.size(); i++)
	{
        if (matrixa.size() != matrixa[i].size()) {

			flag = 1;
			return flag;

		}
	}

	for (int i = 0; i < matrixb.size(); i++)
	{

            if (matrixb.size() != matrixb[i].size()) {

			flag = 1;
			return flag;

	}
}
if(matrixb.size()!= matrixa.size()) flag =1;
return flag;
}
void func_a(string str)
{

    string temp  ;
    vector<float>mat;
	for(int n= 0; n < str.length(); n++){

        if (str[n]=='['||str[n]==']'||str[n]==' '){continue;}
        if ( str[n]==';'){ matrixa.push_back(mat); mat.clear(); continue ;}
        if(isdigit(str[n])){ temp = str.substr(n); mat.push_back(atof(temp.c_str()));}
while(isdigit(str[n+1])||str[n+1]=='-'||str[n+1]=='.'){ n++;}
	}
    matrixa.push_back(mat); mat.clear();
}

void func_b(string str)
{

    string temp  ;
    vector<float>mat;
	for(int n= 0; n < str.length(); n++){

        if (str[n]=='['||str[n]==']'||str[n]==' '){continue;}
        if ( str[n]==';'){ matrixb.push_back(mat); mat.clear(); continue ;}
        if(isdigit(str[n])){ temp = str.substr(n); mat.push_back(atof(temp.c_str()));}
        while(isdigit(str[n+1])||str[n+1]=='-'||str[n+1]=='.'){ n++;}


	}
    matrixb.push_back(mat); mat.clear();
}

void display1(){
	for (int n = 0; n <matrixa.size(); n++){
		for (int j =0 ; j <matrixa[n].size(); j++ ){
			cout << matrixa[n][j] << "    ";
		}
		cout << endl ;
	}
}

void display2(){
	for (int n = 0; n <matrixa.size(); n++){
		for (int j =0 ; j <matrixa[n].size(); j++ ){
			cout << matrixb[n][j] << "    ";
		}
		cout << endl ;
	}
}
// add or sub or multi or divide matrixA & matrixB and store result in matrixA
void op (char o){
for (int n = 0; n <matrixa.size(); n++){
		for (int j =0 ; j <matrixa[n].size(); j++ ){
			switch(o)
			{ case '+':matrixa[n][j]=matrixa[n][j] + matrixb[n][j] ; break ;
			case '*':matrixa[n][j]=matrixa[n][j] * matrixb[n][j] ; break ;
			case '/':matrixa[n][j]=matrixa[n][j] / matrixb[n][j] ; break ;
			case '-':matrixa[n][j]=matrixa[n][j] - matrixb[n][j] ; break ;
			 }
		}
		cout << endl ;
	}

}


int main() {
string input;
char operat;

	while (1)
	{
		getline(cin,input);
func_a(input);
cin >> operat;
cin.ignore();
getline(cin,input);
func_b(input);
		if (error() == 1) {cout << "ERROR";cout << endl; matrixa.clear(); matrixb.clear(); continue;}
if(operat=='+'||operat=='-'||operat=='/'||operat=='*'){ op (operat); display1();}
else{ cout << "ERROR";cout << endl; matrixa.clear();matrixb.clear(); continue;}


matrixa.clear();
matrixb.clear();
cout << endl;
	}
}


