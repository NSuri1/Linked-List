#include <iostream>
#include <fstream>
using namespace std;

class Student
{

	private:

	string fname;
	string lname;
	string id;
	

	public:

	Student()
	{
		fname= " ";
		lname= " ";
		id= " ";
	}
	
	~Student()
	{
		
	}
	
	void addData(string f, string l, string i)
	{
		fname=f;
		lname=l;
		id= i;
	}

	void display()
	{
		cout<< "First name: "<< fname<< endl;
		cout<< "Last name: "<< lname<< endl;
		cout<< "Id #: "<< id<< endl;
	}

	void setfname(string f)
	{
		fname=f;
	}

	void setlname(string l)
	{
		lname=l;
	}

	void setid(int i)
	{
		id=i;
	}

	string getfname()
	{
		return fname;
	}

	string getlname()
	{
		return lname;
	}

	string getid()
	{
		return id;
	}

	

};

class Node
{
	public:
	Node* next;
	Student kid;
	fstream list;

	Node()
	{
		next= 0;
	}
	
	~Node()
	{
		
	}

	void addHead(Node* &head, Node* &temp, string f, string l, string i)
	{

		temp=this;
		temp->kid.addData(f,l,i);

		if(head==0)
		{
			head=temp;
		}

		else
		{
			temp->next=head;
			head= this;
		}
	}

	void addTail(Node* &head, Node* &temp, string f, string l, string i)
	{
		temp=this;
		temp->kid.addData(f,l,i);
		if(head==0)
		{
			head=temp;
		}
		else
		{
			Node* q;
			q=head;

			while(q->next!=0)
			{
				q=q->next;
			}

			q->next=temp;
		}
	}

	void insertBefore(Node* &head, Node* &temp, string placeBefore, string f, string l, string i)
	{
		Node* traveler;
		Node* previous;
		previous=0;
		bool TF=false;
		temp=this;
                temp->kid.addData(f,l,i);
                if(head==0)
                {
			cout<<"No items in the list so this student will be added to the top of the list\n";
                        head=temp;
                }
		else
		{

			traveler=head;
			while(TF==false)
			{
				previous=traveler;
				traveler=traveler->next;
				if(traveler->kid.getfname()==placeBefore)
				{
					TF=true;
				}
					
				if(traveler->next==0)
				break;
			}
			if(TF==true)
			{
	
				if(traveler->next==0)
				{
					traveler->next=temp;
				}
				else
				{
					previous->next=temp;
					temp->next=traveler;
				}
			}
			cout<<"The person you are trying to insert this student before could not be found\n";			

		}
	}

	void insertAfter(Node* &head, Node* &temp, string placeAfter, string f, string l, string i)
	{
                Node* traveler;
                Node* after;
		bool TF=false;
		after=0;
		temp=this;
                temp->kid.addData(f,l,i);
                if(head==0)
                {
                        head=temp;
                }
                else
                {
                        after=head;
                        while(TF==false)
                        {
                               traveler=after;
				after=after->next;
                            	if(traveler->kid.getfname()==placeAfter)
				{
					TF=true;
				}	 
			 	if(after->next==0)
                                break;
                        }
                        if(traveler->next==0)
                        {
                                traveler->next=temp;
                        }
                        else
                        {
                               traveler->next=temp;
				temp->next=after;
                        }

		}
	}

	void deleteHead(Node* &head)
	{
		if(head==0)
		return;
		else
		{
			Node* traveler;
			traveler=head;
			head=head->next;
			delete traveler;
		}
	}

	void deleteTail(Node* head)
	{
		if(head==0)
		return;
		else
		{
			Node* traveler;
			Node* last;
			traveler=head;
			while(traveler->next!=0)
			{
				last=traveler;
				traveler=traveler->next;
			}
			last->next=0;
			delete traveler;
		}
	}

	void deleteItem(Node* &head, string f)
	{
		Node* previous;
		Node* after;
		Node* middle;
		middle=head;
		previous=head;
		after=head;
		bool TF=false;

		if(head->kid.getfname()==f)
		{
			deleteHead(head);
		}
		else
		{
			while(TF==false)
			{
				previous=middle;
				middle=after;
				after=after->next;
				if(middle->kid.getfname()==f)
				TF=true;	
			}

			previous->next=after;
			delete middle;	
		}
	}
	
	void writeToList()
	{
		list.open("list.txt", ios::out | ios::binary | ios::app);
		list.write(reinterpret_cast<char *>(&kid), sizeof(kid));
		list.close();
	}
};

void menu();
void manAddData(string&, string&, string&);

int main()
{
	Node* head;
	Node* temp;
	Node* t3;
	t3=0;
	head=0;
	temp=0;
	string first= " ";
	string last= " ";
	string i= " ";
	int choice;
	Node one;
	string t2;
	

	do
	{
		temp=0;
		choice=0;
		menu();
        	cout<<"Enter your choice!\n";
        	cin>>choice;

		switch(choice)
		{
			case 1:
			temp=new Node;
			manAddData(first, last, i);
			temp->addHead(head, temp, first, last, i);
			break;

			case 2:
			temp=new Node;
			manAddData(first, last, i);
			temp->addTail(head, temp, first, last, i);
			break;

			case 3:
			temp=new Node;
			manAddData(first, last, i);
			cout<<"Enter the first name of who you would like to put this student before: ";
			cin>> t2;
			temp->insertBefore(head, temp, t2, first, last, i);
			break;

			case 4:
			temp=new Node;	
			manAddData(first, last, i);
			cout<<"Enter the first name of who you would like to put this student after: ";
			cin>>t2;
			temp->insertAfter(head, temp, t2, first, last, i);
			break;

			case 5:
			head->deleteHead(head);
			break;

			case 6:
			head->deleteTail(head);
			break;

			case 7:
			cout<<"Enter the first name of the Student you would like to remove from the list\n";
			cin>>t2;
			head->deleteItem(head, t2);
			break;

			case 8:
			if(head==0)
			cout<<"There are no Students in the list!\n";
			else
			{
				t3=head;
				t3->kid.display();
				if(t3->next!=0)
				{
					
					do
					{
						t3=t3->next;
                   				t3->kid.display();
					}
			
					while(t3->next!=0);
					t3=0;
				}
			}
			
			break;

			case 9:
			{	
				t3=head;
				if(head!=0)
				{
					t3->writeToList();
					if(t3->next!=0)
					{
					
						do
						{
							t3=t3->next;
                   					t3->writeToList();
						}
						while(t3->next!=0);
					}
				}
				
				cout<< "The list has been written out to a file and the program has finished.\n";
				return 0;
			}	
			
			default:
			cout<<"Number Entered was not one of the choices, please re-enter your choice!\n";
		}
	}
	while(choice!=9);
	
	return 0;
}

void menu()
{
	cout<<"Choice 1: Add Node To The Head Of A List\n";
	cout<<"Choice 2: Add Node To The Tail Of A List\n";
	cout<<"Choice 3: Insert Node Before A Specific Student\n";
	cout<<"Choice 4: Insert Node After A Specific Student\n";
	cout<<"Choice 5: Delete the Head Of The List\n";
	cout<<"Choice 6: Delete The Tail Of The List\n";
	cout<<"Choice 7: Delete A Specific Node In The List\n";
	cout<<"Choice 8: Display the current list\n";
	cout<<"Choice 9: Exit The Program\n";

}

void manAddData(string & f, string& l, string& i)
{
 	cout<< "Enter First name: ";
        cin>> f;
        cout<< "Enter Last name: ";
        cin>> l;
        cout<< "Enter ID#: ";
        cin>> i;
 }
