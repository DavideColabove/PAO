#include <QCoreApplication>
#include <QDebug>

// TODO: Define the Person class (reuse from previous exercises)

// TODO: Define the Student class
// The class should:
// - Inherit from Person
// - Have a private attribute `university` (QString)
// - Include a constructor to initialize the name, age, and university
// - Have a method `printInfo` that overrides the base class method
//   to display all details (name, age, and university)

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // TODO: Create a Student object
    // TODO: Call the printInfo method to display the student's details

    return app.exec();
}