#include <iostream>
#include <string>

template <typename Head, typename... Rest>
struct Tuple {
	Head head;
	Tuple<Rest...> tail;
};

// Caso específico deve vir depois do caso genérico, 
// e com o tipo especificado na declaração
template <typename Head>
struct Tuple<Head> {
	Head head;
};

template <typename Head>
Tuple<Head> init_tuple(Head last) {
	Tuple<Head> tuple;
	tuple.head = last;

	return tuple;
}

template <typename First, typename... Rest>
Tuple<First, Rest...> init_tuple(First first, Rest... rest) {
	Tuple<First, Rest...> tuple;
	tuple.head = first;
	tuple.tail = init_tuple(rest...);

	return tuple;
}


int main() {
	using namespace std;

	Tuple<int, string, double> t{ 10, { "abc", { 3.14 } } };

	auto tuple = init_tuple("one", 2, 3.0);

	cout << tuple.head << endl;
	cout << tuple.tail.head << endl;
	cout << tuple.tail.tail.head << endl;

	return 0;
}