#include "ListViewWidget.h"

ListViewWidget::ListViewWidget(QWidget *parent) : QWidget(parent) {
    // TODO: Create the list view, line edit, and buttons

    // Create the model and set it to the list view
    model = new QStringListModel(this);
    listView->setModel(model);

    // TODO: Create a vertical layout

    // TODO: Add widgets to the layout

    // TODO: Connect the addButton's clicked signal to the addItem slot
    
    // TODO: Connect the removeButton's clicked signal to the removeItem slot
}

void ListViewWidget::addItem() {
    QString item = lineEdit->text();
    if (!item.isEmpty()) {
        QStringList currentList = model->stringList();
        currentList.append(item);
        model->setStringList(currentList);
        lineEdit->clear();
    }
}

void ListViewWidget::removeItem() {
    QModelIndex selectedIndex = listView->currentIndex();
    if (selectedIndex.isValid()) {
        QStringList currentList = model->stringList();
        currentList.removeAt(selectedIndex.row());
        model->setStringList(currentList);
    }
}
