#include<iostream>
using namespace std;
struct node
{
	int data;
	node* nxt_add;
};
class linklist
{

public:

	node* head;
	node* head1;
	linklist();
	void insert(int);
	void display(node*);
	node* merge_lists(node*, node*);
};
node* linklist::merge_lists(node* A, node* B)
{
	int a;
	int b;
	node* f = A;
	node* f1 = B;
	while (f != NULL || f1 != NULL)
	{
		if (f == NULL)
		{
			while (f1 != NULL)
			{
				if (head == NULL)
				{
					node* new_node = new node;
					new_node->data = f1->data;
					new_node->nxt_add = NULL;
					head = new_node;
				}
				else
				{
					node* ptr = head1;
					while (ptr->nxt_add != NULL)
					{
						ptr = ptr->nxt_add;
					}
					node* new_node = new node;
					new_node->data = f1->data;
					new_node->nxt_add = NULL;
					
					ptr->nxt_add = new_node;

				}

				f1 = f1->nxt_add;

			}
		}
		else if (f1 == NULL)
		{
			while (f != NULL)
			{
				if (head == NULL)
				{
					node* new_node = new node;
					new_node->data = f->data;
					new_node->nxt_add = NULL;
					head = new_node;
				}
				else
				{
					node* ptr = head1;
					while (ptr->nxt_add != NULL)
					{
						ptr = ptr->nxt_add;
					}
					node* new_node = new node;
					new_node->data = f->data;
					
					new_node->nxt_add = NULL;
					ptr->nxt_add = new_node;
				}
				f = f->nxt_add;

			}
		}
		else
		{
			while (f != NULL && f1 != NULL)
			{
				a = f->data;
				b = f1->data;
				if (a < b)
				{
					node* new_node = new node;
					new_node->data = a;
					new_node->nxt_add = NULL;
					if (head1 == NULL)
					{
						head1 = new_node;
						
						f = f->nxt_add;
					}
					else
					{
						node* ptr = head1;
						while (ptr->nxt_add != NULL)
						{
							ptr = ptr->nxt_add;
						}
						ptr->nxt_add = new_node;
						
						f = f->nxt_add;
					}

				}
				else if (b < a)
				{
					node* new_node = new node;
					new_node->data = b;
					new_node->nxt_add = NULL;
					if (head1 == NULL)
					{
						head1 = new_node;
						
						f1 = f1->nxt_add;
					}
					else
					{
						node* ptr = head1;
						while (ptr->nxt_add != NULL)
						{
							ptr = ptr->nxt_add;
						}
						ptr->nxt_add = new_node;
						
						f1 = f1->nxt_add;
					}

				}

			}

		}

	}

	
	return head1;
}
linklist::linklist()
{
	head = NULL;
	head1 = NULL;
}
void linklist::insert(int val)
{
	node* new_node = new node;
	new_node->data = val;
	if (head == NULL)
	{
		head = new_node;

		new_node->nxt_add = NULL;
	}
	else if (head->data > new_node->data)
	{
		new_node->nxt_add = head;
		head = new_node;
	}
	else
	{
		node* ptr = head;
		node* pptr = head->nxt_add;
		int x;
		int z;
		z = val;
		x = head->data;
		while (ptr->nxt_add != NULL)
		{
			x = pptr->data;
			if (z < x)
			{
				break;
			}
			ptr = pptr;
			pptr = pptr->nxt_add;
		}
		if (ptr->nxt_add == NULL)
		{
			
			ptr->nxt_add = new_node;
			new_node->nxt_add = NULL;
		}
		else
		{
			ptr->nxt_add = new_node;
			new_node->nxt_add = pptr;
		}



	}
}
void linklist::display(node* dis)
{
	cout << "************Data in linklist************" << endl;
	while (dis != NULL)
	{
		cout << dis->data;
		if (dis->nxt_add != NULL)
		{
			cout << "->";
		}
		dis = dis->nxt_add;

	}
	cout << endl;
}





int main()
{
	int opt;
	linklist obj;
	linklist obj2;
	int data=1;
	do
	{


		cout << "                  1. Enter data in 1st linklist" << endl
			<< "                  2. Enter data in 2nd linklist" << endl
			<< "                  3. Display data of 1st link list" << endl
			<< "                  4. Display data of 2nd linklist" << endl
			<< "                  5. Merge 2 linklist" << endl
			<< "                  6. Display merged linklist" << endl
			<< "                  0. Exit" << endl;
		cin >> opt;
		switch (opt)
		{
		case 1:
		{
			while (data != 0000)
			{

				cout << "Enter the Element You want to insert/ Enter 0000 To exit: " << endl;
				cin >> data;
				if (data != 0000)
				{


					obj.insert(data);
				}
			}

			break;
		}
		case 2:
		{
			data = 1;
			while (data != 0000)
			{

				cout << "Enter the Element You want to insert/ Enter 0000 To exit: " << endl;
				cin >> data;
				if (data != 0000)
				{


					obj2.insert(data);
				}
			}

			break;
		}
		case 3:
		{
			obj.display(obj.head);
			break;
		}
		case 4:
		{
			obj2.display(obj2.head);
			break; 
		}
		case 5:
		{
			obj.merge_lists(obj.head, obj2.head);
			break;
		}
		case 6:
		{

			obj.display(obj.head1);
			break;
		}
		}

	} while (opt != 0);
}