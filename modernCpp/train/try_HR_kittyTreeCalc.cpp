#include <iostream>

#include <algorithm>
#include <vector>
using namespace std;

typedef struct mynode {
    int                 value;
    vector<mynode*>     children;
} node;

void displayTree ( node* root ) {
    cout << root->value << " " ;
    for ( size_t lc = 0; lc < root->children.size(); lc ++ ) {
        displayTree ( root->children[lc] );
    }
}

class readInputFormTree  {
    node*       m_treeroot;
    vector<vector<int>> m_sets;

    node*       find (node*, int );
public:
    readInputFormTree () ;
    node*       getTree () { return m_treeroot;}
    vector<vector<int>>& getSets () {return m_sets;}
};
typedef vector<int>     Myset;
typedef vector<Myset>   Mysets;
struct mypair {
    int     first;
    int     second;
};
typedef vector<mypair>  Permutes;


node* readInputFormTree::find ( node* root, int value ) {
    if ( root->value == value ) {
        return root;
    } else {
        node* pos = NULL;
        for ( size_t lc = 0; lc < root->children.size() && pos == NULL; lc ++ ) {
            pos = find ( root->children[lc], value );
        }
        return pos;
    }
}
readInputFormTree::readInputFormTree () : m_treeroot(NULL) {
    int nodeCount;
    int setCount;
    cin >> nodeCount >> setCount;
    int father, child;
    cin >> father >> child;
    m_treeroot = new node { father };
    m_treeroot->children.push_back ( new node { child } );
    for ( int nc = 1; nc < nodeCount; nc++ ) {
        int father, child;
        cin >> father >> child;
        node* pos = find ( m_treeroot, father );
        if ( NULL == pos ) {
            cout << "could not find existing value:" << father << endl; 
            displayTree ( m_treeroot );
            exit(0);
        }
        pos->children.push_back ( new node { child } );
    }
    cout << "Starting sets" << endl;
    for ( int sc = 0; sc < setCount; sc++ ) {
        int setsize = 0;
        cin >> setsize;
        vector<int> set(setsize);
        for ( int si = 0; si < setsize; si ++ ) {
            cin >> set[si];
        }
        m_sets.push_back ( set ) ;
    }
}
void displaySets ( vector<vector<int>> &sets )  {
    for ( size_t iter = 0; iter < sets.size() ; iter ++ ) {
        cout << "\nSet :" << iter+1 << " has " << sets[iter].size() << " elements " << endl;
        for ( size_t si = 0; si < sets[iter].size(); si++ ) {
            cout << " " << sets[iter][si];
        }
        cout << endl;
    }
}

Permutes    getPermutes ( Myset &ms ) {
    Permutes  permts;
    for ( size_t index = 0; index < ms.size(); index ++ ) {
        for ( size_t offset = index+1; offset < ms.size(); offset ++ ) {
            mypair val = {ms[index],ms[offset]};
            permts.push_back ( val );
        }
    }
    return permts;
}
long    computeCalc ( node* tree, Permutes &permutes ){
    if ( tree != NULL ) {
        for ( size_t index = 0; index < permutes.size() ; index ++ ) {
            cout << "\n{" << permutes[index].first << "," << permutes[index].second << "}" << endl;
        }
    }
    return -1;
}

int main ( int argc, char** argv ) {
    readInputFormTree rift;
     displayTree ( rift.getTree() );
     displaySets ( rift.getSets() );
    node*   tree = rift.getTree();
    Mysets  sets = rift.getSets();
    for ( size_t i = 0; i < sets.size(); i++ ) {
        Permutes    permutes = getPermutes ( sets[i] );
        long    value = computeCalc ( tree, permutes );
        cout << value << endl;
    }
    return 0;
}

class pathQueue {
    struct pqNode {
        node*   data;
        pqNode* next;
    } ;
    pqNode*     m_head;
    pqNode*     m_tail;
public:
    pathQueue():m_head(NULL),m_tail(NULL){}
    ~pathQueue(){}
    pqNode* begin(){return m_head;}
    bool isEmpty() { return    NULL == m_head;}
    void push_back(node* val) {
        if ( NULL == m_head ){
            m_head = new pqNode{val, NULL};
            m_tail = m_head;
        }else{
            pqNode* pos = new pqNode {val,m_head};
            m_head = pos;
        }
    }
    node* getFarthestMatchingNode ( pathQueue& rightQueue) {
        pqNode* lpos = this->begin();
        pqNode* rpos = rightQueue.begin();
        node*   nodepos = NULL;
        while ( lpos != NULL && rpos != NULL ){
            if ( lpos->data->data == rpos->data->data ) {
                nodepos = lpos->data;
            }else{
                break;
            }
            lpos = lpos->next;
            rpos = rpos->next;
        }
        return nodepos;
    }

};


bool getPathFrom ( node* root, int value, pathQueue& queue ){
    if ( root == NULL ){return false;}
    if ( root->data == value ){
        queue.push_back ( root );
        return true;
    }else{
        bool leftRes = false, rightRes = false;
        if ( root->left != NULL ) leftRes = getPathFrom ( root->left, value, queue);
        if ( leftRes != true && root->right != NULL  ) rightRes = getPathFrom ( root->right, value, queue);
        if ( leftRes || rightRes ) {
            queue.push_back ( root );
            return true;
        }else { return false;}
    }
}

