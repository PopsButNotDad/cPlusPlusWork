#include <vector>

//Write a function, levelAverages, That takes in a pointer to the root of a binary tree that contains number
//values. The function should return a vector containing the average value of each level.

class Node {
    public:
        float val;
        Node* left;
        Node* right;


    Node(float initialVal) {
        val = initialVal;
        left = nullptr;
        right = nullptr;
    }
};



std::vector<float> levelAverages(Node* root) {
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

    levelAverages(&a1); // -> [ 3, 7.5, 1 ]

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

    levelAverages(&a2); // -> [ 5, 32.5, 17.5, 2 ]

    Node a(-1);
    Node b(-6);
    Node c(-5);
    Node d(-3);
    Node e(0);
    Node f(45);
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
    // -3   0     45
    //     /       \
    //    -1       -2

    levelAverages(&a); // -> [ -1, -5.5, 14, -1.5 ]

    Node q(13);
    Node r(4);
    Node s(2);
    Node t(9);
    Node u(2);
    Node v(42);

    q.left = &r;
    q.right = &s;
    r.right = &t;
    t.left = &u;
    u.right = &v;

    //        13
    //      /   \
    //     4     2
    //      \
    //       9
    //      /
    //     2
    //    /
    //   42

    levelAverages(&q); // -> [ 13, 3, 9, 2, 42 ]

    levelAverages(nullptr); // -> [ ]
}