#include <stdio.h>
#include <string.h>

// Define structure for employee information
struct EmployeeStruct
{
    char name[50];
    int employeeID;
    float salary;
};

// Define union for employee information
union EmployeeUnion
{
    char name[50];
    int employeeID;
    float salary;
};

int main()
{
    // Declare and initialize structure variable
    struct EmployeeStruct empStruct;
    strcpy(empStruct.name, "Alice");
    empStruct.employeeID = 101;
    empStruct.salary = 55000.50;

    // Declare and initialize union variable
    union EmployeeUnion empUnion;
    strcpy(empUnion.name, "Alice");
    empUnion.employeeID = 101;
    empUnion.salary = 55000.50;

    // Display the values stored in the structure
    printf("Structure Employee Information:\n");
    printf("Name: %s\n", empStruct.name);
    printf("Employee ID: %d\n", empStruct.employeeID);
    printf("Salary: %.2f\n\n", empStruct.salary);

    // Display the values stored in the union
    printf("Union Employee Information:\n");
    printf("Name: %s\n", empUnion.name);              // Displaying name
    printf("Employee ID: %d\n", empUnion.employeeID); // Displaying employee ID
    printf("Salary: %.2f\n\n", empUnion.salary);      // Displaying salary

    // Display the memory sizes of structure and union
    printf("Size of Structure: %zu bytes\n", sizeof(empStruct));
    printf("Size of Union: %zu bytes\n", sizeof(empUnion));

    return 0;
}
