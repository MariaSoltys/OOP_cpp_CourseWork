# OOP_cpp_CourseWork
This is a personal C++ project for my university course work. the subject of this project is Employee Management System. The project was developed using the Visual Studio environment and includes functionalities such as creating person and employee records, managing salaries, and demonstrating object-oriented programming concepts like inheritance, polymorphism, and operator overloading.

## Features

- **Class `Person`**:
  - Attributes: name, surname, father's name, birthdate, gender.
  - Methods: initialization, copy constructor, setters, getters, overloaded operators (`=`, `<<`, `>>`, `()`).
  - Virtual method `Reading` for polymorphism.

- **Class `Coworker` (derived from `Person`)**:
  - Additional attributes: ID number, salary, work experience, hours worked, hourly rate.
  - Methods: initialization, print details, overridden `Reading`.

- **Class `Salary`**:
  - Contains a list of `Coworker` objects.
  - Methods to calculate salaries and iterate over employee objects using an iterator class.

## Getting Started

### Prerequisites

- Visual Studio or any C++ compiler.
- Basic knowledge of C++ and object-oriented programming.

### Installation

1. **Clone the repository**:
    ```sh
    git clone https://github.com/your-username/EmployeeManagementSystem.git
    ```
2. **Open the project in Visual Studio**:
    - Open Visual Studio.
    - Select `File` > `Open` > `Project/Solution`.
    - Navigate to the cloned repository and open the project file.

3. **Build the project**:
    - In Visual Studio, select `Build` > `Build Solution` to compile the project.

### Usage

1. **Run the executable**:
    - Press `F5` or select `Debug` > `Start Debugging` to run the project.

2. **Follow the prompts**:
    - The console application will prompt you to either hire workers or issue salaries.

### Code Structure

- **Person Class**:
    ```cpp
    class Person {
        // Attributes and methods
    };
    ```

- **Coworker Class**:
    ```cpp
    class Coworker : public Person {
        // Additional attributes and methods
    };
    ```

- **Salary Class**:
    ```cpp
    template<typename T>
    class Salary {
        // Attributes and methods
    };
    ```

- **Iterator Class**:
    ```cpp
    template<typename T>
    class Iterator {
        // Attributes and methods
    };
    ```

### Example

Below is an example usage of the classes:

```cpp
int main() {
    Person person1;
    person1.SetName("John");
    person1.SetSurame("Doe");
    
    Coworker coworker1;
    coworker1.SetWH(40);
    coworker1.print();
    
    Salary<Coworker> salary(3);
    salary.AddElement();
    
    for (Salary<Coworker>::iterator iter = salary.begin(); iter != salary.end(); ++iter) {
        cout << *iter << endl;
    }
}
