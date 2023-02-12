#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <iostream>
#include <memory>
#include "utils.hpp"
#include <exception>
#include <stdexcept>

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef std::ptrdiff_t difference_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef ft::random_access_iterator<value_type>			iterator;
		typedef ft::random_access_iterator<const value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
	private:
		value_type*		_cont;
		std::size_t		_size;
		std::size_t		_capacity;
		allocator_type	_alloc;
	public:
		//Constructors
		vector (const allocator_type& alloc = allocator_type()){_cont = NULL;_size = 0; _capacity = 0; _alloc = alloc;}
		vector (std::size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			_size = n;
			_capacity = n;
			_alloc = alloc;
			_cont = this->_alloc.allocate(_size);
			std::size_t i = 0;
			while ( i < n)
				this->_alloc.construct(_cont + i++, val);
		}
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		{
			_alloc = alloc;
			std::size_t len = last - first;
			_size = len;
			_capacity = len;
			_cont =  this->_alloc.allocate(_capacity);
			std::size_t i = 0;
			while (i < len)
			{
				this->_alloc.construct((_cont + i), *first);
				first++;
				i++;
			}
		}
		vector (const vector &copy)
		{
			_capacity = copy._capacity;
			_size = copy._size;
			_alloc = copy._alloc;
			this->_cont = _alloc.allocate(_capacity);
			std::size_t i = 0;
			while (i < _size)
			{
				_alloc.construct(_cont + i, copy._cont[i]);
				i++;
			}
		}
		~vector()
		{
			while (_size > 0)
				pop_back();
			_alloc.deallocate(_cont, _capacity);
		}

		//Member functions
		vector& operator=(const vector& other)
		{
			if (this == &other)
				return *this;
			while (_size > 0) pop_back();
			_alloc.deallocate(_cont, _capacity);
			this->_capacity = other._capacity;
			this->_alloc = other._alloc;
			this->_size = other._size;
			this->_cont = _alloc.allocate(_capacity);
			std::size_t i = 0;
			while ( i < _size)
			{
				_alloc.construct(_cont + i, other._cont[i]);
				i++;
			}
			return *this;
		}

		allocator_type get_allocator() const{return _alloc;}

		void assign(std::size_t count, const value_type& val)
		{
			while (_size > 0)
				pop_back();
			if (count > _capacity)
			{
				_alloc.deallocate(_cont, _capacity);
				_cont = _alloc.allocate(count);
				_capacity = count;
			}
			std::size_t i = 0;
			while (i < count)
			{
				_alloc.construct(_cont + i, val);
				i++;
			}
			_size = count;
		}

		template <class InputIt>
		void assign (InputIt first, InputIt last, typename enable_if<!is_integral<InputIt>::value>::type* = 0)
		{
			while (_size > 0)
				pop_back();
			std::size_t  count = last - first;
			if (count > _capacity)
			{
				_alloc.deallocate(_cont, _capacity);
				_cont = _alloc.allocate(count);
				_capacity = count;
			}
			std::size_t i = 0;
			while (i < count)
			{
				_alloc.construct(_cont + i, *first);
				first++;
				i++;
			}
			_size = count;
		}
		//iterators
		iterator begin() { return iterator(_cont); }
		iterator end() { return iterator(_cont + _size); }
		const_iterator begin() const { return const_iterator(_cont); }
		const_iterator end() const{ return const_iterator(_cont + _size); }
		reverse_iterator rbegin()  { return reverse_iterator(end()); }
		reverse_iterator rend() { return reverse_iterator(begin()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
		const_reverse_iterator rend() const{ return const_reverse_iterator(begin()); }

		// 		Element Access
		reference at(std::size_t pos)
		{
			if (pos >= size())
				throw std::out_of_range("Out of range");
			return _cont[pos];
		}
		const_reference at( std::size_t pos ) const
		{
			if (pos >= size())
				throw std::out_of_range("Out of range");
			return _cont[pos];
		}
		reference operator[]( std::size_t pos ){return _cont[pos];}
		const_reference operator[]( std::size_t pos ) const{return _cont[pos];}
		reference front(){return _cont[0];}
		const_reference front() const{return _cont[0];}
		reference back(){return _cont[_size -1];}
		const_reference back() const{return _cont[_size - 1];}
		T* data(){return _cont;}
		const T* data() const{return _cont;}

		//Capacity
		bool empty() const{return (_size == 0);}
		std::size_t size() const{return _size;}
		std::size_t capacity() const{return _capacity;}
		std::size_t max_size() const{return _alloc.max_size();}
		void reserve(size_t new_cap)
		{
			if (new_cap > max_size())
				throw std::length_error("Length error");
			if (new_cap < _capacity)
				return;
			T* newAlloc = _alloc.allocate(new_cap);
			std::size_t i = 0;
			while (i < _size)
			{
				_alloc.construct(newAlloc + i, _cont[i]);
				i++;
			}
			i = 0;
			while ( i < _size)
			{
				_alloc.destroy(_cont + i);
				i++;
			}
			if (_cont)
				_alloc.deallocate(_cont, _capacity);
			_capacity = new_cap;
			_cont = newAlloc;
			test("test1", 403);
		}

		//Modifiers
		void clear()
		{
			while (_size > 0)
				pop_back();
		}
		iterator insert(iterator pos, const T& value)
		{
			std::size_t index = pos - begin();
			if (_size == _capacity)
			{
				std::size_t new_cap;
				if (_capacity == 0)
					new_cap = _capacity + 1;
				else
					new_cap = _capacity * 2;
				value_type *newAlloc = _alloc.allocate(new_cap);
				std::size_t i = 0;
				while ( i < (_size - index))
				{
					_alloc.construct(newAlloc + i, _cont[i]);
					i++;
				}
				_alloc.construct(newAlloc + index, value);
				i = index + 1;
				while ( i <= _size)
				{
					_alloc.construct(newAlloc + i, _cont[i - 1]);
					i++;
				}
				i = 0;
				while (i < _size)
				{
					_alloc.destroy(&_cont[i]);
					i++;
				}
				_alloc.deallocate(_cont, _capacity);
				_cont = newAlloc;
				_capacity = new_cap;
			}
			else
			{
				std::size_t i = _size;
				while (i > index)
				{
					_alloc.destroy(_cont + i);
					_alloc.construct(_cont + i, *(_cont + i -1));
					i--;
				}
				_alloc.destroy(_cont + index);
				_alloc.construct(_cont + index, value);
			}
			_size++;
			return begin() + index;
		}
		void insert(iterator pos, std::size_t count, const T& value)
		{
			std::size_t index = pos - begin();
			if (_size + count > _capacity)
			{
				std::size_t new_cap;
				if (_capacity * 2 >= _size + count)
					new_cap = _capacity;
				else
					new_cap =  _size + count;
				value_type *newAlloc = _alloc.allocate(new_cap);
				std::size_t i = 0;
				while (i < (_size - index))
				{
					_alloc.construct(newAlloc + i, _cont[i]);
					i++;
				}
				i = 0;
				while (i < count)
				{
					_alloc.construct(newAlloc + index + i, value);
					i++;
				}
				i = index;
				while ( i < _size)
				{
					_alloc.construct(newAlloc + i + count, _cont[i]);
					i++;
				}
				i = 0;
				while (i < _size)
				{
					_alloc.destroy(_cont + i);
					i++;
				}
				if (_cont)
					_alloc.deallocate(_cont, _capacity);
				_cont = newAlloc;
				_capacity = new_cap;
			}
			else
			{
				std::size_t i = _size;
				while ( i > index)
				{
					_alloc.destroy(_cont + i + count - 1);
					_alloc.construct(_cont + i + count - 1, _cont[i -1]);
					i--;
				}
				i = index;
				while (i < index + count)
				{
					_alloc.destroy(_cont + i);
					_alloc.construct(_cont + i, value);
					i++;
				}
			}
			_size += count;
		}
		template< class InputIt >
		void insert(iterator pos, InputIt first, InputIt last,
		typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type * = NULL)
		{
			std::size_t index = pos - begin();
			std::size_t count = last - first;
			value_type *newAlloc;
			std::size_t new_cap;
			if (_capacity * 2 >= _size + count)
				new_cap = _capacity * 2;
			else
				new_cap = _size + count;
			try
			{
				if (_size + count > _capacity)
				{
					newAlloc = _alloc.allocate(new_cap);
					std::size_t i = 0;
					while ( i < (_size - index))
					{
						_alloc.construct(newAlloc + i, _cont[i]);
						i++;
					}
					i = 0;
					while (i < count)
					{
						_alloc.construct(newAlloc + index + i, *(first));
						first++;
						i++;
					}
					i = index;
					while (i < _size)
					{
						_alloc.construct(newAlloc + i + count, _cont[i]);
						i++;
					}
					i = 0;
					while (i < _size)
					{
						_alloc.destroy(_cont + i);
						i++;
					}
					if (_cont)
						_alloc.deallocate(_cont, _capacity);
					_cont = newAlloc;
					_capacity = new_cap;
				} else
				{
					std::size_t i = _size;
					while (i > index)
					{
						_alloc.destroy(_cont + i + count - 1);
						_alloc.construct(_cont + i + count - 1, _cont[i - 1]);
						i--;
					}
					i = index;
					while (i < index + count)
					{
						_alloc.destroy(_cont + i);
						_alloc.construct(_cont + i, *first);
						first++;
						i++;
					}
				}
				_size += count;
			}
			catch(...)
			{
				std::size_t i = 0;
				while(i < count)
				{
					_alloc.destroy(newAlloc + i + index);
					i++;
				}
				_alloc.deallocate(newAlloc, new_cap);
				throw;
			}
		}

		iterator erase(iterator pos)
		{
			std::size_t index = pos - begin();
			_alloc.destroy(_cont + index);
			std::size_t i = index;
			while ( i < _size - 1)
			{
				_alloc.construct(_cont + i, _cont[i + 1]);
				i++;
			}
			_size--;
			return iterator(_cont + index);
		}
		iterator erase (iterator first, iterator last)
		{
			std::size_t index = first - begin();
			std::size_t count = last - first;
			while (first != last){
				_alloc.destroy(&(*first));
				first++;
			}
			std::size_t temp = index;
			while (last < this->end())
			{
				_alloc.construct(_cont + temp, *last);
				temp++;
				last++;
			}
			_size -= count;
			return iterator(_cont + index);
		}

		void push_back(const value_type& val){
			if (_size == _capacity)
			{
				if (_capacity == 0)
					_capacity = _capacity + 1;
				else
					_capacity = (_capacity * 2);
				this->reserve(_capacity);
			}
			this->_alloc.construct(_cont + _size, val);
			_size++;
		}
		void pop_back()
		{
			_size--;
			_alloc.destroy(&_cont[_size]);
		}

		void resize (std::size_t count, value_type val = value_type()){
			if (_size > count)
			{
				std::size_t i = count;
				while (i > _size)
				{
					_alloc.destroy(_cont + i);
					i++;
				}
				_size = count;
			}
			else if (_size < count)
			{
				if (_capacity < count)
				{
					std::size_t new_cap;
					if (_capacity * 2 > count)
						new_cap =  _capacity * 2;
					else
						new_cap = count;
					reserve(new_cap);
				}
				std::size_t i = _size;
				while ( i < count)
				{
					_alloc.construct(_cont + i, val);
					_size++;
					i++;
				}
			}
		}

		void swap(vector &x){
			std::swap(this->_cont, x._cont);
			std::swap(this->_size, x._size);
			std::swap(this->_capacity, x._capacity);
			std::swap(this->_alloc, x._alloc);
		}
	};

	// Operators
	template < class T, class Alloc >
	bool operator==( const ft::vector<T,Alloc>& v1, const ft::vector<T,Alloc>& v2 )
	{return v1.size() == v2.size() && ft::equal(v1.begin(), v1.end(), v2.begin());}

	template < class T, class Alloc >
	bool operator!=( const ft::vector<T,Alloc>& v1, const ft::vector<T,Alloc>& v2 )
	{return v1.size() != v2.size() || !ft::equal(v1.begin(), v1.end(), v2.begin());}

	template < class T, class Alloc >
	bool operator<( const ft::vector<T,Alloc>& v1, const ft::vector<T,Alloc>& v2 )
	{return ft::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());}

	template < class T, class Alloc >
	bool operator>( const ft::vector<T,Alloc>& v1, const ft::vector<T,Alloc>& v2 )
	{return ft::lexicographical_compare(v2.begin(), v2.end(), v1.begin(), v1.end());}

	template < class T, class Alloc >
	bool operator<=( const ft::vector<T,Alloc>& v1, const ft::vector<T,Alloc>& v2 )
	{return !ft::lexicographical_compare(v2.begin(), v2.end(), v1.begin(), v1.end());}

	template < class T, class Alloc >
	bool operator>=( const ft::vector<T,Alloc>& v1, const ft::vector<T,Alloc>& v2 )
	{return !ft::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());}

//	template <class T, class Alloc>
//	void swap(Vector<T, Alloc> &x, Vector<T, Alloc> &y){x.swap(y);}
}
#endif //FT_CONTAINERS_VECTOR_HPP