/*	Leonardo Pinheiro de Souza - 32127391
	Matheus Farias de Oliveira Matsumoto - 32138271
	Código em Inglês
	Comentários em Portugês-BR
*/

#include <iostream>
#include <clocale>
#include "CircularLinkedList.h"
using namespace std;

void Print(LinkedList& list)
{
	Node* current = list.GetHead();
	while (current->next != list.GetHead()) {
		cout << "[" << current->id << "]" << current->name << "\n";
		current = current->next;
	}
	cout << "[" << current->id << "]" << current->name << "\n";
	current = current->next;
	cout << "\n";
}
void PrintReverse(LinkedList& list)
{
	Node* current = list.GetTail();
	while (current->prev != list.GetTail()) {
		cout << "[" << current->id << "]" << current->name << "\n";
		current = current->prev;
	}
	cout << "[" << current->id << "]" << current->name << "\n";
	current = current->prev;
	cout << "\n";
}
void PrintDoubleListInfo(LinkedList& list)
{
	if (list.isEmpty() == true)
	{
		cout << "\nLista vazia!\n";
	}
	else
	{
		cout << "\nLista:\n";
		Print(list);
		cout << "\nLista invertida:\n";
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
	cout << "\nNó removido -> id: " << temp->id << ", name: " << temp->name << '\n';

	// TODO: Liberar memória alocada para o nó que foi removido.
	PrintDoubleListInfo(list);
	temp = list.RemoveHead();
	cout << "\nNó removido -> id: " << temp->id << ", name: " << temp->name << '\n';

	// TODO: Liberar memória alocada para o nó que foi removido.
	PrintDoubleListInfo(list);
	temp = list.RemoveTail();
	cout << "\nNó removido -> id: " << temp->id << ", name: " << temp->name << '\n';

	// TODO: Liberar memória alocada para o nó que foi removido.
	PrintDoubleListInfo(list);

	// TODO: Liberar memória alocada para a lista.
	cout << "Fim.\n";
}


