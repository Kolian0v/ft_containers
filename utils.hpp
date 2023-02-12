#pragma once

#include <cstddef>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <memory>

//iterator trails
namespace ft{
	template<class Iter>
	struct iterator_traits{
		typedef typename Iter::difference_type difference_type;
		typedef typename Iter::value_type value_type;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::reference reference;
		typedef typename Iter::iterator_category iterator_category;
	};

	template<class T>
	struct iterator_traits<T*>{
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template<class T>
	struct iterator_traits<const T*>{
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};
}

//random assess iterator
namespace ft{
	template<class Iter>
	class reverse_iterator{
	public:
		typedef Iter													iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer				pointer;
		typedef typename ft::iterator_traits<Iter>::reference			reference;
	private:
		iterator_type baseIter;
	public:
		reverse_iterator() : baseIter() {};
		explicit reverse_iterator(iterator_type iter) : baseIter(iter){};

		template<class U>
		reverse_iterator(const reverse_iterator<U> &iter){
			baseIter = iter.base();
		};
		template< class U >
		reverse_iterator& operator=(const reverse_iterator<U> &other){
			if (this == &other)
				return *this;
			this->baseIter = other.base();
			return *this;
		}

		iterator_type base() const {return baseIter;}
		// Operatirs
		reference		 operator*()const {iterator_type tmp = baseIter; return *--tmp;}
		pointer			 operator->()const {return &(operator*());}
		reference		 operator[](difference_type n) const {return base()[-n-1];};
		reverse_iterator &operator++() {--baseIter; return *this;}
		reverse_iterator operator++(int) {reverse_iterator temp = *this; --baseIter; return temp;}
		reverse_iterator &operator--() {++baseIter; return *this;}
		reverse_iterator operator--(int) {reverse_iterator temp = *this; ++baseIter; return temp;}
		reverse_iterator operator+(difference_type n) const {return reverse_iterator(base() - n);};
		reverse_iterator operator-(difference_type n) const {return reverse_iterator(base() + n);};
		reverse_iterator operator+=(difference_type n) {baseIter -= n; return *this;};
		reverse_iterator operator-=(difference_type n) {baseIter += n; return *this;};
	};

	template< class Iterator1, class Iterator2 >
	bool operator==( const reverse_iterator<Iterator1>& lhs,
					 const reverse_iterator<Iterator2>& rhs )
					{return (lhs.base() == rhs.base());}

	template< class Iterator1, class Iterator2 >
	bool operator!=( const reverse_iterator<Iterator1>& lhs,
					 const reverse_iterator<Iterator2>& rhs )
					{return (lhs.base() != rhs.base());}

	template< class Iterator1, class Iterator2 >
	bool operator<( const reverse_iterator<Iterator1>& lhs,
					const reverse_iterator<Iterator2>& rhs )
					{return lhs.base() > rhs.base();}

	template< class Iterator1, class Iterator2 >
	bool operator<=( const reverse_iterator<Iterator1>& lhs,
					 const reverse_iterator<Iterator2>& rhs )
					{return lhs.base() >= rhs.base();}

	template< class Iterator1, class Iterator2 >
	bool operator>( const reverse_iterator<Iterator1>& lhs,
					const reverse_iterator<Iterator2>& rhs )
					{return lhs.base() < rhs.base();}

	template< class Iterator1, class Iterator2 >
	bool operator>=( const reverse_iterator<Iterator1>& lhs,
					 const reverse_iterator<Iterator2>& rhs )
					{return lhs.base() <= rhs.base();}

	template< class Iter >
	reverse_iterator<Iter>
	operator+( typename reverse_iterator<Iter>::difference_type n,
			   const reverse_iterator<Iter>& it )
			{return reverse_iterator<Iter>(it.base() - n);}

