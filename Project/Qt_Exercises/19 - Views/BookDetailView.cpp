#include "BookDetailView.h"

BookDetailView::BookDetailView(QWidget *parent) : QWidget(parent) {
    titleLabel = new QLabel(this);
    authorLabel = new QLabel(this);
    yearLabel = new QLabel(this);

    // TODO: Arrange labels in a layout
}

void BookDetailView::displayBook(const Book &book) {
    // TODO: Set the text of the labels based on the book details
}
