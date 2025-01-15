#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct hospital
{
    int id;
    int age;
    int roomNumber;
    string name;
    string disease;
};

const int maxPatients = 10;
hospital patients[maxPatients];
int patientCount = 0;

void loadPatientsData()
{
    ifstream mypatients("hospital.txt");
    if (mypatients.is_open())
    {
        mypatients >> patientCount;
        mypatients.ignore();
        for (int i = 0; i < patientCount; i++)
        {
            mypatients >> patients[i].id;
            mypatients.ignore();
            getline(mypatients, patients[i].name);
            mypatients >> patients[i].age;
            mypatients.ignore();
            getline(mypatients, patients[i].disease);
            mypatients >> patients[i].roomNumber;
        }
    }
    else
    {
        cout << "Error Loading Data";
    }
    mypatients.close();
}

bool UniqueId(int userPatientId)
{
    for (int i = 0; i < patientCount; i++)
    {
        if (userPatientId == patients[i].id)
        {
            return false;
        }
    }
    return true;
}

void AddpatientData()
{
    cout <<endl;
    cout <<endl;
    cout << "---  Hospital Management System  ---" << endl;
    
    if (patientCount >= maxPatients)
    {
        cout <<endl;
        cout << "Database is full" << endl;
    }
    else
    {
        hospital patient;
        cout << endl;
        cout << "Enter ID : ";
        cin >> patient.id;
        if (UniqueId(patient.id) == false)
        {
            cout <<endl;
            cout << "This ID Already Exist";
            return;
        }
        cout << "Enter Name : ";
        cin.ignore();
        getline(cin, patient.name);
        cout << "Enter Age : ";
        cin >> patient.age;
        cout << "Enter Disease : ";
        cin.ignore();
        getline(cin, patient.disease);
        cout << "Enter Room Number : ";
        cin >> patient.roomNumber;

        patients[patientCount] = patient;
        patientCount++;
    }
}

void Patientsearch()
{
    int id;
    cout << "Enter Patient ID : ";
    cin >> id;

    for (int i = 0; i < patientCount; i++)
    {
        if (patients[i].id == id)
        {
            cout << endl;
            cout << "Patient Found" << endl;
            cout << endl;
            cout << "Patient ID : " << patients[i].id << endl;
            cout << "Patient Name : " << patients[i].name << endl;
            cout << "Patient Age : " << patients[i].age << endl;
            cout << "Patient Disease : " << patients[i].disease << endl;
            cout << "Patient Room Number : " << patients[i].roomNumber << endl;
            cout << endl;
        }
    }
}

void DisplayPatientData()
{
    for (int i = 0; i < patientCount; i++)
    {
        cout << endl;
        cout << "Patient ID : " << patients[i].id << endl;
        cout << "Patient Name : " << patients[i].name << endl;
        cout << "Patient Age : " << patients[i].age << endl;
        cout << "Patient Disease : " << patients[i].disease << endl;
        cout << "Patient Room Number : " << patients[i].roomNumber << endl;
        cout << endl;
    }
}

void savePatientsdata()
{
    ofstream mypatient("hospital.txt");
    if (mypatient.is_open())
    {
        cout << endl;
        cout << "Saving Patient's Data";
        mypatient << patientCount << endl;
        
        for (int i = 0; i < patientCount; i++)
        {
            mypatient << patients[i].id << endl;
            mypatient << patients[i].name << endl;
            mypatient << patients[i].age << endl;
            mypatient << patients[i].disease << endl;
            mypatient << patients[i].roomNumber << endl;
        }
    }
    else
    {
        cout << "Error Saving Data";
    }
    mypatient.close();
}


int main()
{
    int choice;
    do
    {
        cout <<endl;
        cout <<endl;
        cout << "---  Chose Option  ---" << endl;
        cout << endl;
        cout << "1. Add new patients" << endl;
        cout << "2. Search patient by ID" << endl;
        cout << "3. Display details of all patients" << endl;
        cout << "4. Exit"  << endl;
        cout << endl;
        
        cout << "Enter you choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            AddpatientData();
            break;
        case 2:
            Patientsearch();
            break;
        case 3:
            DisplayPatientData();
            break;
        case 4:
            cout << "Exiting ...";
            break;

        default:
            cout << "invalid option";
            break;
        }

    } while (choice != 4);


    loadPatientsData();
    savePatientsdata();
    return 0;
}