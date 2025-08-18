#include "ImageDisplayWidget.h"
#include <QPixmap>

ImageDisplayWidget::ImageDisplayWidget(QWidget *parent)
    : QWidget(parent) {
    setupUI();
    setupShortcuts();

    // TODO: Populate imagePaths with resource paths (e.g., ":/images/image1.jpg", etc.)
    // TODO: Populate imageSelector with image names for user selection
    // TODO: Set the initial image in imageLabel
}

void ImageDisplayWidget::setupUI() {
    imageLabel = new QLabel(this);
    imageSelector = new QComboBox(this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(imageSelector);
    layout->addWidget(imageLabel);

    setLayout(layout);

    connect(imageSelector, &QComboBox::currentIndexChanged, this, &ImageDisplayWidget::onImageSelectionChanged);
}

void ImageDisplayWidget::setupShortcuts() {
    nextShortcut = new QShortcut(QKeySequence("Ctrl+Right"), this);
    prevShortcut = new QShortcut(QKeySequence("Ctrl+Left"), this);

    connect(nextShortcut, &QShortcut::activated, this, &ImageDisplayWidget::showNextImage);
    connect(prevShortcut, &QShortcut::activated, this, &ImageDisplayWidget::showPreviousImage);
}

void ImageDisplayWidget::displayImage(const QString &imagePath) {
    // TODO: Load and set the QPixmap for imageLabel from the given imagePath
}

void ImageDisplayWidget::onImageSelectionChanged(int index) {
    if (index >= 0 && index < imagePaths.size()) {
        displayImage(imagePaths[index]);
    }
}

void ImageDisplayWidget::showNextImage() {
    int currentIndex = imageSelector->currentIndex();
    if (currentIndex < imagePaths.size() - 1) {
        imageSelector->setCurrentIndex(currentIndex + 1);
    }
}

void ImageDisplayWidget::showPreviousImage() {
    int currentIndex = imageSelector->currentIndex();
    if (currentIndex > 0) {
        imageSelector->setCurrentIndex(currentIndex - 1);
    }
}
