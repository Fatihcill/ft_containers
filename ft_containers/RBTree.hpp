#ifndef __RED_BLACK_TREE_HPP__
# define __RED_BLACK_TREE_HPP__

#include <memory>
#include <iostream>
#include "utils.hpp"

#define BLACK 0
#define RED 1

namespace ft
{

	template < class T > struct Node	{
		typedef T					value_type;
		typedef	struct Node< value_type >*	NodePtr;
		value_type value;
		NodePtr parent;
		NodePtr left;
		NodePtr right;
		bool	color;

		bool	_TNULL;
		int		endflag;
		NodePtr	endptr;

		Node(const value_type& val) : value(val), parent(nullptr), color(RED),  _TNULL(false), endflag(0), endptr(nullptr){}
		Node() : value(), parent(nullptr), color(RED),  _TNULL(false), endflag(0), endptr(nullptr){}
	}; // end of Node structure

	template < class T > struct RBTree_iterator	{

		typedef T								value_type;
		typedef value_type&						reference;
		typedef value_type*						pointer;
		typedef	Node< value_type >*				NodePtr;
		typedef	RBTree_iterator< value_type >	iterator;
		typedef	std::bidirectional_iterator_tag		iterator_category;
		typedef	std::ptrdiff_t					difference_type;

		NodePtr father;
		NodePtr TNULL;
		NodePtr node;

		RBTree_iterator() {}
		RBTree_iterator(NodePtr node) : father(NULL), node(node) {}
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
	
	template < class T > struct RBTree_const_iterator	{

		typedef T									value_type;
		typedef value_type&							reference;
		typedef value_type*							pointer;
		typedef	Node< value_type >*					NodePtr;
		typedef	RBTree_const_iterator< value_type >	const_iterator;
		typedef	RBTree_iterator< value_type >		iterator;
		typedef	std::bidirectional_iterator_tag			iterator_category;
		typedef	std::ptrdiff_t						difference_type;

		NodePtr father;
		NodePtr TNULL;
		NodePtr node;

		RBTree_const_iterator(){}
		RBTree_const_iterator(iterator p) : father(p.father), node(p.node) {}
		RBTree_const_iterator(NodePtr node) : father(NULL), node(node) {}
		RBTree_const_iterator(NodePtr node, NodePtr TNULL) : node(node), TNULL(TNULL) {}

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
		bool operator!=(const const_iterator& s) const
		{
			return node != s.node;
		} 
		bool operator==(const const_iterator& s) const
		{
			return node == s.node;
		}

		const_iterator& operator++()
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
		
		const_iterator& operator--(){
			if (node->endflag == 2)
			{
				node = node->parent;
				return *this;
			}
			/*
			if (!node->parent)
				lancia eccezione
			*/
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

		const_iterator operator++(int)
		{
			const_iterator tmp = *this;
			++(*this);
			return tmp;
		}
		const_iterator operator--(int)
		{
			const_iterator tmp = *this;
			--(*this);
			return tmp;
		}
	}; // end of RBTree_const_iterator structure


	template < class K ,
				class T ,
				class Compare = std::less< T >,
				class Allocator = std::allocator< Node< T > >
				> class RBTree	{
	public:
		typedef T										value_type;
		typedef ft::Node< T > *							NodePtr;
		typedef RBTree_iterator< T >					iterator;
		typedef RBTree_const_iterator< T >				const_iterator;
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
			if (x->parent == nullptr) {
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
			if (x->parent == nullptr) {
				this->root = y;
			} else if (x == x->parent->right) {
				x->parent->right = y;
			} else {
				x->parent->left = y;
			}
			y->right = x;
			x->parent = y;
		}

		void fixOrphan(NodePtr dead, NodePtr orphan)
		{
			if (nodeFather(dead) == NULL)
				root = orphan; //QUI!!!!!
			else if (dead == nodeFather(dead)->left)
				nodeFather(dead)->left = orphan;
			else
				nodeFather(dead)->right = orphan;
			if (orphan)
				orphan->parent = nodeFather(dead);
		}

		NodePtr nodeFather(NodePtr k)
		{
			return k->parent;
		}

		NodePtr nodeGranfather(NodePtr k)
		{
			return k->parent->parent;
		}

		//ok sembra
		void balance_after_insetion(NodePtr k)
		{
			NodePtr u;
			while (isRed(k->parent))
			{
				if (k->parent == k->parent->parent->right)
				{
					u = k->parent->parent->left;
					if (isRed(u))
					{
						u->color = BLACK;
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						k = k->parent->parent;
					}
					else
					{
						if (k == k->parent->left)
						{
							k = k->parent;
							right_rotate(k);
						}
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						left_rotate(k->parent->parent);
					}
				}
				else
				{
					u = k->parent->parent->right;;
					if (isRed(u))
					{
						u->color = BLACK;
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						k = k->parent->parent;
					}
					else
					{
						if (k == k->parent->right)
						{
							k = k->parent;
							left_rotate(k);
						}
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						right_rotate(k->parent->parent);
					}
				}
				if (k == root)
					break;
			}
			root->color = BLACK;
		};	// END INSERTION BALANCE

		void balance_after_deletion(NodePtr x)
		{
			NodePtr s;
			while (x != root && !isRed(x))
			{
				if(x == x->parent->left)
				{
					s = x->parent->right;
					if (isRed(s))
					{
						s->color = BLACK;
						x->parent->color = RED;
						left_rotate(x->parent);
						s = x->parent->right;
					}
					if (!isRed(s->left) && !isRed(s->right))
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (!isRed(s->right))
						{
							s->left->color = BLACK;
							s->color = RED;
							right_rotate(s);
							s = x->parent->right;
						}
						s->color = x->parent->color;
						x->parent->color = BLACK;
						s->right->color = BLACK;
						left_rotate(x->parent);
						x = root;
					}
				}
				else
				{
					s = x->parent->left;
					if (isRed(s))
					{
						s->color = BLACK;
						x->parent->color = RED;
						right_rotate(x->parent);
						s = x->parent->left;
					}
					if (!isRed(s->left) && !isRed(s->right))
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (!isRed(s->left))
						{
							s->right->color = BLACK;
							s->color = RED;
							left_rotate(s);
							s = x->parent->left;
						}
						s->color = x->parent->color;
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

		//RBTree ok
		explicit RBTree(const Compare& comp, const Allocator& alloc = Allocator()) : a(alloc), compare_function(comp){
			TNULL = a.allocate(1);
			a.construct(TNULL);
			TNULL->color = 0;
			TNULL->left = nullptr;
			TNULL->right = nullptr;
			TNULL->_TNULL = true;
			
			_END = a.allocate(1);
			a.construct(_END);
			_END->color = 0;
			_END->left = nullptr;
			_END->right = nullptr;
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
                _END->parent = nullptr;
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
			TNULL->left = nullptr;
			TNULL->right = nullptr;
			TNULL->_TNULL = true;
			root = TNULL;
			_END = a.allocate(1);
			a.construct(_END);
			_END->color = 0;
			_END->left = nullptr;
			_END->right = nullptr;
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

		//insertion ok
		ft::pair<iterator, bool> insertion(value_type z)
		{
			NodePtr father = nullptr;
			NodePtr search = root;
			while (search != TNULL)
			{
				father = search;
				if (!comparison()(z, search->value) && !comparison()(search->value, z))
					return ft::make_pair(iterator(search), false);
				if(comparison()(z, search->value))
					search = search->left;
				else
					search = search->right;
			}
			search = a.allocate( 1 );
			a.construct( search, Node< T >(z));
			search->parent = father;
			search->left = TNULL;
			search->right = TNULL;
			if (father == nullptr)
			{
				root = search;
				search->color = 0;
				_RBTsize++;
				update_END();
				return ft::make_pair(iterator(search), true);
			}
			else if (comparison()(z, father->value))
				father->left = search;
			else
				father->right = search;
			if (search->parent->parent == nullptr)
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

		//deletion ok
		size_type deletion(value_type z)
		{
			NodePtr nodeIter = root;
			NodePtr toDelete = TNULL;
			NodePtr toBalance = NULL;
			while (nodeIter != TNULL)
			{
				if (comparison()(z, nodeIter->value) && !comparison()(nodeIter->value, z))
					nodeIter = nodeIter->left;
				else if (!comparison()(z, nodeIter->value) && comparison()(nodeIter->value, z))
					nodeIter = nodeIter->right;
				else
				{
					toDelete = nodeIter;
					break ;
				}
			}
			if  (toDelete == TNULL)
				return 0;
			NodePtr y = toDelete;
			bool original_color = y->color;
			if (toDelete->left == TNULL)
			{
				toBalance = toDelete->right;
				fixOrphan(toDelete, toDelete->right);
			}
			else if (toDelete->right == TNULL)
			{
				toBalance = toDelete->left;
				fixOrphan(toDelete, toDelete->left);
			}
			else
			{
				y = minimum(toDelete->right);
				original_color = y->color;
				toBalance = y->right;
				if (y->parent == toDelete)
					toBalance->parent = y;
				else
				{
					fixOrphan(y, y->right);
					y->right = toDelete->right;
					y->right->parent = y;
				}
				fixOrphan(toDelete, y);
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
            _END->parent = nullptr;
            _LAST = _END;
        }

		iterator search(const value_type& z) {
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

		iterator lower_bound(const value_type& z) { //4
			NodePtr search = root;
			while (search != TNULL)
			{
				if (!comparison()(z, search->value) && !comparison()(search->value, z))
					return iterator(search);
				else if (comparison()(z, search->value) && !comparison()(search->value, z)){
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
				if (!comparison()(z, search->value) && !comparison()(search->value, z))
					return const_iterator(search);
				else if (comparison()(z, search->value) && !comparison()(search->value, z)){
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
	}; // END OF CLASS RBTREE
	template <class Key, class Value>
	std::ostream& operator<<(std::ostream& out, ft::pair<Key,Value>& v)
	{
		return out <<" <"<<v.first<<","<< v.second<<"> ";
	}

} // namespace ft

#endif