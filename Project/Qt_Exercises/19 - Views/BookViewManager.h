#ifndef BOOKVIEWMANAGER_H
#define BOOKVIEWMANAGER_H

#include <QWidget>
#include <QComboBox>
#include <QStackedWidget>
#include "BookListView.h"
#include "BookDetailView.h"
#include "Book.h"

class BookViewManager : public QWidget {
    Q_OBJECT

public:
    explicit BookViewManager(QWidget *parent = nullptr);

    void setBooks(const QVector<Book> &books);

private:
    QComboBox *viewSelector;
    QStackedWidget *viewStack;
    BookListView *listView;
    BookDetailView *detailView;

private slots:
    void switchView(int index);
    void updateDetailView(int bookIndex);

    // TODO: Add methods to handle signals and updates
};

#endif // BOOKVIEWMANAGER_H
