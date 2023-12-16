//Some basic concepts of trees:

/*
Nodes:
The topmost node of the tree is called the root, and the nodes below it are called the child nodes. 
Each node can have multiple child nodes.

Root:
In a tree data structure, the first node is called as Root Node. Every tree must have a root node. 
We can say that the root node is the origin of the tree data structure.

Ancestor:
Any predecessor nodes on the path of the root to that node are called Ancestors of that node.

Parent:
The node which is a predecessor of a node is called the parent node of that node.

Child :
The node which is a descendant of any node, is known as child node. 
In binary tree one node can have maximum of only two child nodes.

Edge:
The link between two nodes is called an edge. 

Leaf node:
An external node (also known as an outer node, leaf node, or terminal node) is any node that does not have child nodes.
A leaf node is the bottom-most node of the tree.

Siblings:
The nodes with the same parent are called Sibling nodes.
*/




//Types of Binary Trees:

/*
1. Full binary tree
  Every node will have either 0 or 2 children.
  
2. Complete binary tree
  All levels should be completely filled except the last level.
  THe last level has all nodes on as left as possible.
  (start filling the tree from the left)
  
3. Perfect binary tree
  All the leaf nodes are at the same level in a perfect binary tree.
  
4. Balanced binary tree
  Height of the tree at maximum is : log(n) where n is the total number of nodes.
  eg. n=8 then log(8) to the base 2 = 3, thus you cannot have a tree of height greater than 3.
  
5. Degenerate binary tree
  Degenerate tree is a skewed tree. 
  (tree is in a straight line or every node has only one child)
*/
