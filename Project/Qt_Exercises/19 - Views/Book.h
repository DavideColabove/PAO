#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book {
public:
    Book(const QString &title, const QString &author, int year);

    QString getTitle() const;
    QString getAuthor() const;
    int getYear() const;

private:
    QString title;
    QString author;
    int year;
};

#endif // BOOK_H
