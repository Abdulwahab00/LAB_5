#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* Prv_add;
	Node* Nxt_add;
};
class DoublyList
{
private:
	Node* head;
	Node* tail;
	int counter;
public:
	DoublyList();
	~DoublyList();
	void displayList();
	void addNode(int);
	void deleteNode(int);
	void removeDuplicateNode();
	void IsEmpty();
	bool IsFull() const;
	
private:

};

DoublyList::DoublyList()
{
	head = nullptr;
	tail = nullptr;

}

DoublyList::~DoublyList()
{
}


void DoublyList::displayList(void)
{
	cout << "Data in List is: ";
	Node* temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->Nxt_add;
	}
	cout << endl;
}
void DoublyList::addNode(int d)
{
	Node* newNode = new Node;
	newNode->data = d;
	newNode->Prv_add = nullptr;
	newNode->Nxt_add = nullptr;

	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->Prv_add = tail;
		tail->Nxt_add = newNode;
		tail = newNode;
	}
	counter++;

}

void DoublyList::deleteNode(int d)
{
	Node* temp = head;
	Node* newNode = new Node;
	newNode->Nxt_add = nullptr;
	newNode->Prv_add = nullptr;
	newNode->data = d;
	if (head == nullptr)
	{
		cout << "List is Empty, Nothing to Delete\n";
		return;
	}
	else
	{
		while (temp->Nxt_add != nullptr)
		{
			if (temp->data == d)
			{

				temp->Prv_add->Nxt_add = temp->Nxt_add;
				temp->Nxt_add->Prv_add = temp->Prv_add->Nxt_add;
				free(temp);
				return;

			}
			temp = temp->Nxt_add;
		}
		if (temp->data == d)
		{
			temp->Prv_add->Nxt_add = nullptr;
			tail = temp;
			free(temp);
		}

	}

}
void DoublyList::removeDuplicateNode()
{
	
	Node* ptr, * i, * ptr2;

	
	if (head == NULL) {
		return;
	}
	else {
		
		for (ptr = head; ptr != NULL; ptr = ptr->Nxt_add) {
			
			for (i = ptr->Nxt_add; i != NULL; i = i->Nxt_add) {
				if (ptr->data == i->data) {
					
					ptr2 = i;
					
					i->Prv_add->Nxt_add = i->Nxt_add;
					if (i->Nxt_add != NULL)
						i->Nxt_add->Prv_add = i->Prv_add;
					
					ptr2 = NULL;
				}
			}
		}
	}
}
void DoublyList::IsEmpty()
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
bool  DoublyList::IsFull() const
{
	Node* temp;
	try {
		temp = new Node;
		delete temp;
		return true;
	}
	catch (bad_alloc exception)
	{
		return false;
	}
}
int main()
{
	DoublyList obj;
	
	int opt;
	do
	{
		int val = 1;
	
	cout <<"           Insert()               ---> Press 1" << endl
		<< "           Delete()               ---> Press 2" << endl
		<< "           IsFull()               ---> Press 3" << endl
		<< "           IsEmpty()              ---> Press 4" << endl
		<< "           RemoveDuplicateNode()  ---> Press 5"<<endl
		<< "           Display()              ---> Press 6" << endl
		<< "           Exit()                 ---> Press 0" << endl;
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


			obj.addNode(val);
		}
	}
		
		break;
	}
	case 2:
	{
		cout << "Enter the data: " << endl;
		cin >> val;
		obj.deleteNode(val);
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
		obj.removeDuplicateNode();
		cout << "************Dublicate Data is Deleted************" << endl;
		break;
	}
	case 6:
	{
		obj.displayList();
		break;
	}
	default:
	{
		cout << "Select the Correct Option" << endl;
	}


	}
	} while (opt!=0);
}