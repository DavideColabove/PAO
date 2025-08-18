#ifndef BOOKLISTVIEW_H
#define BOOKLISTVIEW_H

#include <QWidget>
#include <QListWidget>
#include "Book.h"
#include <QVector>

class BookListView : public QWidget {
    Q_OBJECT

public:
    explicit BookListView(QWidget *parent = nullptr);

    void setBooks(const QVector<Book> &books);

private:
    QListWidget *listWidget;

signals:
    void bookSelected(int index); // Emit when a book is selected
};

#endif // BOOKLISTVIEW_H
