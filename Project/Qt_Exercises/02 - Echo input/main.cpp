#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // Create a QTextStream object for input and output
    QTextStream cin(stdin);
    QTextStream cout(stdout);

    // TODO: Prompt the user to enter a line of text

    // TODO: Read the user's input using QTextStream

    // TODO: Echo the input back to the user

    return app.exec();
}