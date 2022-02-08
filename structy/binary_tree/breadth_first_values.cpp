#include <string>
#include <vector>
#include <queue>

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



std::vector<std::string> breadthFirstValues(Node* root) {
    
    return;
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

    breadthFirstValues(&a1);
    //    -> ["a", "b", "c", "d", "e", "f"]

    Node a("a");
    Node b("b");
    Node c("c");
    Node d("d");
    Node e("e");
    Node f("f");
    Node g("g");
    Node h("h");

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    e.left = &g;
    f.right = &h;

    //      a
    //    /   \
    //   b     c
    //  / \     \
    // d   e     f
    //    /       \
    //   g         h

    breadthFirstValues(&a);
    //   -> ["a", "b", "c", "d", "e", "f", "g", "h"]

    Node a3("a");

    //      a

    breadthFirstValues(&a3);
    //    -> ["a"]

    Node a2("a");
    Node b2("b");
    Node c2("c");
    Node d2("d");
    Node e2("e");
    Node x2("x");

    a2.right = &b2;
    b2.left = &c2;
    c2.left = &x2;
    c2.right = &d2;
    d2.right = &e2;

    //      a
    //       \
    //        b
    //       /
    //      c
    //    /  \
    //   x    d
    //         \
    //          e

    breadthFirstValues(&a2);
    //    -> ["a", "b", "c", "x", "d", "e"]

    breadthFirstValues(nullptr);
    //    -> []
}
