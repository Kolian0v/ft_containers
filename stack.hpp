#ifndef STACK_HPP
# define STACK_HPP

# include "utils.hpp"
# include "vector.hpp"
# include "map.hpp"

namespace ft{

	template<class T, class K = ft::vector<T> >
	class stack
	{
	private:
		typedef K			container_type;
		typedef T			value_type;
		typedef T*			pointer;
		typedef T const *	const_pointer;
		typedef T&			reference;
		typedef T const &	const_reference;
	protected:
		container_type	cop;
	public:
		stack(const K &c=container_type()) {cop=c;};
		stack(stack const &other): cop(other.cop) {};
		~stack(){};
		stack &operator=(stack &other){
			if (this == &other) return *this;
			this->cop = other.cop;
			return *this;
		}
		void swap( stack& other ) {this->cop = other->cop;};
		reference top() {return cop.back();}
		const_reference top() const {return cop.back();}
		bool empty() const {return cop.empty();}
		size_t size() {return cop.size();}
		void push(const value_type &value) {cop.push_back(value);}
		void pop() {cop.pop_back();}

		// Operators
		template<typename stackT, typename containerT>
		friend bool operator==(stack<stackT, containerT> const &s1, stack<stackT, containerT> const &s2) {
			return (s1.cop == s2.cop);
		}
		template<typename stackT, typename containerT>
		friend bool operator!=(stack<stackT, containerT> const &s1, stack<stackT, containerT> const &s2) {
			return (s1.cop != s2.cop);
		}
		template<typename stackT, typename containerT>
		friend bool operator<(stack<stackT, containerT> const &s1, stack<stackT, containerT> const &s2) {
			return (s1.cop < s2.cop);}
		
		template<typename stackT, typename containerT>
		friend bool operator<=(stack<stackT, containerT> const &s1, stack<stackT, containerT> const &s2) {
			return (s1.cop <= s2.cop);
		}
		template<typename stackT, typename containerT>
		friend bool operator>(stack<stackT, containerT> const &s1, stack<stackT, containerT> const &s2) {
			return (s1.cop > s2.cop);
		}
		template<typename stackT, typename containerT>
		friend bool operator>=(stack<stackT, containerT> const &s1, stack<stackT, containerT> const &s2) {
			return (s1.cop >= s2.cop);
		}
	};
}

#endif