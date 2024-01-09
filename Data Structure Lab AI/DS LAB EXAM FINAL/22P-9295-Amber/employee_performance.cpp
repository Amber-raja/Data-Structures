#include <iostream>
#include <vector>
using namespace std;

class Employee
{
public:
    int employeeID;
    string name;
    float sales;
    float customerSatisfaction;
    float projectCompletion;
    float performanceScore;

    Employee(int employeeID, string name, float customerSatisfaction, float projectCompletion, float performanceScore)
    {
        this->employeeID = employeeID;
        this->name = name;
        this->customerSatisfaction = customerSatisfaction;
        this->projectCompletion = projectCompletion;
        this->performanceScore= performanceScore;
    }

    int calculatePerformanceScore()
    {

        int performanceScore = sales + customerSatisfaction + projectCompletion;
        return performanceScore;
    }
};

class MaxHeap
{
public:
    vector<Employee> employeeHeap;

    int getParent(int child)
    {
        if (child == 0)
        {
            return -1;
        }
        return (child - 1) / 2;
    }

    int getLeft(int parent)
    {
        if ((2 * parent) + 1 >= employeeHeap.size())
        {
            return -1;
        }
        return (2 * parent) + 1;
    }

    int getRight(int parent)
    {
        if ((2 * parent) + 2 >= employeeHeap.size())
        {
            return -1;
        }
        return (2 * parent) + 2;
    }

    void swap(Employee *a, Employee *b)
    {
        Employee temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapifyUp(int node)
    {
        int parent = getParent(node);
        if (node >= 0 && parent >= 0 && employeeHeap[parent] < employeeHeap[node])
        {
            swap(&employeeHeap[node], &employeeHeap[parent]);
            heapifyUp(getParent(node));
        }
    }

    void heapifyDown(int node)
    {
        int lchild = getLeft(node);
        int rchild = getRight(node);
        int largest;
        if (lchild >= 0 && rchild >= 0)
        {
            if (employeeHeap[lchild] > employeeHeap[rchild])
            {
                largest = lchild;
            }
            else if (employeeHeap[rchild] > employeeHeap[lchild])
            {
                largest = rchild;
            }
            if (largest > 0)
            {
                swap(&employeeHeap[largest], &employeeHeap[node]);
                heapifyDown(largest);
            }
            cout<<" largest: "<<largest<<endl;
        }
    }

    void insertEmployee(Employee emp)
    {
        employeeHeap.calculatePerformanceScore();
        int size = employeeHeap.size();
        if (size == 0)
        {
            employeeHeap.push_back(emp);
        }
        else
        {
            employeeHeap.push_back(emp);
            heapifyUp(employeeHeap.size() - 1);
        }
    }

    void getTopRankingEmployee()
    {
        cout<<" top performer= "<<heapifyUp();


    }

     void del(int node)
    {

        swap(&employeeHeap[node], &employeeHeap[employeeHeap.size() - 1]);
        employeeHeap.pop_back();
        heapifyDown(node);
    }

    // void del()
    // {
    //     if (employeeHeap.empty())
    //     {
    //         cout << "Empty." << endl;
    //         return;
    //     }
    //     swap(&employeeHeap[0], &employeeHeap[employeeHeap.size() - 1]);
    //     employeeHeap.pop_back();
    //     heapifyDown(0);
    // }

    void updatePerformance(int employeeID, float newSales, float newCS, float newPCE, float score)
    {
        for (int i = 0; i < employeeHeap.size(); i++)
        {
            if (employeeHeap[i].employeeID == employeeID)
            {

               del(employeeID);
                insertEmployee(Employee(employeeID, newSales, newCS, newPCE, score));
                return;
            }
        }
        cout << "Employee not found";
    }

    void displayEmployees()
    {
        if (employeeHeap.empty())
        {
            cout << "No Employees." << endl;
            return;
        }
        cout << "Employee Rankings:" << endl;
        for (const Employee &emp : employeeHeap)
        {
            cout << "Employee ID: " << emp.employeeID << ", Name: " << emp.name << ", Performance Score: " << emp.performanceScore << endl;
        }
    }
};

int main()
{
    MaxHeap employeeMaxHeap;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Enter a new employee details\n";
        cout << "2. Get the top-ranking employee\n";
        cout << "3. Update an employee's scores\n";
        cout << "4. Display employee rankings\n";
        cout << "5. Exit\n";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id;
            string name;
            float sales, cs, pce;
            cout << "Enter Employee ID: ";
            cin >> id;
            cin.ignore(); // Clear newline character from the buffer
            cout << "Enter Employee Name: ";
            getline(cin, name);
            cout << "Enter Sales (in percentage): ";
            cin >> sales;
            cout << "Enter Customer Satisfaction (in percentage): ";
            cin >> cs;
            cout << "Enter Project Completion Efficiency (in percentage): ";
            cin >> pce;

            Employee newEmployee(id, name, cs, pce, sales);
            newEmployee.calculatePerformanceScore();
            employeeMaxHeap.insertEmployee(newEmployee);
            cout << "Employee added successfully!" << endl;
            break;
        }
        case 2:
        {
            employeeMaxHeap.getTopRankingEmployee();
            break;
        }
        case 3:
        {
            int empID;
            float newSales, newCS, newPCE, score;
            cout << "Enter Employee ID to update scores: ";
            cin >> empID;
            cout << "Enter new Sales (in percentage): ";
            cin >> newSales;
            cout << "Enter new Customer Satisfaction (in percentage): ";
            cin >> newCS;
            cout << "Enter new Project Completion Efficiency (in percentage): ";
            cin >> newPCE;
            employeeMaxHeap.updatePerformance(empID, newSales, newCS, newPCE, score);
            break;
        }
        case 4:
        {
            employeeMaxHeap.displayEmployees();
            break;
        }
        case 5:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}
