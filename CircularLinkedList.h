/*	Leonardo Pinheiro de Souza - 32127391
	Matheus Farias de Oliveira Matsumoto - 32138271
	Código em Inglês
	Comentários em Portugês-BR
*/

#ifndef __H_CIRCULAR_LINKED_LIST__
#define __H_CIRCULAR_LINKED_LIST__
#include <string>

class Node {
public:
	Node();
	~Node();

	int id;
	std::string name;
	Node* next;
	Node* prev;
};

class LinkedList {
public:
	LinkedList();
	~LinkedList();

	void Insert(int elem, std::string word);
	void Append(int elem, std::string word);

	Node* RemoveHead();
	Node* RemoveTail();
	Node* RemoveNode(int elem);

	Node* GetHead();
	Node* GetTail();
	Node* GetNode(int elem, std::string word);

	int Count();
	void Clear();
	bool isEmpty();

private:
	int count;
	Node* head = nullptr;
	Node* tail = nullptr;
};

#endif 