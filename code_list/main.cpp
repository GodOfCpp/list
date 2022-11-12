#include <iostream>

template<typename T>
struct elem {
	elem<T>* next;
	T value;

	elem() { next = NULL; }
	elem(elem<T>* n, T v) { next = n; value = v; }

};

template<typename T>
class list {
private:
	elem<T>* first; // ��������� �� ������ ������ (�� �������� �������� value)
	elem<T>* current_position; // ��������� �� ��������� ������� ������(�� �������, ������� � ���� ������� ��������� �� end)
	elem<T>* end; // ��������� ����� ������ (� ��������� next ����� �������� NULL, �� ����� �������� value)

public:

	list() { first = new elem<T>; end = new elem<T>; current_position = first; first->next = end; } // ����������� �� ���������

	~list() { this->clear(); delete first; delete end; } // ���������� ��� �������������� ������ ������

	void push_back(T); // ��������� ���������� ������� � ����� ������
	void push_front(T); // ��������� ���������� ������� � ������ ������
	void insert(int, T); // ��������� ���������� ������� �� index-��� ����� (��������� � 0)

	void pop_back(); // ������� ��������� ������� ������
	void pop_front(); // ������� ������ ������� ������
	void erase(int); // ������� index-��� ������� ������ (��������� � 0)

	void clear(); // ������� ��� ��������� �������� ������

	elem<T>* find(T) const; // ���� ���������� ������� � ������. ���� �������, ���������� ��������� �� ����, ���� ���, ���������� ��������� �� end

	bool isContain(T) const; // ���������, ���������� �� ������ ������� � ������
	bool isEmpty() const { if (first->next == end) return true; return false; } // ��������� ������ �� �������

	void print() const; // ������� � ����� std::cout ��� �������� ������
	
};

//����������
template<typename T>
void list<T>::push_back(T value) {
	elem<T>* el = new elem<T>(NULL, value);
	current_position->next = el;
	current_position = el;
	//current_position->value = el->value;
	current_position->next = end;
}

template<typename T>
void list<T>::push_front(T value) {
	elem<T>* el = new elem<T>(NULL, value);
	if (this->isEmpty()) {
		el->next = end;
		first->next = el;
		current_position = el;
	}
	else {
		el->next = first->next;
		first->next = el;
	}
}

template<typename T>
void list<T>::insert(int index, T value) {
	int counter = 0;
	auto i = first->next;
	auto prev = first;
	while (counter != index) {
		if (i->next == NULL) return;
		prev = i;
		i = i->next;
		counter++;
	}
	elem<T>* el = new elem<T>(NULL, value);
	if (i == end) {
		current_position->next = el;
		current_position = el;
		current_position->next = end;
	}
	else {
		el->next = i;
		prev->next = el;
	}
}

template<typename T>
void list<T>::pop_back() {
	if (this->isEmpty()) return;
	auto prev = first;
	auto i = first->next;
	for (; i->next != end; i = i->next) {
		prev = i;
	}

	elem<T>* temp = i;
	prev->next = end;
	current_position = prev;
	delete temp;
}

template<typename T>
void list<T>::pop_front() {
	if (this->isEmpty()) return;
	elem<T>* temp = first->next;
	first->next = first->next->next;
	delete temp;
	if (this->isEmpty()) { current_position = first; std::cout << "\n123\n"; }
}

template<typename T>
void list<T>::erase(int index) {
	if (this->isEmpty()) return;
	int counter = 0;
	auto prev = first;
	auto i = first->next;
	for (; i->next != end && index != counter; i = i->next) {
		prev = i;
		counter++;
	}

	if (prev == first) { this->pop_front(); return; }
	else if (i->next == end) { this->pop_back(); return; }

	prev->next = i->next;
	delete i;
}

template<typename T>
void list<T>::clear() {
	for (auto i = first->next; i->next != NULL;) {
		elem<T>* temp = i;
		i = i->next;
		delete temp;
	}
	first->next = end;
}

template<typename T>
elem<T>* list<T>::find(T key) const {
	for (auto i = first->next; i->next != NULL; i = i->next) 
		if (i->value == key) return i;

	return end;
}

template<typename T>
bool list<T>::isContain(T key) const {
	for (auto i = first->next; i->next != NULL; i = i->next)
		if (i->value == key) return true;

	return false;
}

template<typename T>
void list<T>::print() const {
	for (auto i = first->next; i->next != NULL; i = i->next)
		std::cout << i->value << ' ';
}

int main() {
	



	return 0;
}