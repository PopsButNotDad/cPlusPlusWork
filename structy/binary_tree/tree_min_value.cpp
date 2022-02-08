#include <stack>
#include <queue>

//Write a function, treeMinValue, that takes in a pointer to the root of a binary tree that contains number values.
//The function should return the minimum value within the tree.

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



int treeMinValue(Node* root) {

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

    treeMinValue(&a1); // -> -2

    Node a2(5);
    Node b2(11);
    Node c2(3);
    Node d2(4);
    Node e2(14);
    Node f2(12);

    a2.left = &b2;
    a2.right = &c2;
    b2.left = &d2;
    b2.right = &e2;
    c2.right = &f2;

    //       5
    //    /    \
    //   11     3
    //  / \      \
    // 4   14     12

    treeMinValue(&a2); // -> 3

    Node a(-1);
    Node b(-6);
    Node c(-5);
    Node d(-3);
    Node e(-4);
    Node f(-13);
    Node g(-2);
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
    // -3   -4   -13
    //     /       \
    //    -2       -2

    treeMinValue(&a); // -> -13

    Node a3(42);

    //        42

    treeMinValue(&a3); // -> 42
}