#include <string>
#include <vector>
#include <stack>

//Write a function, depthFirstValues, that takes in a pointer to the root of a binary tree. The function should
//return a vector containing all values of the tree in depth-first order.


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


std::vector<std::string> depthFirstValues(Node* root) {
    
    std::vector<std::string> values;
    std::stack<Node*> stack;
    if(root != nullptr){
        stack.push(root);
    }

    while (stack.size() > 0){
        Node* current =  stack.top();
        values.push_back(current->val);
        stack.pop();
        if(current->right != nullptr){
            stack.push(current->right);
        }
        if(current->left != nullptr){
            stack.push(current->left);
        }
    }
    return values;
}

void depthFirstValuesRe(Node* root, std::vector<std::string> &values) {
    if(root == nullptr){
        return;
    }
    values.push_back(root->val);
    depthFirstValuesRe(root->left, values);
    depthFirstValuesRe(root->right, values);
}

std::vector<std::string> depthFirstValuesRe(Node* root) {
    std::vector<std::string> values;
    depthFirstValuesRe(root, values);
    return values;
}



int main() {
    Node a("a");
    Node b("b");
    Node c("c");
    Node d("d");
    Node e("e");
    Node f("f");

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;

    //      a
    //    /   \
    //   b     c
    //  / \     \
    // d   e     f

    depthFirstValues(&a); 
    //    -> ["a", "b", "d", "e", "c", "f"]

    Node a1("a");
    Node b1("b");
    Node c1("c");
    Node d1("d");
    Node e1("e");
    Node f1("f");
    Node g1("g");

    a1.left = &b1;
    a1.right = &c1;
    b1.left = &d1;
    b1.right = &e1;
    c1.right = &f1;
    e1.left = &g1;

    //      a
    //    /   \
    //   b     c
    //  / \     \
    // d   e     f
    //    /
    //   g

    depthFirstValues(&a1); 
    //    -> ["a", "b", "d", "e", "g", "c", "f"]

    Node a2("a");
    //      a
    depthFirstValues(&a2); 
    //    -> ["a"]

    Node a3("a");
    Node b3("b");
    Node c3("c");
    Node d3("d");
    Node e3("e");

    a3.right = &b3;
    b3.left = &c3;
    c3.right = &d3;
    d3.right = &e3;

    //      a
    //       \
    //        b
    //       /
    //      c
    //       \
    //        d
    //         \
    //          e

    depthFirstValues(&a3); 
    //    -> ["a", "b", "c", "d", "e"]

    depthFirstValues(nullptr); 
    //    -> []
}

//Complexity
    //n = number of nodes

    //Time: O( n )
    //space:  O( n )