#include <iostream>

using namespace std;

// words to be used on algorithm
string word1, word2;

int edit_distance(int size1, int size2); // edit distance

int main(){

	// read inputs
	while(getline(cin, word1) && getline(cin, word2)){

		// print inputs
		cout << "word1: " << word1 << ", length: " << word1.length() << endl;
		cout << "word2: " << word2 << ", length: " << word2.length() << endl;

		cout << "edit distance: " << edit_distance(word1.length(), word2.length()) << endl;

	}

}

int edit_distance(int size1, int size2){

	int insert, erase, keep, diff, minimum;

	// base cases
	if(size1 == 0)
		return size2;
	if(size2 == 0)
		return size1;

	/* recursion */

	// calculate the 3 possible subproblems
	if(word1[size1] == word2[size2])
		diff = 0;
	else
		diff = 1;
	keep = edit_distance(size1 - 1, size2 - 1) + diff;
	insert = edit_distance(size1 - 1, size2) + 1;
	erase = edit_distance(size1, size2 - 1) + 1;

	minimum = insert;
	// minimum out of all
	if(keep != -1)
		minimum = min(keep, minimum);
	minimum = min(minimum, erase);
	return minimum;
}