#pragma once

template<typename boom> class vector
{
private:
	boom * a;
	int siz;
	int capacit;
public:
	vector();
	boom at(int index);
	void insert(int index, boom value);
	int size();
	void reserve(int cap);
	int capacity();
	int indexof(boom val);
	void push_back(boom e);
	boom pop_back();
	boom& operator [](int i);
	void clear();
};

template<typename boom>
vector<boom>::vector()
{
	siz = 0;
	a = new boom[10];
	capacit = 10;
}

template<typename boom>
boom vector<boom>::at(int index)
{
	if (index<0 || index >= this->siz)
	{
		std::cout << "out of bounds";
	}
	else
	{
		return a[index];
	}
}
template<typename boom>
void vector<boom>::reserve(int cap)
{
	if (capacit>cap){ return; }

	boom*b = new boom[cap];
	if (a != NULL)
	{
		for (int i = 0; i<siz; i++)
		{
			b[i] = a[i];
		}
		delete[] a;
	}
	a = b;
	capacit = cap;

}
template<typename boom>
int vector<boom>::capacity(){ return this->capacit; }
template<typename boom>
int vector<boom>::size(){ return this->siz; }
template<typename boom>
void vector<boom>::insert(int index, boom value)
{
	if (siz == capacit)
	{
		reserve(capacit * 2);
	}
	if (index<0 || index>siz){ std::cout << "out of range"; }
	else if (index == siz){ push_back(value); }
	else
	{
		for (int i = siz; i>index; i--)
		{
			a[i] = a[i - 1];
		}
		siz++;
		a[index] = value;
	}
}
template<typename boom>
void vector<boom>::push_back(boom e)
{
	if (siz == capacit)
	{
		reserve(capacit * 2);
	}
	a[siz] = e;
	siz++;

}
template<typename boom>
boom vector<boom>::pop_back()
{
	boom r = a[siz];
	siz--;
	return r;
}
template<typename boom>
boom& vector<boom>::operator[](int i)
{
	return a[i];
}
template<typename boom>
void::vector<boom>::clear()
{
	delete[] a; 
	a = new boom[capacit];
	siz = 0;
}
