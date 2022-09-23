#include<iostream>
using namespace std;

long long D[100000];
long long findmin(int, int, int);

int main()
{
	int N, A, B, W;
		
	cin>>N>>A>>B>>W;
	
	for(int i=1; i<=N; i++){
		cin>>D[i];
	}
	
	cout<<W+findmin(N, A, B)<<endl;
	
	return 0;
}

long long findmin(int N, int A, int B)
{
	long long X = 1, idx = 1, last_idx = 0, sum = 0;
	int Z[100000] = {0};
	
	D[0] = 100000001;
	
	for(int i=2; i<=N; i++){
		if(-A+B*(i-last_idx) > 0){
			if(B*(idx-last_idx)*(i-idx+1)-A > D[idx]){
				Z[idx] = 1;
				last_idx = idx;
				idx = 0;
			}
		}
		if(D[i]-B*(i-last_idx) < D[idx]-B*(idx-last_idx)){
			idx = i;
		}
	}
	
	if(-A+B*(N-last_idx) > D[N]){
		Z[N] = 1;
	}
	
	for(int i=1; i<=N; i++){
		if(Z[i] > 0){
			sum += D[i];
			X = 1;
		}
		else{
			sum += -A+B*X;
			X++;
		}
	}
	
	return sum;
}
