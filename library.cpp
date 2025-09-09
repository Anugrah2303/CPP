#include <iostream>
#include <string>
using namespace std;

class LibraryItem
{
private:
    string title="";
    string author="";
    string dueDate="";

public:
    void setTitle(string newTitle)
    {
        title=newTitle;
    }

    void setAuthor(string newAuthor)
    {
        author=newAuthor;
    }

    void setDueDate(string newDueDate)
    {
        dueDate=newDueDate;
    }

    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    string getDueDate()
    {
        return dueDate;
    }

    virtual void checkOut()=0;
    virtual void returnItem()=0;
    virtual void displayDetails()=0;

    ~LibraryItem()
    {
    }
};

class Book : public LibraryItem
{
private:
    string isbn="";

public:
    void setISBN(string newISBN)
    {
        if(newISBN.size()<5)
        {
            cout<<"Error: Invalid ISBN format!"<<endl;
            isbn="UNKNOWN";
        }
        else
        {
            isbn=newISBN;
        }
    }

    string getISBN()
    {
        return isbn;
    }

    void checkOut()
    {
        cout<<"Book '"<<getTitle()<<"' has been checked out."<<endl;
    }

    void returnItem()
    {
        cout<<"Book '"<<getTitle()<<"' has been returned."<<endl;
    }

    void displayDetails()
    {
        cout<<"[Book] Title: "<<getTitle()<<", Author: "<<getAuthor()
            <<", ISBN: "<<isbn<<", Due Date: "<<getDueDate()<<endl;
    }
};

class DVD : public LibraryItem
{
private:
    int duration=0;

public:
    void setDuration(int d)
    {
        if(d<=0)
        {
            cout<<"Error: Duration must be positive!"<<endl;
            duration=0;
        }
        else
        {
            duration=d;
        }
    }

    int getDuration()
    {
        return duration;
    }

    void checkOut()
    {
        cout<<"DVD '"<<getTitle()<<"' has been checked out."<<endl;
    }

    void returnItem()
    {
        cout<<"DVD '"<<getTitle()<<"' has been returned."<<endl;
    }

    void displayDetails()
    {
        cout<<"[DVD] Title: "<<getTitle()<<", Author: "<<getAuthor()
            <<", Duration: "<<duration<<" mins, Due Date: "<<getDueDate()<<endl;
    }
};

class Magazine : public LibraryItem
{
private:
    int issueNumber=0;

public:
    void setIssueNumber(int n)
    {
        if(n<=0)
        {
            cout<<"Error: Issue number must be positive!"<<endl;
            issueNumber=0;
        }
        else
        {
            issueNumber=n;
        }
    }

    int getIssueNumber()
    {
        return issueNumber;
    }

    void checkOut()
    {
        cout<<"Magazine '"<<getTitle()<<"' has been checked out."<<endl;
    }

    void returnItem()
    {
        cout<<"Magazine '"<<getTitle()<<"' has been returned."<<endl;
    }

    void displayDetails()
    {
        cout<<"[Magazine] Title: "<<getTitle()<<", Author: "<<getAuthor()
            <<", Issue: "<<issueNumber<<", Due Date: "<<getDueDate()<<endl;
    }
};

