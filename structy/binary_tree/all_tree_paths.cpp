#include <vector>
#include <string>

//Write a function, allTreePaths, that takes in a pointer to the root of a binary tree. The function should return 
//a 2-dimensional vector where each subvector represents a root-to-leaf path in the tree. 

//The order within an individual path must start at the root and end at the leaf, but the relative order among paths in 
//the outer vector does not matter. 

//You may assume that the input tree is non-empty.

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

std::vector<std::vector<std::string>> allTreePaths(Node* root) {
    // todo
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

    allTreePaths(&a1); // ->
    // [
    //   [ "a", "b", "d" ],
    //   [ "a", "b", "e" ],
    //   [ "a", "c", "f" ]
    // ]

    Node a("a");
    Node b("b");
    Node c("c");
    Node d("d");
    Node e("e");
    Node f("f");
    Node g("g");
    Node h("h");
    Node i("i");

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    e.left = &g;
    e.right = &h;
    f.left = &i;

    //         a
    //      /    \
    //     b      c
    //   /  \      \
    //  d    e      f
    //      / \    /
    //     g  h   i

    allTreePaths(&a); // ->
    // [
    //   [ "a", "b", "d" ],
    //   [ "a", "b", "e", "g" ],
    //   [ "a", "b", "e", "h" ],
    //   [ "a", "c", "f", "i" ]
    // ]

    Node q("q");
    Node r("r");
    Node s("s");
    Node t("t");
    Node u("u");
    Node v("v");

    q.left = &r;
    q.right = &s;
    r.right = &t;
    t.left = &u;
    u.right = &v;

    //      q
    //    /   \
    //   r     s
    //    \
    //     t
    //    /
    //   u
    //  /
    // v

    allTreePaths(&q); // ->
    // [
    //   [ "q", "r", "t", "u", "v" ],
    //   [ "q", "s" ]
    // ]

    Node z("z");

    //      z

    allTreePaths(&z); // ->
    // [
    //   ["z"]
    // ]
}

//Complexity
    //n = number of nodes 

    //Time: ~O( n )
    //Space: ~O( n )