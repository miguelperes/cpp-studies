#include <iostream>

// Factorial 
template <int N> struct Factorial {
 static const int result = N * Factorial<N-1>::result;
};
 
template <> struct Factorial<0> {
 static const int result = 1;
};

// Fibonacci
template <int N> struct Fib {
 static const int result = Fib<N-1>::result + Fib<N-2>::result;
};
 
template <> struct Fib<0> {
 static const int result = 0;
};

template <> struct Fib<1> {
 static const int result = 1;
};


// MDC
template <int A, int B> struct MDC {
	static const int result = MDC<A % B, B % A>::result;
};

template <int A> struct MDC<A, 0> {

	static const int result = A;
};

template <int B> struct MDC<0, B> {

	static const int result = B;
};


 
int main() {
 std::cout << Factorial<5>::result << "\n";
 std::cout << Fib<10>::result << "\n";
 std::cout << MDC<18, 36>::result << std::endl;

 return 0;
}



