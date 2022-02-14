#include <vector>
#include <string>
#include <stack>

//Write a function, leafList, that takes in a pointer to the root of a binary tree and returns a vector containing the
//values of all leaf nodes in left-to-right order.


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


//Depth First Iterative
// std::vector<std::string> leafList(Node* root) {
//     std::stack<Node*> stack;
//     std::vector<std::string> result;

//     if(root != nullptr){
//         stack.push(root);
//     }

//     while(stack.size() > 0){
//         Node* current = stack.top();
//         stack.pop();

//         if(current->right == nullptr && current->left == nullptr){
//             result.push_back(current->val);
//         }

//         if(current->right != nullptr){
//             stack.push(current->right);
//         }

//         if(current->left != nullptr){
//             stack.push(current->left);
//         }

        
//     }
//     return result;
// }


//Depth First Recurisve with helper function
void fillLeaves(Node* root, std::vector<std::string> &leaves){
    if (root == nullptr){
        return;
    }

    if(root->left == nullptr && root->right == nullptr){
        leaves.push_back(root->val);
    }

    fillLeaves(root->left, leaves);
    fillLeaves(root->right, leaves);
}

std::vector<std::string> leafList(Node* root) {
    std::vector<std::string> leaves;

    fillLeaves(root, leaves);
    return leaves;


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

    leafList(&a1); // -> [ "d", "e", "f" ]

    Node a2("a");
    Node b2("b");
    Node c2("c");
    Node d2("d");
    Node e2("e");
    Node f2("f");
    Node g2("g");
    Node h2("h");

    a2.left = &b2;
    a2.right = &c2;
    b2.left = &d2;
    b2.right = &e2;
    c2.right = &f2;
    e2.left = &g2;
    f2.right = &h2;

    //      a
    //    /   \
    //   b     c
    //  / \     \
    // d   e     f
    //    /       \
    //   g         h

    leafList(&a2); // -> [ "d", "g", "h" ]

    Node a("5");
    Node b("11");
    Node c("54");
    Node d("20");
    Node e("15");
    Node f("1");
    Node g("3");

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    e.left = &f;
    e.right = &g;

    //        5
    //     /    \
    //    11    54
    //  /   \
    // 20   15
    //      / \
    //     1  3

    leafList(&a); // -> [ "20", "1", "3", "54" ]

    Node x("x");

    //      x

    leafList(&x); // -> [ "x" ]

    leafList(nullptr); // -> [ ]
}

//Complexity
    //n = number of nodes

    //Time: O( n )
    //Space: O( n )