#include<iostream>
using namespace std;
class Doubly_LinkList
{
private:
	struct node
	{
		node* prv_add;
		int data;
		node* nxt_add;
	};
	node* head;
	node* tail;
public:
	Doubly_LinkList();
	void insert(int);
	void display();
	void Delete();
	void IsEmpty();
	void reverseList();
	bool IsFull() const;

};
Doubly_LinkList::Doubly_LinkList()
{
	head = NULL;
	tail = NULL;
}
void Doubly_LinkList::insert(int d)
{
	node* newNode = new node;
	newNode->data = d;
	newNode->prv_add = nullptr;
	newNode->nxt_add = nullptr;

	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->prv_add = tail;
		tail->nxt_add = newNode;
		tail = newNode;
	}
	

}
void Doubly_LinkList::Delete()
{
	if (head == NULL)
	{
		cout << "Your Doubly_LinkList is Empty " << endl;
	}
	else
	{
		node* ptr = head;
		while (ptr->nxt_add!=  NULL)
		{
			ptr = ptr->nxt_add;
		}
		ptr->prv_add->nxt_add = NULL;
		delete ptr;
	}
}
void Doubly_LinkList::display()
{
	node* ptr = head;
	while (ptr != NULL)
	{
		cout  << ptr->data;
		if (ptr->nxt_add != NULL)
		{
			cout << "<==>";
		}
		
		ptr = ptr->nxt_add;
	}
	cout << endl;
}
void Doubly_LinkList::IsEmpty()
{
	if (head == NULL)
	{
		cout << "Your Doubly_LinkList is Empty" << endl;
	}
	else
	{
		cout << "Your Doubly_LinkList is Not Empty" << endl;
	}
}
bool  Doubly_LinkList::IsFull() const
{
	node* temp;
	try {
		temp = new node;
		delete temp;
		return true;
	}
	catch (bad_alloc exception)
	{
		return false;
	}
}
void Doubly_LinkList::reverseList()
{
	node* current = head;
	tail = head;
	node* prev = NULL;
	node* next = NULL;
	while (current != nullptr)
	{
		next = current->nxt_add;
		current->nxt_add = prev;
		current->prv_add = next;
		prev = current;
		current = next;
	}
	head = prev;
}
int main()
{
	Doubly_LinkList obj;
	int opt, val=1;
	do
	{

	
	cout << "           Insert()     ---> Press 1" << endl
		<< "           Delete()     ---> Press 2" << endl
		<< "           IsFull()     ---> Press 3-" << endl
		<< "           IsEmpty()    ---> Press 4" << endl
		<< "           Display()    ---> Press 5" << endl
		<< "           reverseList  ---> Press 6" << endl
		<< "           Exit()       ---> Press 0" << endl;
	cin >> opt;
	switch (opt)
	{
	case 1:
	{
	 while (val != 0000)
	{

		cout << "Enter the Element You want to insert/ Enter 0000 To exit: " << endl;
		cin >> val;
		if (val != 0000)
		{


			obj.insert(val);
		}
	}
		
		break;
	}
	case 2:
	{
		obj.Delete();
		break;
	}
	case 3:
	{
		if (obj.IsFull())
		{
			cout << "Your Doubly_LinkList is not Full " << endl;
		}
		else
		{
			cout<<" Your Doubly_LinkList is Full " << endl;
		}
		break;
	}
	case 4:
	{
		obj.IsEmpty();
		break;
	}
	case 5:
	{
		obj.display();
		break;
	}
	case 6:
	{
		obj.reverseList();
		cout << "********Link list Reversed********" << endl;
		break;
	}
	default:
	{
		cout << "Select the Correct Option" << endl;
	}


	}
	} while (opt!=0);
}