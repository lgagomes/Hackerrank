/*
https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/problem

The height of a binary tree is the number of edges between the tree's root
and its furthest leaf. This means that a tree containing a single node has
a height of 0.

Complete the getHeight function provided in your editor so that it returns
the height of a binary tree. This function has a parameter, root, which is
a pointer to the root node of a binary tree.

Note: The Height of binary tree with single node is taken as zero.


Sample Input
7
3
5
2
1
4
6
7

        3
      /   \
    2      5
   /     /   \
  1     4     6
               \
                7

Note: A binary search tree is a binary tree in which the value of each parent
node's left child is less than the value the parent node, and the value of the
parent node is less than the value of its right child.

Sample Output
3

Explanation
The longest root-to-leaf path is 3 -> 5 -> 6 -> 7

There are 4 nodes in this path that are connected by 3 edges, meaning our binary
tree's height = 3. Thus, we print 3 as our answer.
*/

#include <iostream>
#include <cstddef>

using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution
{
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }
            else {
                Node* cur;
                if(data <= root->data){
                    cur = insert(root->left, data);
                    root->left = cur;
                }
                else{
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
}

/*The tree node has data, left child and right child
class Node {
    int data;
    Node* left;
    Node* right;
};

*/

int height(Node* root) {
        if (root==NULL)
            return -1;
        else
        {
            /* compute the depth of each subtree */
            int lDepth = height(root->left);
            int rDepth = height(root->right);

            /* use the larger one */
            if (lDepth > rDepth)
                return(lDepth+1);
            else
                return(rDepth+1);
        }
    }
}; //End of Solution

int main() {
    Solution myTree;
    Node* root = NULL;
    int t;
    int data;

    cin >> t;

    while(t-- > 0){
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.height(root);
    cout << height;

    return 0;
}