	template< class Iterator >
	typename reverse_iterator<Iterator>::difference_type
	operator-( const reverse_iterator<Iterator>& lhs,
			   const reverse_iterator<Iterator>& rhs )
			{return rhs.base() - lhs.base();}
}

namespace ft {
	template<class T>
	class random_access_iterator
	{
	public:
		typedef T								*pointer;
		typedef T								&reference;
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef std::random_access_iterator_tag iterator_category;
		typedef T*								iterator_type;
	private:
		pointer ptr;
	public:
		random_access_iterator() : ptr(NULL) {};
		random_access_iterator(pointer ptr) : ptr(ptr) {};
		~random_access_iterator() {};
		random_access_iterator(const random_access_iterator &copy)  { *this = copy; }
		random_access_iterator &operator=(const random_access_iterator &rhs) {
			if (this == &rhs)
				return *this;
			this->ptr = rhs.ptr;
			return *this;
		}
		// Const conversion
		operator random_access_iterator<const value_type> () const {
			return random_access_iterator<const value_type>(ptr);
		}

		pointer base() const { return ptr; }
		// Operators
		pointer operator->() const { return ptr; }
		reference operator*() const { return *ptr; }
		random_access_iterator &operator++() {
			++ptr;
			return *this;
		}
		random_access_iterator operator++(int) {
			random_access_iterator temp = *this;
			++ptr;
			return temp;
		}
		random_access_iterator &operator--() {
			--ptr;
			return *this;
		}
		random_access_iterator operator--(int) {
			random_access_iterator temp = *this;
			--ptr;
			return temp;
		}
		random_access_iterator operator+(difference_type n) const {return ptr + n;};
		random_access_iterator operator-(difference_type n) const {return ptr - n;};
		difference_type operator-(const random_access_iterator &it) {return ptr - it.ptr;};
		difference_type operator+(const random_access_iterator &it) {return ptr + it.ptr;};
		random_access_iterator operator+=(difference_type n)  {ptr += n;return *this;};
		random_access_iterator operator-=(difference_type n)  {ptr -= n;return *this;};
		reference operator[](difference_type n) const {return ptr[n];};
	};

	//non member functions
	template<class T>
	random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n,
										const random_access_iterator<T> &rhs)
										{return (rhs + n);}
	template<class Iterator1, class Iterator2>
	bool operator==(ft::random_access_iterator<Iterator1> const &lhs,
					ft::random_access_iterator<Iterator2> const &rhs)
					{return (lhs.base() == rhs.base());}

	template<class Iterator1, class Iterator2>
	bool operator!=(ft::random_access_iterator<Iterator1> const &lhs,
					ft::random_access_iterator<Iterator2> const &rhs)
					{return (lhs.base() != rhs.base());}

	template<class Iterator1, class Iterator2>
	bool operator>(ft::random_access_iterator<Iterator1> const &lhs,
				   ft::random_access_iterator<Iterator2> const &rhs)
					{return (lhs.base() > rhs.base());}

	template<class Iterator1, class Iterator2>
	bool operator>=(ft::random_access_iterator<Iterator1> const &lhs,
					ft::random_access_iterator<Iterator2> const &rhs)
					{return (lhs.base() >= rhs.base());}

	template<class Iterator1, class Iterator2>
	bool operator<(ft::random_access_iterator<Iterator1> const &lhs,
				   ft::random_access_iterator<Iterator2> const &rhs)
					{return (lhs.base() < rhs.base());}

	template<class Iterator1, class Iterator2>
	bool operator<=(ft::random_access_iterator<Iterator1> const &lhs,
					ft::random_access_iterator<Iterator2> const &rhs)
					{return (lhs.base() <= rhs.base());}
}
//Red black tree iterator

namespace ft{
	template<class Pair, class NodePointer>
	class rb_tree_iterator{
	public:
		typedef Pair       									value_type;
		typedef Pair&  										reference;
		typedef Pair* 										pointer;
		typedef NodePointer									node_pointer;
		typedef std::ptrdiff_t								difference_type;
		typedef typename std::bidirectional_iterator_tag	iterator_category;
		typedef Pair*										iterator_type;


	private:
		node_pointer ptr;
		node_pointer root;
		node_pointer nil;
	public:
		rb_tree_iterator() : ptr(NULL), root(NULL), nil(NULL) {}
		rb_tree_iterator(node_pointer ptr, node_pointer root, node_pointer  nil) :
				ptr(ptr), root(root), nil(nil) {}
		//Const conversion
		template <typename U, typename P1> 
		rb_tree_iterator(const rb_tree_iterator<U,P1>& u) {
			ptr = u.getPtr();
			root = u.getRoot();
			nil = u.getNil();
		}
		rb_tree_iterator(const rb_tree_iterator &copy){*this = copy;}
		rb_tree_iterator &operator=(const rb_tree_iterator &rbt){
			if (this == &rbt)
				return *this;
			this->ptr = rbt.getPtr();
			this->root = rbt.getRoot();
			this->nil = rbt.getNil();
			return *this;
		}
		~rb_tree_iterator() {};

