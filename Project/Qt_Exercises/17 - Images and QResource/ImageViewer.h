#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QWidget>
#include <QLabel>
#include <QKeyEvent>

class ImageViewer : public QWidget {
    Q_OBJECT

public:
    explicit ImageViewer(QWidget *parent = nullptr);

protected:
    // Handle key press events to toggle images
    void keyPressEvent(QKeyEvent *event) override;

private:
    QLabel *imageLabel; // Label to display the image
    QString currentImage; // Path to the currently displayed image

    // TODO: Add a private method to switch between images
};

#endif // IMAGEVIEWER_H