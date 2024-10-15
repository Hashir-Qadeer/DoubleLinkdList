#include<iostream>
using namespace std;
template<typename X>
struct DNode
{
	X info;
	DNode<X>* next;
	DNode<X>* prev;
	DNode() :next(nullptr), prev(nullptr)
	{}
	DNode(X val) :info(val), next(nullptr), prev(nullptr)
	{}
};
template<typename T>
class CDLL
{
	DNode<T>* head;
public:
	CDLL() :head(nullptr)
	{}
	~CDLL()
	{
		while (head)
			removeAtHead();
	}

	void insertAtTail(T val)
	{
		DNode<T>* p = new DNode<T>(val);
		if (head == nullptr)
		{
			head = p;
			head->next = head->prev = head;
			return;
		}
		p->next = head;
		p->prev = head->prev;
		head->prev->next = p;
		head->prev = p;
	}
	void insertAfter(T key, T val)
	{
		if (head == nullptr)
			return;
		DNode<T>* p = head;
		do
		{
			if (p->info == key)
			{
				DNode<T>* x = new DNode<T>(val);
				x->next = p->next;
				x->prev = p;
				p->next = x;
				x->next->prev = x;
				return;
			}
			p = p->next;
		} while (p != head);
	}
	void insertBefore(T key, T val)
	{
		if (head == nullptr)
			return;
		if (head->info == key)
		{
			insertAtHead(val);
			return;
		}
		DNode<T>* p = head->next;
		while (p != head && p->info != key)
		{
			p = p->next;
		}
		if (p != head)
		{
			DNode<T>* x = new DNode<T>(val);
			x->next = p;
			x->prev = p->prev;
			p->prev = x;
			x->prev->next = x;
		}
	}

	void removeAtHead()
	{
		if (head == nullptr)
			return;
		if (head->prev == head && head->next == head)
		{
			delete head;
			head = nullptr;
			return;
		}
		DNode<T>* p = head;
		head->next->prev = head->prev;
		head->prev->next = head->next;
		head = head->next;
		delete p;
	}
	void removeAtTail()
	{
		if (head == nullptr)
			return;
		if (head->prev == head && head->next == head)
		{
			delete head;
			head = nullptr;
			return;
		}
		DNode<T>* p = head->prev;
		p->prev->next = head;
		head->prev = p->prev;
		delete p;
	}
	void removeAfter(T key)
	{
		if (head == nullptr)
			return;
		DNode<T>* p = head;
		do
		{
			if (p->info == key)
			{
				if (head == head->prev)//only one node
				{
					delete head;
					head = nullptr;
					return;
				}
				DNode<T>* x = p->next;
				p->next = x->next;
				x->next->prev = p;
				if (x == head)//head node deleteion
					head = p->next;
				delete x;
				return;
			}
			p = p->next;
		} while (p != head);
	}
	void removeBefore(T key)
	{
		if (head == nullptr)
			return;
		if (head->info == key && head->prev == head && head->next == head)//if there is only one node
			return;
		DNode<T>* p = head;
		do
		{
			if (p->info == key)
			{
				DNode<T>* x = p->prev;
				p->prev = x->prev;
				if (head->next == p)// if key is  2nd node
					head = p;
				p->prev->next = p;
				delete x;
				return;
			}
			p = p->next;
		} while (p != head);
	}
	
};
int main()
{
	
	return 0;
}