#include <vector>

// Write a function, addLists, that takes in pointers to the heads of two linked lists, each representing a number. 
// The nodes of the linked lists contain digits as values. The nodes in the input lists are reversed; 
// this means that the least significant digit of the number is the head. The function should return the head 
// of a new linked listed representing the sum of the input lists. The output list should have its digits 
// reversed as well.

//Be sure to dynamically allocate the new nodes in memory using new.

class Node {
    public:
        int val;
        Node *next;

    Node(int initialVal){
        val = initialVal;
        next = nullptr;
    }
};

Node *addLists(Node *head1, Node *head2) {
    Node* dummyHead = new Node(0);
    Node* tail = dummyHead;
    int carry = 0;
    Node* current1 = head1;
    Node* current2 = head2;
    while(current1 != nullptr || current2 != nullptr || carry == 1){
        int val1 = current1 == nullptr ? 0 : current1->val;
        int val2 = current2 == nullptr ? 0 : current2->val;
        int sum = val1 + val2 + carry;
        carry = sum > 9 ? 1 : 0;
        int digit = sum % 10;
        if(current1 != nullptr){
            current1 = current1->next;
        }
        if(current2 != nullptr){
            current2 = current2->next;
        }
        tail->next = new Node(digit);
        tail = tail->next;
    }
    return dummyHead->next;
}

Node *addListsRe(Node *head1, Node *head2) {

}

int main() {
    //   621
    // + 354
    // -----
    //   975

    Node a1(1);
    Node a2(2);
    Node a3(6);
    a1.next = &a2;
    a2.next = &a3;
    // 1 -> 2 -> 6

    Node b1(4);
    Node b2(5);
    Node b3(3);
    b1.next = &b2;
    b2.next = &b3;
    // 4 -> 5 -> 3

    addLists(&a1, &b1);
    // 5 -> 7 -> 9

    //  7541
    // +  32
    // -----
    //  7573

    Node a10(1);
    Node a20(4);
    Node a30(5);
    Node a40(7);
    a10.next = &a20;
    a20.next = &a30;
    a30.next = &a40;
    // 1 -> 4 -> 5 -> 7

    Node b10(2);
    Node b20(3);
    b10.next = &b20;
    // 2 -> 3

    addLists(&a10, &b10);
    // 3 -> 7 -> 5 -> 7

    //   39
    // + 47
    // ----
    //   86

    Node a100(9);
    Node a200(3);
    a100.next = &a200;
    // 9 -> 3

    Node b100(7);
    Node b200(4);
    b100.next = &b200;
    // 7 -> 4

    addLists(&a100, &b100);
    // 6 -> 8

    //   89
    // + 47
    // ----
    //  136

    Node a1000(9);
    Node a2000(8);
    a1000.next = &a2000;
    // 9 -> 8

    Node b1000(7);
    Node b2000(4);
    b1000.next = &b2000;
    // 7 -> 4

    addLists(&a1000, &b1000);
    // 6 -> 3 -> 1

    //   999
    //  +  6
    //  ----
    //  1005

    Node a10000(9);
    Node a20000(9);
    Node a30000(9);
    a10000.next = &a20000;
    a20000.next = &a30000;
    // 9 -> 9 -> 9

    Node b10000(6);
    // 6

    addLists(&a10000, &b10000);
    // 5 -> 0 -> 0 -> 1
}

//Iterative & Recursive Complexity
    //n = length of list 1
    //m = length of list 2

    //Time: O( max(n,m) )
    //Space: O( max(n,m) )

