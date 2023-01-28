#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Cars
{
    string Company[200] = {"Maruti", "Honda", "Toyota", "Ford", "Tata", "Mahindra", "Hyundai", "Renault", "Skoda", "Volkswagen", "Mercedes", "BMW", "Audi"};
    string Model[200] = {"Swift", "City", "Innova", "Figo", "Nano", "XUV", "i20", "Kwid", "Octavia", "Polo", "Benz", "X5", "A4"};
    string Color[200] = {"Red", "White", "Black", "Blue", "Silver", "Yellow", "Green", "Grey", "Brown", "Orange", "Purple", "Pink", "Gold"};
    string MaxSpeed[200] = {"180", "200", "210", "190", "160", "170", "180", "190", "200", "210", "220", "230", "240"};
    string FuelType[200] = {"Petrol", "Diesel", "Petrol", "Diesel", "Petrol", "Diesel", "Petrol", "Diesel", "Petrol", "Diesel", "Petrol", "Diesel", "Petrol"};
    string Manufacturer[200] = {"India", "Japan", "India", "India", "Japan", "India", "Japan", "France", "India", "Germany", "India", "Germany", "Germany"};
    int Price[200] = {500000, 600000, 700000, 800000, 900000, 1000000, 1100000, 1200000, 1300000, 1400000, 1500000, 1600000, 1700000};
} car;

struct Lease_info
{
    string First_Name[100];
    string Last_Name[100];
    string National_ID[100];
    string Phone_Number[100];
    int Payment[100];
} lease;
void Menu()
{
    int num = 1;
    for (int i = 0; i < 13; i++)
    {
        cout << "\t\t\t\t" << num << ". " << car.Company[i] << endl;
        num++;
    }
}

void Details(int Choice)
{
    cout << "\t\t\t ----------------------------" << endl;
    cout << "\t\t\t Company: " << car.Company[Choice - 1] << endl;
    cout << "\t\t\t ----------------------------" << endl;
    cout << "\t\t\t Model: " << car.Model[Choice - 1] << endl;
    cout << "\t\t\t Color: " << car.Color[Choice - 1] << endl;
    cout << "\t\t\t Max Speed: " << car.MaxSpeed[Choice - 1] << endl;
    cout << "\t\t\t Fuel Type: " << car.FuelType[Choice - 1] << endl;
    cout << "\t\t\t Manufacturer: " << car.Manufacturer[Choice - 1] << endl;
    cout << endl;
    cout << "\t\t\t ----------------------------" << endl;
    cout << "\t\t\t Price: " << car.Price[Choice - 1] << endl;
    cout << "\t\t\t ----------------------------" << endl;
}

void check_lease(int j)
{
    if (lease.Payment[j] >= car.Price[j])
    {
        cout << "\t\t\t Payment Successful" << endl;
        cout << "\t\t\t Thank you for using our service" << endl;
    }
    else
    {
        cout << "\t\t\t Payment Unsuccessful" << endl;
        cout << "\t\t\t Please pay the full amount " << car.Price[j] << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t Enter the amount you are paying : ";
        cin >> lease.Payment[j];
        cout << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        check_lease(j);
    }
}

void user_input(int Choice)
{
    system("cls");
    int i;
    int j = Choice - 1;
    cout << "\t\t\t--------------------------------------------" << endl;
    cout << "\t\t\t\t Please Provide your details : " << endl;
    cout << "\t\t\t--------------------------------------------" << endl;

    cout << "\t Note : PAYMMENT WON'T BE PROCEED IF THE AMOUNT IS LESS THAN THE RATE OF THE CAR " << endl;
    cout << "\t\t\t--------------------------------------------" << endl;
    cout << "\t\t\t First Name : ";
    cin >> lease.First_Name[i];
    cout << "\t\t\t Last Name : ";
    cin >> lease.Last_Name[i];
    cout << "\t\t\t Enter your National ID : ";
    cin >> lease.National_ID[i];
    cout << "\t\t\t Enter your Phone Number : ";
    cin >> lease.Phone_Number[i];
    cout << "\t\t\t--------------------------------------------" << endl;
    cout << "\t\t\t Enter the amount you are paying : ";
    cin >> lease.Payment[i];
    cout << "\t\t\t--------------------------------------------" << endl;

    check_lease(j);
}

int login()
{
    string pass = "";
    char ch;
    cout << "\t\t\t\t Car Rental System login" << endl;
    cout << "\t\t\t -------------------------------------------" << endl;
    cout << "\t\t\t Enter Password: ";
    ch = _getch();

    while (ch != 13)
    {
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    if (pass == "pass")
    {
        cout << endl;
        cout << "\t\t\t Password Matched" << endl;

        cout << "\t\t\t Loading..." << endl;
        cout << endl;
        cout << endl;
        system("PAUSE");
        cout << "\t\t\tAccess Granted ! Welcome to our system" << endl;
        cout << "\t\t\t\tDeveloped by : Amogh Saxena" << endl;
        system("cls");
    }
    else
    {
        cout << endl;
        cout << "\t\t\t Password Not MAtched" << endl;
        cout << "\t\t\t Try Again" << endl;
        system("PAUSE");
        system("cls");
        login();
    }
    return 0;
}

int main()
{
    login();
    string decide = "yes";
    cout << "\t\t\t--------------------------------------------" << endl;
    cout << "\t\t\t\t Welcome to Car Rental System" << endl;
    cout << "\t\t\t--------------------------------------------" << endl;
    cout << endl;
    cout << "\t\t\t Choose your option" << endl;
    cout << "\t\t\t--------------------------------------------" << endl;

    while (decide != "exit")
    {
        Menu();
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t Your Choice: ";
        int choice;
        cin >> choice;
        system("cls");
        Details(choice); // details

        cout << "\t\t\t Are you sure you want to rent this car (yes/no/exit) : ";
        cin >> decide;
        if (decide == "yes" || decide == "Yes")
        {
            user_input(choice);
            cout << "\t\t\t Do you want to continue (yes/no)" << endl;
            cin >> decide;
            if (decide == "no" || decide == "NO")
                cout << "\t\t\t Thank you for using our system" << endl;
            break;
            system("cls");
        }

        else
        {
            if (decide == "no" || decide == "NO")
            {
                system("cls");
                continue;
            }
            else if (decide == "exit" || decide == "EXIT")
            {
                cout << "\t\t\t Thank you for using our system" << endl;
                break;
            }
        }
    }
    getch();
    return 0;
}

// int login()
// {
//    string pass = "";
//    char ch;
//    cout << "\n\n\n\n\n\n\n\t\t\t\t\t   Car Rental System Login";
//    cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
//    ch = _getch();
//    while (ch != 13)
//    { // character 13 is enter
//       pass.push_back(ch);
//       cout << '*';
//       ch = _getch();
//    }
//    if (pass == "pass")
//    {
//       cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
//       system("PAUSE");
//       system("CLS");
//    }
//    else
//    {
//       cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
//       system("PAUSE");
//       system("CLS");
//       login();
//    }
// }


// Developed by : Amogh Saxena 
                // @amoghsaxena24