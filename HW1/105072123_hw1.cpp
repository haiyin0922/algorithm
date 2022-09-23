#include <iostream>
#include<algorithm>
using namespace std;

int element[10000][5] = {0};
int findmax(int, int, int);

int main()
{
	int T, N, K, S;
	
	cin>>T;
	
	for(int i=0; i<T; i++){
		cin>>N>>K>>S;
		int maxele[5] = {0};
		for(int j=0; j<N; j++){
			for(int k=0; k<S; k++){
				cin>>element[j][k];
				maxele[k] = max(maxele[k], element[j][k]);
			}
		}
		if(K>=S) cout<<maxele[0]+maxele[1]+maxele[2]+maxele[3]+maxele[4]<<endl;
		else cout<<findmax(N, K, S)<<endl;	 
	}
}

int findmax(int N, int K, int S)
{
	int energy = 0;
	int maxijkl[5] = {0};
	int maxijk[5] = {0};
	int maxij[5] = {0};
	
	for(int i=0; i<N-(K-1); i++){
		for(int j=i+1; j<N-(K-2); j++){
			for(int idx=0; idx<S; idx++){
				maxij[idx] = max(element[i][idx], element[j][idx]);
			}
			energy = max(energy, maxij[0]+maxij[1]+maxij[2]+maxij[3]+maxij[4]);
			if(K>2){
				for(int k=j+1; k<N-(K-3); k++){
					for(int idx=0; idx<S; idx++){
						maxijk[idx] = max(maxij[idx], element[k][idx]);
					}
					energy = max(energy, maxijk[0]+maxijk[1]+maxijk[2]+maxijk[3]+maxijk[4]);
					if(K>3){
						for(int l=k+1; l<N; l++){
							for(int idx=0; idx<S; idx++){
								maxijkl[idx] = max(maxijk[idx], element[l][idx]);
							}
							energy = max(energy, maxijkl[0]+maxijkl[1]+maxijkl[2]+maxijkl[3]+maxijkl[4]);
						}
					}
				}
			}
		}
	}
	
	return energy;
}
