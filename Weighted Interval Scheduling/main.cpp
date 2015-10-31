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
vector<int> schedule;

int wis(int ntasks); // weighted interval schedule

// NEEDS TO FIX 0-INDEX FOR SOLUTION RETRIEVAL
int main(){

	// read inputs
	while(cin >> ntasks){

		// resize task and answer vectors
		tasks.resize(ntasks);
		schedule.resize(ntasks);

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

		// set base case
		schedule[0] = 0;

		// calculate weighted interval schedule
		wis(ntasks);

		// get best result
		int best = 0, bestindex = 0;;
		for(int i = 0; i < ntasks; ++i){
			if(best < schedule[i]){
				best = schedule[i];
				bestindex = i;
			}
		}

		// print schedule vector
		for(int i = 0; i < ntasks; ++i){
			cout << schedule[i] << " ";
		}
		cout << endl;

		cout << "Best schedule cost: " << best << endl;

		// recover solution
		cout << bestindex << " ";
		for(int i = tasks[bestindex].p; i != 0; i = tasks[i].p)
			cout << i << " ";
		cout << endl;
	}

} // main

int wis(int ntasks){
	for(int i = 1; i < ntasks; ++i)
		schedule[i] = max(schedule[i - 1], tasks[i].weight + schedule[tasks[i].p]);
}