#include "BookListView.h"

BookListView::BookListView(QWidget *parent) : QWidget(parent) {
    listWidget = new QListWidget(this);

    // TODO: Connect the listWidget's itemClicked signal to emit bookSelected with the correct index
}

void BookListView::setBooks(const QVector<Book> &books) {
    // TODO: Populate the listWidget with book titles
}
