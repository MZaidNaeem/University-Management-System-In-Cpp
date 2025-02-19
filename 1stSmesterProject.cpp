
//////////////////////////////////////////////////       University managment system      ///////////////////////////////////////////////////////////////

#include <iostream>

#include <cmath>

#include <string>

#include <iomanip>

#include <fstream>

using namespace std;

///////////////////////////////////////////////////////////// Function prototypes/////////////////////////////////////////////////////////////////

// Passing total vairalbe using pointer in different funtion
void std_compiler_read(int count, string name[], int roll_no[], string depart[], string contact[], string gmail[], int *total);
void std_file_read(int count, string name[], int roll_no[], string depart[], string contact[], string gmail[], int *total);
void std_file_write(string name[], int roll_no[], string depart[], string contact[], string gmail[], int *total);
void admin_portal(string name[], int roll_no[], string depart[], string contact[], string gmail[], int *total);
bool admin_login(string *username, string *password);
int input_failure(int number);
void enroll_std(string name[], int roll_no[], string depart[], string contact[], string gmail[], int *total);
void show_std(string name[], int roll_no[], string depart[], string contact[], string gmail[], int *total);
void search_std(int roll_no[], string name[], string depart[], string contact[], string gmail[], int *total);
void update_std(string name[], int roll_no[], string depart[], string contact[], string gmail[], int *total);
void delete_std(string name[], int roll_no[], string depart[], string contact[], string gmail[], int *total);
void teacher_portal(int roll_no[], string name[], int pf_marks[], int ict_marks[], int physics[], int eng_marks[], int isl[], int total_marks[], float cgpa[], int *total);
bool teacher_login(string *username, string password);
string subject_selector(string username);
void selector(string username, int roll_no[], string name[], int marks[], int *total);
void enter_marks(int roll_no[], string name[], int marks[], int *total);
void search_marks(int roll_no[], string name[], int marks[], int *total);
void show_marks(int roll_no[], string name[], int marks[], int *total);
void delete_marks(int roll_no[], string name[], int marks[], int *total);
void student_portal(string name[], int roll_no[], string depart[], string contact[], string gmail[], int pf_marks[], int ict_marks[], int physics[], int eng_marks[], int isl[], int total_marks[], float cgpa[], int *total);
void personal_detail(string name, int roll_no, string depart, string contact, string gmail);
void result_card(string name, int roll_no, int pf_marks, int ict_marks, int physics, int eng_marks, int isl, float cgpa);
float average_calculator(int pf_marks, int ict_marks, int physics, int eng_marks, int isl);
float cgpa_calculator(int pf_marks, int ict_marks, int physics, int eng_marks, int isl);
float subject_gpa_calculator(int marks);
void file_result_write(string name, int roll_no, int pf_marks, int ict_marks, int physics, int eng_marks, int isl, int average, float cgpa);

///////////////////////////////////////////////////////////   Main function /////////////////////////////////////////////////////////////////////

int main()
{
    // declaring different variables that we will deal with in this project
    string name[100], depart[100], contact[100], gmail[100];
    int roll_no[100];
    int pf_marks[100], ict_marks[100], physics[100], eng_marks[100], isl[100], total_marks[100];
    float cgpa[100];
    int total = 0;
    int num;
    bool checker = true;

    // loop to go to different portals
    while (checker)
    {
        // Displaying options for the user
        cout << setw(20) << "" << setw(40) << left << "Press 1 to open administration portal" << endl;
        cout << setw(20) << "" << setw(40) << left << "Press 2 to open the teacher portal" << endl;
        cout << setw(20) << "" << setw(40) << left << "Press 3 to open the student portal" << endl;
        cout << setw(20) << "" << setw(40) << left << "Press 4 to exit the program" << endl;

        // Asking for user input
        cout << "Enter the number here: ";

        cin >> num;

        switch (num)
        {

        case 1:
            cout << "\nYou are redirecting to admin portal\n";
            admin_portal(name, roll_no, depart, contact, gmail, &total);
            break;
        case 2:
            cout << "\nYou are redirecting to teacher portal\n";
            teacher_portal(roll_no, name, pf_marks, ict_marks, physics, eng_marks, isl, total_marks, cgpa, &total);
            break;
        case 3:
            cout << "\nYou are redirecting to student portal\n";
            student_portal(name, roll_no, depart, contact, gmail, pf_marks, ict_marks, physics, eng_marks, isl, total_marks, cgpa, &total);
            break;
        case 4:
            checker = false;

            cout << "\nExiting...\n";
            break;
        default:
            cout << "\nInput Failure: Please input the correct number\n";
            break;
        }
    }

    return 0;
}

