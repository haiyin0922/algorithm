#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream fout;

    fout.open("testcase.txt");  

	fout<<"100000"<<endl<<"100000"<<endl<<"100000"<<endl<<"100000"<<endl;
	
	for(int i=0; i<100000; i++){
		fout<<"100000"<<endl; 	
	}
	
	
	fout.close();
	
}


