#include <QCoreApplication>
#include <QDebug>

// TODO: Define the Person class
// The class should have:
// - A private attribute `name` (QString)
// - A private attribute `age` (int)
// - A public constructor that initializes `name` and `age`
// - A public method `getName` that returns the name
// - A public method `getAge` that returns the age
// - A public method `printInfo` to display the person's details using qDebug()

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // TODO: Create a Person object using the constructor
    // TODO: Display the person's details by calling `printInfo`

    return app.exec();
}