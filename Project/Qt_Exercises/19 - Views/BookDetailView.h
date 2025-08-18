#ifndef BOOKDETAILVIEW_H
#define BOOKDETAILVIEW_H

#include <QWidget>
#include <QLabel>
#include "Book.h"

class BookDetailView : public QWidget {
    Q_OBJECT

public:
    explicit BookDetailView(QWidget *parent = nullptr);

    void displayBook(const Book &book);

private:
    QLabel *titleLabel;
    QLabel *authorLabel;
    QLabel *yearLabel;
};

#endif // BOOKDETAILVIEW_H
