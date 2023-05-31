#include <iostream>

class smart_array{
	int arr_size, ite_arr=0;
	int* arr0;
	public:
		smart_array(int arr_size)
		{
			arr0 = new int[arr_size];
			this->arr_size = arr_size;
		}
		~smart_array() { delete [] arr0; }
		void add_element(int elem_arr) {
			if (ite_arr < arr_size)
			{
				arr0[ite_arr] = elem_arr;
				ite_arr++;
			}
			else std::cout << "Элемент вышел за рамки массиа";
		}
		int get_element(int index) {
			if (index > 0 && index < ite_arr) return arr0[index];
			else  throw "ошибка в номере";
		}
};

int main()
{
   
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}
