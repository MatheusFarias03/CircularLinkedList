// main.cpp
/*	Leonardo Pinheiro de Souza - 32127391
	Matheus Farias de Oliveira Matsumoto - 32138271
	C�digo em Ingl�s
	Coment�rios em Portug�s-BR
*/
#include <iostream>
#include <clocale>
#include "LinkedList.h"
using namespace std;

void Print(LinkedList& list)
{
	Node* current = list.GetHead();
	while (current->next != list.GetHead()) {
		cout << "[" << current->id << "]" << " " << current->name;
		current = current->next;
	}
}
void PrintReverse(LinkedList& list)
{
	Node* current = list.GetTail();
	while (current->next != list.GetTail()) {
		cout << "[" << current->id << "]" << " " << current->name;
		current = current->previous;
	}
}
void PrintDoubleListInfo(LinkedList list)
{
	if (list.IsEmpty())
	{
		cout << "Lista vazia!\n";
	}
	else
	{
		cout << "Lista:\n";
		Print(list);
		cout << "Lista invertida:\n";
		PrintReverse(list);
	}
}
int main()
{
	LinkedList list;

	setlocale(LC_CTYPE, "Portuguese");
	cout << "*** Lista Circular Duplamente Ligada/Encadeada (Doubly Circular Linked List) ***\n";
	PrintDoubleListInfo(list);
	list.Insert(1, "Carol");
	list.Insert(2, "Eric");
	list.Insert(3, "John");
	list.Append(4, "Leo");
	list.Append(5, "Julia");
	list.Append(6, "Lisa");
	PrintDoubleListInfo(list);
	list.Clear();
	PrintDoubleListInfo(list);
	list.Insert(11, "Paulo");
	list.Append(22, "Thomas");
	list.Insert(33, "Olga");
	list.Append(44, "Bia");
	list.Insert(55, "Angela");
	list.Append(66, "Karen");
	list.Insert(77, "Adauto");
	PrintDoubleListInfo(list);
	Node* temp = list.RemoveNode(44);
	cout << "N� removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	// TODO: Liberar mem�ria alocada para o n� que foi removido.
	PrintDoubleListInfo(list);
	temp = list.RemoveHead();
	cout << "N� removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	// TODO: Liberar mem�ria alocada para o n� que foi removido.
	PrintDoubleListInfo(list);
	temp = list.RemoveTail();
	cout << "N� removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	// TODO: Liberar mem�ria alocada para o n� que foi removido.
	PrintDoubleListInfo(list);
	// TODO: Liberar mem�ria alocada para a lista.
	cout << "Fim.\n";
}