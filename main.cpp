// main.cpp
/*	Leonardo Pinheiro de Souza - 32127391
	Matheus Farias de Oliveira Matsumoto - 32138271
	Código em Inglês
	Comentários em Portugês-BR

	Referências:
	https://stackoverflow.com/questions/59458264/exception-thrown-read-access-violation-it-was-0xffffffffffffffff
	https://www.w3schools.com/cpp/cpp_strings.asp
*/
#include <iostream>
#include <clocale>
#include "LinkedList.h"
using namespace std;

void Print(LinkedList& list)
{
	int aux = 0;
	Node* current = list.GetHead();
	while (aux != list.Count()) {
		cout << "[" << current->id << "]" << " " << current->name << "\n";
		current = current->next;
		aux++;
	}
}
void PrintReverse(LinkedList& list)
{
	int aux = 0;
	Node* current = list.GetTail();
	while (aux != list.Count()) {
		cout << "[" << current->id << "]" << " " << current->name << "\n";
		current = current->previous;
		aux++;
	}
}
void PrintDoubleListInfo(LinkedList list)
{
	if (list.IsEmpty() == true)
	{
		cout << "Lista vazia!\n";
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
	cout << "Nó removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	PrintDoubleListInfo(list);
	temp = list.RemoveHead();
	cout << "Nó removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	PrintDoubleListInfo(list);
	temp = list.RemoveTail();
	cout << "Nó removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	PrintDoubleListInfo(list);
	cout << "\nFim.\n";
}