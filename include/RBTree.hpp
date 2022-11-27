#ifndef __RED_BLACK_TREE_HPP__
# define __RED_BLACK_TREE_HPP__

#include <memory>
#include <iostream>
#include "utils.hpp"
#include "iterator.hpp"

#define BLACK 0
#define RED 1

namespace ft
{

	/*
		Rules:
			1- Nodes are Red or Black
			2- Root and Nil(leaves) are black
			3- If node is red, then its children are black
			4- All paths from a node contain the same number of black nodes
	*/
	template < class T > struct Node
	{
		T value;
		struct Node< T >* parent;
		struct Node< T >* left;
		struct Node< T >* right;
		bool	color;

		bool	_TNULL;
		//nil leaf
		int		endflag;
		// 1 -> node is end
		// 2 -> currently node is Nill
		struct Node< T >*	endptr;

		Node(const T& val) : value(val), parent(NULL), color(RED),  _TNULL(false), endflag(0), endptr(NULL){}
		Node() : value(), parent(NULL), color(RED),  _TNULL(false), endflag(0), endptr(NULL){}
	}; // end of Node structure

	template < class T > struct RBTree_iterator
	{
		typedef T									value_type;
		typedef value_type&							reference;
		typedef value_type*							pointer;
		typedef	Node< value_type >*					NodePtr;
		typedef	RBTree_iterator< value_type >		iterator;
		typedef	std::bidirectional_iterator_tag		iterator_category;
		typedef	std::ptrdiff_t						difference_type;

		NodePtr TNULL;
		NodePtr node;

		RBTree_iterator() {}
		RBTree_iterator(NodePtr node) : node(node) {}
		RBTree_iterator(NodePtr node, NodePtr TNULL) : node(node), TNULL(TNULL) {}

		reference operator*() const
		{
			if (node == NULL)
				throw std::out_of_range("Out of range");
			return node->value;
		}
		pointer operator->() const
		{
			if (node == NULL)
				throw std::out_of_range("Out of range");
			return &node->value;
		}
		bool operator!=(const iterator& s) const
		{
			return node != s.node;
		} 
		bool operator==(const iterator& s) const
		{
			return node == s.node;
		}

		iterator& operator++()
		{
			if (node->endflag)
			{
				if (node->endflag == 2) // se flag == 2 sono in end
					throw std::out_of_range("Out of range");
				node = node->endptr;
				return(*this);
			}
			if (!node->right->_TNULL)
			{
				node = node->right;
				while(!node->left->_TNULL)
					node = node->left;
				return *this;
			}
			NodePtr next = node->parent;
			while(!next->_TNULL && node == next->right){
				node = next;
				next = next->parent;
			}
			node = next;
			return *this;
		}
		
		iterator& operator--(){
			if (node->endflag == 2)
			{
				node = node->parent;
				return *this;
			}
			if (!node->left->_TNULL){
				node = node->left;
				while(!node->right->_TNULL)
					node = node->right;
				return *this;
			}
			NodePtr prec = node->parent;
			while(!prec->_TNULL && node == prec->left){
				node = prec;
				prec = prec->parent;
			}
			node = prec;
			return *this;
		}

		iterator operator++(int)
		{
			iterator tmp = *this;
			++(*this);
			return tmp;
		}
		iterator operator--(int)
		{
			iterator tmp = *this;
			--(*this);
			return tmp;
		}
	}; // end of RBTree_iterator structure


