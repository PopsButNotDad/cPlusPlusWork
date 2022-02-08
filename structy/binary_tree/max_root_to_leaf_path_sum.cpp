#include <stack>
#include <queue>

//Write a function, maxPathSum, that takes in a pointer to the root of a binary tree that contains number values.
//The function should return the maximum sum of any root to leaf path within the tree.

//You may assume that the input tree is non-empty.

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


//Depth First Recursive
int maxPathSum(Node* root) {
    
    return;
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

    maxPathSum(&a1); // -> 18

    Node a2(5);
    Node b2(11);
    Node c2(54);
    Node d2(20);
    Node e2(15);
    Node f2(1);
    Node g2(3);

    a2.left = &b2;
    a2.right = &c2;
    b2.left = &d2;
    b2.right = &e2;
    e2.left = &f2;
    e2.right = &g2;

    //        5
    //     /    \
    //    11    54
    //  /   \
    // 20   15
    //      / \
    //     1  3

    maxPathSum(&a2); // -> 59

    Node a(-1);
    Node b(-6);
    Node c(-5);
    Node d(-3);
    Node e(0);
    Node f(-13);
    Node g(-1);
    Node h(-2);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    e.left = &g;
    f.right = &h;

    //        -1
    //      /   \
    //    -6    -5
    //   /  \     \
    // -3   0    -13
    //     /       \
    //    -1       -2

    maxPathSum(&a); // -> -8

    Node a3(42);

    //        42

    maxPathSum(&a3); // -> 42
}

//complexity
    //n = number of nodes 

    //Time: O( n )
    //Space: O( n )