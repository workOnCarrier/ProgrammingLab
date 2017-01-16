
#include <iostream>

#include <string>

using namespace std;




typedef struct Node {
	int data;
        struct Node* next;
}Node ;


bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if ( head == NULL ) return false;
    Node* next = head->next;
    bool      isLoop = false;
    while ( next != NULL ){
        if ( next->next == next ) {
            isLoop = true;
            break;
        }
        Node* current = head;
        while ( current != next ){
            if ( current == next->next ) {
                isLoop = true;
                break;
            }
            current = current->next;
        }
        if ( isLoop == true ) break;
        next = next->next;
    }
    return isLoop;
}


void populate_noLoop (Node* &ptr ){
    Node* nxt = new Node{5,NULL};
    Node* nxt1 = new Node { 10,nxt};
    ptr = new Node{20,nxt1};
}
void populate_Loop (Node* &ptr ){
    Node* nxt = new Node{5,NULL};
    Node* nxt1 = new Node { 10,nxt};
    nxt->next = nxt1;
    ptr = new Node{20,nxt1};
}
void display (Node* head ) {
    for ( int i = 0; i < 3; i++ ) {
        cout << head->data << endl;
        head = head->next;
    }
}
void test_loop () {
    Node* head;
    populate_Loop ( head );
    display ( head );
    if ( has_cycle ( head ) ) {
        cout << "loop" << endl;
    }else{
        cout << "No loop" << endl;
    }
}

void test_no_loop () {
    Node* head;
    populate_noLoop ( head );
    display ( head );
    if ( has_cycle ( head ) ) {
        cout << "loop" << endl;
    }else{
        cout << "No loop" << endl;
    }
}
int main () {
    test_no_loop() ;
    return 0;
}


