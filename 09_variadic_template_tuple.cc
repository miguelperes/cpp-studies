#include <iostream>
#include <string>

template <typename Head, typename... Rest>
struct Tuple {
	Head head;
	Tuple<Rest...> tail;
};

/* Caso específico deve vir depois do caso genérico, e com o tipo especificado na declaração */

// Caso base: último membro da tupla, não terá cauda
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

template <int i, typename Head>
Head at(Tuple<Head>& tuple) {
	if(i == 0)
		return tuple.head;
	else
		throw "Error: tuple size exceeded.";
}

template <int i, typename Head, typename... Tail>
Head at(Tuple<Head, Tail...>& tuple) {
	if(i == 0)
		return tuple.head;
	else
		return at<(i-1)>(tuple.tail);
}

int main() {
	using namespace std;

	Tuple<int, string, double> t{ 10, { "abc", { 3.14 } } };

	auto tuple = init_tuple(1, 2, 3);

	/* Getting values manually */
	// cout << tuple.head << endl;
	// cout << tuple.tail.head << endl;
	// cout << tuple.tail.tail.head << endl;

	/* Using at function */
	cout << at<0>(tuple) << endl;
	cout << at<1>(tuple) << endl;
	cout << at<2>(tuple) << endl;

	return 0;
}