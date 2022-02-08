#include <queue>
#include <stack>
#include <iostream>

//Write a function, treeSum, that takes in a pointer to the root of a binary tree that contains number values.
//The function should return the total sum of all values in the tree.

class Node {
    public:
        int val;
        Node* left;
        Node* right;


    Node(int initialVal) {
        val = initialVal;
        left = nullptr;
        right = nullptr;
    }
};


//Breadth first
// int treeSum(Node* root) {
//     int result = 0;
//     std::queue<Node*> queue;

//     if(root != nullptr){
//         queue.push(root);
//     }

//     while(queue.size() > 0){
//         Node* current = queue.front();
//         queue.pop();

//         result += current->val;

//         if(current->left != nullptr){
//             queue.push(current->left);
//         }

//         if(current->right != nullptr){
//             queue.push(current->right);
//         }
//     }

//     return result;
// }

//Depth First Iterative
// int treeSum(Node* root) {
//     int result = 0;
//     std::stack<Node*> stack;

//     if(root != nullptr){
//         stack.push(root);
//     }

//     while(stack.size() > 0){
//         Node* current = stack.top();
//         stack.pop();
//         result += current->val;
//         if(current->right != nullptr){
//             stack.push(current->right);
//         }
//         if(current->left != nullptr){
//             stack.push(current->left);
//         }


//     }
//     return result;
// }

//Depth First Recursive
int treeSum(Node* root) {
    if(root == nullptr){
        return 0;
    }

    
}

int main() {
    Node a1(3);
    Node b1(11);
    Node c1(4);
    Node d1(4);
    Node e1(-2);
    Node f1(1);

    a1.left = &b1;
    a1.right = &c1;
    b1.left = &d1;
    b1.right = &e1;
    c1.right = &f1;

    //       3
    //    /    \
    //   11     4
    //  / \      \
    // 4   -2     1

    treeSum(&a1); // -> 21

    Node a(1);
    Node b(6);
    Node c(0);
    Node d(3);
    Node e(-6);
    Node f(2);
    Node g(2);
    Node h(2);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    e.left = &g;
    f.right = &h;

    //      1
    //    /   \
    //   6     0
    //  / \     \
    // 3   -6    2
    //    /       \
    //   2         2

    treeSum(&a); // -> 10

    treeSum(nullptr); // -> 0
}

//Recursive complexity
    //n = number of nodes

    //Time: O( n )
    //Space: O( n )