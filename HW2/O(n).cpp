#include<iostream>
#include<algorithm>
#include<fstream>
#include <Windows.h>
using namespace std;

int *array1, *array2;
int findmedian(int);

int main()
{
	int n;
	
	freopen("testcase.txt", "rt", stdin);
	
	cin>>n;
	array1 = new int[n+1];
	array2 = new int[n+1];
	array1[0] = 0;
	array2[0] = 0;
	
	for(int i=1; i<=n; i++){
		cin>>array1[i];
	}
	for(int i=1; i<=n; i++){
		cin>>array2[i];
	}
	
	if(n==1) cout<<(array1[1]+array2[1])/2;
	else if(n==2) cout<<(max(array1[1], array2[1]) + min(array1[2], array2[2]))/2;
	else cout<<findmedian(n);
	cout<<endl;
	
	delete []array1;
	delete []array2;
	
	return 0;
}

int findmedian(int n)
{
	int n1 = 1;
	int n2 = 1;
	
	LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);

    LARGE_INTEGER start;
    QueryPerformanceCounter(&start);
	
	while(n1+n2<n+1){	
		if(array1[n1+1]<array2[n2+1]) n1++;
		else n2++;
	}
	
 	LARGE_INTEGER end;
    QueryPerformanceCounter(&end);

    // for microseconds use 1000000.0
    double interval = static_cast<double>(end.QuadPart- start.QuadPart) / 
                      frequency.QuadPart; // in seconds
    cout<<"Time taken by function: "<<interval*1000000<<" microseconds"<<endl;
	
	if(array1[n1]>array2[n2]) 
		return max((array1[n1]+array1[n1-1])/2, (array1[n1]+array2[n2])/2);
	else
		return max((array2[n2]+array2[n2-1])/2, (array1[n1]+array2[n2])/2);
}