		// Operators
		bool operator==(const rb_tree_iterator &rbt) const {return ptr == rbt.ptr;}
		bool operator!=(const rb_tree_iterator &rbt) const {return ptr != rbt.ptr;}
		reference operator*() const {return ptr->val;}
		pointer operator->() const {return &ptr->val;}
		rb_tree_iterator &operator++(){
			if (ptr == getMax(root)){
				ptr = nil;
				return *this;
			}else if (ptr == nil){
				ptr = NULL;
				return *this;
			}else
				ptr = findNext(ptr);
			return *this;
		}
		rb_tree_iterator operator++(int){
			rb_tree_iterator	tmp = *this;
			operator++();
			return tmp;
		}
		rb_tree_iterator &operator--(){
			if (ptr == nil){
				ptr = getMax(root);
				return *this;
			}
			ptr = findPrevious(ptr);
			return *this;
		}
		rb_tree_iterator operator--(int){
			rb_tree_iterator 	tmp = *this;
			operator--();
			return tmp;
		}

		// Getters and finders
		node_pointer getMax(node_pointer ndptr){
			for (;ndptr && ndptr->right != nil; ndptr = ndptr->right);
			return ndptr;
		}
		node_pointer getMin(node_pointer ndptr){
			for (;ndptr && ndptr->left != nil; ndptr = ndptr->left);
			return ndptr;
		}

		node_pointer findNext(node_pointer ndptr){
			if (ndptr->right != nil)
				return getMin(ndptr->right);
			node_pointer temp = ndptr->parent;
			while (temp != nil && ndptr == temp->right){
				ndptr = temp;
				temp = temp->parent;
			}
			return temp;
		}
		node_pointer findPrevious(node_pointer ndptr){
			if (ndptr->left != nil)
				return getMax(ndptr->left);
			node_pointer tmp = ndptr->parent;
			while (tmp != nil && ndptr == tmp->left){
				ndptr = tmp;
				tmp = tmp->parent;
			}
			return tmp;
		}

		node_pointer getPtr() const {return ptr;}
		node_pointer getRoot() const {return root;}
		node_pointer getNil() const {return nil;}
	};
}
//red black tree

enum Color{BLACK,RED};

template <class T>
class RBNode{
public:
	typedef T		value_type;
	RBNode 			*left;
	RBNode 			*right;
	RBNode 			*parent;
	value_type 		val;
	int 			color;

	RBNode(): left(NULL), right(NULL), parent(NULL), val(), color(BLACK) {}
	RBNode(const value_type &data) : left(NULL), right(NULL), val(data), color(BLACK) {}
	RBNode(const value_type &val, RBNode *left, RBNode *right, RBNode *parent, int color) : left(left), right(right), parent(parent), val(val), color(color){}
	~RBNode(){};
	RBNode(const RBNode &other): left(other.left), right(other.right), parent(other.parent), val(other.val), color(other.color){}

	RBNode& operator=(const RBNode &other){
		if (this == &other)
			return *this;
		this->left = other->left;
		this->right = other->right;
		this->parent = other->parent;
		this->val = other->val;
		this->color = other->color;
	}
};

template <class ValueType, class Key, class Compare, class Allocator>
class RBTree{
public:
	typedef ValueType														value_type;
	typedef Key																key_type;
	typedef RBNode<value_type>												Node;
	typedef std::size_t														size_type;
	typedef Compare															key_compare;
	typedef typename Allocator::template rebind<RBNode<value_type> >::other	allocator_type;
	typedef typename allocator_type::pointer								pointer;
	typedef typename allocator_type::const_pointer							const_pointer;

