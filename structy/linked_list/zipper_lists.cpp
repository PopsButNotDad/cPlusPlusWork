#include <string>

//Write a function, zipperLists, that takes in pointers to the heads of two linked lists. The function should zipper the
//two lists together into single linked list by alternating nodes. If one of the linked lists is longer than the other,
//the resulting list should terminate with the remaining nodes. The function should return a pointer to the head of the
//zippered linked list. 

//Do this in-place

//You may assume that both input lists are non-empty.

class Node {
    public:
        std::string val;
        Node* next;

    Node(std::string initialVal) {
        val = initialVal;
        next = nullptr;
    }
};

Node* zipperLists(Node* head1, Node* head2) {
    Node* newHead = head1;
    Node* tail = newHead;
    Node* current1 = head1->next;
    Node* current2 = head2;
    int count = 1;

  while (current1 != nullptr && current2 != nullptr){
        if(count % 2 == 0){
            tail->next = current1;
            current1 = current1->next;
        }else {
            tail->next = current2;
            current2 = current2->next;
        }
        tail = tail->next;
        count += 1;
    }
    if(current1 != nullptr){
        tail->next=current1;
    }
    if(current2 != nullptr){
        tail->next = current2;
    }  

return newHead;
}

Node* zipperListsRe(Node* head1, Node* head2){
    if(head1 == nullptr){
        return head2;
    }

    if(head2 == nullptr){
        return head1;
    }

    Node* head1Next = head1;
    Node* head2Next = head2;

    head1->next = head2;

    Node* remainingHead = zipperListsRe(head1Next, head2Next);

    head2->next = remainingHead;

    return head1;
}

int main () {
    Node a("a");
    Node b("b");
    Node c("c");
    a.next = &b;
    b.next = &c;
    // a -> b -> c

    Node x("x");
    Node y("y");
    Node z("z");
    x.next = &y;
    y.next = &z;
    // x -> y -> z

    zipperLists(&a, &x);
    // a -> x -> b -> y -> c -> z

    Node a0("a");
    Node b0("b");
    Node c0("c");
    Node d0("d");
    Node e0("e");
    Node f0("f");
    a0.next = &b0;
    b0.next = &c0;
    c0.next = &d0;
    d0.next = &e0;
    e0.next = &f0;
    // a -> b -> c -> d -> e -> f

    Node x0("x");
    Node y0("y");
    Node z0("z");
    x0.next = &y0;
    y0.next = &z0;
    // x -> y -> z

    zipperLists(&a0, &x0);
    // a -> x -> b -> y -> c -> z -> d -> e -> f

    Node s("s");
    Node t("t");
    s.next = &t;
    // s -> t

    Node one("1");
    Node two("2");
    Node three("3");
    Node four("4");
    one.next = &two;
    two.next = &three;
    three.next = &four;
    // 1 -> 2 -> 3 -> 4

    zipperLists(&s, &one);
    // s -> 1 -> t -> 2 -> 3 -> 4

    Node w("w");
    // w

    Node one0("1");
    Node two0("2");
    Node three0("3");
    one0.next = &two0;
    two0.next = &three0;
    // 1 -> 2 -> 3

    zipperLists(&w, &one0);
    // w -> 1 -> 2 -> 3

    Node one1("1");
    Node two1("2");
    Node three1("3");
    one1.next = &two1;
    two1.next = &three1;
    // 1 -> 2 -> 3

    Node w0("w");
    // w

    zipperLists(&one1, &w0);
    // 1 -> w -> 2 -> 3
}

//Iterative Complexity:
    // n = length of list 1
    // m = length of list 2

    //Time: O( min(n,m) )
    //Space: O( 1 )

//Recursive Complexity:
    // n = length of list 1
    // m = length of list 2

    //Time: 
    //Space: 