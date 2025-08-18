#include "BookViewManager.h"

BookViewManager::BookViewManager(QWidget *parent) : QWidget(parent) {
    viewSelector = new QComboBox(this);
    viewStack = new QStackedWidget(this);

    listView = new BookListView(this);
    detailView = new BookDetailView(this);

    viewStack->addWidget(listView);
    viewStack->addWidget(detailView);

    viewSelector->addItem("List View");
    viewSelector->addItem("Detail View");

    // TODO: Connect viewSelector to switchView
    // TODO: Connect listView's bookSelected signal to updateDetailView

    // TODO: Arrange viewSelector and viewStack in a layout
}

void BookViewManager::setBooks(const QVector<Book> &books) {
    // TODO: Set books for the listView and detailView
}

void BookViewManager::switchView(int index) {
    // TODO: Switch to the selected view in the viewStack
}

void BookViewManager::updateDetailView(int bookIndex) {
    // TODO: Display the details of the selected book in detailView
}
