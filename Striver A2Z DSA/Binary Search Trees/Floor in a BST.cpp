/*
Floor of a key is the greatest value which is smaller than or equal to the given key.

eg, given the elements 2, 5, 6, 10, 15 and key=7, floor of 7 is then 6.
Had 7 been present in the array, that would have been 7.
*/

//code:

int Floor(BinaryTreeNode<int> *root, int x){
	int floor=-1;

	while(root){
		if(root->data==x) return x;

		if(root->data>x){
			root= root->left;
		}else{
			floor= root->data;
			root= root->right;
		}
	}
	return floor;
}

