#include <QCoreApplication>
#include <QDebug>

// TODO: Define the Person class
// The class should:
// - Include a virtual `printInfo` method

// TODO: Define the Student class
// The class should:
// - Inherit from Person
// - Override the `printInfo` method to include university details

void displayInfo(Person *person) {
    // TODO: Call the printInfo method on the passed object
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // TODO: Create a Person object
    // TODO: Create a Student object

    // TODO: Call displayInfo for each object

    return app.exec();
}