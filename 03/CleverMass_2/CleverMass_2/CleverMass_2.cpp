#include <iostream>

class smart_array {
	int arr_size, copasity_objects=0;
	int* arr0;
	
public:
	smart_array(int arr_size)
	{
		
		arr0 = new int[arr_size];
		this->arr_size = arr_size;			
	}
	smart_array(const  smart_array &g):copasity_objects(0)
	{
		arr0= new int[arr_size];
		this->arr_size = arr_size;		
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
	std::cout << new_array.get_element(0);
	//arr = new_array;

}