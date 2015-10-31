#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct item{
	double weight;
	double value;
};

item kwr(int capacity); // knapsack without repetition

// global variables
map<int, item> solutions; // subproblem solutions hash
vector<item> items;

int main(void){

	int capacity, n_items;
	item result;

	while(cin >> capacity){

		cin >> n_items;

		items.resize(n_items);

		// read items
		for(int i = 0; i < n_items; ++i){
			cin >> items[i].weight >> items[i].value;
		}

		// calculate optimal solution
		result = kwr(capacity);

		for(int i = 0; i < solutions.size(); ++i)
			cout << "solutions[" << i << "] = " << solutions[i].weight << " " << solutions[i].value << endl;

		// print solution
		cout << "weight: " << result.weight << ", value: " << result.value << endl;

		items.clear();
		solutions.clear();

	}

	return 0;
}

item kwr(int capacity){

	item bag = {0, 0}, t_item, current;

	if(solutions.count(capacity))
		return solutions[capacity];

	// try every item to optimize cost
	for(int i = 0; i < items.size(); ++i){
		t_item = items[i];
		if(t_item.weight > capacity)
			continue;

		current = kwr(capacity - t_item.weight);
		current.weight += t_item.weight;
		current.value += t_item.value;

		// keep best cost and return
		if(bag.value < current.value)
			bag = current;

	}

	solutions[capacity] = bag;
	return bag;

}