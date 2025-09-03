#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
private:
    int vehicleId;
    string manufacturer;
    string model;
    int year;
    static int totalVehicles;

public:
    Vehicle()
    {
        vehicleId=0;
        manufacturer="Unknown";
        model="Unknown";
        year=0;
        totalVehicles++;
    }

    Vehicle(int vehicleId,const string& manufacturer,const string& model,int year)
    {
        this->vehicleId=vehicleId;
        this->manufacturer=manufacturer;
        this->model=model;
        this->year=year;
        totalVehicles++;
    }

    virtual ~Vehicle()
    {
        totalVehicles--;
    }

    void setVehicleId(int vehicleId)
    {
        this->vehicleId=vehicleId;
    }

    int getVehicleId() const
    {
        return vehicleId;
    }

    void setManufacturer(const string& manufacturer)
    {
        this->manufacturer=manufacturer;
    }

    string getManufacturer() const
    {
        return manufacturer;
    }

    void setModel(const string& model)
    {
        this->model=model;
    }

    string getModel() const
    {
        return model;
    }

    void setYear(int year)
    {
        this->year=year;
    }

    int getYear() const
    {
        return year;
    }

    static int getTotalVehicles()
    {
        return totalVehicles;
    }

    virtual void display() const
    {
        cout<<"Vehicle ID: "<<vehicleId
            <<" Manufacturer: "<<manufacturer
            <<" Model: "<<model
            <<" Year: "<<year;
    }
};

int Vehicle::totalVehicles=0;

class Car:public Vehicle
{
private:
    string fuelType;

public:
    Car(int vehicleId,const string& manufacturer,const string& model,int year,const string& fuelType)
        :Vehicle(vehicleId,manufacturer,model,year)
    {
        this->fuelType=fuelType;
    }

    void setFuelType(const string& fuelType)
    {
        this->fuelType=fuelType;
    }

    string getFuelType() const
    {
        return fuelType;
    }

    void display() const override
    {
        Vehicle::display();
        cout<<" Fuel Type: "<<fuelType;
    }
};

class ElectricCar:public Car
{
private:
    int batteryCapacity;

public:
    ElectricCar(int vehicleId,const string& manufacturer,const string& model,int year,
                const string& fuelType,int batteryCapacity)
        :Car(vehicleId,manufacturer,model,year,fuelType)
    {
        this->batteryCapacity=batteryCapacity;
    }

    void setBatteryCapacity(int batteryCapacity)
    {
        this->batteryCapacity=batteryCapacity;
    }

    int getBatteryCapacity() const
    {
        return batteryCapacity;
    }

    void display() const override
    {
        Car::display();
        cout<<" Battery Capacity: "<<batteryCapacity<<" kWh";
    }
};

class Aircraft
{
private:
    int flightRange;

public:
    Aircraft(int flightRange=0)
    {
        this->flightRange=flightRange;
    }

    void setFlightRange(int flightRange)
    {
        this->flightRange=flightRange;
    }

    int getFlightRange() const
    {
        return flightRange;
    }

    virtual void display() const
    {
        cout<<" Flight Range: "<<flightRange<<" km";
    }
};

class FlyingCar:public Car,public Aircraft
{
public:
    FlyingCar(int vehicleId,const string& manufacturer,const string& model,int year,
              const string& fuelType,int flightRange)
        :Car(vehicleId,manufacturer,model,year,fuelType),Aircraft(flightRange)
    {
    }

    void display() const override
    {
        Car::display();
        Aircraft::display();
    }
};

class SportsCar:public ElectricCar
{
private:
    int topSpeed;

public:
    SportsCar(int vehicleId,const string& manufacturer,const string& model,int year,
              const string& fuelType,int batteryCapacity,int topSpeed)
        :ElectricCar(vehicleId,manufacturer,model,year,fuelType,batteryCapacity)
    {
        this->topSpeed=topSpeed;
    }

    void setTopSpeed(int topSpeed)
    {
        this->topSpeed=topSpeed;
    }

    int getTopSpeed() const
    {
        return topSpeed;
    }

    void display() const override
    {
        ElectricCar::display();
        cout<<" Top Speed: "<<topSpeed<<" km/h";
    }
};

class Sedan:public Car
{
public:
    Sedan(int vehicleId,const string& manufacturer,const string& model,int year,const string& fuelType)
        :Car(vehicleId,manufacturer,model,year,fuelType)
    {
    }
};

class SUV:public Car
{
public:
    SUV(int vehicleId,const string& manufacturer,const string& model,int year,const string& fuelType)
        :Car(vehicleId,manufacturer,model,year,fuelType)
    {
    }
};

class VehicleRegistry
{
private:
    Vehicle* vehicles[100];
    int count;

public:
    VehicleRegistry()
    {
        count=0;
    }

    void addVehicle(Vehicle* vehicle)
    {
        if(count<100)
        {
            vehicles[count++]=vehicle;
            cout<<"Vehicle added successfully\n";
        }
        else
        {
            cout<<"Registry Full\n";
        }
    }

