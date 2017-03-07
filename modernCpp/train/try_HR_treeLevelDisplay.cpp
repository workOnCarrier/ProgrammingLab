#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};
ostream& operator << ( ostream& stream, node* np) {
    stream << np->data << " ";
    return stream;
}
 
template <typename T>
class myQueue {
    struct ln {
        T* nodePtr;
        ln* prev;
        ln* next;
    };
    int m_level;
    ln* m_head;
    ln* m_tail;
public:
    myQueue () : m_level{0},m_head{NULL},m_tail (NULL) { }
    ~myQueue () { 
        while ( NULL != m_head ) {
            ln* pos = m_head;
            m_head = m_head->next;
            delete pos;
        }
    }

    void push ( T* newNode ) {
        ln* newLNode = new ln{ newNode, NULL, NULL };
        if ( NULL == m_head ) {
            m_head = newLNode;
            m_tail = newLNode;
        } else { 
            m_tail->next = newLNode;
            m_tail = newLNode;
        }
    }
    T*  pop ( ) {
        ln* oldhead = m_head;
        if ( oldhead == NULL ) {
            throw "no more data";
        }else{
            m_head = m_head -> next;
            if ( m_head == NULL ) m_tail = NULL;
        }
        T* node = oldhead->nodePtr;
        return node;
    }
    bool isEmpty () {
        return NULL == m_head;
    }
    void display () {
        ln* pos = m_head;
        while ( pos != NULL ) {
            cout << pos->nodePtr  ;
            pos = pos->next;
        }
    }
};
typedef myQueue<node>   nodeQueue;

void parseBreadthFirst(node * root) {
    nodeQueue lmObj;
    if ( root == NULL ) return;
    node* pos = root;
    lmObj.push ( root );
    while ( lmObj.isEmpty() == false ) {
        pos = lmObj.pop ();
        cout << pos->data << " ";
        if ( NULL != pos->left ) lmObj.push ( pos->left );
        if ( NULL != pos->right ) lmObj.push( pos->right );
    }
}


node* createTree () {
    node* head = new node {20,NULL};
    return head;
}
void populateTree ( node* root ) ;

void test_tree ( ) {
    node* pos = createTree ();
    populateTree (pos);
    parseBreadthFirst ( pos );
}
void test_myQueue () ;

int main ( int argc, char** argv ) {
    test_tree ();
    // test_myQueue () ;
    return 0;
}

void test_myQueue () {
    nodeQueue nqObj;
    node* pos = createTree ();
    nqObj.push ( pos );
    pos = createTree ();
    pos->data = 10;
    nqObj.push ( pos );
    nqObj.display();
    cout << endl;
    cout << "hello world" << endl;

    cout << nqObj.pop() << endl;
    cout << "hello world" << endl;
}


void populateTree ( node* root ) {
    root->left = new node;
    root->left->data = 10;
    root->right = new node;
    root->right->data = 300;
}
