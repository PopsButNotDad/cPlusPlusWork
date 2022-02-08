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



int treeSum(Node* root) {
    // todo
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