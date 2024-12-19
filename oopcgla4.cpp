#include <iostream>
#include <fstream>
using namespace std;
class employee // name of employee class
{
    char name[20]; // variable declaration
    int emp_id;
    float salary;

public:
    void accept()
    {
        cin >> name;
        cin >> emp_id;
        cin >> salary;
    }
    void display()
    {
        cout << "\n"
             << name << "\t" << emp_id << "\t" << salary;
    }
};
int main()
{
    cout<<"Name : Rohan Jagdish Sali , AI&DS , Batch : B2 , Roll no.: 23224\n";
    employee o[5];
    fstream f;
    int i, n;
    f.open("input.txt"); // create employee
    cout << "\nHow many employee information wanted to store : ";
    cin >> n;

    cout << "\nEnter information of employees (Enter name, emp_id, salary)...";
    for (i = 0; i < n; i++)
    {
        cout << "\nEnter information of employee " << i+1 << " : ";
        o[i].accept();                        // accept input from user
        f.write((char *)&o[i], sizeof(o[i])); // write object in employee
    }
    f.close();
    f.open("input.txt", ios::in);
    cout << "\nInformation of employee is as follows ...";
    for (i = 0; i < n; i++)
    {
        f.read((char *)&o[i], sizeof(o[i])); // read data from employee
        o[i].display();
    }
    f.close();
    return 0;
}