#include <iostream>
#include <vector>

using namespace std;

struct task {
	int start;
	int end;
	int weight;
	int p; // last non-overlapping task
};

// global variables
int ntasks;
vector<task> tasks;

int wis(int ntasks); // weighted interval schedule

int main(){

	// read inputs
	while(cin >> ntasks){

		// resize task vector
		tasks.resize(ntasks);

		for(int i = 0; i < ntasks; ++i){
			cin >> tasks[i].start >> tasks[i].end >> tasks[i].weight;
			cout << tasks[i].start << " " << tasks[i].end << " " << tasks[i].weight << endl;
		}

		// sort inputs by task finish time

		// calculate p-values
		for(int i = 0; i < ntasks; ++i)
			for(int j = i; j > 0; --j){
				if(tasks[i].start > tasks[j].end){
					tasks[i].p = j;
					break;
				}
			}

		// calculate weighted interval schedule
		cout << "Best schedule cost: " << wis(ntasks - 1) << endl;
	}

} // main

int wis(int ntasks){
	// base case
	if(ntasks == 0)
		return 0;
	// recursion
	return max(wis(ntasks - 1), tasks[ntasks].weight + wis(tasks[ntasks].p));
} // wis