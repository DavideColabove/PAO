#include <QApplication>
#include "BookViewManager.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QVector<Book> books = {
        Book("The Catcher in the Rye", "J.D. Salinger", 1951),
        Book("To Kill a Mockingbird", "Harper Lee", 1960),
        Book("1984", "George Orwell", 1949)
    };

    BookViewManager manager;
    manager.setBooks(books);
    manager.show();

    return app.exec();
}