	typedef ft::rb_tree_iterator<value_type, pointer>						iterator;
	typedef ft::rb_tree_iterator<const value_type, const_pointer>			const_iterator;
	typedef ft::reverse_iterator<iterator>									reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;

private:
	pointer				root;
	pointer				nil;
	size_type			_size;
	allocator_type		alloc;
	key_compare			comp;

public:
	RBTree(key_compare const& cmp = key_compare()){
		comp = cmp;
		_size = 0;
		nil = alloc.allocate(1);
		alloc.construct(nil, Node());
		root = nil;
	}
	~RBTree() {}
	RBTree (const RBTree &other){
		*this = other;
	}

	RBTree& operator=(const RBTree& other){
		if (this == &other)
			return *this;
		clear();
		deallocateNil();
		this->alloc = other.alloc;
		this->comp = other.comp;
		nil = alloc.allocate(1);
		alloc.construct(nil, Node());
		root = nil;
		deepCopy(other.root, other.nil);
		return *this;
	}
	void deepCopy(pointer rootPtr, pointer nilPtr){
		if (rootPtr != nilPtr){
			insert(rootPtr->val);
			deepCopy(rootPtr->right, nilPtr);
			deepCopy(rootPtr->left, nilPtr);
		}
	}
	//iterators
	iterator					begin(){return iterator(getMin(), root, nil);}
	const_iterator				begin() const {return const_iterator(getMin(), root, nil);}
	iterator					end(){return iterator(nil, root, nil);}
	const_iterator				end() const {return const_iterator(nil, root, nil);}
	reverse_iterator			rbegin(){return reverse_iterator(end());}
	const_reverse_iterator		rbegin() const {return const_reverse_iterator(end());}
	reverse_iterator			rend(){return reverse_iterator(begin());}
	const_reverse_iterator		rend() const {return const_reverse_iterator(begin());}
	pointer find(const value_type &key) const {
		pointer tmp = root;
		while (tmp != nil){
			if (comp(key, tmp->val))
				tmp = tmp->left;
			else if(comp(tmp->val, key))
				tmp = tmp->right;
			else
				return tmp;
		}
		return nil;
	}

	size_type size() const {return _size;}

	size_type max_size() const {return alloc.max_size();}

	void clear(){
		if (root != nil)
			recursiveCleer(root);
		_size = 0;
		root = nil;
	}

	void swap(RBTree &other){
		std::swap(root, other.root);
		std::swap(nil, other.nil);
		std::swap(_size, other._size);
		std::swap(alloc, other.alloc);
		std::swap(comp, other.comp);
	}

	iterator lower_bound(const value_type& key){
		pointer temp = root;
		iterator result;
		iterator endit = end();
		endit--;
		while (temp != nil){
			if (!comp(temp->val, key)){
				result = iterator(temp, root, nil);
				temp = temp->left;
			}else
				temp = temp->right;
		}
		if (!comp(key, *endit))
			return iterator(nil, root, nil);
		return result;
	}
	const_iterator lower_bound(const value_type& key) const {
		pointer temp = root;
		const_iterator result;
		const_iterator endit = end();
		endit--;
		while (temp != nil){
			if (!comp(temp->val, key)){
				result = const_iterator(temp, root, nil);
				temp = temp->left;
			}else
				temp = temp->right;
		}
		if (!comp(key, *endit))
			return const_iterator(nil, root, nil);
		return result;
	}

	iterator upper_bound(const value_type& key){
		pointer temp = root;
		iterator result;
		iterator endit = end();
		endit--;
		while (temp != nil){
			if (comp(key, temp->val)){
				result = iterator(temp, root, nil);
				temp = temp->left;
			}else
				temp = temp->right;
		}
		if (!comp(key, *endit))
			return iterator(nil, root, nil);
		return result;
	}
	const_iterator upper_bound(const value_type& key) const {
		pointer temp = root;
		const_iterator result;
		const_iterator endit = end();
		endit--;
		while (temp != nil){
			if (comp(key, temp->val)){
				result = const_iterator(temp, root, nil);
				temp = temp->left;
			}
			else
				temp = temp->right;
		}
		if (!comp(key, *endit))
			return const_iterator(nil, root, nil);
		return result;
	}

