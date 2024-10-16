#include<bits/stdc++.h>
#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<sys/stat.h>
#include<chrono>
#include<stdlib.h>
#include<ctime>
#include<unistd.h>

using namespace std;

class TrafficManagementSystem
{
    public:
    int welcome()
    {
        clearConsole();
        time_t tt;
        struct tm * ti;
        time (&tt);
        ti = localtime(&tt);
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<" " <<asctime(ti);
        delay();
        clearConsole();
        cout<<"**'\t\t\t\t\t\t\t\t '**"<<endl;
        cout<<"**'\t\t HEARTY WELCOME TO TRAFFIC MANAGEMENT\t\t'**"<<endl;
        cout<<"**'\t\t\t\t\t\t\t\t '**"<<endl;
        cout<<endl<<endl<<endl;
        cout<<"**'\t\t ENTER YOUR DESIRED OPTION:\t\t\t '**"<<endl;
        cout<<"**'\t\t\t\t\t\t\t\t '**"<<endl;
        cout<<"**'\t\t Press 1 To record new vehicles and search existing vehicles \t\t'**"<<endl;
        cout<<"**'\t\t Press 2 To get record of challans \t\t'**"<<endl;
        cout<<"**'\t\t Press 3 To search and control traffic control booths\t '**"<<endl;
        cout<<"**'\t\t Press 4 If you require HELP \t\t\t'**"<<endl;
        cout<<"**'\t\t Press 5 If you want to end our Service\t\t'**"<<endl;
        cout<<"**'\t\t\t\t\t\t\t\t '**"<<endl;
        cout<<"**'\t Please enter your desired choice: ___ \t\t\t'**"<<endl;
        int ch{0};
        cin>>ch;
        switch(ch)
        {
            case 1:
                clearConsole();
                recordOfVehicle();
                break;
            case 2:
                clearConsole();recordOfChallan();
                break;
            case 3:
                clearConsole();
                trafficContBooth();
                break;
            case 4:
                clearConsole();
                helpInfo();
                break;
            case 5:
                delay();
                clearConsole();
                cout<<"**' \t Thank You for Using Our Service! Have a Nice Day :) \t '**"<<endl;
                break;
            default:
                cout<<"Enter a valid choice!!"<<endl;
                delay();
                clearConsole();
                welcome();
        }
        return 0;
    }
    int delay()
    {
        time_t current_time = time(NULL);
        time_t target_time = current_time + 5;
        sleep(2);
        return 0;
    }
    int recordOfVehicle()
    {
        cout<<"*\t\t ----Record of Vehicles---- \t\t*"<<endl;
        cout<<"** \t\t\t\t\t\t\t **"<<endl;
        cout<<"* \t\tSelect your desired option \t\t:- *"<<endl;
        cout<<"** \t\t\t\t\t\t\t **"<<endl;
        cout<<"* Press 1 to Add a New Vehicle *"<<endl;
        cout<<"* Press 2 to Search for a Vehicle Using its registration number *"<<endl;
        cout<<"* Press 3 to search a vehicle through the owner's name *"<<endl;
        cout<<"* *"<<endl;
        cout<<"* Press 0 for home *"<<endl;
        cout<<"* Please enter your desired choice__ *"<<endl;
        cout<<"* *"<<endl;
        int RegofChoice{0};
        cin>>RegofChoice;
        switch (RegofChoice)
        {
            case 0:
            clearConsole();
            welcome();
            break;
            case 1:
            recordOfVehicle_1();
            break;
            case 2:
            recordOfVehicle_2();
            break;
            case 3:
            recordOfVehicle_3();
            break;
            default:
                cout<<"Enter a valid choice!!"<<endl;
        }
        return 0;
    }
    int recordOfVehicle_1()
    {
        clearConsole();  
        ofstream fio;    
        string regNumber, ownerName, dateOfReg, expiryDate, vehicleName, manufacturerName, colour;
        string filename = "RecordOfVehicle.csv";
        string header = "Registration Number,Owner Name,Date of Registration,Expiry Date,Vehicle Name,Manufacturer Name,Colour";

        // Instructions for the user
        cin.ignore();
        cout << "Welcome to the CHALLAN MANAGEMENT portal" << endl;
        cout << "Please enter your vehicle's registration number in the format 'XX-XX-XX-XXXX': " << endl;
        getline(cin, regNumber);
        cout << "Please enter the owner's name (use '_' instead of space between first and last name): " << endl;
        getline(cin, ownerName);
        cout << "Enter the date of registration (format: DD-MM-YYYY): " << endl;
        getline(cin, dateOfReg);
        cout << "Enter the expiry date (format: DD-MM-YYYY): " << endl;
        getline(cin, expiryDate);
        cout << "Enter the vehicle name: " << endl;
        getline(cin, vehicleName);
        cout << "Enter the manufacturer's name: " << endl;
        getline(cin, manufacturerName);
        cout << "Enter the vehicle color: " << endl;
        getline(cin, colour);

        // Check if the file exists
        if (!fileExists(filename)) {
            // If the file is new, open it in append mode and write the header
            fio.open(filename, ios::app);
            fio << header << endl;
            fio.close();
        }
        if (fileExists(filename) && !fileHasHeader(filename, header)) 
        {
            // Open the file in read and write mode (both input and output)
            ifstream inFile(filename);
            string fileContents;
            string line;

            // Read the entire file contents and store in memory
            while (getline(inFile, line)) 
            {
                fileContents += line + "\n";
            }
            inFile.close();

            // Open the file in write mode to overwrite it with the header
            ofstream outFile(filename);
            outFile << header << endl;  // Write the header

            // Write the previously read contents back into the file
            outFile << fileContents;
            outFile.close();

            cout << "Header added successfully to the existing file." << endl;
        }
        fio.open(filename, ios::app);
        fio << regNumber << "," << ownerName << "," << dateOfReg << "," << expiryDate << "," << vehicleName << ","
            << manufacturerName << "," << colour << endl;
        fio.close();
        cout << "Data has been entered successfully!" << endl;
        delay();
        clearConsole();
        recordOfChallan();
        return 0;
    }
    int recordOfVehicle_2()
    {
        clearConsole();
        string path = "RecordOfTheVehicles.csv";
        ifstream file( path.c_str() );
        if(file.is_open())
        {
            cout << " WELCOME to the registration portal\n" ;
            cout <<endl<< "Please enter the registration number of the vehicle that you are searching for\n" <<endl;
            cout <<"The Registration Number should be in format 'XX-XX-XX-XXXX'!!"<<endl;
            string word ;
            cin >> word ;
            int count = 0 ;
            string person ;
            while( file >> person )
            {
                if( word == person )
                {
                    ++count ;
                    cout<<person<<endl;
                }
            }
            if(count > 0)
            {
                cout << "The entered registration number " << word << "'is found in our records"<<endl ;
                int choice;
                cout<<endl<<"Press 1 to go back to the home screen and Press 2 if you want to enter the registration number again ";
                cin>>choice;
                (choice ==1) ? welcome(): recordOfVehicle_2();
            }
            else
            {
                cout<<"Sorry!!!! Entered Registration number is not found";
                int choice;
                cout<<endl<<"Press 1 to go back to the home screen and Press 2 if you want to enter the registration number again ";
                cin>>choice;
                (choice ==1) ? welcome(): recordOfVehicle_2();
            }
        }
        else
        {
            cerr << "Error!!!!401!!!\n" ;
            delay();
            welcome();
        }
        return 0;
    }
    int recordOfVehicle_3()
    {
        clearConsole();
        string path = "RecordOfVehicle.csv";
        ifstream file(path.c_str());

        if (file.is_open()) 
        {
            cout << " Welcome to Challan Management System\n" << endl;
            cout <<endl<< "Please enter the name of the owner of the vehicle that you are searching for\n"<<endl ;
            cout << "*' If Name contains Lastname then use '_' between first name and last name '*"<<endl;

            string text;
            cin >> text;  
            bool found = false;  
            string line;
            getline(file, line);
            while (getline(file, line)) 
            {
                stringstream ss(line);
                string regNumber, ownerName, dateOfReg, expiryDate, vehicleName, manufacturerName, colour;
                getline(ss, regNumber, ',');
                getline(ss, ownerName, ',');
                getline(ss, dateOfReg, ',');
                getline(ss, expiryDate, ',');
                getline(ss, vehicleName, ',');
                getline(ss, manufacturerName, ',');
                getline(ss, colour, ',');

                // Compare the registration number with user input
                if (ownerName == text) 
                {
                    found = true;
                    // If a match is found, display the record
                    cout << "\nThe entered Owner's Name '" << text << "' has been found successfully in our records.\n";
                    cout << "Registration Number: " << regNumber << endl;
                    cout << "Owner Name: " << ownerName << endl;
                    cout << "Date of Registration: " << dateOfReg << endl;
                    cout << "Expiry Date: " << expiryDate << endl;
                    cout << "Vehicle Name: " << vehicleName << endl;
                    cout << "Manufacturer Name: " << manufacturerName << endl;
                    cout << "Colour: " << colour << endl;

                    // Allow the user to choose the next action
                    int choice;
                    cout << endl << "Enter 1 to go to the home screen, or press 2 to search for another Owner's Name: ";
                    cin >> choice;
                    if (choice == 1)
                        welcome();
                    else
                        recordOfVehicle_3();
                    break;
                }
            }

            // If no match was found
            if (!found) {
                clearConsole();
                cout << "Sorry!!!! Owner's Name '" << text << "' is not found !!" << endl;
                int choice;
                cout << endl << "Enter 1 to go back to the home screen, or press 2 to search for another Owner's Name: ";
                cin >> choice;
                if (choice == 1)
                    welcome();
                else
                    recordOfVehicle_3();
            }

            file.close();  // Close the file after use
        } 
        else 
        {
            cerr << "Error!!!! 402! Could not open the file.\n";
            delay();
            welcome();
        }
        return 0;
    }
    int recordOfChallan()
    {
        cout<<"* ----Record of Challan---- *"<<endl;
        cout<<"* *"<<endl;
        cout<<"* Enter your desired Option :- *"<<endl;
        cout<<"* *"<<endl;
        cout<<"* Press 1 to Add a New Challan *"<<endl;
        cout<<"* Press 2 to search for Challan Using registration number *"<<endl;
        cout<<"* Press 3 to search for Challan Using Owner's name *"<<endl;
        cout<<"* Press 4 to search for Challan Using Challan ID *"<<endl;
        cout<<"* *"<<endl;
        cout<<"* Press 0 if you want to go back to home *"<<endl;
        cout<<"* Enter your desired choice ___ *"<<endl;
        cout<<"* *"<<endl;
        cout<<"* *"<<endl;
        cout<<"* *"<<endl;
        cout<<"* *"<<endl;
        int ROCChoice{0};
        cin>>ROCChoice;
        switch (ROCChoice)
        {
            case 0:
                clearConsole();
                welcome();
                break;
            case 1:
                recordOfChallan_1();
                break;
            case 2:
                recordOfChallan_2();
                break;
            case 3:
                recordOfChallan_3();
                break;
            case 4:
                recordOfChallan_4();
                break;
            default:
                cout << "please enter a valid case" << endl;
        }
        return 0;
    }
    int recordOfChallan_1() 
    {
        clearConsole();  
        ofstream fio;    
        string regNumber, ownerName, dateOfChallan, vehicleName, manufacturerName, colour, ChallanId, FineAmt, Status, Violation;
        string filename = "RecordOfChallan.csv";
        string header = "Registration Number,Owner Name,Date of Violation, Violation Type,Vehicle Name,Manufacturer Name,Colour,ChallanId,Fine Amount,Status";

        // Instructions for the user
        cin.ignore();
        cout << "Welcome to the CHALLAN MANAGEMENT portal" << endl;
        cout << "Please enter your vehicle's registration number in the format 'XX-XX-XX-XXXX': " << endl;
        getline(cin, regNumber);
        cout << "Please enter the owner's name (use '_' instead of space between first and last name): " << endl;
        getline(cin, ownerName);
        cout << "Enter the date of registration (format: DD-MM-YYYY): " << endl;
        getline(cin, dateOfChallan);
        cout<< "Enter the violation commited: "<<endl;
        getline(cin, Violation);
        cout << "Enter the vehicle name: " << endl;
        getline(cin, vehicleName);
        cout << "Enter the manufacturer's name: " << endl;
        getline(cin, manufacturerName);
        cout << "Enter the vehicle color: " << endl;
        getline(cin, colour);
        cout<< "Enter the Challan Number :"<<endl;
        getline(cin, ChallanId);
        cout<<"Enter the Fine Amount :"<<endl;
        getline(cin, FineAmt);
        cout<<"Enter Yes if Fine paid. No if not paid :"<<endl;
        getline(cin, Status);

        // Check if the file exists
        if (!fileExists(filename)) {
            // If the file is new, open it in append mode and write the header
            fio.open(filename, ios::app);
            fio << header << endl;
            fio.close();
        }
        if (fileExists(filename) && !fileHasHeader(filename, header)) 
        {
            // Open the file in read and write mode (both input and output)
            ifstream inFile(filename);
            string fileContents;
            string line;

            // Read the entire file contents and store in memory
            while (getline(inFile, line)) 
            {
                fileContents += line + "\n";
            }
            inFile.close();

            // Open the file in write mode to overwrite it with the header
            ofstream outFile(filename);
            outFile << header << endl;  // Write the header

            // Write the previously read contents back into the file
            outFile << fileContents;
            outFile.close();

            cout << "Header added successfully to the existing file." << endl;
        }
        fio.open(filename, ios::app);
        fio << regNumber << "," << ownerName << "," << dateOfChallan << "," << Violation << "," << vehicleName << ","
            << manufacturerName << "," << colour << "," << ChallanId << "," << FineAmt << "," << Status << endl;
        fio.close();
        cout << "Data has been entered successfully!" << endl;
        delay();
        clearConsole();
        recordOfChallan();
        return 0;  
    }
    int recordOfChallan_2()
    {
        clearConsole();  // Clear the console at the start
        string path = "RecordOfChallan.csv";
        ifstream file(path.c_str());  // Open the CSV file

        if (file.is_open()) 
        {
            cout << " Welcome to Challan Management System\n" << endl;
            cout << endl << "Enter the registration number of the vehicle that you are searching for\n" << endl;
            cout << "The Registration Number should be in format 'XX-XX-XX-XXXX'!!" << endl;

            string text;
            cin >> text;  
            bool found = false;  
            string line;
            getline(file, line);
            while (getline(file, line)) 
            {
                stringstream ss(line);
                string regNumber, ownerName, dateOfReg, expiryDate, vehicleName, manufacturerName, colour, ChallanId, FineAmt;
                getline(ss, regNumber, ',');
                getline(ss, ownerName, ',');
                getline(ss, dateOfReg, ',');
                getline(ss, expiryDate, ',');
                getline(ss, vehicleName, ',');
                getline(ss, manufacturerName, ',');
                getline(ss, colour, ',');
                getline(ss, ChallanId, ',');
                getline(ss, FineAmt, ',');

                // Compare the registration number with user input
                if (regNumber == text) 
                {
                    found = true;
                    // If a match is found, display the record
                    cout << "\nThe entered Registration number '" << text << "' has been found successfully in our records.\n";
                    cout << "Registration Number: " << regNumber << endl;
                    cout << "Owner Name: " << ownerName << endl;
                    cout << "Date of Registration: " << dateOfReg << endl;
                    cout << "Expiry Date: " << expiryDate << endl;
                    cout << "Vehicle Name: " << vehicleName << endl;
                    cout << "Manufacturer Name: " << manufacturerName << endl;
                    cout << "Colour: " << colour << endl;
                    cout << "Challan Number: "<< ChallanId <<endl;
                    cout << "Fine Amount: "<< FineAmt << endl;


                    // Allow the user to choose the next action
                    int choice;
                    cout << endl << "Enter 1 to go to the home screen, or press 2 to search for another registration number: ";
                    cin >> choice;
                    if (choice == 1)
                        welcome();
                    else
                        recordOfChallan_2();
                    break;
                }
            }

            // If no match was found
            if (!found) {
                clearConsole();
                cout << "Sorry!!!! Registration number '" << text << "' is not found !!" << endl;
                int choice;
                cout << endl << "Enter 1 to go back to the home screen, or press 2 to search for another registration number: ";
                cin >> choice;
                if (choice == 1)
                    welcome();
                else
                    recordOfChallan_2();
            }

            file.close();  // Close the file after use
        } 
        else 
        {
            cerr << "Error!!!! 402! Could not open the file.\n";
            delay();
            welcome();
        }
        return 0;
    }
    int recordOfChallan_3()
    {
        clearConsole();
        string path = "RecordOfChallan.csv";
        ifstream file(path.c_str());

        if (file.is_open()) 
        {
            cout << " Welcome to Challan Management System\n" << endl;
            cout <<endl<< "Please enter the name of the owner of the vehicle that you are searching for\n"<<endl ;
            cout << "*' If Name contains Lastname then use '_' between first name and last name '*"<<endl;

            string text;
            cin >> text;  
            bool found = false;  
            string line;
            getline(file, line);
            while (getline(file, line)) 
            {
                stringstream ss(line);
                string regNumber, ownerName, dateOfReg, expiryDate, vehicleName, manufacturerName, colour, ChallanId, FineAmt;
                getline(ss, regNumber, ',');
                getline(ss, ownerName, ',');
                getline(ss, dateOfReg, ',');
                getline(ss, expiryDate, ',');
                getline(ss, vehicleName, ',');
                getline(ss, manufacturerName, ',');
                getline(ss, colour, ',');
                getline(ss, ChallanId, ',');
                getline(ss, FineAmt, ',');

                // Compare the registration number with user input
                if (ownerName == text) 
                {
                    found = true;
                    // If a match is found, display the record
                    cout << "\nThe entered Owner's Name '" << text << "' has been found successfully in our records.\n";
                    cout << "Registration Number: " << regNumber << endl;
                    cout << "Owner Name: " << ownerName << endl;
                    cout << "Date of Registration: " << dateOfReg << endl;
                    cout << "Expiry Date: " << expiryDate << endl;
                    cout << "Vehicle Name: " << vehicleName << endl;
                    cout << "Manufacturer Name: " << manufacturerName << endl;
                    cout << "Colour: " << colour << endl;
                    cout << "Challan Number: "<< ChallanId <<endl;
                    cout << "Fine Amount: "<< FineAmt << endl;

                    // Allow the user to choose the next action
                    int choice;
                    cout << endl << "Enter 1 to go to the home screen, or press 2 to search for another Owner's Name: ";
                    cin >> choice;
                    if (choice == 1)
                        welcome();
                    else
                        recordOfChallan_3();
                    break;
                }
            }

            // If no match was found
            if (!found) {
                clearConsole();
                cout << "Sorry!!!! Owner's Name '" << text << "' is not found !!" << endl;
                int choice;
                cout << endl << "Enter 1 to go back to the home screen, or press 2 to search for another Owner's Name: ";
                cin >> choice;
                if (choice == 1)
                    welcome();
                else
                    recordOfChallan_3();
            }

            file.close();  // Close the file after use
        } 
        else 
        {
            cerr << "Error!!!! 402! Could not open the file.\n";
            delay();
            welcome();
        }
        return 0;
    }
    int recordOfChallan_4()
    {
        clearConsole();
        string path = "RecordOfChallan.csv";
        ifstream file(path.c_str());

        if (file.is_open()) 
        {
            cout << " Welcome to Challan Management System\n" << endl;
            cout <<endl<< "Please enter the name of the owner of the vehicle that you are searching for\n"<<endl ;
            cout << "*' If Name contains Lastname then use '_' between first name and last name '*"<<endl;

            string text;
            cin >> text;  
            bool found = false;  
            string line;
            getline(file, line);
            while (getline(file, line)) 
            {
                stringstream ss(line);
                string regNumber, ownerName, dateOfReg, expiryDate, vehicleName, manufacturerName, colour, ChallanId, FineAmt;
                getline(ss, regNumber, ',');
                getline(ss, ownerName, ',');
                getline(ss, dateOfReg, ',');
                getline(ss, expiryDate, ',');
                getline(ss, vehicleName, ',');
                getline(ss, manufacturerName, ',');
                getline(ss, colour, ',');
                getline(ss, ChallanId, ',');
                getline(ss, FineAmt, ',');

                // Compare the registration number with user input
                if (ChallanId == text) 
                {
                    found = true;
                    // If a match is found, display the record
                    cout << "\nThe entered Owner's Name '" << text << "' has been found successfully in our records.\n";
                    cout << "Registration Number: " << regNumber << endl;
                    cout << "Owner Name: " << ownerName << endl;
                    cout << "Date of Registration: " << dateOfReg << endl;
                    cout << "Expiry Date: " << expiryDate << endl;
                    cout << "Vehicle Name: " << vehicleName << endl;
                    cout << "Manufacturer Name: " << manufacturerName << endl;
                    cout << "Colour: " << colour << endl;
                    cout << "Challan Number: "<< ChallanId <<endl;
                    cout << "Fine Amount: "<< FineAmt << endl;

                    // Allow the user to choose the next action
                    int choice;
                    cout << endl << "Enter 1 to go to the home screen, or press 2 to search for another Owner's Name: ";
                    cin >> choice;
                    if (choice == 1)
                        welcome();
                    else
                        recordOfChallan_4();
                    break;
                }
            }

            // If no match was found
            if (!found) {
                clearConsole();
                cout << "Sorry!!!! Owner's Name '" << text << "' is not found !!" << endl;
                int choice;
                cout << endl << "Enter 1 to go back to the home screen, or press 2 to search for another Owner's Name: ";
                cin >> choice;
                if (choice == 1)
                    welcome();
                else
                    recordOfChallan_4();
            }

            file.close();  // Close the file after use
        } 
        else 
        {
            cerr << "Error!!!! 402! Could not open the file.\n";
            delay();
            welcome();
        }
        return 0;
    }
    int trafficContBooth()
    {
        // Traffic Control Booths
        cout<<"* ----Traffic Control Booths---- *"<<endl;
        cout<<"* *"<<endl;
        cout<<"* Enter your desired Option :- *"<<endl;
        cout<<"* *"<<endl;
        cout<<"* 1. Senapati Traffic Control Booth *"<<endl;
        cout<<"* 2. Imphal East Traffic Control Booth *"<<endl;
        cout<<"* 3. Imphal West Traffic Control Booth *"<<endl;
        cout<<"* *"<<endl;
        cout<<"* Press 0 if you want to go back to the home screen *"<<endl;
        cout<<"* Enter your desired choice ___ *"<<endl;
        cout<<"* *"<<endl;
        int TrafficCBChoice{0};
        cin>>TrafficCBChoice;
        switch (TrafficCBChoice)
        {
            case 0:
                clearConsole();
                welcome();
                break;
            case 1:
                trafficContBooth_1();
                break;
            case 2:
                trafficContBooth_2();
                break;
            case 3:
                trafficContBooth_3();
                break;
            default:
                cout<<"Enter a valid choice!!"<<endl;
        }
        return 0;
    }
    int trafficContBooth_1()
    {
        clearConsole();
        traffic_signal_controller();
        for (int i = 0; i < 20; ++i)
        {
            cout<<" Senapati Traffic Control Booth "<<endl;
            cout<<"Vehicles that are going out of the city Vehicles that are coming into the city"<<endl;
            cout<<endl<<" "<<i+1<<" "<<i+5<<endl;
            delay();
            clearConsole();
        }
        trafficContBooth();
        return 0;
    }
    int trafficContBooth_2()
    {
        clearConsole();
        traffic_signal_controller();
        for (int i = 0; i < 20; ++i)
        {
            cout<<" Imphal East Traffic Control Booth "<<endl;
            cout<<"Vehicles that are going out of the city Vehicles that are coming into the city"<<endl;
            cout<<endl<<" "<<i*3+2<<" "<<i*3+4<<endl;
            delay();
            clearConsole();
        }
        trafficContBooth();
        return 0;
    }
    int trafficContBooth_3()
    {
        clearConsole();
        traffic_signal_controller();
        for (int i = 0; i < 10; ++i)
        {
            cout<<" Imphal West Traffic Control Booth "<<endl;
            cout<<"Vehicles that are going out of the city Vehicles that are coming into the city"<<endl;
            cout<<endl<<" "<<i*3+1<<" "<<i*4+3<<endl;
            delay();
            clearConsole();
        }
        trafficContBooth();
        return 0;
    }
    int helpInfo()
    {
        //Helpline Information and nearby hospitals
        cout<<"* ----Helpline Info And Nearby Healthcare Centres---- *"<<endl;
        cout<<"* *"<<endl;
        cout<<"* Enter Your desired Option :- *"<<endl;
        cout<<"* *"<<endl;
        cout<<"* Press 1 to get the helpline numbers *"<<endl;
        cout<<"* Press 2 to get info of the hospitals in Senapati *"<<endl;
        cout<<"* Press 3 to get info of the hospitals in Imphal East *"<<endl;
        cout<<"* Press 4 to get info of the hospitals in Imphal West*"<<endl;
        cout<<"* *"<<endl;
        cout<<"* Press 0 if you want to go back to home *"<<endl;
        cout<<"* Enter your desired choice___ *"<<endl;
        cout<<"* *"<<endl;
        int CChoice{0};
        cin>>CChoice;
        switch (CChoice)
        {
            case 0:
                clearConsole();
                welcome();
                break;
            case 1:
                {
                    clearConsole();
                    string para;
                    ifstream myfile("HelplineNumbers.txt");
                    if (myfile.is_open())
                    {
                        while (getline(myfile, para))
                        {
                            cout<<para<<'\n';
                        }
                        myfile.close();
                    }
                    else
                        cout << "Error!!!! 403!";
                    int ch;
                    cout << endl << "Press 1 if you want to go back to the Home Page" << endl;
                    cin >> ch;
                    if (ch == 1)
                    {
                        clearConsole();
                        welcome();
                    }
                    else
                    {
                        cout << endl << "Please Enter Valid option !!";
                        cout << endl << endl << "Press 1 if you want to go back to the Home Page" << endl;
                        cin >> ch;
                        if (ch == 1)
                        {
                            clearConsole();
                            welcome();
                        }
                    }
                }
                break;
            case 2:
                {
                    clearConsole();
                    string line;
                    ifstream myfile("HSenapati.txt");
                    if (myfile.is_open())
                    {
                        while (getline(myfile, line))
                        {
                            cout << line << '\n';
                        }
                        myfile.close();
                    }
                    else
                        cout << "Error!!!! 403!";
                    int ch;
                    cout << endl << "Press 1 if you want to go back to the Home Page" << endl;
                    cin >> ch;
                    if (ch == 1)
                    {
                        clearConsole();
                        welcome();
                    }
                    else
                    {
                        cout << endl << "Please Enter Valid option !!";
                        cout << endl << endl << "Press 1 if you want to go back to the Home Page" << endl;
                        cin >> ch;
                        if (ch == 1)
                        {
                            clearConsole();
                            welcome();
                        }
                    }
                }
                break;
            case 3:
                {
                    clearConsole();
                    string line;
                    ifstream myfile("HEast.txt");
                    if (myfile.is_open())
                    {
                        while (getline(myfile, line))
                        {
                            cout<<line<<'\n';
                        }
                        myfile.close();
                    }
                    else
                        cout << "Error!!!! 403!";
                    int ch;
                    cout << endl << "Press 1 if you want to go back to the Home Page" << endl;
                    cin >> ch;
                    if (ch == 1)
                    {
                        clearConsole();
                        welcome();
                    }
                    else
                    {
                        cout << endl << "Please Enter Valid option !!";
                        cout << endl << endl << "Press 1 if you want to go back to the Home Page" << endl;
                        cin >> ch;
                        if (ch == 1)
                        {
                            clearConsole();
                            welcome();
                        }
                    }
                    break;
                }
            case 4:
                {
                    clearConsole();
                    string line;
                    ifstream myfile("HWest.txt");
                    if (myfile.is_open())
                    {
                        while (getline(myfile, line))
                        {
                            cout<<line<<'\n';
                        }
                        myfile.close();
                    }
                    else
                        cout << "Error!!!! 404!";
                    int ch;
                    cout << endl << "Press 1 if you want to go back to the Home Page" << endl;
                    cin >> ch;
                    if (ch == 1)
                    {
                        clearConsole();
                        welcome();
                    }
                    else
                    {
                        cout << endl << "Please Enter Valid option !!";
                        cout << endl << endl << "Press 1 if you want to go back to the Home Page" << endl;
                        cin >> ch;
                        if (ch == 1)
                        {
                            clearConsole();
                            welcome();
                        }
                    }
                    break;
                }
            default:
                cout<<"Enter a valid choice!!"<<endl;
        }
        return 0;
    }
    int clearConsole()
    {
        //cout<<"\033[2J\033[1;1H";
        system("cls");
    }
    void traffic_signal_controller() 
    {
        while (true) 
        {
            char mode;
            cout << "Choose mode: 'A' for Automatic, 'M' for Manual, or 'Q' to Quit:" << endl;
            cin >> mode;
            mode = toupper(mode);  // Convert to uppercase

            if (mode == 'A') {
                cout << "Automatic mode activated" << endl;
                automatic_traffic_signal();  // Call automatic mode
            } 
            else if (mode == 'M') {
                cout << "Manual mode activated" << endl;
                manual_traffic_signal();  // Call manual mode
            } 
            else if (mode == 'Q') {
                cout << "Exiting program..." << endl;
                break;
            } 
            else {
                cout << "Invalid mode, please choose again." << endl;
            }
        }
    }
    void automatic_traffic_signal() {
        while (true) {
            // Nort Green, East,South,West Red
            display_signal("North", "Green");
            display_signal("South", "Red");
            display_signal("East", "Red");
            display_signal("West", "Red");
            sleep(10);   // Green for 10 seconds
            cout<<endl<<endl;

            // Yellow for North-East
            display_signal("North", "Yellow");
            display_signal("South", "Red");
            display_signal("East", "Red");
            display_signal("West", "Red");
            sleep(3);    // Yellow for 3 seconds
            cout<<endl<<endl;
            
            // East Green, North-South,West Red
            display_signal("North", "Red");
            display_signal("South", "Red");
            display_signal("East", "Green");
            display_signal("West", "Red");
            sleep(10);   // Green for 10 seconds
            cout<<endl<<endl;
            
            // Yellow for South-East
            display_signal("North", "Red");
            display_signal("South", "Red");
            display_signal("East", "Yellow");
            display_signal("West", "Red");
            sleep(3);    // Yellow for 3 seconds
            cout<<endl<<endl;
            
            // South Green , North,East,West Red
            display_signal("North", "Red");
            display_signal("South", "Green");
            display_signal("East", "Red");
            display_signal("West", "Red");
            sleep(10);
            cout<<endl<<endl;
            
            // Yellow for South-West
            display_signal("North", "Red");
            display_signal("South", "Yellow");
            display_signal("East", "Red");
            display_signal("West", "Red");
            sleep(3);
            cout<<endl<<endl;
            
            // West Green, North,South,East Red
            display_signal("North", "Red");
            display_signal("South", "Red");
            display_signal("East", "Red");
            display_signal("West", "Green");
            sleep(10);
            cout<<endl<<endl;
            
            // Yellow for North-West
            display_signal("North", "Red");
            display_signal("South", "Red");
            display_signal("East", "Red");
            display_signal("West", "Yellow");
            sleep(3);
            cout<<endl<<endl;
        }
    }
    void manual_traffic_signal() 
    {
        while (true) {
            char input;
            cout << "Enter 'N' for North Green, 'E' for East Green, 'S' for South Green, 'W' for West Green or 'X' to Exit:" << endl;
            cin >> input;
            input = toupper(input);   // Convert to uppercase

            if (input == 'N') {
                display_signal("North", "Green");
                display_signal("South", "Red");
                display_signal("East", "Red");
                display_signal("West", "Red");
                sleep(5);
                display_signal("North", "Yellow");
                display_signal("South", "Red");
                display_signal("East", "Red");
                display_signal("West", "Red");
            } 
            else if (input == 'E') {
                display_signal("North", "Red");
                display_signal("South", "Red");
                display_signal("East", "Green");
                display_signal("West", "Red");
                sleep(5);
                display_signal("North", "Red");
                display_signal("South", "Red");
                display_signal("East", "Yellow");
                display_signal("West", "Red");
            }
            else if(input == 'S'){
                display_signal("North", "Red");
                display_signal("South", "Green");
                display_signal("East", "Red");
                display_signal("West", "Red");
                sleep(5);
                display_signal("North", "Red");
                display_signal("South", "Yellow");
                display_signal("East", "Red");
                display_signal("West", "Red");
            }
            else if(input == 'W'){
                display_signal("North", "Red");
                display_signal("South", "Red");
                display_signal("East", "Red");
                display_signal("West", "Green");
                sleep(5);
                display_signal("North", "Red");
                display_signal("South", "Red");
                display_signal("East", "Red");
                display_signal("West", "Yellow");
            }
            else if (input == 'X') {
                cout << "Exiting manual mode..." << endl;
                break;
            } 
            else {
                cout << "Invalid input, please try again." << endl;
            }
            cout<<endl<<endl;
        }
    }
    void display_signal(const string& direction, const string& light) 
    {
        cout << direction << " Light: " << light << endl;
    }
    bool fileExists(const string& filename) 
    {
        struct stat buffer;
        return (stat(filename.c_str(), &buffer) == 0);
    }
    // Function to check if the first line of the file is a header
    bool fileHasHeader(const string& filename, const string& header) 
    {
        ifstream file(filename);
        string firstLine;

        if (file.is_open()) {
            getline(file, firstLine);  // Read the first line
            file.close();
            return (firstLine == header);  // Check if the first line matches the header
        }

        return false;
    }
};

int main()
{
    TrafficManagementSystem ob1;
    ob1.welcome();
    return 0;
}