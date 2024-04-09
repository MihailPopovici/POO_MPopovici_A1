#include <iostream>

using namespace std;

template<typename T>
bool compare_for_sort(T value1, T value2) {
	if (value1 > value2) return true;
	return false;
}

template <typename T>
bool compare_eq(T value1, T value2) {
	if (value1 == value2) return true;
	return false;
}

template<class T>
class Node {
private:
	T value;
	Node<T>** sons;
	int size, capacity;
public:
	Node() : value(), sons(new Node<T>*[10]), size(0), capacity(0) {}
	void add_son(Node<T>* node) {
		if (this->size == this->capacity) resize(2 * this->capacity);
		this->sons[this->size] = node;
		this->size++;
	}
	void add_son_at(Node<T>* node, int index) {
		if (this->size == this->capacity) resize(2 * this->capacity);
		for (int i = this->size; i > index; i--)
			this->sons[i] = this->sons[i - 1];
		this->sons[index] = node;
		this->nrOfSons++;
	}
	Node<T>* get_son(int index) {
		return this->sons[index];
	}
	int count_all_sons() {
		int count = this->size;
		for (int i = 0; i < node->size; ++i) {
			count += node->sons[i]->count();
		}
		return count;
	}

private:
	void resize(int newCapacity) {
		Node<T>** buff = new Node<T>*[newCapacity];
		memcpy(buff, this->sons, this->size * sizeof(Node<T>*));
		delete[] this->sons;
		this->sons = buff;
		this->capacity = newCapacity;
	}
};

template<class T>
class Tree {
private:
	Node<T>* root;
public:
	Node<T>* add_node(Node<T>* parent, T value) {
		Node<T>* temp = new Node<T>;
		temp->value = value;
		if (parent == nullptr) {
			root=temp;
		}
		else {
			parent->add_son(temp);
		}
		return temp;
	}
	Node<T>* get_node(Node<T>* parent, int index) {
		return parent->get_son(index);
	}
	void insert(Node<T>* parent, T value, int index) {
		Node<T>* temp = new Node<T>;
		temp->value = value;
		parent->add_son_at(temp, index);
	}
	int count(Node<T>* parent) {
		if (parent == nullptr) return root->count_all_sons();
		return parent->count_all_sons();

	}
};

int main() {

}