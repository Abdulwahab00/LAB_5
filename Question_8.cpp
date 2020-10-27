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
public:
	Doubly_LinkList();
	void insert(int);
	void insertAt(int index, int value);
	void insertAfter(int requeted_value, int new_value);
	void display();
	void Delete();
	void IsEmpty();
	bool IsFull() const;

};
Doubly_LinkList::Doubly_LinkList()
{
	head = NULL;
}
void Doubly_LinkList::insert(int val)
{
	if (head == NULL)
	{
		node* new_node = new node;
		new_node->prv_add = NULL;
		new_node->nxt_add = NULL;
		new_node->data = val;
		head = new_node;
	}
	else
	{
		node* x;
		x = head;
		while (x->nxt_add != NULL)
		{
			x = x->nxt_add;
		}
		node* new_node = new node;
		x->nxt_add = new_node;

		new_node->prv_add = x;
		new_node->data = val;
		new_node->nxt_add = NULL;

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
void Doubly_LinkList:: insertAt(int index, int value)
{
	int i = 1;
	node* ptr = head;
	bool n = false;
	while (ptr->nxt_add!=NULL)
	{
		if (i == index)
		{
			n = true;
			break;
		}
		ptr = ptr->nxt_add;
		i++;
	}
	if (n)
	{
		ptr->data = value;
	}
	if (!n)
	{
		cout << "NO Node on the given index" << endl;
	}
}
void Doubly_LinkList::insertAfter(int requeted_value, int new_value)
{
	int i = 1;
	node* ptr = head;
	bool n = false;
	while (ptr->nxt_add != NULL)
	{
		if (ptr->data== requeted_value)
		{
			n = true;
			break;
		}
		ptr = ptr->nxt_add;
		i++;
	}
	if (n)
	{
		if (ptr->nxt_add == NULL)
		{
			cout << "Can not insert. Because there is no next node" << endl;
		}
		else
		{
			ptr = ptr->nxt_add;
			ptr->data = new_value;
		}
	}
	if (!n)
	{
		cout << "There is no node having such value" << endl;
	}
}
int main()
{
	Doubly_LinkList obj;
	int opt, val=1;
	do
	{

	
	cout << "           Insert()		---> Press 1" << endl
		<< "           InsertAt()		---> Press 2" << endl
		<< "           InsertAfter()		---> Press 3" << endl
		<< "           Delete()		---> Press 4" << endl
		<< "           IsFull()		---> Press 5" << endl
		<< "           IsEmpty()		---> Press 6" << endl
		<< "           Display()		---> Press 7" << endl
		<< "           Exit()			---> Press 0" << endl;
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
		cout << "Enter the Index Value: ";
		int in, ii;
		cin >> in;
		cout << "Enter the Data: ";
		cin >> ii;
		obj.insertAt(in, ii);
		break;
	}
	case 3:
	{
		cout << "Enter the requeted_value : ";
		int in, ii;
		cin >> in;
		cout << "Enter the new_value: ";
		cin >> ii;
		obj.insertAfter(in, ii);
		break;
	}
	case 4:
	{
		obj.Delete();
		break;
	}
	case 5:
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
	case 6:
	{
		obj.IsEmpty();
		break;
	}
	case 7:
	{
		obj.display();
		break;
	}
	default:
	{
		cout << "Select the Correct Option" << endl;
	}


	}
	} while (opt!=0);
}