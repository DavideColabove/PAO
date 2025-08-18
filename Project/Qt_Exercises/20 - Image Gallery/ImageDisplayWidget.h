#ifndef IMAGEDISPLAYWIDGET_H
#define IMAGEDISPLAYWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QVBoxLayout>
#include <QKeySequence>
#include <QShortcut>

class ImageDisplayWidget : public QWidget {
    Q_OBJECT

public:
    explicit ImageDisplayWidget(QWidget *parent = nullptr);

private:
    QLabel *imageLabel;
    QComboBox *imageSelector;
    QVector<QString> imagePaths;

    QShortcut *nextShortcut;
    QShortcut *prevShortcut;

    void setupUI();
    void setupShortcuts();

private slots:
    void displayImage(const QString &imagePath);
    void onImageSelectionChanged(int index);
    void showNextImage();
    void showPreviousImage();
};

#endif // IMAGEDISPLAYWIDGET_H
