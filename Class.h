#pragma once

template<typename T1>
class List {
public:
	List();
	~List();

	void push_back(T1 data);

	int GetSize() { return Size; }

	void clear();

	void push_front(T1 data);

	void insert(T1 value, int index);

	void pop_front();

	void removeAt(int index);

	void pop_back();

	void show();

	T1 showOne(int index);

private:


//	template< typename T>
	class Node {
	private:


	public:
		Node * pNext;
		T1 data;
		Node(T1 data = T1(), Node *pNext = NULL)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node *head;
};