    void displayAll() const
    {
        cout<<"\nVehicle Registry\n";
        for(int i=0;i<count;i++)
        {
            vehicles[i]->display();
            cout<<endl;
        }
        cout<<"End of Registry\n";
    }

    void searchById(int vehicleId) const
    {
        for(int i=0;i<count;i++)
        {
            if(vehicles[i]->getVehicleId()==vehicleId)
            {
                cout<<"Vehicle Found\n";
                vehicles[i]->display();
                cout<<endl;
                return;
            }
        }
        cout<<"Vehicle with ID "<<vehicleId<<" not found\n";
    }
};

int main()
{
    VehicleRegistry registry;
    int choice;

    do
    {
        cout<<"\nVehicle Registry Menu\n";
        cout<<"1. Add Car\n";
        cout<<"2. Add Electric Car\n";
        cout<<"3. Add Flying Car\n";
        cout<<"4. Add Sports Car\n";
        cout<<"5. Add Sedan\n";
        cout<<"6. Add SUV\n";
        cout<<"7. View All Vehicles\n";
        cout<<"8. Search by ID\n";
        cout<<"0. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        if(choice==1)
        {
            int vehicleId,year;
            string manufacturer,model,fuelType;
            cout<<"Enter ID Manufacturer Model Year FuelType: ";
            cin>>vehicleId>>manufacturer>>model>>year>>fuelType;
            registry.addVehicle(new Car(vehicleId,manufacturer,model,year,fuelType));
        }
        else if(choice==2)
        {
            int vehicleId,year,batteryCapacity;
            string manufacturer,model,fuelType;
            cout<<"Enter ID Manufacturer Model Year FuelType BatteryCapacity: ";
            cin>>vehicleId>>manufacturer>>model>>year>>fuelType>>batteryCapacity;
            registry.addVehicle(new ElectricCar(vehicleId,manufacturer,model,year,fuelType,batteryCapacity));
        }
        else if(choice==3)
        {
            int vehicleId,year,flightRange;
            string manufacturer,model,fuelType;
            cout<<"Enter ID Manufacturer Model Year FuelType FlightRange: ";
            cin>>vehicleId>>manufacturer>>model>>year>>fuelType>>flightRange;
            registry.addVehicle(new FlyingCar(vehicleId,manufacturer,model,year,fuelType,flightRange));
        }
        else if(choice==4)
        {
            int vehicleId,year,batteryCapacity,topSpeed;
            string manufacturer,model,fuelType;
            cout<<"Enter ID Manufacturer Model Year FuelType BatteryCapacity TopSpeed: ";
            cin>>vehicleId>>manufacturer>>model>>year>>fuelType>>batteryCapacity>>topSpeed;
            registry.addVehicle(new SportsCar(vehicleId,manufacturer,model,year,fuelType,batteryCapacity,topSpeed));
        }
        else if(choice==5)
        {
            int vehicleId,year;
            string manufacturer,model,fuelType;
            cout<<"Enter ID Manufacturer Model Year FuelType: ";
            cin>>vehicleId>>manufacturer>>model>>year>>fuelType;
            registry.addVehicle(new Sedan(vehicleId,manufacturer,model,year,fuelType));
        }
        else if(choice==6)
        {
            int vehicleId,year;
            string manufacturer,model,fuelType;
            cout<<"Enter ID Manufacturer Model Year FuelType: ";
            cin>>vehicleId>>manufacturer>>model>>year>>fuelType;
            registry.addVehicle(new SUV(vehicleId,manufacturer,model,year,fuelType));
        }
        else if(choice==7)
        {
            registry.displayAll();
        }
        else if(choice==8)
        {
            int vehicleId;
            cout<<"Enter Vehicle ID: ";
            cin>>vehicleId;
            registry.searchById(vehicleId);
        }

    }while(choice!=0);

    cout<<"Exiting Vehicle Registry System\n";
    return 0;
}

/*
======== Sample Output ========

Vehicle Registry Menu
1. Add Car
2. Add Electric Car
3. Add Flying Car
4. Add Sports Car
5. Add Sedan
6. Add SUV
7. View All Vehicles
8. Search by ID
0. Exit
Enter your choice: 1
Enter ID Manufacturer Model Year FuelType: 101 Toyota Corolla 2020 Petrol
Vehicle added successfully

Vehicle Registry Menu
Enter your choice: 7

Vehicle Registry
Vehicle ID: 101 Manufacturer: Toyota Model: Corolla Year: 2020 Fuel Type: Petrol
End of Registry

Vehicle Registry Menu
Enter your choice: 8
Enter Vehicle ID: 101
Vehicle Found
Vehicle ID: 101 Manufacturer: Toyota Model: Corolla Year: 2020 Fuel Type: Petrol

Vehicle Registry Menu
Enter your choice: 0
Exiting Vehicle Registry System
================================
*/
