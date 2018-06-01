#pragma once


template<typename T1>
List<T1>::List()
{
	Size = 0;
	head = NULL;
}
template<typename T1>
List<T1>::~List() {
	clear();
}

template<typename T1>
void List<T1>::push_back(T1 data) {
	if (head == NULL) {
		head = new Node(data); // סעגמנ‏זלמ םמגטי וכולוםע Node
	}
	else {
		Node*current = this->head;
		while (current->pNext != NULL) {
			current = current->pNext;
		}
		current->pNext = new Node(data);
	}
	Size++;
}

template<typename T1>
void List<T1>::clear() {
	while (Size) {
		pop_front();
	}
	//  cout << "List was cleared" << endl;
}

template<typename T1>
void List<T1>::push_front(T1 data) {
	head = new Node(data, head);
	Size++;
}

template<typename T1>
void List<T1>::insert(T1 data, int index) {
	if (index == 0) {
		push_front(data);
	}
	else {
		Node*previous = this->head;

		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}

		previous->pNext = new Node(data, previous->pNext);
		Size++;
	}
}

template<typename T1>
void List<T1>::pop_front() {
	Node*temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T1>
void List<T1>::removeAt(int index) {
	if (index == 0) {
		pop_front();
	}
	else {
		Node*previous = this->head;

		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}

		Node*toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;

	}
}
template<typename T1>
void List<T1>::pop_back() {
	removeAt(Size - 1);
}

template<typename T1>
void List<T1>::show() {
	Node*value = this->head;
	while (value != NULL) {
		//    cout << value->data << " ";
		value = value->pNext;
	}
}


template<typename T1>
T1 List<T1>::showOne(int index) {
	Node*current = this->head;
	int counter = 0;
	while (current != NULL) {

		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}


bool containe(List<char> &lst, char elem) {
	for (int i = 0; i < lst.GetSize(); i++) {
		if (lst.showOne(i) == elem) {
			return true;
		}
	}
	return false;
}
