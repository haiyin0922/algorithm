#include<iostream>
#include<algorithm>
using namespace std;

int *array1, *array2;
int findmedian(int);

int main()
{
	int n;
	
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
	int n1 = (n+2)/2;
	int n2 = (n+1)/2;
	int remain = (n+1)/2;
	
	while(n1<n && n2<n && (array1[n1+1]<array2[n2] || array1[n1]>array2[n2+1])){	
		remain = (remain>1)? remain/2 : 1;
		if(array1[n1]>array2[n2]){
			n1 = n1 - remain;
			n2 = n2 + remain;
		}
		else{
			n1 = n1 + remain;
			n2 = n2 - remain;
		} 
	}
	
	if(array1[n1]>array2[n2]) 
		return max((array1[n1]+array1[n1-1])/2, (array1[n1]+array2[n2])/2);
	else
		return max((array2[n2]+array2[n2-1])/2, (array1[n1]+array2[n2])/2);
}
