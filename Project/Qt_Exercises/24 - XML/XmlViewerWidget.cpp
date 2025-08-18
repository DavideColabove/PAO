#include "XmlViewerWidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QFile>
#include <QDomDocument>
#include <QTreeWidgetItem>
#include <QFileDialog>
#include <QMessageBox>

XmlViewerWidget::XmlViewerWidget(QWidget *parent) : QWidget(parent) {
    treeWidget = new QTreeWidget(this);
    treeWidget->setHeaderLabels({"Title", "Author", "Year"});

    QPushButton *saveButton = new QPushButton("Save", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(treeWidget);
    layout->addWidget(saveButton);

    connect(saveButton, &QPushButton::clicked, this, &XmlViewerWidget::onSaveButtonClicked);

    loadXml();
}

void XmlViewerWidget::loadXml() {
    // TODO: Use a QFileDialog to select an XML file

    // TODO: Open selected file

    // TODO: Parse the content of the file using a QDomDocument

    // TODO: Access the root element
    // QDomElement root = 

    treeWidget->clear();

    QDomNodeList books = root.elementsByTagName("book");
    for (int i = 0; i < books.count(); ++i) {
        QDomNode node = books.at(i);
        if (node.isElement()) {
            QDomElement book = node.toElement();
            QTreeWidgetItem *item = new QTreeWidgetItem(treeWidget);
            item->setText(0, book.attribute("title"));
            item->setText(1, book.attribute("author"));
            item->setText(2, book.attribute("year"));
        }
    }
}

void XmlViewerWidget::saveXml() {
    // TODO: Use a QFileDialog to select a path to which save the file

    // TODO: Open path in write mode

    QDomDocument doc;
    QDomElement root = doc.createElement("library");
    doc.appendChild(root);

    for (int i = 0; i < treeWidget->topLevelItemCount(); ++i) {
        QTreeWidgetItem *item = treeWidget->topLevelItem(i);
        QDomElement book = doc.createElement("book");
        book.setAttribute("title", item->text(0));
        book.setAttribute("author", item->text(1));
        book.setAttribute("year", item->text(2));
        root.appendChild(book);
    }

    QTextStream out(&file);
    out << doc.toString();
    file.close();
}

void XmlViewerWidget::onSaveButtonClicked() {
    saveXml();
}
