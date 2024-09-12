#include<iostream>
#include<array>
#include<vector>
#include<list>
#include<iterator>

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n------------------------------------------\n"

//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_LIST

template<typename T> void vector_info(const std::vector<T>& vec)
{
	cout << endl;
	cout << "Size:" << vec.size() << endl;
	cout << "Capacity:" << vec.capacity() << endl;
	cout << "MaxSize:" << vec.max_size() << endl;
}
void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello STL" << endl;
#ifdef STL_ARRAY
	//array-это хранит данные ввиде статического массива.
	//При создании 'array', кроме типа хранимых значений, так же оюязательно нужно указать 
	//количество хранимых значений
	const int N = 5;
	std::array<int, N> arr = { 3,5,8,13,21};
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	//vector-это контейнер, который хранит данные ввиде динамического массива.
	//При создании вектора обязательно задают только тип хранимых элементов 
	std::vector<int> vec = { 0,1,1,2,3,5,8,13,21,34 };
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << tab;
	}
	vector_info(vec);
	vec.push_back(55);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec.at(i) << tab;
	}
	cout << endl;
	vector_info(vec);
	vec.reserve(24);
	vector_info(vec);
	vec.shrink_to_fit();
	vector_info(vec);
	vec.resize(8);
	for (std::vector<int> ::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	vector_info(vec);
	int index;
	int value;
	cout << "введите позицию добавляемого элемента: "; cin >> index;
	cout << "введите значение добавляемого элемента: "; cin >> value;
	std::vector<int>::iterator position_insert = vec.begin();
	std::advance(position_insert, index);
	vec.insert(position_insert, value);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec.at(i) << tab;
	}
	cout << endl;
	cout << "введите позицию удаляемого элемента: "; cin >> index;
	std::vector<int>::iterator position_erase = vec.begin() ;
	advance(position_erase, index);
	vec.erase(position_erase);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec.at(i) << tab;
	}
#endif // STL_VECTOR

#ifdef STL_LIST
	std::list<int> list = { 3,5,8,13,21,34,55 };
	for (std::list<int>::iterator i = list.begin();
		i != list.end();
		i++)cout << *i << tab;cout << endl;
	int index;
	int value;
	cout << "введите позицию добавляемого элемента: "; cin >> index;
	cout << "введите значение добавляемого элемента: "; cin >> value;
	std::list<int>::iterator position_insert = list.begin();
	std::advance(position_insert, index);
	list.insert(position_insert, value);
	for (std::list<int>::iterator i = list.begin();
		i != list.end();
		i++)cout << *i << tab; cout << endl;
	cout << "введите позицию удаляемого элемента: "; cin >> index;
	std::list<int>:: iterator position_erase = list.begin();
	advance(position_erase, index);
	list.erase(position_erase);
	for (std::list<int>::iterator i = list.begin();
		i != list.end();
		i++)cout << *i << tab;cout << endl;
#endif // STL_LIST


}