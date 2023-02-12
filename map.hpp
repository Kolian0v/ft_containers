#ifndef FT_CONTAINERS_MAP_HPP
# define FT_CONTAINERS_MAP_HPP

# include <iostream>
# include "utils.hpp"

namespace ft
{
	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
			{
	public:
		typedef Key									key_type;
		typedef T									mapped_type;
		typedef ft::pair<const Key, T>				value_type;
		typedef std::size_t							size_type;
		typedef std::ptrdiff_t						difference_type;
		typedef Compare								key_compare;
		typedef Allocator							allocator_type;
		typedef value_type&							reference;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer	const_pointer;

		class value_compare{
		protected:
			typedef key_compare comp;
		public:
			bool operator()(const value_type& lhs, const value_type& rhs) const{
				return comp()(lhs.first, rhs.first);
			}
		};
	private:
		typedef RBTree<value_type, key_type, value_compare, allocator_type> rbTree;
	public:
		// RB Tree part
		typedef typename rbTree::iterator					iterator;
		typedef typename rbTree::const_iterator				const_iterator;
		typedef typename rbTree::reverse_iterator			reverse_iterator;
		typedef typename rbTree::const_reverse_iterator		const_reverse_iterator;
	private:
		rbTree				_rbTree;
		allocator_type		_alloc;
		key_compare			_compare;
		value_compare		_value_compare;
	public:
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()): _rbTree(), _alloc(alloc), _compare(comp), _value_compare(value_compare()){}
		template< class InputIt >
		map(InputIt first, InputIt last,
			const Compare& comp = Compare(),
			const Allocator& alloc = Allocator()) : _alloc(alloc), _compare(comp){
			while (first != last){
				_rbTree.insert(*first);
				first++;
			}
		}
		~map(){
			clear();
			_rbTree.deallocateNil();
		}
		map(const map& other){*this = other;}

		allocator_type get_allocator() const{
			return _alloc;
		}

		T& operator[](const Key& key){
			insert(ft::make_pair(key, mapped_type()));
			iterator res = find(key);
			return res->second;
		}
		map& operator=(const map& other){
			if (this == &other)
				return *this;
			_rbTree = other._rbTree;
			_compare = other._compare;
			_alloc = other._alloc;
			_value_compare = other._value_compare;
			return *this;
		}
		// Iterators
		iterator					begin() {return	_rbTree.begin(); }
		const_iterator 				begin() const {return	_rbTree.begin(); }
		iterator					end() {return	_rbTree.end(); }
		const_iterator				end() const {return	_rbTree.end(); }
		reverse_iterator			rbegin() {return	_rbTree.rbegin(); }
		const_reverse_iterator		rbegin() const {return	_rbTree.rbegin(); }
		reverse_iterator			rend() {return	_rbTree.rend(); }
		const_reverse_iterator		rend() const {return	_rbTree.rend(); }

		bool empty() const{return (size() == 0);}
		size_type size() const{return _rbTree.size();}
		size_type max_size() const{return _rbTree.max_size();}
		void clear(){_rbTree.clear();}

		ft::pair<iterator, bool> insert( const value_type& value ){
			bool isInserted = _rbTree.insert(value);
			return ft::make_pair(find(value.first), isInserted);
		}
		template< class InputIt >
		void insert( InputIt first, InputIt last ){
			while (first != last){
				insert(*first);
				first++;
			}
		}
		iterator insert(iterator hint, const value_type& value){
			(void)hint;
			insert(value);
			return find(value.first);
		}

		void erase(iterator pos){
			erase(pos->first);
		}
		void erase(iterator first, iterator last)
		{
			while (first != last)
			{
				first = find(first->first);
				erase((first++)->first);
			}
			
		}
		size_type erase(const Key& key){return _rbTree.erase(ft::make_pair(key, mapped_type()));}

		void swap(map& other){
			_rbTree.swap(other._rbTree);
		}
		size_type count(const Key& key) const{
			return find(key) != end();
		}
		iterator find(const key_type &key){
			return iterator( _rbTree.find(ft::make_pair(key, mapped_type())), _rbTree.getRoot(), _rbTree.getNil());
		}
		const_iterator find(const Key& key ) const{
			return const_iterator( _rbTree.find(ft::make_pair(key, mapped_type())), _rbTree.getRoot(), _rbTree.getNil());
		}
		iterator lower_bound(const Key& key){
			return _rbTree.lower_bound(ft::make_pair(key, mapped_type()));
		}
		const_iterator lower_bound(const Key& key) const{
			return _rbTree.lower_bound(ft::make_pair(key, mapped_type()));
		}
		iterator upper_bound(const Key& key){
			return _rbTree.upper_bound(ft::make_pair(key, mapped_type()));
		}
		const_iterator upper_bound(const Key& key) const{
			return _rbTree.upper_bound(ft::make_pair(key, mapped_type()));
		}
		ft::pair<iterator, iterator> equal_range(const Key& key){
			return ft::make_pair(lower_bound(key), upper_bound(key));
		}
		ft::pair<const_iterator, const_iterator> equal_range(const Key& key) const{
			return ft::make_pair(lower_bound(key), upper_bound(key));
		}

		key_compare key_comp() const{return key_compare();}
		value_compare value_comp() const{return value_compare();}

	};
	// Operators
	template< class Key, class T, class Compare, class Alloc >
	bool operator==(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs){
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator!=(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs){
		return !(lhs == rhs);
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator<(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs){
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator<=(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs){
		return !(rhs < lhs);
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator>(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs){
		return rhs < lhs;
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator>=(const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs){
		return !(rhs > lhs);
	}
	template< class Key, class T, class Compare, class Alloc >
	void swap(ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs){
		lhs.swap(rhs);
	}
};

#endif
