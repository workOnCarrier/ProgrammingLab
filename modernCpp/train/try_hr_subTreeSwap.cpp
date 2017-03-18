// https://www.hackerrank.com/challenges/swap-nodes-algo
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct mynode {
    int         data;
    mynode*     left;
    mynode*     right;
} node;
class readInputFormTree  {
    node*       m_treeroot;
    vector<int> m_swaps;

    node*       find (node*, int );
public:
    readInputFormTree () ;
    node*       getTree () { return m_treeroot;}
    vector<int> getSwaps () {return m_swaps;}
};

readInputFormTree::readInputFormTree () : m_treeroot(NULL) {
    int nodeCount = 0;
    cin >> nodeCount;
    m_treeroot = new node {1,NULL, NULL};
    for ( int count = 0; count < nodeCount; count ++ ) {
        int lchild, rchild;
        cin >> lchild >> rchild;
        if ( lchild == -1 && rchild == -1 ) continue;
        node* pos = find ( m_treeroot,  count+1 );
        if ( lchild != -1 ) pos->left = new node { lchild, NULL, NULL };
        if ( rchild != -1 ) pos->right = new node { rchild, NULL, NULL };
    }
    int swapCount ;
    cin >> swapCount;
    for ( int sc = 0; sc < swapCount; sc++ ){
        int si;
        cin >> si;
        m_swaps.push_back (si);
    }
}
node* readInputFormTree::find ( node* root, int value ) {
    if ( root->data == value ) {
        return root;
    } else {
        node* pos = NULL;
        if ( root->left != NULL ) pos = find ( root->left, value );
        if ( pos == NULL && root->right != NULL ) pos = find ( root->right, value );
        return pos;
    }
}
int height ( node* root ){
    int h = 0;
    if ( root == NULL ) return h ;
    int lh = height ( root->left );
    int rh = height ( root->right );

    if ( lh > rh ) {
        h = lh+1;
    }else{
        h = rh+1;
    }
    return h ;
}

void swap ( node* root, int level, int currLevel = 1 ){
    if ( level == currLevel ) {
        node* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }else{
        if ( root->left != NULL ) swap ( root->left, level, currLevel+1 );
        if ( root->right != NULL ) swap ( root->right, level, currLevel+1 );
    }
}
void displayInOrder ( node* root ) {
    if ( NULL != root ){
        displayInOrder ( root->left );
        cout << root->data << " ";
        displayInOrder ( root->right );
    }
}

void swapForAll ( node* root, vector<int> swapLevels ) {
    int h = height ( root );
    for ( size_t sc = 0; sc < swapLevels.size() ; sc++ ) {
        int level = swapLevels[sc];
        for ( int multi = 1; multi*level < h; multi++ ) {
            swap ( root, multi*level );
        }
        displayInOrder ( root );
        cout << endl;
    }
}
int main () {
    readInputFormTree   rift_obj;
    node* root = rift_obj.getTree();
    // cout << "height of tree:" << height ( root ) << endl;
    vector<int>     sis = rift_obj.getSwaps();
    // cout << sis.size() << endl;
    // displayInOrder ( root ) ;
    swapForAll ( root, sis );
    // cout << "Hello world" << endl;
    return 0;
}
