#include <iostream>
using namespace std;

struct Map {
    int V, E;    
	const long long MAX_DIS = 100000000000001;
	const long long MAX_WEI = 1000000001;
    virtual void read_input() = 0;
    virtual void process() = 0;
    virtual void output() = 0;
    virtual ~Map() {}
};

class LosSantosMap: public Map {
	int vis[100000];
	int **w;
	long long d[100000];
public:
	void Relax(int u){
		for(int i=0; i<V; i++){
    		if(vis[i]<0 && w[u][i]<MAX_WEI && d[i]>d[u]+w[u][i])
    			d[i] = d[u]+w[u][i];
		}
		
		return;
	}
    void read_input() override {
		cin>>V>>E;
		
		w = new int*[V];
		for(int i=0; i<V; i++){
    		w[i] = new int[V];
		}
		

		for(int i=0; i<V; i++){
        	for(int j=0; j<V; j++){
        		if(i==j) w[i][j] = 0;
				else w[i][j] = MAX_WEI;
			}
		}
		
        for(int i=0; i<E; i++){
        	int vi, vj;
			cin>>vi>>vj;
			cin>>w[vj][vi];
		}
		
		d[0] = 0;
        for(int i=1; i<V; i++){
        	d[i] = MAX_DIS;
        	vis[i] = -1;
		}
		
		return; 
    }
    void process() override {
    	int v = 0;
		long long MIN_DIS = 0;
		
		while(MIN_DIS != MAX_DIS){
			vis[v] = 1;
			Relax(v);
			MIN_DIS = MAX_DIS;
			for(int i=1; i<V; i++){
				if(vis[i]<0 && d[i]<MIN_DIS){
					v = i;
					MIN_DIS = d[i];
				}
			}
		}
		
		return;
    }
    void output() override {
		for(int i=0; i<V; i++){
        	if(vis[i]<0) cout<<"INF"<<endl;
        	else cout<<d[i]<<endl;
		}
		
		return; 
    }
};

class PortalChambersMap: public Map {
    long long d[1000][1000];
public:
    void read_input() override {
        cin>>V>>E;
		
		for(int i=0; i<V; i++){
        	for(int j=0; j<V; j++){
        		d[i][j] = MAX_DIS;
			}
		}
		
        for(int i=0; i<E; i++){
        	int vi, vj;
			cin>>vi>>vj;
			cin>>d[vi][vj];
		}
		
		return;
    }
    void process() override {
		int N = V;
		
		while(N--){
    		for(int i=0; i<V; i++){
    			for(int j=0; j<V; j++){
    				for(int k=0; k<V; k++){
						d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
					}
				}
			}
		}
		
		return;
    }
    void output() override {
        for(int i=0; i<V; i++){
        	if(d[i][i]==MAX_DIS) cout<<"INF"<<endl;
        	else cout<<d[i][i]<<endl;
		}
		
		return;
    }
};

class SkyrimMap: public Map {
	int w[10000][10000];
	long long d[10000];
public:
    void read_input() override {
        cin>>V>>E;
		
		d[0] = 0;
		for(int i=1; i<V; i++){
        	d[i] = -MAX_DIS;
		}
		
		for(int i=0; i<V; i++){
			for(int j=0; j<V; j++){
				w[i][j] = -MAX_WEI;
			}
		}
		
        for(int i=0; i<E; i++){
        	int vi, vj;
			cin>>vi>>vj;
			cin>>w[vi][vj];
		}
		
		return;
    }
    void process() override {
  		int N = V-1;
  		
  		while(N--){
			for(int i=0; i<V; i++){
				for(int j=0; j<V; j++){
    				if(w[i][j]>-MAX_WEI && d[j]<d[i]+w[i][j])
    					d[j] = d[i]+w[i][j];
    			}
			}
		}
		
		return;
    }
    void output() override {
    	int flag = 0;
    	
		for(int i=0; i<V; i++){
			for(int j=0; j<V; j++){
				if(w[i][j]>-MAX_WEI && d[j]<d[i]+w[i][j]){
					flag = 1;
					break;
				}
			}
			if(flag) break;
		}
		
		if(flag) cout<<"TRUE"<<endl;
		else cout<<"FALSE"<<endl;
        
        return;
    }
};

class BlightTownMap: public Map {
    // TODO: Store graphs and other variables
public:
    void read_input() override {
        // TODO
    }
    void process() override {
        // TODO
    }
    void output() override {
        // TODO
    }
};

int main(void)
{
    int T, map_kind;
    Map* map;
    cin >> T;
    while (T--) {
        cin >> map_kind;
        switch (map_kind) {
            case 1: map = new LosSantosMap(); break;
            case 2: map = new PortalChambersMap(); break;
            case 3: map = new SkyrimMap(); break;
            case 4: map = new BlightTownMap(); break;
            default: return 1;
        }
        map->read_input();
        map->process();
        map->output();
        delete map;
    }
    return 0;
}