////////////////////////////////////////////////////////Function definitions///////////////////////////////////////////////////////////////////

void admin_portal(string name[], int roll_no[], string depart[], string contact[], string gmail[], int *total)
{
    string username, password;
    // calling the funciton of admin login for user authentication
    bool checker = admin_login(&username, &password);
    if (checker == true)
    {
        int num;
        bool checker = true;
        while (checker)
        {
            cout << setw(40) << "\nPress 1 to enter data of students:" << left << endl;
            cout << setw(40) << "Press 2 to show data of students:" << left << endl;
            cout << setw(42) << "Press 3 to search data of students:" << left << endl;
            cout << setw(44) << "Press 4 to update data of students:" << left << endl;
            cout << setw(42) << "Press 5 to delete data of students:" << left << endl;
            cout << setw(31) << "Press 6 to go back:" << endl;
            cout << setw(17) << "Enter the value: ";
            cin >> num;
            switch (num)
            {
            case 1:
                enroll_std(name, roll_no, depart, contact, gmail, total);
                break;
            case 2:
                show_std(name, roll_no, depart, contact, gmail, total);
                break;
            case 3:
                search_std(roll_no, name, depart, contact, gmail, total);
                break;
            case 4:
                update_std(name, roll_no, depart, contact, gmail, total);
                break;
            case 5:
                delete_std(name, roll_no, depart, contact, gmail, total);
                break;
            case 6:
                checker = false;
                break;
            default:
                cout << "Please enter right number: ";
                break;
            }
        }
    }
}
// functiono to ensure admin authentication
bool admin_login(string *user_name, string *pass_word)
{
    bool checker = true;
    int x;
    while (checker)
    {
        cout << "\nEnter the username: ";
        cin >> *user_name;
        cout << "Enter the password: ";
        cin >> *pass_word;
        if (*user_name == "faculty" && *pass_word == "cui")
        {
            cout << setw(20) << "" << "You login successfully";
            checker = false;
            return true;
        }
        else
        {
            cout << setw(20) << "" << "You input incorrect username or password";
            cout << "\nPress 1 to re_enter username:" << endl;
            cout << "Press 2 to go back:" << endl;
            cout << "Enter the number: ";
            cin >> x;
            if (x == 2)
            {
                break;
            }
        }
    }
    return false;
}

// funcion to add student from complier or file by administration
void enroll_std(string name[], int roll_no[], string depart[], string contact[], string gmail[], int *total)
{
    int count = 0;
    char path;
    cout << "\nHow many students you want to enroll: ";
    cin >> count;
    if (count == 0)
    {
        cout << "You do not want to enter data of students..\n";
    }
    else
    {
        cout << "Where you want to read from f for file/ c for compiler: ";
        cin >> path;
        if (path == 'c')
        {
            // calling funciton to read from compiler
            std_compiler_read(count, name, roll_no, depart, contact, gmail, total);
        }
        else
        {
            // calling funciton to read from file
            std_file_read(count, name, roll_no, depart, contact, gmail, total);
        }
        std_file_write(name, roll_no, depart, contact, gmail, total);
    }
}

