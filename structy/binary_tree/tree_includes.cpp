#include <string>
#include <stack>
#include <queue>

//Write a function, treeIncludes, that takes in a pointer to the root of a binary tree and a target value.
//The function should return a boolean indicating whether or not the value is contained in the tree.

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


//Breadth first
// bool treeIncludes(Node* root, std::string targetVal) {
//     std::queue<Node*> queue;

//     if(root != nullptr){
//         queue.push(root);
//     } 

//     while(queue.size() > 0){
//         Node* current = queue.front();
//         queue.pop();
//         if(current->val == targetVal){
//             return true;
//         }

//         if(current->left != nullptr){
//             queue.push(current->left);
//         }
//         if(current->right != nullptr){
//             queue.push(current->right);
//         }

//     }
//     return false;
// }


//depth first iterative
// bool treeIncludes(Node* root, std::string targetVal) {
//     std::stack<Node*> stack;

//     if(root != nullptr){
//         stack.push(root);
//     } 

//     while(stack.size() > 0){
//         Node* current = stack.top();
//         stack.pop();
//         if(current->val == targetVal){
//             return true;
//         }

//         if(current->left != nullptr){
//             stack.push(current->left);
//         }
//         if(current->right != nullptr){
//             stack.push(current->right);
//         }

//     }
//     return false;
// }

//depth first recursive
bool treeIncludes(Node* root, std::string targetVal){
    if(root == nullptr){
        return false;
    }

    if(root->val == targetVal){
        return true;
    }

    return treeIncludes(root->left, targetVal);
    
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

    treeIncludes(&a1, "e"); // -> 1 (true)

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

    treeIncludes(&a2, "a"); // -> 1 (true)

    Node a3("a");
    Node b3("b");
    Node c3("c");
    Node d3("d");
    Node e3("e");
    Node f3("f");

    a3.left = &b3;
    a3.right = &c3;
    b3.left = &d3;
    b3.right = &e3;
    c3.right = &f3;

    //      a
    //    /   \
    //   b     c
    //  / \     \
    // d   e     f

    treeIncludes(&a3, "n"); // -> 0 (false)

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

    treeIncludes(&a, "f"); // -> 1 (true)

    Node a4("a");
    Node b4("b");
    Node c4("c");
    Node d4("d");
    Node e4("e");
    Node f4("f");
    Node g4("g");
    Node h4("h");

    a4.left = &b4;
    a4.right = &c4;
    b4.left = &d4;
    b4.right = &e4;
    c4.right = &f4;
    e4.left = &g4;
    f4.right = &h4;

    //      a
    //    /   \
    //   b     c
    //  / \     \
    // d   e     f
    //    /       \
    //   g         h

    treeIncludes(&a4, "p"); // -> 0 (false)

    treeIncludes(nullptr, "b"); // -> 0 (false)
}

//Complexity for both iterative and recursive
    //n = number of nodes

    //Time: O( n )
    //Space: O( n )
