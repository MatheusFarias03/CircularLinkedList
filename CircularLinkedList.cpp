/*	Leonardo Pinheiro de Souza - 32127391
	Matheus Farias de Oliveira Matsumoto - 32138271
	Código em Inglês
	Comentários em Portugês-BR
*/

#include "CircularLinkedList.h"
#include<iostream>

// Funções do Node
Node::Node()
	:id(0), name("\0"), next(nullptr), prev(nullptr) {}

Node::~Node() {}



// Funções da LinkedList
LinkedList::LinkedList()
	: count(0), head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {}

void LinkedList::Insert(int elem, std::string word) {

	Node* node = new Node();
	node->id = elem;
	node->name = word;
	node->next = head;
	node->prev = tail;

	if (isEmpty() == true) {
		tail = node;
		head = node;
	}
		
	head->prev = node;
	tail->next = node;
	head = node;
	count++;
}

void LinkedList::Append(int elem, std::string word) {

	Node* node = new Node();
	node->id = elem;
	node->name = word;
	node->next = head;
	node->prev = tail;

	if (isEmpty() == true) {
		head = node;
		tail = node;
	}
	else {
		tail->next = node;
		head->prev = node;
	}
	tail = node;
	count++;
}

Node* LinkedList::RemoveHead() {

	if (isEmpty() == true)
		return nullptr;

	Node* toRemove = head;

	if (head == tail) {
		head->next = nullptr;
		head->prev = nullptr;
		head, tail = nullptr;
	}
	else {
		head = head->next;
		head->prev = tail;
		tail->next = head;
	}
		
	count--;
	toRemove->next = nullptr;
	toRemove->prev = nullptr;
	return toRemove;
}

Node* LinkedList::RemoveTail() {

	if (head == tail)
		return RemoveHead();

	Node* toRemove = tail;

	tail = tail->prev;
	tail->next = head;
	toRemove->next->prev = tail;
	count--;

	toRemove->next = nullptr;
	toRemove->prev = nullptr;
	return toRemove;
}

Node* LinkedList::RemoveNode(int elem, std::string word) {

	Node* toRemove = head;

	while (toRemove->next != head && toRemove->id != elem && toRemove->name != word) {
		toRemove = toRemove->next;
	}

	if (toRemove == nullptr)
		return nullptr;
	else if (toRemove == head)
		return RemoveHead();
	else if (toRemove == tail)
		return RemoveTail();
	else {
		toRemove->prev->next = toRemove->next;
		toRemove->next->prev = toRemove->prev;
		toRemove->next = nullptr;
		toRemove->prev = nullptr;
		return toRemove;
	}
}

Node* LinkedList::GetNode(int elem, std::string word) {

	Node* node = head;

	while (node->next != head) {
		if (node->id == elem && node->name == word)
			return node;
		node = node->next;
	}
	return nullptr;
}

Node* LinkedList::GetHead() {
	return head;
}

Node* LinkedList::GetTail() {
	return tail;
}

int LinkedList::Count() {
	return count;
}

bool LinkedList::isEmpty() {
	if (head == nullptr)
		return true;
	else
		false;
}

void LinkedList::Clear() {
	Node* next = nullptr;

	while (head != nullptr) {
		next = head->next;
		delete head; // Parte importante para liberar espaço na memória
		head = next;
	}

	head, tail = nullptr;
	count = 0;
}