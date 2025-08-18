#include "Book.h"

Book::Book(const QString &title, const QString &author, int year)
    : title(title), author(author), year(year) {}

QString Book::getTitle() const {
    return title;
}

QString Book::getAuthor() const {
    return author;
}

int Book::getYear() const {
    return year;
}