	template < class K ,
				class T ,
				class Compare = std::less< T >,
				class Allocator = std::allocator< Node< T > >
				> class RBTree	{
	public:
		typedef T										value_type;
		typedef ft::Node< T > *							NodePtr;
		typedef RBTree_iterator< T >					iterator;
		typedef RBTree_iterator< T >					const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef size_t									size_type;
	
	private:
		NodePtr		root;
		NodePtr		TNULL;
		Allocator	a;
		Compare		compare_function;
		size_t		_RBTsize;

		NodePtr		_LAST;
		NodePtr		_END;

		//updated _END and _LAST
		//_LAST is the biggest value of the map and _END is the 
		void update_END()
		{
			NodePtr iter = root;
			while(iter->right && !iter->right->_TNULL)
				iter = iter->right;
			if (_LAST != _END)
			{
				_LAST->endflag = 0;
				_LAST->endptr = NULL;
			}
			_LAST = iter;
			_LAST->endflag = 1;
			_LAST->endptr = _END;
			_END->parent = _LAST;
		}

		Compare comparison() const {
			return compare_function;
		}

		void printHelper(NodePtr root, std::string indent, bool last) {
			// print the tree structure on the screen
			if (root != TNULL) {
			std::cout<<indent;
			if (last) {
				std::cout<<"R----";
				indent += "     ";
			} else {
				std::cout<<"L----";
				indent += "|    ";
			}
				
			std::string sColor = root->color?"RED":"BLACK";
			std::cout<<root->value<<"("<<sColor<<")"<<std::endl;
			printHelper(root->left, indent, false);
			printHelper(root->right, indent, true);
			}
		}

		void deleteAllNodes(NodePtr node)
		{
			if (node)
			{
				if (node->left)
					deleteAllNodes(node->left);
				if (node->right)
					deleteAllNodes(node->right);
				if (node != TNULL)
				{
					a.destroy(node);
					a.deallocate(node, 1);
				}
			}
		}

		bool isRed(NodePtr k)
		{
			if (!k) return BLACK;
			return k->color == RED;
		};

		NodePtr minimum(NodePtr node) {
			while (node->left != TNULL) {
				node = node->left;
			}
			return node;
		}

		void left_rotate(NodePtr x) {
			NodePtr y = x->right;
			x->right = y->left;
			if (y->left != TNULL) {
				y->left->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == NULL) {
				this->root = y;
			} else if (x == x->parent->left) {
				x->parent->left = y;
			} else {
				x->parent->right = y;
			}
			y->left = x;
			x->parent = y;
		}

		void right_rotate(NodePtr x) {
			NodePtr y = x->left;
			x->left = y->right;
			if (y->right != TNULL) {
				y->right->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == NULL) {
				this->root = y;
			} else if (x == x->parent->right) {
				x->parent->right = y;
			} else {
				x->parent->left = y;
			}
			y->right = x;
			x->parent = y;
		}

		//help us move subtrees
		
		void transplant(NodePtr dead, NodePtr orphan)
		{
			if (dead->parent == NULL)			 // dead is root
				root = orphan;
			else if (dead == dead->parent->left) // dead is left
				dead->parent->left = orphan;
			else								// dead is right	
				dead->parent->right = orphan;
			if (orphan)
				orphan->parent = dead->parent;
		}

		/*	
			Scenarios:
				2- Z.uncle == red
				3- Z.uncle == black(triangle)
				4- Z.uncle == black(line)
		*/
		void balance_after_insetion(NodePtr k)
		{
			NodePtr uncle;
			while (isRed(k->parent))
			{
				if (k->parent == k->parent->parent->right)
				{
					uncle = k->parent->parent->left;
					if (isRed(uncle)) //Scenario 2 recoloring
					{
						uncle->color = BLACK;
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						k = k->parent->parent;
					}
					else
					{
						if (k == k->parent->left) //Scenario 3
						{
							k = k->parent;
							right_rotate(k);
						}
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						left_rotate(k->parent->parent); //Scenario 4
					}
				}
				else
				{
					uncle = k->parent->parent->right;
					if (isRed(uncle)) //Scenario 2 recoloring
					{
						uncle->color = BLACK;
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						k = k->parent->parent;
					}
					else
					{
						if (k == k->parent->right) //Scenario 3
						{
							k = k->parent;
							left_rotate(k);
						}
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						right_rotate(k->parent->parent); //Scenario 4
					}
				}
				if (k == root)
					break;
			}
			root->color = BLACK;
		}

		/*
			1- w is red
			2- w is black and w.left & right are black
			3- w is black and w.left is red and w.right is black
			4- w is black and w.right is red
		*/
		void balance_after_deletion(NodePtr x)
		{
			NodePtr s;
			while (x != root && !isRed(x))
			{
				if(x == x->parent->left)
				{
					s = x->parent->right;
					if (isRed(s)) // type 1
					{
						s->color = BLACK;
						x->parent->color = RED;
						left_rotate(x->parent);
						s = x->parent->right;
					}
					if (!isRed(s->left) && !isRed(s->right)) // type 2
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (!isRed(s->right)) // type 3
						{
							s->left->color = BLACK;
							s->color = RED;
							right_rotate(s);
							s = x->parent->right;
						}
						s->color = x->parent->color; // type 4
						x->parent->color = BLACK;
						s->right->color = BLACK;
						left_rotate(x->parent);
						x = root;
					}
				}
				else
				{
					s = x->parent->left;
					if (isRed(s)) // type 1
					{
						s->color = BLACK;
						x->parent->color = RED;
						right_rotate(x->parent);
						s = x->parent->left;
					}
					if (!isRed(s->left) && !isRed(s->right)) // type 2
					{
						s->color = RED;
						x = x->parent;
					}
					else 
					{
						if (!isRed(s->left))//type 3
						{
							s->right->color = BLACK;
							s->color = RED;
							left_rotate(s);
							s = x->parent->left;
						}
						s->color = x->parent->color; //type 4
						x->parent->color = BLACK;
						s->left->color = BLACK;
						right_rotate(x->parent);
						x = root;
					}
				}
			}
			x->color = BLACK;
		};	// END DELETION BALANCE


