#include <string>
#include <iostream>

class ArrayInt
{
	public:
		ArrayInt(int _size) {
			size  = _size;
			array = new int[size];
		};

		void put(int idx, int value) {
			if(idx >= size || idx < 0){
				std::cout << "Indice fora dos limites do array\n";
			} else {
				array[idx] = value;
			}
		};

		int at(int idx) {
			if(idx >= size || idx < 0){
				std::cout << "Indice fora dos limites do array\n";
				return -1;
			} else {
				return array[idx];
			}
		};

		void print() {
			for(int i = 0; i < size; i++)
			{
				std::cout << array[i] << "\t";
			}
			std::cout << "\n";
		};

	protected:

		// Colocar em at() e put()
		bool validRange(int n) { 
			if(n >= 0 && n < size) {
				std::cout("Limite de array ultrapassado\n");
				return true;
			}
			else
				return false;
		}

		void error( std::string msg ) {
			std::cout << "Error! " << msg << std::endl;
		}

	private:
		int size;
		int *array;
};


int main()
{
	using namespace std;
	cout << "Tarefa 01\n";

	// Construtor        // Não permitido para um construtor sem parâmetro, C++ acha que é função
	ArrayInt myArray = 3;

	// Put
	myArray.put(0, 6);
	myArray.put(1, 25);
	
	// Put error
	myArray.put(99, 8);

	// At
	int val = myArray.at(0);
	cout << "Valor at: " << val << "\n";
	myArray.print();
	
	// At error
	val = myArray.at(999);
}