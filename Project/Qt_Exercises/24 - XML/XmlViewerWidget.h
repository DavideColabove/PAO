#ifndef XMLVIEWERWIDGET_H
#define XMLVIEWERWIDGET_H

#include <QWidget>
#include <QTreeWidget>

class XmlViewerWidget : public QWidget {
    Q_OBJECT

public:
    explicit XmlViewerWidget(QWidget *parent = nullptr);

private:
    QTreeWidget *treeWidget;

    void loadXml();
    void saveXml();

private slots:
    void onSaveButtonClicked();
};

#endif // XMLVIEWERWIDGET_H
