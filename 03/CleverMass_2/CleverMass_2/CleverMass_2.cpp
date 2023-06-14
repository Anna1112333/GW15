#include <iostream>
#include <algorithm>

class smart_array {
public:
	int arr_size{ 0 }, copasity_objects = 0;
	int* arr0;
	

	smart_array(int arr_size)
	{		
		arr0 = new int[arr_size];
		this->arr_size = arr_size;			
	}
	smart_array(const  smart_array &g)
	{					
				this->arr_size = g.arr_size;
				this->copasity_objects = g.copasity_objects;
				this->arr0 = new int[g.arr_size];
				for (int i = 0; i < g.arr_size; i++)
					this->arr0[i] = g.arr0[i];					
	}

	smart_array& operator = (const smart_array& g1) {
		if (this != &g1) {
			if (this->arr_size == g1.arr_size)
				for (int i = 0; i < g1.arr_size; i++)
					this->arr0[i] = g1.arr0[i];
			else {
				delete[] this->arr0;
				this->arr0 = new int[g1.arr_size];
				for (int i = 0; i < g1.arr_size; i++)
					this->arr0[i] = g1.arr0[i];
			}
		}
		return *this;
	}

	~smart_array()
	{
		delete[] arr0;
	}

	void add_element(int elem_arr) {
		if ( copasity_objects< arr_size)
		{
			arr0[copasity_objects] = elem_arr;
			copasity_objects++;
		}
		else { std::cout << "Элемент вышел за рамки массиа"; }
	}
	int get_element(int index) {
		if ((index >= 0) &&( index <= copasity_objects))
			return arr0[index];
		else {
			std::cout << "ошибка в номере"; return 500;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	smart_array arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);
	std::cout<<arr.get_element(2)<<std::endl;

	smart_array new_array(2);
	new_array.add_element(44);
	new_array.add_element(34);
	std::cout << new_array.get_element(0)<<std::endl;
	
	arr = new_array;
	std::cout << arr.get_element(0) << std::endl;
}