#include <vector>
#include <string>

//Write a function, pathFinder, that takes in a pointer to the root of a binary tree and a target value.
//The function should return a pointer to a vector respresenting a path to the target value.

//Be sure to dynamically allocate the vector with new

//If the target value is not present in the tree, then return nullptr.

//You may assume that the tree contains unique values.

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



std::vector<std::string>* pathFinder(Node* root, std::string targetVal) {
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

    pathFinder(&a1, "e"); // -> [ "a", "b", "e" ]

    Node a2("a");
    Node b2("b");
    Node c2("c");
    Node d2("d");
    Node e2("e");
    Node f2("f");

    a2.left = &b2;
    a2.right = &c2;
    b2.left = &d2;
    b2.right = &e2;
    c2.right = &f2;

    //      a
    //    /   \
    //   b     c
    //  / \     \
    // d   e     f

    pathFinder(&a2, "p"); // -> null

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

    pathFinder(&a, "c"); // -> ["a", "c"]

    Node a3("a");
    Node b3("b");
    Node c3("c");
    Node d3("d");
    Node e3("e");
    Node f3("f");
    Node g3("g");
    Node h3("h");

    a3.left = &b3;
    a3.right = &c3;
    b3.left = &d3;
    b3.right = &e3;
    c3.right = &f3;
    e3.left = &g3;
    f3.right = &h3;

    //      a
    //    /   \
    //   b     c
    //  / \     \
    // d   e     f
    //    /       \
    //   g         h

    pathFinder(&a3, "h"); // -> ["a", "c", "f", "h"]

    Node x("x");

    //      x

    pathFinder(&x, "x"); // -> ["x"]

    pathFinder(nullptr, "x"); // -> null

    Node* root = new Node("0");
    Node* curr = root;
    for (int i = 1; i <= 6000; i += 1) {
    curr->right = new Node(std::to_string(i));
    curr = curr->right;
    }

    //      0
    //       \
    //        1
    //         \
    //          2
    //           \
    //            3
    //             .
    //              .
    //               .
    //              5999
    //                \
    //                6000

    pathFinder(root, "3451"); // -> [0, 1, 2, 3, ..., 3450, 3451]
}

//Complexity
    //n = number of nodes

    //Time: 
    //Space: