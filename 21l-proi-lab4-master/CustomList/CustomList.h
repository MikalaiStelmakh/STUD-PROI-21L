#pragma once
#pragma once
#pragma once
#include <iostream>

const size_t default_size = 10;

template<typename T>
class Node
{
private:
	T value;
	bool isZero;
public:
	Node()
	{
		std::memset(&value, 0, sizeof(value));
		isZero = false;
	}
	Node(T Value, bool IsZero)
	{
		value = Value; isZero = IsZero;
	}
	T get_value();
	bool get_isZero();
	Node<T>& operator=(Node<T>& node);
};

template<typename T>
T Node<T>::get_value() {
	return value;
}

template<typename T>
bool Node<T>::get_isZero() {
	return isZero;
}

template<typename T>
Node<T>& Node<T>::operator=(Node<T>& node) {
	value = node.value;
	isZero = node.isZero;
	return *this;
}

template <typename T, size_t N = default_size>
class List
{
protected:
	Node<T> data[N];
	int max = N;
public:
	List() = default;
	void insert(int index, T const element);
	void remove(int index);
	T const operator[](int index);
	void clear();
	int size();
	T* const getArray();
};


template <typename T, size_t N>
void List<T, N>::insert(int index, T const element)
{
	bool is_zero = element == false;
	data[index] = Node<T>(element, is_zero);
}

template <typename T, size_t N>
void List<T, N>::remove(int index)
{
	data[index] = Node<T>();
}

template <typename T, size_t N>
T const List<T, N>::operator[](int index)
{
	return data[index].get_value();
}

template <typename T, size_t N>
void List<T, N>::clear()
{
	for (int i = 0; i < max; ++i)
		data[i] = Node<T>();
}

template <typename T, size_t N>
int List<T, N>::size()
{
	return max;
}

template<typename T, size_t N>
T* const List<T, N>::getArray()
{
	T static new_array[N];
	std::memset(&new_array, 0, sizeof(new_array));

	for (int i = 0; i < max; ++i)
		new_array[i] = data[i].get_value();

	return new_array;
}

template <typename T, size_t N = default_size>
class SortedList : public List<T, N>
{
private:
	void insert(int index, T element);
	bool is_in_list(T element);
public:
	SortedList() = default;
	void push(T element);
};

template<typename T, size_t N>
bool SortedList<T, N>::is_in_list(T element)
{
	for (int i = 0; i < this->max; ++i)
	{
		if (this->data[i].get_value() == element)
		{
			if (element != false)
				return true;
			if (this->data[i].get_isZero() == true)
				return true;
		}
	}
	return false;
}

template<typename T, size_t N>
void SortedList<T, N>::push(T element)
{
	if (is_in_list(element) == true)
	{
		return;
	}
	for (int i = 0; i < this->max; ++i)
	{
		if (element < this->data[i].get_value() || 
			(this->data[i].get_value() == false && 
			this->data[i].get_isZero() == false)
			)
		{
			if (this->data[i].get_isZero() == false)
			{
				for (int j = this->max - 2; j >= i; --j)
				{
					this->data[j + 1] = this->data[j];
				}
				bool is_zero = element == false;
				Node<T> new_element(element, is_zero);
				this->data[i] = new_element;
				return;
			}
		}
	}

}
