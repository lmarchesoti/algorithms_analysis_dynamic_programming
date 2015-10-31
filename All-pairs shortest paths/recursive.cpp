#include <iostream>
#include <vector>

using namespace std;

// global variables
int nodes;
vector<vector<int> > weights;
vector<vector<int> > spaths;

int apsp(int i, int j, int k); // shortest path from i to j through k (or not)

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
		for(int i = 0; i < nodes; ++i)
			spaths[i].resize(nodes);

		// read weight matrix
		for(int i = 1; i < nodes; ++i)
			for(int j = 1; j < nodes; ++j){
				cin >> weights[i][j];
				// starting shortest path is the weight matrix itself
				spaths[i][j] = 0;//weights[i][j];
			}

		// calculate shortest paths
		for(int k = 0; k < nodes; ++k)
			for(int i = 1; i < nodes; ++i)
				for(int j = 1; j < nodes; ++j)
					spaths[i][j] = apsp(i, j, k);

		// print all shortest paths
		cout << "cost matrix: " << endl;
		for(int i = 1; i < nodes; ++i){
			for(int j = 1; j < nodes; ++j)
				cout << spaths[i][j] << " ";
		cout << endl;
		}

		cout << endl;

		/* clear data structures */
		for(int i = 0; i < nodes; ++i)
			weights[i].clear();
		weights.clear();
		for(int i = 0; i < nodes; ++i){
			spaths[i].clear();
		}
		spaths.clear();

	}

} // main

int apsp(int i, int j, int k){

	// base
	if(k == 0)
		return weights[i][j];

	// recursion
	return min(apsp(i, j, k - 1), apsp(i, k, k - 1) + apsp(k, j, k - 1));
}