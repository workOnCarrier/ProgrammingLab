// bst.cpp : Defines the entry point for the console application.
//

#include "bst.h"

int main(int argc, char* argv[])
{
	myBSTree<int>	tree;
	int input[] = { 20,5,10,6,7,13,9,14,12};
	for ( auto val : input ) {
		tree.addNode ( val );
	}
	return 0;
}

