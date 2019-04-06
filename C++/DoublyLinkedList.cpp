#include "DoublyLinkedList.h"
#include <iomanip>
#include <sstream>
using namespace std;

DoublyLinkedList::DoublyLinkedList()
{

}

DoublyLinkedList::DoublyLinkedList(int val)
{

}

DoublyLinkedList::~DoublyLinkedList()
{

}

void DoublyLinkedList::insert_back(int val)
{
	if (tail == nullptr)
		tail = n;
	n->next = head;
	head = n;
	if (n->next != nullptr)
		n->next->prev = head;

}

void DoublyLinkedList::insert_front(int val)
{
    Node* n = new Node(val);
    if (head == nullptr)
        tail = n;
    n->next = head; head = n;
    if (n->next != nullptr)
        n->next->prev = head;
}

void DoublyLinkedList::insert_at(int val, int idx)
{

}

Node& DoublyLinkedList::find(int val)
{
	Node* next = head;
	while (head; next->data == head){
		next = head->next;
		head = next;
	}

}

void DoublyLinkedList::delete_at(int idx)
{
	Node* next = nullptr;
	while (head){
		next = head->next;
		delete head;
		head = next;
	}

}

Node& DoublyLinkedList::get_head()
{
	return *head;
}

Node& DoublyLinkedList::get_tail()
{
    return *tail;
}

Node const& DoublyLinkedList::get_head() const
{
    return *head;
}

Node const& DoublyLinkedList::get_tail() const
{
    return *tail;
}

ostream& operator<<(ostream &os, DoublyLinkedList const& ll) {
    os << "Doubly Linked List" << endl;
    if (&(ll.get_head()) == nullptr)
        return (os << "Empty" << endl);
    os << "Head: " << &(ll.get_head()) << "\t Tail: " << &(ll.get_tail()) << endl;
    Node const* curr = &(ll.get_head());
    os << "Nodes (accessible from head to tail):" << endl << endl;
    os << setw(16) << setfill(' ') << ' ' << ' ' << center("prev", 15) << ' ' << center("data", 15) << ' ' << center("next", 15) << endl;
    while (curr != nullptr) {
        ostringstream oss; oss << (curr->prev); string prev = oss.str(); oss.str(""); oss << (curr->next); string next = oss.str(); oss.str(""); oss << (curr->data); string data = oss.str(); oss.str(""); oss << curr; string address = oss.str();
        os << setw(16) << setfill(' ') << ' ' << '.' << setw(16) << setfill('-') << '.' << setw(16) << '.' << setw(16) << '.' << endl;
        os << setw(16) << setfill(' ') << center(address,15) << '|' << setw(15) << setfill(' ') << center(prev, 15) << '|' << setw(15) << center(data, 15) << '|' << setw(15) << center(next, 15) << '|'<< endl;
        os << setw(16) << setfill(' ') << ' ' << '\'' << setw(16) << setfill('-') << '\'' << setw(16) << '\'' << setw(16) << '\'' << endl;
        os << endl;
        curr = curr->next;
    }
    return os;
}

string center (const string &str, const int col_width)
{
    // quick and easy (but error-prone) implementation
    int padl = (col_width - str.length()) / 2;
    int padr = (col_width - str.length()) - padl;
    string strf = string(padl, ' ') + str + string(padr, ' ');
    return strf;
}