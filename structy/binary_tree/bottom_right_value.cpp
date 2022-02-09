#include <string>
#include <queue>

//Write a function, bottomRightValue, that takes in a pointer to the root of a binary tree. The function should return
//the right-most value in the bottom-most level of the tree.

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



std::string bottomRightValue(Node* root) {
    std::queue<Node*> queue;
    queue.push(root);

    Node* current;
    while(queue.size() > 0){
        current = queue.front();
        queue.pop();

        if(current->left != nullptr){
            queue.push(current->left);
        }

        if(current->right != nullptr){
            queue.push(current->right);
        }
    }
    return current->val;
}

int main() {
    Node a0("3");
    Node b0("11");
    Node c0("10");
    Node d0("4");
    Node e0("-2");
    Node f0("1");

    a0.left = &b0;
    a0.right = &c0;
    b0.left = &d0;
    b0.right = &e0;
    c0.right = &f0;

    //       3
    //    /    \
    //   11     10
    //  / \      \
    // 4   -2     1

    bottomRightValue(&a0); // -> "1"

    Node a1("-1");
    Node b1("-6");
    Node c1("-5");
    Node d1("-3");
    Node e1("-4");
    Node f1("-13");
    Node g1("-2");
    Node h1("6");

    a1.left = &b1;
    a1.right = &c1;
    b1.left = &d1;
    b1.right = &e1;
    c1.right = &f1;
    e1.left = &g1;
    e1.right = &h1;

    //        -1
    //      /   \
    //    -6    -5
    //   /  \     \
    // -3   -4   -13
    //     / \       
    //    -2  6

    bottomRightValue(&a1); // -> "6"

    Node a("-1");
    Node b("-6");
    Node c("-5");
    Node d("-3");
    Node e("-4");
    Node f("-13");
    Node g("-2");
    Node h("6");
    Node i("7");


    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    e.left = &g;
    e.right = &h;
    f.left = &i;

    //        -1
    //      /   \
    //    -6    -5
    //   /  \     \
    // -3   -4   -13
    //     / \    /   
    //    -2  6  7 

    bottomRightValue(&a); // -> "7"

    Node a2("a");
    Node b2("b");
    Node c2("c");
    Node d2("d");
    Node e2("e");
    Node f2("f");

    a2.left = &b2;
    a2.right = &c2;
    b2.right = &d2;
    d2.left = &e2;
    e2.right = &f2;

    //      a
    //    /   \ 
    //   b     c
    //    \
    //     d
    //    /
    //   e
    //  /
    // f
            
    bottomRightValue(&a2); // -> "f"

    Node a3("42");

    //      42

    bottomRightValue(&a3); // -> "42"
}

//Complexity
    //n = number of nodes 

    //Time: O( n )
    //Space: O( n )