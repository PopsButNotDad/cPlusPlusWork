//Write a function, isUnivalueList, that takes in the head of a linked list as an argument. The function should
//return a boolean indivating whether or not the linked list contains exactly one inque value.

//You may assume that the inpyut list is non-empty.

class Node {
    public:
        int val;
        Node* next;

    Node(int initialVal) {
        val = initialVal;
        next = nullptr;
    }
};

bool isUnivalueList(Node* head) {
    Node* current = head;

    while(current != nullptr){
        if(current->val == head->val){
            current = current->next;
        } else{
            return false;
        }
    }
    return true;
}

bool isUnivalueListRe(Node* head) {

}

int main () {
    Node a(7);
    Node b(7);
    Node c(7);

    a.next = &b;
    b.next = &c;

    // 7 -> 7 -> 7

    isUnivalueList(&a); // 1 (true)

    Node a0(7);
    Node b0(7);
    Node c0(4);

    a0.next = &b0;
    b0.next = &c0;

    // 7 -> 7 -> 4

    isUnivalueList(&a0); // 0 (false)

    Node u(2);
    Node v(2);
    Node w(2);
    Node x(2);
    Node y(2);

    u.next = &v;
    v.next = &w;
    w.next = &x;
    x.next = &y;

    // 2 -> 2 -> 2 -> 2 -> 2

    isUnivalueList(&u); // 1 (true)

    Node u0(2);
    Node v0(2);
    Node w0(3);
    Node x0(3);
    Node y0(2);

    u0.next = &v0;
    v0.next = &w0;
    w0.next = &x0;
    x0.next = &y0;

    // 2 -> 2 -> 3 -> 3 -> 2

    isUnivalueList(&u0); // 0 (false)

    Node z(42);

    // 42

    isUnivalueList(&z); // 1 (true)
}

//Iterative Complexity
    //n = number of nodes

    //Time: O( n )
    //Space: O( 1 )

//Recursive Complexity
    //n = number of nodes

    //Time: O( n )
    //Space: O( n )