#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include<fstream>

class Car
{
    public:
    int vehicleNo;
    float hoursStayed;
    char driverName[15], vipStatus, timeSlot[50];

    void input()
    {
        system("CLS");
        int d;
        cout<<"\n\n\t\tEnter the name of the driver: ";
        cin>>driverName;
        cout<<"\n\n\t\tEnter the car number: ";
        cin>>vehicleNo;
        cout<<"\n\n\t\tEnter the number of hours of stay: ";
        cin>>hoursStayed;
        cout<<"\n\n\t\tEnter the time slot: ";
        cin>>timeSlot;

        if(d < 20 && hoursStayed < 8)
        {
            cout<<"\n\n\t\tParking Available! You can park your car.";
        }
        else
        {
            cout<<"\n\n\t\tParking not possible!!";
        }
        cout<<"\n\n\t\tCar has been parked.";
    }

    void calculateExpenses()
    {
        cout<<"\n\t\n\tAre you a V.I.P: y/n ";
        cin>>vipStatus;
        if(vipStatus == 'y')
        {
            system("CLS");
            cout<<"\n\t\n\tTotal expense during parking: ";
            cout<<hoursStayed * 20<<" rupees";
        }
        else
        {
            system("CLS");
            cout<<"\n\t\n\tTotal expenses during parking: ";
            cout<<hoursStayed * 25<<" rupees";
        }
    }

    void output()
    {
        cout<<"\n\n\t\tDriver Name: "<<driverName<<endl;
        cout<<"\n\n\t\tCar Number: "<<vehicleNo<<endl;
        cout<<"\n\n\t\tHours Of Stay: " <<hoursStayed;
        cout<<"\n\n\t\tTime Slot Of Parking: " <<timeSlot;
    }
};

void deleteRecord()
{
    Car a; // Declare 'a' here

    int vehicleNumber;
    system("CLS");
    cout<<"\n\n\t\tEnter the car number you want to depart: ";
    cin>>vehicleNumber;

    ifstream inFile;
    inFile.open("parking3.dat", ios::binary);
    ofstream outFile;
    outFile.open("temp.dat", ios::out | ios::binary);

    while(inFile.read((char*)&a, sizeof(a)))
    {
        if(a.vehicleNo != vehicleNumber)
        {
            outFile.write((char*)&a, sizeof(a));
        }
    }

    cout<<"\n\n\t\t Parking Record Deleted";

    inFile.close();
    outFile.close();

    remove("parking3.dat");
    rename("temp.dat", "parking3.dat");
}

int main()
{
    int login();
    login();
    int choice, vehicleNo, d;
    Car a; // Declare 'a' here

    while(1) {
        system("CLS");

        cout << "\n\n\t\t ====== CAR PARKING RESERVATION SYSTEM ======";
        cout <<"\n\n                                          ";
        cout<<" \n\t\t\t======================";
        cout << "\n\n\t\t\t  1. Park a Car";
        cout << "\n\n\t\t\t  2. View Total Cars Parked";
        cout << "\n\n\t\t\t  3. View Total Parking Charges and Details";
        cout << "\n\n\t\t\t  4. Departure of a Car";
        cout << "\n\n\t\t\t  5. Exit Program";
        cout<<" \n\t\t\t======================";
        cout << "\n\n";
        cout << "\t\t\t Select Your Choice ::";
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                char f;
                cout<<"\n\n\t\t==Do You Want to continue==y/n ";
                cin>>f;

                if(f == 'y')
                {
                    ofstream f1("parking3.dat",ios::binary|ios::out|ios::app);
                    a.input();
                    f1.write((char*)&a,sizeof(a));
                }
                break;
            }

            case 2:
            {
                system("CLS");
                cout << "\n\n\t\t=== View the Records in the Parking Database ===";
                cout << "\n";
                ifstream infile("parking3.dat",ios::binary|ios::in);
                int d = 1;

                while (infile.read((char *)&a,sizeof (a)))
                {
                    system("CLS");
                    cout << "\n";
                    cout<<"\n\n\tCar position in parking lot: "<<d;
                    d++;
                    a.output();
                    cout<<"\n";
                    cout<<"\n\n\n";
                    system("PAUSE");
                    cout<<endl;
                }
                break;
            }

            case 4:
            {
                deleteRecord();
                break;
            }

            case 3:
            {
                ifstream infile("parking3.dat",ios::binary|ios::in);
                while (infile.read((char *)&a,sizeof (a)))
                {
                    cout << "\n";
                    a.calculateExpenses();
                    a.output();
                    cout<<"\n";
                    cout<<endl;
                }
                break;
            }

            case 5:
            {
                system("CLS");
                cout<<"\n\n\n\t\t\tBrought To You By: Md. Daud Hossain Supto \n";
                exit(0);
                break;
            }

            default :
            {
                cout<<"\n\n\t\tInvalid input";
                cout<<"\n\n\t\tPress Enter to continue";
            }
        }
        getch();
    }
}

int login()
{
    string pass ="";
    char ch;
    cout <<"\n\n\n\n\n\n\n\t\t\t\t\tCar Parking Reservation System Login";
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
    ch = _getch();

    while(ch != 13)//character 13 is enter
    {
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }

    if(pass == "pass")
    {
        cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
        system("PAUSE");
    }
    else
    {
        cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
        system("PAUSE");
        system("CLS");
        login();
    }
}
