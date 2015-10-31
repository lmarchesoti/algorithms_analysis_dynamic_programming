#include <iostream>
#include <vector>

using namespace std;

// global variables
int nodes;
vector<vector<int> > weights;
vector<vector<int> > spaths;
vector<vector<int> > paths;

void apsp(int nodes); // shortest paths

int main(){

	// read inputs
	while(cin >> nodes){

		// use nodes 1 through n
		++nodes;

		// resize graph
		weights.resize(nodes);
		for(int i = 0; i < nodes; ++i)
			weights[i].resize(nodes);
		// resize path matrix
		spaths.resize(nodes);
		paths.resize(nodes);
		for(int i = 0; i < nodes; ++i){
			spaths[i].resize(nodes);
			paths[i].resize(nodes);
		}

		// read weight matrix
		for(int i = 1; i < nodes; ++i)
			for(int j = 1; j < nodes; ++j){
				cin >> weights[i][j];
				spaths[i][j] = 0;
			}

		// calculate shortest paths
		apsp(nodes);

		// print all costs
		cout << "cost matrix: " << endl;
		for(int i = 1; i < nodes; ++i){
			for(int j = 1; j < nodes; ++j)
				cout << spaths[i][j] << " ";
		cout << endl;
		}

		// print all shortest paths
		cout << "shortest paths: " << endl;
		for(int i = 1; i < nodes; ++i){
			for(int j = 1; j < nodes; ++j){
				if(i != j){
					cout << i << " ";
					int k = paths[i][j];
				//	while(k != j){
				//		cout << k << " ";
				//		k = paths[k][j];
				//	}
					cout << j << endl;
				}
			}
		}
				
		cout << endl;

		/* clear data structures */
		for(int i = 0; i < nodes; ++i)
			weights[i].clear();
		weights.clear();
		for(int i = 0; i < nodes; ++i){
			spaths[i].clear();
			paths[i].clear();
		}
		spaths.clear();
		paths.clear();

		/* end */

	}

} // main

void apsp(int nodes){

	int kcost;

	// fill in base cases
	for(int i = 1; i < nodes; ++i)
		for(int j = 1; j < nodes; ++j){
			spaths[i][j] = weights[i][j];
			paths[i][j] = j;
		}

	// fill shortest paths matrix
	for(int k = 1; k < nodes; ++k)
		for(int i = 1; i < nodes; ++i)
			for(int j = 1; j < nodes; ++j){
				// cost-only one-liner
				//spaths[i][j] = min(spaths[i][j], spaths[i][k] + spaths[k][j]);
				// cost + path
				kcost = spaths[i][k] + spaths[k][j];
				if(kcost < spaths[i][j]){
					spaths[i][j] = kcost;
					paths[i][j] = k;
				}
			}

}
