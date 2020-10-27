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
	int count;
public:
	Doubly_LinkList();
	void insert(int);
	void display();
	void DeleteAt(int index);
	void DeleteAfter(int requeted_value);
	void IsEmpty();
	bool IsFull() const;

};
Doubly_LinkList::Doubly_LinkList()
{
	head = NULL;
	count = 0;
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
		count++;
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
		count++;

	}

}
void Doubly_LinkList::DeleteAt(int index)
{
	node* ptr;
	ptr = head;
	for (int i = 1; i <= index + 1; i++)
	{
		if (i == index)
		{
			if (head == ptr)
			{
				head = head->nxt_add;
				head->prv_add = NULL;
				delete ptr;
				return;
			}
			else if (ptr->nxt_add == NULL)
			{
				ptr->prv_add->nxt_add = NULL;
				delete ptr;
				return;
			}
			else
			{
				ptr->prv_add->nxt_add = ptr->nxt_add;
				ptr->nxt_add->prv_add = ptr->prv_add;
				delete ptr;
				return;
			}
		}
		ptr = ptr->nxt_add;
	}
	cout << "Node does Not Exit" << endl;
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
void Doubly_LinkList::DeleteAfter(int requeted_value)
{
	node* ptr = head;
	bool n=false;
	while (ptr->nxt_add!=NULL)
	{
		if (ptr->data == requeted_value)
		{
			n =true;
			break;
		}
		ptr = ptr->nxt_add;
	}
	if (n)
	{
		if (ptr->nxt_add == NULL)
		{
			cout << "There is no next node" << endl;
			cout << "So there is nothing to Delete" << endl;
		}
		else
		{
			ptr = ptr->nxt_add;
			ptr->prv_add->nxt_add = ptr->nxt_add;
			ptr->nxt_add->prv_add = ptr->prv_add;
			delete ptr;
			return;
		}
	}
	if (!n)
	{
		cout << "There is no Node having Such Data" << endl;
	}
}
int main()
{
	Doubly_LinkList obj;
	int opt, val=1;
	do
	{

	
	cout << "           Insert()		 ---> Press 1" << endl
		<< "           DeleteAt()		 ---> Press 2" << endl
		<< "           DeleteAfter()		 ---> Press 3" << endl
		<< "           IsFull()		 ---> Press 4" << endl
		<< "           IsEmpty()		 ---> Press 5" << endl
		<< "           Display()		 ---> Press 6" << endl
		<< "           Exit()			 ---> Press 0" << endl;
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
		cout<<"Enter the index you want to Delete"<<endl;
		int n;
		cin >> n;
		obj.DeleteAt(n);
		break;
	}
	case 3:
	{
		{
			cout << "Enter the value you want to Delete" << endl;
			int n;
			cin >> n;
			obj.DeleteAfter(n);
			break;
		}
	}
	case 4:
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
	case 5:
	{
		obj.IsEmpty();
		break;
	}
	case 6:
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