int main()
{
    const int MAX_ITEMS=10;
    LibraryItem* libraryItems[MAX_ITEMS];
    int itemCount=0;
    int choice=0;

    do
    {
        cout<<"\n===== Library Management System ====="<<endl;
        cout<<"1. Add Book"<<endl;
        cout<<"2. Add DVD"<<endl;
        cout<<"3. Add Magazine"<<endl;
        cout<<"4. Display All Items"<<endl;
        cout<<"5. Check Out Item"<<endl;
        cout<<"6. Return Item"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        if(choice==1)
        {
            if(itemCount>=MAX_ITEMS)
            {
                cout<<"Error: Library is full!"<<endl;
                continue;
            }

            Book* b=new Book();
            string title="",author="",dueDate="",isbn="";

            cout<<"Enter Book Title: ";
            cin.ignore();
            getline(cin,title);
            cout<<"Enter Author: ";
            getline(cin,author);
            cout<<"Enter Due Date: ";
            getline(cin,dueDate);
            cout<<"Enter ISBN: ";
            getline(cin,isbn);

            b->setTitle(title);
            b->setAuthor(author);
            b->setDueDate(dueDate);
            b->setISBN(isbn);

            libraryItems[itemCount]=b;
            itemCount=itemCount+1;

            cout<<"Book added successfully!"<<endl;
        }
        else if(choice==2)
        {
            if(itemCount>=MAX_ITEMS)
            {
                cout<<"Error: Library is full!"<<endl;
                continue;
            }

            DVD* d=new DVD();
            string title="",author="",dueDate="";
            int duration=0;

            cout<<"Enter DVD Title: ";
            cin.ignore();
            getline(cin,title);
            cout<<"Enter Author: ";
            getline(cin,author);
            cout<<"Enter Due Date: ";
            getline(cin,dueDate);
            cout<<"Enter Duration (minutes): ";
            cin>>duration;

            d->setTitle(title);
            d->setAuthor(author);
            d->setDueDate(dueDate);
            d->setDuration(duration);

            libraryItems[itemCount]=d;
            itemCount=itemCount+1;

            cout<<"DVD added successfully!"<<endl;
        }
        else if(choice==3)
        {
            if(itemCount>=MAX_ITEMS)
            {
                cout<<"Error: Library is full!"<<endl;
                continue;
            }

            Magazine* m=new Magazine();
            string title="",author="",dueDate="";
            int issue=0;

            cout<<"Enter Magazine Title: ";
            cin.ignore();
            getline(cin,title);
            cout<<"Enter Author: ";
            getline(cin,author);
            cout<<"Enter Due Date: ";
            getline(cin,dueDate);
            cout<<"Enter Issue Number: ";
            cin>>issue;

            m->setTitle(title);
            m->setAuthor(author);
            m->setDueDate(dueDate);
            m->setIssueNumber(issue);

            libraryItems[itemCount]=m;
            itemCount=itemCount+1;

            cout<<"Magazine added successfully!"<<endl;
        }
        else if(choice==4)
        {
            for(int i=0;i<itemCount;i++)
            {
                libraryItems[i]->displayDetails();
            }
        }
        else if(choice==5)
        {
            int idx=0;
            cout<<"Enter item index to check out (0-"<<itemCount-1<<"): ";
            cin>>idx;
            if(idx<0 || idx>=itemCount)
            {
                cout<<"Error: Invalid index!"<<endl;
            }
            else
            {
                libraryItems[idx]->checkOut();
            }
        }
        else if(choice==6)
        {
            int idx=0;
            cout<<"Enter item index to return (0-"<<itemCount-1<<"): ";
            cin>>idx;
            if(idx<0 || idx>=itemCount)
            {
                cout<<"Error: Invalid index!"<<endl;
            }
            else
            {
                libraryItems[idx]->returnItem();
            }
        }

    }while(choice!=0);

    for(int i=0;i<itemCount;i++)
    {
        delete libraryItems[i];
    }

    cout<<"Exiting Library Management System..."<<endl;
    return 0;
}

/*
OUTPUT 

===== Library Management System =====
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
0. Exit
Enter your choice: 1
Enter Book Title: C++ Basics
Enter Author: Bjarne
Enter Due Date: 15-09-2025
Enter ISBN: 12345
Book added successfully!

===== Library Management System =====
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
0. Exit
Enter your choice: 2
Enter DVD Title: Inception
Enter Author: Nolan
Enter Due Date: 20-09-2025
Enter Duration (minutes): 148
DVD added successfully!

===== Library Management System =====
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
0. Exit
Enter your choice: 4
[Book] Title: C++ Basics, Author: Bjarne, ISBN: 12345, Due Date: 15-09-2025
[DVD] Title: Inception, Author: Nolan, Duration: 148 mins, Due Date: 20-09-2025

===== Library Management System =====
Enter your choice: 5
Enter item index to check out (0-1): 0
Book 'C++ Basics' has been checked out.

===== Library Management System =====
Enter your choice: 6
Enter item index to return (0-1): 1
DVD 'Inception' has been returned.

===== Library Management System =====
Enter your choice: 0
Exiting Library Management System...


*/
