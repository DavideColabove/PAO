#include <QApplication>
#include <QFont>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>
#include "lcdrange.h"
#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent) {
    QPushButton *quit = new QPushButton(tr("Quit"));
    quit->setFont(QFont("Times", 18, QFont::Bold));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    QGridLayout *grid = new QGridLayout;
    LCDRange *previousRange = 0;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            LCDRange *lcdRange = new LCDRange;
            grid->addWidget(lcdRange, row, col);
            // ogni signal di un LCDRange connesso allo stesso slotdel precedente LCDRange
            if (previousRange)
                connect(lcdRange, SIGNAL(valueChanged(int)), previousRange, SLOT(setValue(int)));
            previousRange = lcdRange;
        }
    }
    // abbiamo creato una catena di segnali e slot
    QVBoxLayout *vblayout = new QVBoxLayout;
    vblayout->addWidget(quit);
    vblayout->addLayout(grid);
    setLayout(vblayout);
}
