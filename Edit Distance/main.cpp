#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

// words to be used on algorithm
string word1, word2;
// problem matrix
vector<vector<int> > problem;

int edit_distance(); // calculate edit distance and fill problem matrix

void print_path(); // prints the edit path in the current problem matrix

int diff(int x, int y); // returns 0 if the words are equal on these indices, 1 otherwise

int main(){

	// read inputs
	while(getline(cin, word1) && getline(cin, word2)){

		// print inputs
		cout << "word1: " << word1 << ", length: " << word1.length() << endl;
		cout << "word2: " << word2 << ", length: " << word2.length() << endl;

		problem.resize(word1.length() + 1);
		for(int i = 0; i < problem.size(); ++i)
			problem[i].resize(word2.length() + 1);

		/* edit distance calculation */

		// print edit distance
		cout << "edit distance: " << edit_distance() << endl;
		// print edit path
		cout << "edit path: " << endl;
		print_path();
		cout << endl;

		/* end */

		for(int i = 0; i < problem.size(); ++i)
			problem[i].clear();
		problem.clear();

	}

}

int edit_distance(){

	int minimum;

	// fill in base cases
	for(int j = 0; j < problem[0].size(); ++j)
		problem[0][j] = j;
	for(int i = 0; i < problem.size(); ++i)
		problem[i][0] = i;

	// calculate subproblems in the entire matrix
	for(int i = 1; i < problem.size(); ++i)
		for(int j = 1; j < problem[0].size(); ++j){
			// rather long one liner
			//problem[i][j] = min(min(problem[i - 1][j] + 1, problem[i][j - 1] + 1), problem[i - 1][j - 1] + diff(i, j));
			minimum = min(problem[i - 1][j], problem[i][j - 1]);
			++minimum;
			minimum = min(minimum, problem[i - 1][j - 1] + diff(i - 1, j - 1));
			problem[i][j] = minimum;
		}

	return problem.back().back();

}

int diff(int x, int y){
	if(word1[x] == word2[y])
		return 0;
	else
		return 1;
}

void print_path(){

	int top, left, tl, minimum;

	vector<char> reverse_path1, reverse_path2;
	// print result matrix
	/*
	for(int k = 0; k < problem.size(); ++k){
		for(int h = 0; h < problem.size(); ++h)
			cout << problem[k][h] << "\t";
		cout << endl;
	}
	*/

	int i = problem.size() - 1;
	int j = problem[0].size() - 1;

	// go through result matrix from result to origin
	for(; i > 0 || j > 0;){
		top = problem[i - 1][j];
		left = problem[i][j - 1];
		tl = problem[i - 1][j - 1];
		minimum = min(min(top, left), tl);
		if(minimum == tl){
			reverse_path1.push_back(word1[i - 1]);
			reverse_path2.push_back(word2[j - 1]);
			--i;--j;
		} else
		if(minimum == left){
			reverse_path1.push_back('_');
			reverse_path2.push_back(word2[j - 1]);
			--j;
		} else
		if(minimum == top){
			reverse_path1.push_back(word1[i - 1]);
			reverse_path2.push_back('_');
			--i;
		}
	}

	// print edited first word
	for(;reverse_path1.size() > 0;){
		cout << reverse_path1.back() << " ";
		reverse_path1.pop_back();
	}
	cout << endl;

	// print edited second word
	for(;reverse_path2.size() > 0;){
		cout << reverse_path2.back() << " ";
		reverse_path2.pop_back();
	}
	cout << endl;

}