	bool insert( const value_type& value ) {
		pointer newNode = createNode(value);
		pointer y = NULL;
		pointer x = this->root;
		while (x != nil) {
			y = x;
			if (comp(newNode->val, x->val))
				x = x->left;
			else if (comp(x->val, newNode->val))
				x = x->right;
			else{
				alloc.destroy(newNode);
				alloc.deallocate(newNode, 1);
				return false;
			}
		}
		newNode->parent = y;
		if (y == NULL)
			root = newNode;
		else if (comp(newNode->val, y->val))
			y->left = newNode;
		else
			y->right = newNode;
		_size++;
		if (newNode->parent == NULL) {
			newNode->color = BLACK;
			return true;
		}
		if (newNode->parent->parent == NULL)
			return true;
		fixInsertion(newNode);
		return  true;
	}
	void fixInsertion(pointer node){
		pointer uncle;
		while (node->parent->color == RED){
			if (node->parent == node->parent->parent->right) {
				uncle = node->parent->parent->left;
				if (uncle->color == RED) {
					uncle->color = BLACK;
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent;
				} else {
					if (node == node->parent->left){
						node = node->parent;
						rightRotate(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					leftRotate(node->parent->parent);
				}
			} else{
				uncle = node->parent->parent->right;
				if (uncle->color == RED){
					uncle->color = BLACK;
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent;
				}else{
					if (node == node->parent->right){
						node = node->parent;
						leftRotate(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					rightRotate(node->parent->parent);
				}
			}
			if (node == root)
				break;
		}
		root->color = BLACK;
	}

	bool erase(const value_type &key){
		pointer node = root;
		pointer x, y, z;
		z = nil;
		while (node != nil){
			if (comp(node->val, key))
				node = node->right;
			else if (comp(key, node->val))
				node = node->left;
			else {
				z = node;
				break;
			}
		}
		if (z == nil)
			return false;
		y = z;
		int originalColor = y->color;
		if (y->left == nil){
			x = z->right;
			rbReplace(z, z->right);
		}else if (z->right == nil){
			x = z->left;
			rbReplace(z, z->left);
		}else{
			y = getMin(z->right);
			originalColor = y->color;
			x = y->right;
			if (y->parent == z)
				x->parent = y;
			else{
				rbReplace(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}
			rbReplace(z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		alloc.destroy(z);
		alloc.deallocate(z, 1);
		if(originalColor == BLACK)
			fixDeletion(x);
		_size--;
		return true;
	}

	void fixDeletion(pointer node){
		pointer sibling;
		while (node != root && node->color == BLACK){
			if (node == node->parent->left){
				sibling = node->parent->right;
				if (sibling->color == RED){
					sibling->color = BLACK;
					node->parent->color = RED;
					leftRotate(node->parent);
					sibling = node->parent->right;
				}
				if (sibling->left->color == BLACK && sibling->right->color == BLACK){
					sibling->color = RED;
					node = node->parent;
				}else{
					if (sibling->right->color == BLACK){
						sibling->left->color = BLACK;
						sibling->color = RED;
						rightRotate(sibling);
						sibling = node->parent->right;
					}
					sibling->color = node->parent->color;
					node->parent->color = BLACK;
					sibling->right->color = BLACK;
					leftRotate(node->parent);
					node = root;
				}
			}else{
				sibling = node->parent->left;
				if (sibling->color == RED){
					sibling->color = BLACK;
					node->parent->color = RED;
					rightRotate(node->parent);
					sibling = node->parent->left;
				}
				if (sibling->right->color == BLACK && sibling->right->color == BLACK){
					sibling->color = RED;
					node = node->parent;
				}else{
					if (sibling->left->color == BLACK){
						sibling->right->color = BLACK;
						sibling->color = RED;
						leftRotate(sibling);
						sibling = node->parent->left;
					}
					sibling->color = node->parent->color;
					node->parent->color = BLACK;
					sibling->left->color = BLACK;
					rightRotate(node->parent);
					node = root;
				}
			}
		}
		node->color = BLACK;
	}

	// Rotations
	void leftRotate(pointer x){
		pointer  y = x->right;
		x->right = y->left;
		if (y->left != nil)
			y->left->parent = x;
		y->parent = x->parent;
		if (x->parent == NULL)
			this->root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->left = x;
		x->parent = y;
	}
	void rightRotate(pointer x){
		pointer y = x->left;
		x->left = y->right;
		if (y->right != nil)
			y->right->parent = x;
		y->parent = x->parent;
		if (x->parent == NULL)
			this->root = y;
		else if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;
		y->right = x;
		x->parent = y;
	}

	void rbReplace(pointer x, pointer y){
		if (x->parent == NULL)
			root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->parent = x->parent;
	}

	pointer getMin(pointer node){
		if (node == nil || node == NULL)
			return nil;
		for(;node->left != nil;node = node->left);
		return node;
	}
	pointer getMin() const {
		if (root == NULL || root == nil)
			return nil;
		pointer temp = root;
		for (;temp->left != nil;temp = temp->left);
		return temp;
	}

	void recursiveCleer(pointer root){
		if (root != nil){
			recursiveCleer(root->left);
			recursiveCleer(root->right);
			alloc.destroy(root);
			alloc.deallocate(root, 1);
		}
	}

	pointer createNode(const value_type &val){
		pointer newNode = alloc.allocate(1);
		alloc.construct(newNode, Node(val, nil, nil, NULL, RED));
		return newNode;
	}
	void deallocateNil(){
		alloc.destroy(nil);
		alloc.deallocate(nil, 1);
	}
	pointer getRoot() const {return root;}
	pointer getNil() const {return nil;}
};

//other utility
namespace ft {
	template<bool Cond, class T = void>
	struct enable_if {
	};
	template<class T>
	struct enable_if<true, T> {
		typedef T type;
	};
	template <class T, T v>
	struct integral_constant{
		static const T value = v;
		typedef T						value_type;
		typedef integral_constant<T,v>	type;
		operator value_type() const { return value; }
	};
	typedef integral_constant<bool, true>   true_type;
	typedef integral_constant<bool, false>  false_type;
	template <class T>	struct is_integral						: public false_type {};
	template <>			struct is_integral<bool>				: public true_type {};
	template <>			struct is_integral<char>				: public true_type {};
	template <>			struct is_integral<signed char>			: public true_type {};
	template <>			struct is_integral<unsigned char>		: public true_type {};
	template <>			struct is_integral<wchar_t>				: public true_type {};
	template <>			struct is_integral<short>				: public true_type {};
	template <>			struct is_integral<unsigned short>		: public true_type {};
	template <>			struct is_integral<int>					: public true_type {};
	template <>			struct is_integral<unsigned int>		: public true_type {};
	template <>			struct is_integral<long>				: public true_type {};
	template <>			struct is_integral<unsigned long>		: public true_type {};
	template <>			struct is_integral<long long>			: public true_type {};
	template <>			struct is_integral<unsigned long long>	: public true_type {};
	template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 begin1, InputIterator1   end1, InputIterator2 begin2 ) {
		while (begin1 != end1) {
			++begin1;
			++begin2;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								  InputIterator2 first2, InputIterator2 last2){
		while (first1 != last1){
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2!=last2);
	}
	template< class T1, class T2>
	struct pair{
		typedef	T1		first_type;
		typedef	T2		second_type;
		typedef	T2		third_type;
		pair() : first(first_type()), second(second_type()) {}
		pair(const T1& x, const T2& y) : first(x), second(y) {}
		template< class U1, class U2 >
		pair(const pair<U1, U2>& p): first(p.first), second(p.second) {}
		pair& operator=(const pair& other) {
			if (this == &other)
				return *this;
			this->first = other.first;
			this->second = other.second;
			return *this;
		}
		first_type first;
		second_type second;
		third_type third;
	};

	template< class T1, class T2 >
	ft::pair<T1,T2> make_pair(T1 t, T2 u){return pair<T1, T2>(t, u);}

	// Operators
	template< class T1, class T2 >
	bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){return (lhs.first == rhs.first && lhs.second == rhs.second);}
	template< class T1, class T2 >
	bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){return !(lhs == rhs);}
	template< class T1, class T2 >
	bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){return (lhs.first < rhs.first) || (!(rhs.first < lhs.first) && lhs.second < rhs.second);}
	template< class T1, class T2 >
	bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){return !(rhs < lhs);}
	template< class T1, class T2 >
	bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){return (rhs < lhs);}
	template< class T1, class T2 >
	bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){return !(lhs < rhs);}
}

