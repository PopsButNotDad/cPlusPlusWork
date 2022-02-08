#include <string>

class Node {
    public:
        Node* left;
        Node* right;
        std::string val;


    Node(std::string initialVal){
        val = initialVal;
        left = nullptr;
        right = nullptr;
    }
};




int main() {
    Node a("A");
    Node b("B");
    Node c("C");
    Node d("D");
    Node e("E");
    Node f("F");

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right= &e;
    c.right = &f;

}

//          a
//        /  \
//      B     C
//    /  \     \
//   D    E     F
