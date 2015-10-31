#include <iostream>
#include <list>

using namespace std;

struct item{
	double weight;
	double value;
};

item kwr(int capacity, list<item> items); // knapsack without repetition

int main(void){

	int capacity, n_items;
	list<item> items;
	item result;

	while(cin >> capacity){

		cin >> n_items;

		// read items
		for(int i = 0; i < n_items; ++i){
			cin >> result.weight >> result.value;
			items.push_back(result);
		}

		// calculate optimal solution
		result = kwr(capacity, items);

		// print solution
		cout << "weight: " << result.weight << ", value: " << result.value << endl;

		items.clear();

	}

	return 0;
}

item kwr(int capacity, list<item> items){

	item bag = {0, 0}, temp_bag1, temp_bag2, t_item;
	list<item> dup;

	// for all items
	for(int i = 0; i < items.size(); ++i){
		// remove item from list to check cost without it
		t_item = items.front();
		items.pop_front();

		// safe check
		if(t_item.weight > capacity) // should reinsert element, but it doesn't matter
			continue;

		// either item belongs to solution
		temp_bag1 = kwr(capacity - t_item.weight, items);
		temp_bag1.weight += t_item.weight;
		temp_bag1.value += t_item.value;

		// or it doesn't
		temp_bag2 = kwr(capacity, items);

		// max of the three gets to return
		if(bag.value < temp_bag1.value)
			bag = temp_bag1;
		if(bag.value < temp_bag2.value)
			bag = temp_bag2;

		// put item back in list
		items.push_back(t_item);
	}

	return bag;

}