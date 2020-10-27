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
	void Delete();
	void product_of_Prime_node();
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
void Doubly_LinkList::Delete()
{
	if (head == NULL)
	{
		cout << "Your Doubly_LinkList is Empty " << endl;
	}
	else
	{
		node* ptr = head;
		while (ptr->nxt_add != NULL)
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
		cout << ptr->data;
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
bool isPrime(int n)
{
	
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;

	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}
void Doubly_LinkList::product_of_Prime_node()
{
	node* ptr = head;
	int product = 1;
	int i = 1;
	
	while (ptr!=NULL)
	{

	
	
		if (isPrime(i))
		{
			
			
			product = product * ptr->data;
			
		}
		ptr = ptr->nxt_add;
		i++;
	
	}
	cout << "Product of Prime Number Nodes is----------> "  << product << endl;
}
int main()
{
	Doubly_LinkList obj;
	int opt, val = 1;
	do
	{


		cout << "           Insert()				  ---> Press 1" << endl
			<< "           Delete()				 ---> Press 2" << endl
			<< "           IsFull()				 ---> Press 3" << endl
			<< "           IsEmpty()				 ---> Press 4" << endl
			<<"           product_of_Prime_node()			 ---> Press 5"<<endl
			<< "           Display()		 	 	---> Press 6" << endl
			<< "           Exit()			   		---> Press 0" << endl;
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
				cout << " Your Doubly_LinkList is Full " << endl;
			}
			break;
		}
		case 4:
		{
			obj.IsEmpty();
			break;
		}
		case 5 :
		{
			obj.product_of_Prime_node();
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
	} while (opt != 0);
}