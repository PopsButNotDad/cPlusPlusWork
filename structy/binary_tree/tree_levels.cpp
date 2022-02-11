#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>

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
// breadth first iterative
std::vector<std::vector<std::string>> treeLevels(Node* root) {
    std::queue<std::tuple<Node*, int>> queue;
    std::vector<std::vector<std::string>> result;

    if(root != nullptr){
        queue.push(std::tuple {root, 0});
    }

    while(queue.size() > 0){
        auto [current, level] = queue.front();
        queue.pop();

        if(result.size() == level){
            result.push_back(std::vector<std::string> {current->val});
        } else{
            result[level].push_back({current->val});
        }


        if(current->left != nullptr){
            queue.push(std::tuple {current->left, level+1});
        }

        if(current->right != nullptr){
            queue.push(std::tuple {current->right, level+1});
        }
    }
    return result;
}

//depth first iterative
// std::vector<std::vector<std::string>> treeLevels(Node* root) {
//     std::stack<std::tuple<Node*, int>> stack;
//     std::vector<std::vector<std::string>> result;


//     if(root != nullptr){
//         stack.push(std::tuple {root, 0});
//     }

//     while(stack.size() > 0){
//         auto [current, level] = stack.top();
//         stack.pop();

//         if(result.size() == level){
//             result.push_back(std::vector<std::string> {current->val});
//         } else{
//             result[level].push_back({current->val});
//         }

//         if(current->right != nullptr){
//             stack.push(std::tuple {current->right, level+1});
//         }

//         if(current->left != nullptr){
//             stack.push(std::tuple {current->left, level+1});
//         }

//     }
//     return result;
// }

//depth first recursive
// void fillLevels(Node* root, std::vector<std::vector<std::string>> &levels, int level) {
//     if (root == nullptr){
//         return;
//     }

//     if(levels.size() == level){
//         levels.push_back(std::vector<std::string> { root->val});
//     } else {
//         levels[level].push_back(root->val);
//     }

//     fillLevels(root->left, levels, level+1);
//     fillLevels(root->right, levels, level+1);
// }

// std::vector<std::vector<std::string>> treeLevels(Node* root) {
//     std::vector<std::vector<std::string>> levels;
//     fillLevels(root, levels, 0);
//     return levels;
// }

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

//Complexity
    //n = number of nodes
    
    //Time: O( n )
    //Space: O( n )