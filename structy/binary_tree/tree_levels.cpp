#include <vector>
#include <string>

//Write a function, treeLevels, that takes in a pointer to the root of a binary tree. The function should return
//a 2-Dimensional array where each subarray represents a level of the tree.

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



std::vector<std::vector<std::string>> treeLevels(Node* root) {
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

    treeLevels(&a1); // ->
    // [
    //   ["a"],
    //   ["b", "c"],
    //   ["d", "e", "f"]
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

    treeLevels(&a); // ->
    // [
    //   ["a"],
    //   ["b", "c"],
    //   ["d", "e", "f"],
    //   ["g", "h", "i"]
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

    treeLevels(&q); //->
    // [
    //   ["q"],
    //   ["r", "s"],
    //   ["t"],
    //   ["u"],
    //   ["v"]
    // ]

    treeLevels(nullptr); // -> []
}