#include<iostream>
#include<cstring>

using namespace std;

class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];
    static int trainCount;

public:

    Train() 
    {
        trainNumber=0;
        strcpy(trainName,"NULL");
        strcpy(source,"NULL");
        strcpy(destination,"NULL");
        strcpy(trainTime,"NULL");
    }

    Train(int tNo, const char* tName, const char* src, const char* dest, const char* tTime) 
    {
        trainNumber=tNo;
        strcpy(trainName,tName);
        strcpy(source,src);
        strcpy(destination,dest);
        strcpy(trainTime,tTime);
        trainCount++;
    }

    ~Train() 
    {
        trainCount--;
    }

    int getTrainNumber() 
    {
        return trainNumber;
    }

    const char* getTrainName() 
    {
        return trainName;
    }

    const char* getSource() 
    {
        return source;
    }

    const char* getDestination() 
    {
        return destination;
    }

    const char* getTrainTime() 
    {
        return trainTime;
    }

    void setTrainNumber(int num) 
    {
        trainNumber = num;
    }

    void setTrainName(const char* name) 
    {
        strcpy(trainName, name);
    }

    void setSource(const char* src) 
    {
        strcpy(source, src);
    }

    void setDestination(const char* dest) 
    {
        strcpy(destination, dest);
    }

    void setTrainTime(const char* time) 
    {
        strcpy(trainTime, time);
    }

    void inputTrainDetails() 
    {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore();  
        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);
        cout << "Enter Source: ";
        cin.getline(source, 50);
        cout << "Enter Destination: ";
        cin.getline(destination, 50);
        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
        trainCount++;
    }

    void displayTrainDetails() 
    {
        cout << "Train Number: "<<trainNumber<<endl;
        cout << "Train Name: "<<trainName<<endl;
        cout << "Source: "<<source<<endl;
        cout << "Destination: "<<destination<<endl;
        cout << "Train Time: "<<trainTime<<endl;
    }

    static int getTrainCount() 
    {
        return trainCount;
    }
};

int Train::trainCount = 0;

class RailwaySystem 
{
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem() 
    {
        totalTrains=0;
        trains[0]=Train(101,"Bullet Train","Rajasthan","Mumbai","1 AM");
        trains[1]=Train(102,"Vande Bharath","Ahmedabad","Mumbai","3 PM");
        trains[2]=Train(103,"Indian Express","Kanyakumari","Kolkata","12 PM");
        totalTrains=3;
    }

    void addTrain() 
    {
        if (totalTrains>=100)
        {
            cout<<"Train limit reached!"<<endl;
            return;
        }
        trains[totalTrains].inputTrainDetails();
        totalTrains++;
        cout<<"Train added successfully.\n";
    }

    void displayAllTrains() 
    {
        if (totalTrains==0) 
        {
            cout<<"No train records found.\n";
            return;
        }

        for(int i=0;i<totalTrains;i++) 
        {
            cout<<"\nTrain"<<i+1<<"details:\n";
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int number)
    {
        bool found = false;
        for(int i=0;i<totalTrains;i++) 
        {
            if (trains[i].getTrainNumber()==number)
            {
                cout<<"\nTrain Found:\n";
                trains[i].displayTrainDetails();
                found=true;
                break;
            }
        }

        if(!found)
        {
            cout<<"Train with number"<<number<<" not found!"<<endl;
        }
    }
};

int main() 
{
    RailwaySystem system;
    int choice;

    do 
    {
        cout<<"\n--- Railway Reservation System Menu ---\n";
        cout<<"1. Add New Train Record\n";
        cout<<"2. Display All Train Records\n";
        cout<<"3. Search Train by Number\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) 
        {
        case 1:
            system.addTrain();
            break;
        case 2:
            system.displayAllTrains();
            break;
        case 3:
            int number;
            cout << "Enter Train Number to search: ";
            cin >> number;
            system.searchTrainByNumber(number);
            break;
        case 4:
            cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } 
    while(choice!=4);

    return 0;
}

/*
Output:-

--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter your choice: 1
Enter Train Number: 1001
Enter Train Name: Anu Explress
Enter Source: Chennai
Enter Destination: Jambu
Enter Train Time: 5:30 pm
Train added successfully.

--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter your choice: 2

Train1details:
Train Number: 101
Train Name: Bullet Train
Source: Rajasthan
Destination: Mumbai
Train Time: 1 AM

Train2details:
Train Number: 102
Train Name: Vande Bharath
Source: Ahmedabad
Destination: Mumbai
Train Time: 3 PM

Train3details:
Train Number: 103
Train Name: Indian Express
Source: Kanyakumari
Destination: Kolkata
Train Time: 12 PM

Train4details:
Train Number: 1001
Train Name: Anu Explress
Source: Chennai
Destination: Jambu
Train Time: 5:30 pm

--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter your choice: 3
Enter Train Number to search: 10 
Train with number10 not found!

--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter your choice: 4
Exiting the system. Goodbye!

*/