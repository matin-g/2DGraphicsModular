#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include <stdexcept>
template<typename T>
class vector
{
public:
    vector() :size_v{ 0 }, elem{ nullptr }, space{ 0 }
	{}// end of vector

    explicit vector(int s) : size_v{ 0 }, space{ s }
	{
		elem = new T[s];
	}// end of vector(int)


	vector(const vector& rhs) : space{ rhs.space }, size_v{ rhs.size_v }
	{
		elem = new T[rhs.space];
		for (int i = 0; i < rhs.size_v; i++)
		{
			*(elem + i) = *(rhs.elem + i);
		}
	}//end of vector(const vector&)

	vector& operator=(const vector& rhs) // copy assignment
	{
		if (this != &rhs)
		{
			if (size_v <= rhs.size_v) //if vector is less that rhs
			{
				delete[] elem;
				elem = new T[rhs.size_v];
				size_v = rhs.size_v;
				space = rhs.space;
			}
			else
			{
				size_v = rhs.size_v;
			}
			for (int i = 0; i < size_v; i++)
				*(elem + i) = *(rhs.elem + i);
		}

	}
	vector(vector&& rhs) // move constructor
		:size_v{ rhs.size_v }, space{ rhs.space }
	{
		elem = rhs.elem;
		rhs.elem = nullptr;
		rhs.size = 0;
		rhs.space = 0;
	}
	vector& operator=(vector&& rhs) // move assignment
	{
		if (this != &rhs)
		{
			delete[] elem;
			elem = rhs.elem;
			rhs.elem = nullptr;
			rhs.size = 0;
			rhs.space = 0;
		}
		return *this;
	}
	~vector() // destructor
	{
		delete[] elem;
		elem = nullptr;
	}
	const T& operator[] (int index) // access: return reference
	{
		if (index >= size_v)
		{
			throw std::out_of_range("This is out of range of the vector. Invalid access.");
		}
		return elem[index];
	}
	int size() const // the current size
	{
		return size_v;
	}
	int capacity() const // current available space
	{
		return space;
	}
	void resize(int newsize) // grow
	{

		T* temp = new T[newsize];
		int i = 0;


		for (i; i < newsize; i++)
		{
			if (i < size_v)
				temp[i] = elem[i];
		}
		if (size_v > newsize)
			size_v = newsize;
		// this is not like the real STL vector where we can accept another
		//default argument to initialize data if our old vector is smaller that the resize.
	}
	void push_back(T val) // add element
	{
		if (size_v < space)
		{
			elem[++size_v] = val;
		}
		else
		{
            if(space != 0)// check for empty vector
            {
                reserve(2 * space);
                elem[++size_v] = val;
            }
            else
            {
                reserve(1);
                elem[++size_v] = val;
            }
		}
	}
	void reserve(int newalloc) // get more space
	{
		if (newalloc > space)
		{
			T* temp = new T[newalloc];
			for (int i = 0; i < size_v; i++)
			{
				temp[i] = elem[i];
			}
			delete[] elem;
			elem = temp;
			temp = nullptr;
			space = newalloc;
		}
	}
	using iterator = T * ;
	using const_iterator = const T*;
	iterator begin() // points to first element
	{
		return elem;
	}
	const_iterator begin() const
	{
		return elem;
	}
	iterator end() // points to one beyond the last element
	{
		return (elem + space);
	}
	const_iterator end() const
	{
		return elem + space;
	}
	iterator insert(iterator p, const T& v)// insert a new element v before p
	{
		T* temp = nullptr;
		if (size_v >= space)
		{
			temp = new T[size_v * 2];
			space = size_v * 2;
		}
		else
		{
			temp = new T[space];
		}
		int i = 0;
		iterator j;
		for (j = begin(); j != p; j++)
		{
			temp[i] = *j;
			i++;
		}
		iterator returnIt = temp + i;
		temp[i] = v;
		i++;

		for (j; j != end(); j++)
		{
			while (i < space)
			{
				temp[i] = *j;
				i++;
			}
		}

		size_v++;
		delete[] elem;
		elem = temp;
		temp = nullptr;

		return returnIt;
	}
	iterator erase(iterator p) // remove element pointed to by p
	{
		T* temp = new T[space];
		int i = 0;
		iterator j;
		for (j= begin(); j < p; j++)
		{
			temp[i] = *j;
		}
		
		iterator returnIt = temp + i;
		i++;

		for (i; i < size_v; ++i)
		{
			temp[i] = *j;
			j++;
		}
		
		size_v--;

		delete[] elem;
		elem = temp;
		temp = nullptr;

		return returnIt;
	}
private:
	int size_v;
	T* elem;
	int space;
};

#endif // VECTOR_H
