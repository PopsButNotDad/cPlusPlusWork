//Write a function, mergeLists, that takes in pointers to the heads of the two sorted linked lists. The function should
//merge the linked two lists together into single sorted linked list. The function should return a pointer to the head
//of the merged linked lists. 

//Do this in place, by mutating the original Nodes.

//You may assume that both input lists are non-empty and contain increasing sorted numbers.


class Node {
    public:
        int val;
        Node* next;

    Node(int initialVal) {
        val = initialVal;
        next = nullptr;
    }
};



Node* mergeLists(Node* head1, Node* head2) {
    Node dummyHead(0);
    Node* tail = &dummyHead;
    Node* current1 = head1;
    Node* current2 = head2;
    while (current1 != nullptr && current2 != nullptr){
        if (current1->val < current2->val){
            tail->next = current1;
            current1 = current1->next;
        } else {
            tail->next = current2;
            current2 = current2->next;
        }
        tail = tail->next;
    }
    if(current1 == nullptr){
        tail->next = current2;
    }
    if(current2 == nullptr){
        tail->next = current1;
    }
    return dummyHead.next;
}


//recursive function will return the head of the list so we don't need the dummy head variable like the iterative version
Node* mergeListsRe(Node* head1, Node* head2) {
    if(head1 == nullptr){
        return head2;
    }
    if(head2 == nullptr){
        return head1;
    }

    if(head1->val < head2->val){
        head1->next =mergeListsRe(head1->next, head2);
        return head1;
    } else {
        head2->next = mergeListsRe(head1, head2->next);
        return head2;
    }
}


int main() {
    Node a(5);
    Node b(7);
    Node c(10);
    Node d(12);
    Node e(20);
    Node f(28);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    // 5 -> 7 -> 10 -> 12 -> 20 -> 28

    Node q(6);
    Node r(8);
    Node s(9);
    Node t(25);
    q.next = &r;
    r.next = &s;
    s.next = &t;
    // 6 -> 8 -> 9 -> 25

    mergeLists(&a, &q);
    // 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 12 -> 20 -> 25 -> 28 

    Node a0(5);
    Node b0(7);
    Node c0(10);
    Node d0(12);
    Node e0(20);
    Node f0(28);
    a0.next = &b0;
    b0.next = &c0;
    c0.next = &d0;
    d0.next = &e0;
    e0.next = &f0;
    // 5 -> 7 -> 10 -> 12 -> 20 -> 28

    Node q0(1);
    Node r0(8);
    Node s0(9);
    Node t0(10);
    q0.next = &r0;
    r0.next = &s0;
    s0.next = &t0;
    // 1 -> 8 -> 9 -> 10

    mergeLists(&a0, &q0);
    // 1 -> 5 -> 7 -> 8 -> 9 -> 10 -> 10 -> 12 -> 20 -> 28 

    Node h(30);
    // 30

    Node p(15);
    Node z(67);
    p.next = &z;
    // 15 -> 67

    mergeLists(&h, &p);
    // 15 -> 30 -> 67
}

//Iterative Complexity
    //n = length of list 1
    //m = length of list 2

    //Time: O( min(n,m) )
    //space: O( 1 )

//Recursive Complexity
    //n = length of list 1
    //m = length of list 2

    //Time: O( min(n,m) )
    //Space: O( min(n,m) )