// function to read students from file
void std_file_read(int count, string name[], int roll_no[], string depart[], string contact[], string gmail[], int *total)
{
    ifstream input("input.txt");
    if (!input)
    {
        cout << setw(20) << "" << "There is an issue in your input file" << endl;
        return;
    }

    for (int i = *total; i < *total + count; i++)
    {
        getline(input, name[i]);
        input >> roll_no[i];
        input.ignore();
        getline(input, depart[i]);
        getline(input, contact[i]);
        getline(input, gmail[i]);
        if (!input)
        {
            cout << "Error reading data for student " << i + 1 << endl;
            return;
        }
    }
    *total += count;
}

// function to read students from compiler
void std_compiler_read(int count, string name[], int roll_no[], string depart[], string contact[], string gmail[], int *total)
{
    for (int i = *total; i < *total + count; i++)
    {
        cout << setw(20) << "" << "Enter data of Student no " << i + 1 << endl;
        cout << setw(20) << "" << "Enter the name: ";
        cin.ignore();
        getline(cin, name[i]);
        cout << setw(20) << "" << "Enter the roll no: ";
        cin >> roll_no[i];
        cout << setw(20) << "" << "Enter the depart: ";
        cin >> depart[i];
        cout << setw(20) << "" << "Enter the contact no: ";
        cin >> contact[i];
        cout << setw(20) << "" << "Enter the gmail: ";
        cin >> gmail[i];
    }
    *total += count;
}
// function to write students in file
void std_file_write(string name[], int roll_no[], string depart[], string contact[], string gmail[], int *total)
{
    ofstream out("students.txt");
    if (!out)
    {
        cout << "\nUnable to open file\n"
             << endl;
        return;
    }
    else
    {
        if (*total == 0)
        {
            cout << "\nThere is no data of student..\n";
            out << "There is no data of student..";
        }
        else
        {
            // Print headers
            out << setw(18) << left << "Student No" << setw(30) << left << "Name" << setw(15) << left << "Roll No" << setw(15) << left << "Dept" << setw(20) << left << "Contact" << setw(25) << left << "Gmail" << endl;
            out << string(105, '-') << endl; // Separator line

            // Print student data
            for (int i = 0; i < *total; i++)
            {
                out << setw(18) << left << i + 1 << setw(30) << left << name[i] << setw(15) << left << roll_no[i] << setw(15) << left << depart[i] << setw(20) << left << contact[i] << setw(25) << left << gmail[i] << endl;
            }
            out.close();
        }
    }
}

