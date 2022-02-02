//Write a function, sumList, that takes in a pointer to the head of a linked list containing numbers as an argument. 
//The function should return the total sum of all values in the linked list.

class Node {
    public:
        int val;
        Node* next;

    Node(int initialVal) {
        val = initialVal;
        next = nullptr;
    }
};

int sumList(Node* head) {
    int result = 0;
    Node* current = head;
    while (current != nullptr){
        result = current->val + result;
        current = current->next;
    }
    return result;
}

int sumListRe(Node* head){
    if (head == nullptr) {
        return 0;
    }

    return head->val + sumListRe(head->next);

}

int main() {
    Node a(2);
    Node b(8);
    Node c(3);
    Node d(-1);
    Node e(7);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e; 
    
    // 2 -> 8 -> 3 -> -1 -> 7

    sumList(&a); // 19

    Node x(38);
    Node y(4);

    x.next = &y; // 38 -> 4

    sumList(&x); // 42

    Node z(100); // 100

    sumList(&z); // 100

    sumList(nullptr); // 0

}

//Iterative Complexity
    //n = number of nodes 

    //Time: O( n )
    //Space: O( n )

//Recursive Complexity
    //n = number of nodes 

    //Time: O( n )
    //Space: O( n )