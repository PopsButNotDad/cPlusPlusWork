#include <stack>
#include <queue>

//Write a function, treeValueCount, that takes in a pointer to the root of a binary treeand a target value.
//The function should return the number of times that target occurs in the tree.


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


//Breadth First Iterative
// int treeValueCount(Node* root, int targetVal) {
//     std::queue<Node*> queue;
//     int count = 0;

//     if(root != nullptr){
//         queue.push(root);
//     }

//     while(queue.size() > 0){
//         Node* current = queue.front();
//         queue.pop();

//         if(current->val == targetVal){
//             count += 1;
//         }

//         if(current->left != nullptr){
//             queue.push(current->left);
//         }

//         if(current->right != nullptr){
//             queue.push(current->right);
//         }
//     }
//     return count;
// }

//Depth First Iterative
// int treeValueCount(Node* root, int targetVal) {
//     std::stack<Node*> stack;
//     int count = 0;

//     if(root!=nullptr){
//         stack.push(root);
//     }

//     while(stack.size() > 0){
//         Node* current = stack.top();
//         stack.pop();

//         if(current->val == targetVal){
//             count += 1;
//         }

//         if(current->left != nullptr){
//             stack.push(current->left);
//         }

//         if(current->right != nullptr){
//             stack.push(current->right);
//         }
//     }
    
//     return count;
// }

//Depth First Recursive
int treeValueCount(Node* root, int targetVal) {
    if(root == nullptr){
        return 0;
    }


    //ternary operator can refactor this
    // if(root->val == targetVal){
    //     return 1 + treeValueCount(root->left, targetVal) + treeValueCount(root->right, targetVal);
    // } else {
    //     return treeValueCount(root->left, targetVal) + treeValueCount(root->right, targetVal);
    // }

    int match = root->val == targetVal ? 1 : 0;

    return match + treeValueCount(root->left, targetVal) + treeValueCount(root->right, targetVal);

}

int main() {
    Node a0(12);
    Node b0(6);
    Node c0(6);
    Node d0(4);
    Node e0(6);
    Node f0(12);

    a0.left = &b0;
    a0.right = &c0;
    b0.left = &d0;
    b0.right = &e0;
    c0.right = &f0;

    //      12
    //    /   \
    //   6     6
    //  / \     \
    // 4   6     12

    treeValueCount(&a0,  6); // -> 3

    Node a1(12);
    Node b1(6);
    Node c1(6);
    Node d1(4);
    Node e1(6);
    Node f1(12);

    a1.left = &b1;
    a1.right = &c1;
    b1.left = &d1;
    b1.right = &e1;
    c1.right = &f1;

    //      12
    //    /   \
    //   6     6
    //  / \     \
    // 4  6     12

    treeValueCount(&a1,  12); // -> 2

    Node a(7);
    Node b(5);
    Node c(1);
    Node d(1);
    Node e(8);
    Node f(7);
    Node g(1);
    Node h(1);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    e.left = &g;
    f.right = &h;

    //      7
    //    /   \
    //   5     1
    //  / \     \
    // 1   8     7
    //    /       \
    //   1         1
    treeValueCount(&a, 1); // -> 4

    Node a2(7);
    Node b2(5);
    Node c2(1);
    Node d2(1);
    Node e2(8);
    Node f2(7);
    Node g2(1);
    Node h2(1);

    a2.left = &b2;
    a2.right = &c2;
    b2.left = &d2;
    b2.right = &e2;
    c2.right = &f2;
    e2.left = &g2;
    f2.right = &h2;

    //      7
    //    /   \
    //   5     1
    //  / \     \
    // 1   8     7
    //    /       \
    //   1         1

    treeValueCount(&a2, 9); // -> 0

    treeValueCount(nullptr, 42); // -> 0
}

//Complexity
    //n = number of nodes 

    //Time: O( n )
    //Space: O( n )