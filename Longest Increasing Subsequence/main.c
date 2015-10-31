#include <stdio.h>
#include <stdlib.h>

int* costs; // vector with cost for path nodeing at each node
int* path; // vector with path for each vertice
int size; // size of sequence vector
int* sequence; // vector with input sequence

int lis(int node); // longest increasing subsequence

int main(){

	int i; // iterator
	int node;

	/* scan input */
	while(scanf("%d\n", &size) != EOF){

		sequence = malloc(size * sizeof(int));
		path = calloc(size, sizeof(int));
		costs = calloc(size, sizeof(int));

		for(i = 0; i < size; ++i){
			scanf("%d ", &sequence[i]);
		}
		/* end */

		// find lis across input
		for(i = size - 1; i >= 0; --i){
			lis(i);
		}

		/* print path and cost vectors */
		/*
		printf("path vector:\n");
		for(i = 0; i < size; ++i){
			printf("%d ", path[i]);
		}
		printf("\ncost vector:\n");
		for(i = 0; i < size; ++i){
			printf("%d ", costs[i]);
		}
		printf("\n");
		*/		

		// find lis node
		node = 0;
		for(i = 0; i < size; ++i)
			if(costs[i] > costs[node])
				node = i;

		// print lis and cost
		printf("%d\n", costs[node]);
		do {
			printf("%d ", sequence[node]);
			node = path[node];
		}	while(node != 0);
		printf("\n");

		// clear memory
		free(path);
		free(costs);
		free(sequence);

	}

} // main

int lis(int node){

	int i, maxcost = 0, cost;

	if (costs[node] != 0)
		return costs[node];

	// get lis for each subproblem
	for(i = node + 1; i < size; ++i){
		// check nodes to which this one links to
		if (sequence[node] < sequence[i]){
			cost = lis(i);
			// if theres a bigger path, append to it
			if (cost > maxcost) {
				maxcost = cost;
				path[node] = i;
			}
		}
	}

	// set the minimum cost
	costs[node] = maxcost + 1;

	// return this node's cost
	return maxcost + 1;

} // lis