#include <string>
#include <algorithm>

//Write a function, howHigh, that takes in a pointer to the root of a binary tree. The function should return a number
//representing the height of the tree.

//The height of a binary tree is defined as the maximal number of edges from the root node to any leaf node.

//If the tree is empty return -1;

class Node {
    public:
        std::string val;
        Node* left;
        Node* right;


    Node(std::string initialVal) {
        val = initialVal;
        left = nullptr;
        right = nullptr;
    }
};


int howHigh(Node* root) {
    if(root == nullptr){
        return -1;
    }
    return 1 + std::max(howHigh(root->left), howHigh(root->right));
    
}

int main() {
    Node a1("a");
    Node b1("b");
    Node c1("c");
    Node d1("d");
    Node e1("e");
    Node f1("f");

    a1.left = &b1;
    a1.right = &c1;
    b1.left = &d1;
    b1.right = &e1;
    c1.right = &f1;

    //      a
    //    /   \
    //   b     c
    //  / \     \
    // d   e     f

    howHigh(&a1); // -> 2

    Node a("a");
    Node b("b");
    Node c("c");
    Node d("d");
    Node e("e");
    Node f("f");
    Node g("g");

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    e.left = &g;

    //      a
    //    /   \
    //   b     c
    //  / \     \
    // d   e     f
    //    /
    //   g

    howHigh(&a); // -> 3

    Node a2("a");
    Node c2("c");

    a2.right = &c2;

    //      a
    //       \
    //        c

    howHigh(&a2); // -> 1

    Node a3("a");

    //      a

    howHigh(&a3); // -> 0

    howHigh(nullptr); // -> -1
}

//Complexity: 
    //n = number of nodes 

    //Time: O( n )
    //Space: O( n )