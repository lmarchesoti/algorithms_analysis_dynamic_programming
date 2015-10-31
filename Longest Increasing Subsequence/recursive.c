#include <stdio.h>
#include <stdlib.h>

int size; // size of sequence vector
int* sequence; // vector with input sequence

int lis(int node); // longest increasing subsequence

int main(){

	int i; // iterator
	int node, liscost, new_lis, lisnode;

	/* scan input */
	while(scanf("%d\n", &size) != EOF){

		sequence = malloc(size * sizeof(int));

		for(i = 0; i < size; ++i){
			scanf("%d ", &sequence[i]);
		}
		/* end */

		// find lis across input
		liscost = 0;
		for(i = size - 1; i >= 0; --i){
			new_lis = lis(i);
			if(new_lis > liscost){
				liscost = new_lis;
				lisnode = i;
			}
		}

		// print lis and cost
		printf("node: %d\n", lisnode);
		printf("cost: %d\n", liscost);

		// this one doesn't remember the path
		/*
		do {
			printf("%d ", sequence[node]);
			node = path[node];
		}	while(node != 0);
		printf("\n");
		*/

		// clear memory
		free(sequence);

	}

} // main

int lis(int node){

	int i, maxcost = 0, cost;

	// get lis for each subproblem
	for(i = node + 1; i < size; ++i){
		// check nodes to which this one links to
		if (sequence[node] < sequence[i]){
			cost = lis(i);
			// if theres a bigger path, append to it
			if (cost > maxcost) {
				maxcost = cost;
			}
		}
	}

	// return this node's cost
	return maxcost + 1;

} // lis