// function to show students on compiler
void show_std(string name[], int roll_no[], string depart[], string contact[], string gmail[], int *total)
{

    if (*total == 0)
    {
        cout << "\n\n\n\nThere is no data of student..";
    }
    else
    {

        // Print headers
        cout << endl;
        cout << setw(18) << left << "Student No" << setw(30) << left << "Name" << setw(15) << left << "Roll No" << setw(15) << left << "Dept" << setw(20) << left << "Contact" << setw(25) << left << "Gmail" << endl;
        cout << string(105, '-') << endl; // Separator line
        // Print student data
        for (int i = 0; i < *total; i++)
        {
            cout << setw(18) << left << i + 1 << setw(30) << left << name[i] << setw(15) << left << roll_no[i] << setw(15) << left << depart[i] << setw(20) << left << contact[i] << setw(25) << left << gmail[i] << endl;
        }
    }
}
// function to search student from the array
void search_std(int roll_no[], string name[], string depart[], string contact[], string gmail[], int *total)
{
    if (*total == 0)
    {
        cout << "No student data available." << endl;
    }
    else
    {
        int searcher;
        cout << setw(20) << "" << "Enter Roll No to search: ";
        cin >> searcher;
        bool found = false;
        for (int i = 0; i < *total; i++)
        {
            if (searcher == roll_no[i])
            {
                cout << endl;
                cout << setw(10) << left << "Name:" << setw(20) << right << name[i] << endl;
                cout << setw(10) << left << "Roll No:" << setw(20) << right << roll_no[i] << endl;
                cout << setw(10) << left << "Depart:" << setw(20) << right << depart[i] << endl;
                cout << setw(10) << left << "Contact:" << setw(20) << right << contact[i] << endl;
                cout << setw(10) << left << "Gmail:" << setw(20) << right << gmail[i] << endl;
                cout << setw(30) << setfill('-') << "" << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << endl;
            cout << setw(20) << "" << "!Student not found." << endl;
        }
    }
}

// function to update the data of student
void update_std(string name[], int roll_no[], string depart[], string contact[], string gmail[], int *total)
{
    if (*total == 0)
    {
        cout << "No student data available." << endl;
    }
    else
    {
        int searcher;
        cout << "\n\tEnter Roll No to search: ";
        cin >> searcher;
        bool found = false;
        for (int i = 0; i < *total; i++)
        {
            if (searcher == roll_no[i])
            {
                cout << setw(20) << left << "Enter data of Student no" << setw(10) << right << i + 1 << endl;
                cout << "\n\tEnter the name: " << endl;
                cin.ignore();
                getline(cin, name[i]);
                cout << "\n\tEnter the roll no: " << endl;
                cin >> roll_no[i];
                cout << "\n\tEnter the depart: " << endl;
                cin >> depart[i];
                cout << "\n\tEnter the contact no: " << endl;
                cin >> contact[i];
                cout << "\n\tEnter the gmail: " << endl;
                cin >> gmail[i];
                std_file_write(name, roll_no, depart, contact, gmail, total);
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "\n\nStudent not found.\n"
                 << endl;
        }
    }
}
// function to delete the data of student
void delete_std(string name[], int roll_no[], string depart[], string contact[], string gmail[], int *total)
{
    if (total == 0)
    {
        cout << "\n\nNo student data available.\n"
             << endl;
    }
    else
    {
        int choice;
        cout << setw(20) << "" << "Press 1 to delete all records" << endl;
        cout << setw(20) << "" << "Press 2 to delete a specific record" << endl;
        cout << setw(20) << "" << "Enter the number: ";
        cin >> choice;
        if (choice == 1)
        {
            *total = 0;
            std_file_write(name, roll_no, depart, contact, gmail, total);
            cout << "\n\tAll student records deleted." << endl;
        }
        else if (choice == 2)
        {
            int roll;
            cout << "\n\tEnter Roll No to delete: ";
            cin >> roll;
            bool found = false;
            for (int i = 0; i < *total; i++)
            {
                if (roll_no[i] == roll)
                {
                    for (int j = i; j < *total - 1; j++)
                    {
                        name[j] = name[j + 1];
                        roll_no[j] = roll_no[j + 1];
                        depart[j] = depart[j + 1];
                        contact[j] = contact[j + 1];
                        gmail[j] = gmail[j + 1];
                    }

                    (*total)--;
                    found = true;
                    break;
                }
            }
            if (found)
            {
                std_file_write(name, roll_no, depart, contact, gmail, total);
                cout << "\n\tStudent record deleted." << endl;
            }
            else
            {
                cout << "\n\tStudent not found." << endl;
            }
        }
        else
        {
            cout << "\n\tInvalid choice. Please enter 1 or 2." << endl;
        }
    }
}

// Portal for the teacher
void teacher_portal(int roll_no[], string name[], int pf_marks[], int ict_marks[], int physics[], int eng_marks[], int isl[], int total_marks[], float cgpa[], int *total)
{
    string username, password;
    bool login = teacher_login(&username, password);
    while (login)
    {
        string subject = subject_selector(username);
        if (subject == "pf")
        {
            selector(username, roll_no, name, pf_marks, total);
            login = false;
        }
        else if (subject == "ict")
        {
            selector(username, roll_no, name, ict_marks, total);
            login = false;
        }
        else if (subject == "eng")
        {
            selector(username, roll_no, name, eng_marks, total);
            login = false;
        }
        else if (subject == "isl")
        {
            selector(username, roll_no, name, isl, total);
            login = false;
        }
        else if (subject == "phy")
        {
            selector(username, roll_no, name, physics, total);
            login = false;
        }
    }
}

// bool return type function for teacher authentication
bool teacher_login(string *username, string password)
{
    bool checker = true;
    int x;
    while (checker)
    {
        cout << "Enter the username: " << endl;
        cin >> *username;
        cout << "Enter the password: " << endl;
        cin >> password;
        if ((*username == "aksam" || *username == "junaid" || *username == "ayesha" || *username == "zohaib" || *username == "marukh") && password == "cui")
        {
            cout << setw(20) << "" << "You login successfully" << endl;
            checker = false;
            return true;
        }
        else
        {
            cout << setw(20) << "" << "You input incorrect username or password";
            cout << "Press 1 to reenter username:" << endl;
            cout << "Press 2 to go back:" << endl;
            cin >> x;
            if (x == 2)
            {
                break;
            }
        }
    }
}

// string function to select user
string subject_selector(string username)
{
    if (username == "aksam")
    {
        return "pf";
    }
    else if (username == "junaid")
    {
        return "ict";
    }
    else if (username == "ayesha")
    {
        return "eng";
    }
    else if (username == "zohaib")
    {
        return "isl";
    }
    else if (username == "marukh")
    {
        return "phy";
    }
}

// void returntype function for teacher to manage the record
void selector(string username, int roll_no[], string name[], int marks[], int *total)
{
    cout << "\nHello Professor " << username << endl;
    bool check = true;
    while (check)
    {
        int a;
        cout << setw(20) << "" << "Press 1 to enter the marks of student:" << endl;
        cout << setw(20) << "" << "Press 2 to search the marks of specific student:" << endl;
        cout << setw(20) << "" << "Press 3 to show the marks of students:" << endl;
        cout << setw(20) << "" << "Press 4 to delete the marks of student:" << endl;
        cout << setw(20) << "" << "Press 5 to go back" << endl;
        cout << setw(15) << right << "Enter the number: " << endl;
        cin >> a;
        switch (a)
        {
        case 1:
            enter_marks(roll_no, name, marks, total);
            break;
        case 2:
            search_marks(roll_no, name, marks, total);
            break;
        case 3:
            show_marks(roll_no, name, marks, total);
            break;
        case 4:
            delete_marks(roll_no, name, marks, total);
            break;
        case 5:
            check = false;
            break;
        default:
            cout << endl;
            cout << setw(20) << "" << "Please enter the correct number";
            break;
        }
    }
    return;
}

// void returntype function to enter marks of the students
void enter_marks(int roll_no[], string name[], int marks[], int *total)
{
    int student_roll_no, control;
    cout << "\nEnter the roll no of student: ";
    cin >> student_roll_no;
    bool check = true;
    bool found = false;
    while (check)
    {
        if (*total == 0)
        {
            cout << "There is no studnet data in your database";
        }
        else
        {
            for (int finder = 0; finder < *total; finder++)
            {
                if (roll_no[finder] == student_roll_no)
                {
                    cout << "\nEnter the marks of that student ( " << name[finder] << " )  : ";
                    cin >> marks[finder];
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                cout << "\nThere is no student of such roll no";
            }
        }
        cout << "\nPress 1 to enter marks of another student: ";
        cout << "\nPress 2 to go back: ";
        cin >> control;
        switch (control)
        {
        case 2:
            check = false;
            break;
        default:
            cout << "Input failure";
        }
        return;
    }
}

// void returntype function shows marks of all student to respected teacher
void show_marks(int roll_no[], string name[], int marks[], int *total)
{
    if (*total == 0)
    {
        cout << "\nThere no student data in database";
    }
    else
    {

        // Print headers
        cout << setw(18) << left << "Student No" << setw(30) << left << "Name" << setw(15) << left << "Roll No" << setw(15) << left << "Marks" << endl;
        cout << string(80, '-') << endl; // Separator line

        // Print student data
        for (int i = 0; i < *total; i++)
        {
            cout << setw(18) << left << i + 1 << setw(30) << left << name[i] << setw(15) << left << roll_no[i] << setw(15) << left << marks[i] << endl;
        }
    }
}

// void return function to search student marks by teacher
void search_marks(int roll_no[], string name[], int marks[], int *total)
{
    int student_roll_no;
    bool found = false;
    cout << "\nEnter the roll no of the studnent: ";
    cin >> student_roll_no;
    if (*total == 0)
    {
        cout << "there is no student data availabel.";
    }
    else
    {
        for (int i = 0; i < *total; i++)
        {
            if (roll_no[i] == student_roll_no)
            {
                cout << setw(18) << left << "Student No" << setw(30) << left << "Name" << setw(15) << left << "Roll No" << setw(15) << left << "Marks" << endl;
                cout << string(80, '-') << endl; // Separator line

                // Print student data
                for (int i = 0; i < *total; i++)
                {
                    cout << setw(18) << left << i + 1 << setw(30) << left << name[i] << setw(15) << left << roll_no[i] << setw(15) << left << marks[i] << endl;
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                cout << "No student of this roll no found";
            }
        }
    }
}

// void return type function to delete the student marks
void delete_marks(int roll_no[], string name[], int marks[], int *total)
{
    int student_roll_no;
    cout << "\nEnter the roll of student whose marks you want to delete";
    cin >> student_roll_no;
    bool found = false;
    if (*total == 0)
    {
        cout << "There is no student data available";
    }
    else
    {
        for (int i = 0; i < *total; i++)
        {
            if (roll_no[i] == student_roll_no)
            {
                marks[i] = 0;
                found = true;
                break;
            }
        }
        if (found == false)
        {
            cout << "No student of this roll no found";
        }
    }
}

// function for controlling student portal
void student_portal(string name[], int roll_no[], string depart[], string contact[], string gmail[], int pf_marks[], int ict_marks[], int physics[], int eng_marks[], int isl[], int total_marks[], float cgpa[], int *total)
{
    int student_roll_no;
    int selector;
    cout << "\nPlease enter your roll number : ";
    cin >> student_roll_no;
    for (int i = 0; i < *total; i++)
    {
        if (student_roll_no == roll_no[i])
        {
            cout << setw(20) << "" << "Press 1 to see your personal details." << endl;
            cout << setw(20) << "" << "Press 2 to see your result card. " << endl;
            cout << setw(20) << "" << "Press 3 to go back" << endl;
            cout << setw(20) << "" << "Enter the number here" << endl;
            cin >> selector;
            switch (selector)
            {
            case 1:
                personal_detail(name[i], roll_no[i], depart[i], contact[i], gmail[i]);
                break;
            case 2:
                result_card(name[i], roll_no[i], pf_marks[i], ict_marks[i], physics[i], eng_marks[i], isl[i], cgpa[i]);
                break;
            default:
                cout << "Input failure";
                break;
            }
        }
        else
        {
            cout << "Our system is unable to find any student with that roll number";
        }
    }
}

// function to show personal details of student
void personal_detail(string name, int roll_no, string depart, string contact, string gmail)
{
    cout << endl;
    cout << setw(10) << left << "Name:" << setw(20) << right << name << endl;
    cout << setw(10) << left << "Roll No:" << setw(20) << right << roll_no << endl;
    cout << setw(10) << left << "Depart:" << setw(20) << right << depart << endl;
    cout << setw(10) << left << "Contact:" << setw(20) << right << contact << endl;
    cout << setw(10) << left << "Gmail:" << setw(20) << right << gmail << endl;
    cout << setw(30) << setfill('-') << "" << endl;
}

// function to show  result card  on console
void result_card(string name, int roll_no, int pf_marks, int ict_marks, int physics, int eng_marks, int isl, float cgpa)
{
    float average = average_calculator(pf_marks, ict_marks, physics, eng_marks, isl);
    cgpa = cgpa_calculator(pf_marks, ict_marks, physics, eng_marks, isl);
    cout << "\n======================== Result Card ========================\n";
    cout << setfill(' ') << left << setw(20) << "Name:" << right << setw(30) << name << endl;
    cout << setfill(' ') << left << setw(20) << "Roll No:" << right << setw(30) << roll_no << endl;
    cout << setfill(' ') << left << setw(20) << "PF Marks:" << right << setw(30) << pf_marks << endl;
    cout << setfill(' ') << left << setw(20) << "ICT Marks:" << right << setw(30) << ict_marks << endl;
    cout << setfill(' ') << left << setw(20) << "Physics Marks:" << right << setw(30) << physics << endl;
    cout << setfill(' ') << left << setw(20) << "English Marks:" << right << setw(30) << eng_marks << endl;
    cout << setfill(' ') << left << setw(20) << "Islamiyat Marks:" << right << setw(30) << isl << endl;
    cout << setfill(' ') << left << setw(20) << "Average Marks:" << right << setw(30) << average << endl;
    cout << setfill(' ') << left << setw(20) << "CGPA:" << right << setw(30) << cgpa << endl;
    cout << "=============================================================\n";
    cout << "Your result card is also provide in the file name result.txt\n";
    cout << "=============================================================\n";
    file_result_write(name, roll_no, pf_marks, ict_marks, physics, eng_marks, isl, average, cgpa);
}

// function to write result card  in file
void file_result_write(string name, int roll_no, int pf_marks, int ict_marks, int physics, int eng_marks, int isl, int average, float cgpa)
{
    ofstream output("result.txt");
    output << "\n======================== Result Card ========================\n";
    output << setfill(' ') << left << setw(20) << "Name:" << right << setw(30) << name << endl;
    output << setfill(' ') << left << setw(20) << "Roll No:" << right << setw(30) << roll_no << endl;
    output << setfill(' ') << left << setw(20) << "PF Marks:" << right << setw(30) << pf_marks << endl;
    output << setfill(' ') << left << setw(20) << "ICT Marks:" << right << setw(30) << ict_marks << endl;
    output << setfill(' ') << left << setw(20) << "Physics Marks:" << right << setw(30) << physics << endl;
    output << setfill(' ') << left << setw(20) << "English Marks:" << right << setw(30) << eng_marks << endl;
    output << setfill(' ') << left << setw(20) << "Islamiyat Marks:" << right << setw(30) << isl << endl;
    output << setfill(' ') << left << setw(20) << "Average Marks:" << right << setw(30) << average << endl;
    output << setfill(' ') << left << setw(20) << "CGPA:" << right << setw(30) << cgpa << endl;
    output << "=============================================================\n";
    output.close();
}

float average_calculator(int pf_marks, int ict_marks, int physics, int eng_marks, int isl)
{
    float cal = (pf_marks + ict_marks + physics + eng_marks + isl) / 5.0;
    return cal;
}

// function to find total cgpa depending upon the credit hours
float cgpa_calculator(int pf_marks, int ict_marks, int physics, int eng_marks, int isl)
{
    float pf_gpa = subject_gpa_calculator(pf_marks);
    float ict_gpa = subject_gpa_calculator(ict_marks);
    float physics_gpa = subject_gpa_calculator(physics);
    float eng_gpa = subject_gpa_calculator(eng_marks);
    float isl_gpa = subject_gpa_calculator(isl);
    float cgpa = ((pf_gpa * 4) + (ict_gpa * 3) + (physics_gpa * 3) + (eng_gpa * 3) + (isl_gpa * 2)) / 15;
    return cgpa;
}

// function to find gpa of each subject by using standard formulae of gpa in such a way that the marks above 85 gives 4 gpa
float subject_gpa_calculator(int marks)
{
    float subject_gpa = (marks >= 85) ? 4.0 : (marks >= 80) ? 3.66
                                          : (marks >= 75)   ? 3.33
                                          : (marks >= 70)   ? 3.0
                                          : (marks >= 65)   ? 2.66
                                          : (marks >= 60)   ? 2.0
                                          : (marks >= 55)   ? 1.5
                                          : (marks >= 50)   ? 1.0
                                                            : 0.0;
    return subject_gpa;
}