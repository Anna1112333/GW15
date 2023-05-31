#include <iostream>

class smart_array {
	int arr_size, ite_arr = 0, copasity_objects=0;
	int** arr0[10];
	
public:
	smart_array(int arr_size)
	{
		arr0[copasity_objects] = new int*[arr_size];
		this->arr_size = arr_size;
	
		copasity_objects++;
	}
	~smart_array() {
		for(int i=0; i< copasity_objects; i++)
		delete[] arr0[i];
		delete[] arr0; 
	}
	void add_element(int elem_arr) {
		if (ite_arr < arr_size)
		{
			arr0[copasity_objects][ite_arr] = elem_arr;
			ite_arr++;
		}
		else std::cout << "Элемент вышел за рамки массиа";
	}
	int get_element(int index) {
		if (index > 0 && index < ite_arr) return arr0[copasity_objects][index];
		else  throw "ошибка в номере";
	}
};

int main()
{	
	smart_array arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);

	smart_array new_array(2);
	new_array.add_element(44);
	new_array.add_element(34);

	arr = new_array;

}