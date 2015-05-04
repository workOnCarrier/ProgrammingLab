#ifndef __BST_H__
#define __BST_H__

#include <exception>
#include <string>
using namespace std;
class InternalError: std::exception{
public:
	//InternalError( char* excStr):exception(excStr){}
	InternalError ( char* excStr):m_message(excStr){}
	~InternalError ( ) throw () {}
private:
    string  m_message;
};
template <typename E>                    // base element type
class myBSTree {
public:
	class Position ;
protected:
//	template <typename E>                           // base element type
	class Node {                             // a node position
		typedef Node* NodePtr;
		public:
			// constructor with all the surrounding nodes
			// and default values as NULL
			Node ( E &value, Node* parent = NULL, Node* left = NULL, Node* right = NULL):m_parent(parent), m_left(left), m_right(right), m_value( value ) {}
			E& operator*() { return m_value; }

			NodePtr&		left() { return m_left; }
			NodePtr&	right () { return m_right; }
			NodePtr&	parent() { return m_parent; }

		private:
			NodePtr			m_parent;
			NodePtr			m_left;
			NodePtr			m_right;
			E				m_value;
		friend class Position;
		friend class myBSTree;
	};

public:
	class Position {
			Node    *m_node;
		public:
			Position ( Node* node ) : m_node(node) {}
			E& operator*() { E &value = m_node->operator*(); return value; }
			void setRight ( Position rPos ) {
					m_node->m_right = rPos.m_node;
					if ( ! rPos.isNullNode() )
					rPos.m_node->m_parent = m_node;
			}
			void setLeft  ( Position rPos ) {
					m_node->m_left  = rPos.m_node;
					if ( ! rPos.isNullNode() )
					rPos.m_node->m_parent = m_node;
			}
			void setParent ( Position rPos ) { m_node->m_parent = rPos.m_node; }

			bool operator == ( Position & rhs ) { return rhs.m_node == this.m_node; }
			bool isRoot() const { return m_node->parent() == NULL ;}
			bool isLeaf() const { return m_node->left() == NULL && m_node->right() == NULL ; }
			bool isNullNode() const { return NULL == m_node; }

			Position 		left() const { return Position(m_node->left()); }
			Position 		right () const { return Position(m_node->right()); }
			Position 		parent() const{ return Position(m_node->parent()); }
		 	Position 		root () const { 
				if ( isRoot() ) 
					return Position(*this);
				else
					return parent().root();
			}

			void 	addLeft ( E & value ) { m_node->m_left = new Node ( value , m_node ); // left and right are null
			}
			void 	addRight ( E & value ) { m_node->m_right = new Node ( value , m_node ); // left and right are null
			}
		friend class myBSTree;
	};
public:                                 // public functions
	myBSTree() : m_root(NULL), m_nodeCount(0) {}

	int 		size() const { return m_nodeCount; }
	bool 		empty() const { return 0==m_nodeCount; }
	Position  root() const { return Position ( m_root ); }

	void		addRoot ( E &value ) { 
		if ( NULL != m_root ){
			throw InternalError ( "Trying to add a root, when it Already exists" );
		}else
		{
			m_root = new Node(value);
			m_nodeCount = 1; 
		}
	}
	void		addNode ( E &value ){
		Position 	currPos = root();
		Position 	prevPos = root ();

		while ( currPos.isNullNode() == false )
		{
			if ( *currPos > value ) {
				prevPos = currPos;
				currPos = currPos.left();
			}
			else
			{
				prevPos = currPos;
				currPos = currPos.right();
			}
		}
		if ( prevPos.isNullNode() ) // this is root and is null
		{	addRoot ( value );	}
		else
		{
			if ( *prevPos > value )
			{
				prevPos.addLeft ( value );
			}else
			{
				prevPos.addRight ( value );
			}
		}
	}
	void	deleteNode ( Position& delPos ){
		// check the validity of current position
		if ( delPos.isNullNode() ) throw InternalError ( "deleting a Null Node is not a valid scenario" );
		else if ( delPos.left().isNullNode() && delPos.right().isNullNode() ) { // deleting root it self with no children
			m_root = NULL;
			--m_nodeCount;
			return;
		}
		else if ( delPos.left().isNullNode() ) { Transplant( delPos, delPos.right() ); }
		else if ( delPos.right().isNullNode() ) { Transplant( delPos, delPos.left() ); }
		else   // the delete position has both the subtrees valid
		{
			Position preDes = getMinOfSubmyBSTree ( delPos.right() );
			if ( preDes.parent() != delPos ) {
				Transplant ( preDes, preDes.right );
				preDes.setRight( delPos.right()  );
				if ( !preDes.right().isNullNode() )
					preDes.right().setparent( preDes );
			}
			Transplant ( delPos, preDes );
			preDes.setLeft( delPos.left() );
			if ( !preDes.left().isNullNode() )
				preDes.left().setparent( preDes );
		}
		--m_nodeCount;
	}
protected:
	Position	getMinOfSubmyBSTree  ( Position refPos ) {
		while ( !refPos.left().isNullNode() ) refPos = refPos.left();
		return refPos;
	}
	Position		getMaxOfSubmyBSTree ( Position refPos ) {
		while ( ! refPos.right().isNullNode() ) refPos = refPos.right() ;
		return refPos;
	}
	Position	successor ( Position refPos ){
		if ( !refPos.right().isNullNode() ) // if valid right node
		{
			return getMinOfSubmyBSTree ( refPos.right() );
		}else
		{
			Position parent = refPos.parent() ;
			while ( !parent.isNullNode() && refPos == parent.right() ){
				refPos = parent;
				parent = refPos.parent();
			}
			return parent;
		}
	}
	Position	predecessor ( Position refPos ) {
		if ( ! refPos.left().isNullNode() )
		{
			return getMaxOfSubmyBSTree ( refPos.left() );
		}else
		{
			Position parent = refPos.parent();
			while ( !parent.isNullNode() && refPos == parent.right() ) {
				refPos = parent;
				parent = refPos.parent();
			}
			return parent;
		}
	}
	void Transplant ( Position onPos, Position withPos ) {
		if ( onPos.isRoot() ) {
			m_root = withPos.m_node;
		} else if ( onPos == onPos.parent().right() ) {
			onPos.parent().setRight (withPos );
		}else
		{
			onPos.parent().setLeft( withPos );
		}
	}

private:
	Node*	m_root;
	int		m_nodeCount;

	int depth ( Position const & pos )
	{
		if ( pos.isRoot() )
			return 0;
		else
			return 1 + depth ( pos.parent() );
	}
};


#endif //__BST_H__
