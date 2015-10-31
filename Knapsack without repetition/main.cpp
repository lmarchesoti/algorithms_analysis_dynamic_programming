#include <iostream>
#include <vector>

using namespace std;

struct item{
	double weight;
	double value;
};

item kwr(int capacity, int n_items); // knapsack without repetition

// global variables
vector<vector<item> > solutions; // subproblem solutions hash
vector<item> items; // item list

int main(void){

	int capacity, n_items;
	item result;

	while(cin >> capacity){

		cin >> n_items;

		items.resize(n_items);

		solutions.resize(n_items + 1);
		for(int i = 0; i <= n_items; ++i)
			solutions[i].resize(capacity + 1);

		// read items
		for(int i = 0; i < n_items; ++i){
			cin >> result.weight >> result.value;
			items.push_back(result);
		}

		// calculate optimal solution
		result = kwr(capacity, n_items);

		// print solution
		cout << "weight: " << result.weight << ", value: " << result.value << endl;

		items.clear();

	}

	return 0;
}

item kwr(int capacity, int n_items){

	item bag = {0, 0}, left, top, tl;

	// base
	for(int i = 0; i <= n_items; ++i)
		solutions[i][0] = bag;
	for(int j = 0; j <= capacity; ++j)
		solutions[0][j] = bag;

	// fill matrix
	for(int i = 1; i <= n_items; ++i)
		for(int j = 1; j <= capacity; ++j){

			// left item
			left = solutions[i][j - 1];
			if(left.weight + items[i].weight < capacity){
				left.value += items[i].value;
				left.weight += items[i].weight;
			}

			// top item
			top = solutions[i - 1][j];
			if(top.weight + items[i].weight < capacity){
				top.value += items[i].value;
				top.weight += items[i].weight;
			}

			// top left item
			tl = solutions[i - 1][j - 1];
			if(tl.weight + items[i].weight < capacity){
				tl.value += items[i].value;
				tl.weight += items[i].weight;
			}

			// biggest of the three makes it into the matrix
			solutions[i][j] = tl;
			if(solutions[i][j].value < left.value)
				solutions[i][j] = left;
			if(solutions[i][j].value < top.value)
				solutions[i][j] = top;

		}

	// fetch best solution and return
	bag = solutions[n_items][capacity];
	return bag;

}