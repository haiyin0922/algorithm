#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream fout;

    fout.open("testcase.txt");  

	fout<<"1000000"<<endl;
	for(int i=1; i<=2000000; i++){
		fout<<i<<" "; 	
	}
	
	fout.close();
	
}