	public:
		explicit RBTree(const Compare& comp, const Allocator& alloc = Allocator()) : a(alloc), compare_function(comp)
		{
			TNULL = a.allocate(1);
			a.construct(TNULL);
			TNULL->color = 0;
			TNULL->left = NULL;
			TNULL->right = NULL;
			TNULL->_TNULL = true;
			
			_END = a.allocate(1);
			a.construct(_END);
			_END->color = 0;
			_END->left = NULL;
			_END->right = NULL;
			_END->_TNULL = true;
			_END->endflag = 2;
			_LAST = _END;

			_RBTsize = 0;
			root = TNULL;
		};

		RBTree<K, T, Compare, Allocator> & operator=(RBTree<K, T, Compare, Allocator> const & src){
            if (this == &src)
                return(*this);
            if (root != TNULL)
            {
                deleteAllNodes(root);
                root = TNULL;
                _END->parent = NULL;
                _LAST = _END;
            }
			_RBTsize = 0;
            const_iterator iter = src.begin();
            while(iter != src.end()){
                insertion(*iter);
                iter++;
            }
            return(*this);
        }
		
        RBTree(const RBTree<K, T, Compare, Allocator>& other) : a(other.getAllocator()), compare_function(other.compare_function){
			TNULL = a.allocate(1);
			a.construct(TNULL);
			TNULL->color = 0;
			TNULL->left = NULL;
			TNULL->right = NULL;
			TNULL->_TNULL = true;
			root = TNULL;
			_END = a.allocate(1);
			a.construct(_END);
			_END->color = 0;
			_END->left = NULL;
			_END->right = NULL;
			_END->_TNULL = true;
			_END->endflag = 2;
			_LAST = _END;
			*this = other;
        }
		
		~RBTree()
		{
			deleteAllNodes(root);
			a.destroy(TNULL);
			a.deallocate(TNULL, 1);
			a.destroy(_END);
			a.deallocate(_END, 1);
		};

		/*
			Strategy:
				1- insert z and color is red
				2- recolor and rotate nodes to fix the tree
			
			Scenarios:
				1- Z == root
				2- Z.uncle == red
				3- Z.uncle == black(triangle)
				4- Z.uncle == black(line)
		*/
		ft::pair<iterator, bool> insertion(value_type z)
		{
			NodePtr parent = NULL;
			NodePtr search = root;
			while (search != TNULL)
			{
				parent = search;
				if(comparison()(z, search->value))
					search = search->left;
				else
					search = search->right;
			}
			search = a.allocate(1);
			a.construct(search, Node<value_type>(z));
			search->parent = parent;
			search->left = TNULL;
			search->right = TNULL;
			if (parent == NULL) //Scenario 1
			{
				root = search;
				search->color = BLACK;
				_RBTsize++;
				update_END();
				return ft::make_pair(iterator(search), true);
			}
			else if (comparison()(z, parent->value))
				parent->left = search;
			else
				parent->right = search;

			if (search->parent->parent == NULL) //adding child node of root
			{
				_RBTsize++;
				update_END();
				return ft::make_pair(iterator(search), true);
			}
			balance_after_insetion(search);
			_RBTsize++;
			update_END();
			return ft::make_pair(iterator(search), true);
		} // END INSERTION

