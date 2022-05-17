/*	Leonardo Pinheiro de Souza - 32127391
	Matheus Farias de Oliveira Matsumoto - 32138271
	Código em Inglês
	Comentários em Portugês-BR
*/

#include "LinkedList.h"
#include<iostream>
using namespace std;

// Funções do Node
Node::Node()
	:id(0), name(" "), next(nullptr), previous(nullptr) {}

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
	node->previous = tail;

	if (IsEmpty() == true)
	{
		tail = node;
		head = node;
	}
	
	head->previous = node;
	head = node;
	tail->next = node;
	count++;
}

void LinkedList::Append(int elem, std::string word) {

	Node* node = new Node();
	node->id = elem;
	node->name = word;
	node->next = head;
	node->previous = tail;

	if (IsEmpty() == true)
	{
		head = node;
		tail = node;
	}
	else
	{
		tail->next = node;
		head->previous = node;
	}
	
	tail = node;
	count++;
}

Node* LinkedList::RemoveHead() {

	Node* toRemove = head;

	if (head == tail)
		head, tail = nullptr;
	else
	{
		head = head->next;
		head->previous = tail;
		tail->next = head;
	}
		
	count--;
	toRemove->next = nullptr;
	toRemove->previous = nullptr;
	return toRemove;
}

Node* LinkedList::RemoveTail() {

	if (head == tail)
		return RemoveHead();

	Node* toRemove = tail;
	tail = tail->previous;
	tail->next = head;
	head->previous = tail;

	count--;
	toRemove->next = nullptr;
	toRemove->previous = nullptr;
	return toRemove;
}

Node* LinkedList::RemoveNode(int elem) {

	Node* toRemove = head;

	while (toRemove->next != head && toRemove->id != elem) {
		toRemove = toRemove->next;
	}

	if (toRemove == nullptr)
		return nullptr;
	else if (toRemove == head)
		return RemoveHead();
	else if (toRemove == tail)
		return RemoveTail();
	else {
		toRemove->previous->next = toRemove->next;
		toRemove->next->previous = toRemove->previous;
		count--;
		toRemove->next = nullptr;
		toRemove->previous = nullptr;
		return toRemove;
	}
}

Node* LinkedList::GetNode(int elem) {

	Node* node = head;

	while (node->next != head) {
		if (node->id == elem)
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

bool LinkedList::IsEmpty() {
	if (head == nullptr || count == 0)
		return true;
	else
		return false;
}

void LinkedList::Clear() {
	Node* next = nullptr;

	while (count != 0) {
		next = head->next;
		head->previous = nullptr;
		head->next = nullptr;
		delete head; // Parte importante para liberar espaço na memória
		head = next;
		count--;
	}

	head, tail = nullptr;
	count = 0;
}