		//Cases
		//1- left is Nil
		//2- right is Nil
		//3- neither is Nil
		size_type deletion(value_type z)
		{
			NodePtr toDelete = root;
			NodePtr toBalance = NULL;
			while (toDelete != TNULL)
			{
				if (comparison()(z, toDelete->value)) // is less
					toDelete = toDelete->left;
				else if (!comparison()(z, toDelete->value)) // is greater
					toDelete = toDelete->right;
				else
					break ;
			}
			if  (toDelete == TNULL)
				return 0;
			NodePtr y = toDelete;
			bool original_color = y->color;
			if (toDelete->left == TNULL) // case 1
			{
				toBalance = toDelete->right;
				transplant(toDelete, toDelete->right);
			}
			else if (toDelete->right == TNULL) //case 2
			{
				toBalance = toDelete->left;
				transplant(toDelete, toDelete->left);
			}
			else //case 3
			{
				y = minimum(toDelete->right);
				original_color = y->color;
				toBalance = y->right;
				if (y->parent == toDelete)
					toBalance->parent = y;
				else
				{
					transplant(y, y->right);
					y->right = toDelete->right;
					y->right->parent = y;
				}
				transplant(toDelete, y);
				y->left = toDelete->left;
				y->left->parent = y;
				y->color = toDelete->color;
			}
			a.destroy(toDelete);
			a.deallocate(toDelete, 1);
			if (original_color == BLACK)
				balance_after_deletion(toBalance);
			_RBTsize--;
			update_END();
			return 1;
		} // END NODE DELETION

		iterator begin()
		{
			NodePtr left = root;
			if (!_RBTsize)
				return (end());
			while(left->left != TNULL)
				left = left->left;
			return iterator(left);
		}

		iterator end()
		{
			return iterator(_END);
		}

		const_iterator begin() const
		{
			NodePtr left = root;
			if (!_RBTsize)
				return (end());
			while(left->left != TNULL)
				left = left->left;
			return iterator(left);
		}

		const_iterator end() const
		{
			return iterator(_END);
		}

		//support function

		void clear()
        {
            deleteAllNodes(root);
            _RBTsize = 0;
            root = TNULL;
            _END->parent = NULL;
            _LAST = _END;
        }

		iterator search(const value_type& z)
		{
			NodePtr search = root;
			while (search != TNULL)
			{
				if(comparison()(z, search->value) && !comparison()(search->value, z))
					search = search->left;
				else if (!comparison()(z, search->value) && comparison()(search->value, z))
					search = search->right;
				else
					return iterator(search);
			}
			iterator last = end();
			return last;
		}

		const_iterator search(const value_type& z) const{
			NodePtr search = root;
			while (search != TNULL)
			{
				if(comparison()(z, search->value) && !comparison()(search->value, z))
					search = search->left;
				else if (!comparison()(z, search->value) && comparison()(search->value, z))
					search = search->right;
				else
					return iterator(search);			
			}
			return end();
		}

		bool count(const value_type& z) const{
			NodePtr search = root;
			while (search != TNULL)
			{
				if(comparison()(z, search->value) && !comparison()(search->value, z))
					search = search->left;
				else if (!comparison()(z, search->value) && comparison()(search->value, z))
					search = search->right;
				else
					return true;			
			}
			return false;
		}

		iterator lower_bound(const value_type& z) {
			NodePtr search = root;
			while (search != TNULL)
			{
				if (!comparison()(z, search->value) && !comparison()(search->value, z)) // is equal
					return iterator(search);
				else if (comparison()(z, search->value)) // is smaller for std::less
				{
					if (search->left == TNULL)
						return iterator(search);
					search = search->left;
				}
				else
				{
					if (search->right == TNULL)
						return ++iterator(search);
					search = search->right;
				}
			}
			return end();
		}

		const_iterator lower_bound(const value_type& z) const{
			NodePtr search = root;
			while (search != TNULL)
			{
				if (!comparison()(z, search->value) && !comparison()(search->value, z)) // is equal ?
					return const_iterator(search);
				else if (comparison()(z, search->value))
				{
					if (search->left == TNULL)
						return const_iterator(search);
					search = search->left;
				}
				else
				{
					if (search->right == TNULL)
						return ++const_iterator(search);
					search = search->right;
				}
			}
			return end();
		}

		iterator upper_bound(const value_type& z) {
			iterator tmp = lower_bound(z);

			if (tmp == end() || comparison()(z, *tmp))
				return tmp;
			else
				return ++tmp;
		}

		const_iterator upper_bound(const value_type& z) const{
			const_iterator tmp = lower_bound(z);

			if (tmp == end() || comparison()(z, *tmp))
				return tmp;
			else
				return ++tmp;
		}

		pair<iterator,iterator> equal_range(const value_type& z) {
			return ft::make_pair(lower_bound(z), upper_bound(z));
		}

		pair<const_iterator, const_iterator> equal_range(const value_type& z) const{
			return ft::make_pair(lower_bound(z), upper_bound(z));
		}
		
		void print()
		{
			if (root)
				printHelper(this->root, "", true);
		}

		size_type size() const {
			return _RBTsize;
		}

		size_type max_size() const {
			return (a.max_size());
		}

		Allocator getAllocator() const{
            return a;
        }
		//-----------------------//
	};
}

#endif