//
// Created by Guglielmo Fratticioli on 19/08/19.
//

#include "DrumKitWidget.h"
#include "Drum.h"
#include "DrumKit.h"
#include "DrumWidget.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>

DrumKitWidget::DrumKitWidget(QWidget *parent) : QWidget(parent) {
    drumKit = new DrumKit(this);
    drumKit->addObserver(this);
    addbutton = new QPushButton(this);
    addbutton->setStyleSheet(QString("*{background: rgba(196,237,255);}"));
    addbutton->setText(QString("Add"));
    connect(addbutton, SIGNAL(clicked()), this, SLOT(on_add_pressed()));

    layout = new QVBoxLayout(this);
    layout->setDirection(QBoxLayout::BottomToTop);
    layout->addStretch(0);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 17, 0, 0);
    layout->addWidget(addbutton, Qt::AlignHCenter);
    layout->setAlignment(addbutton, Qt::AlignHCenter);
    this->setLayout(layout);
}

void DrumKitWidget::on_add_pressed() {
    //DRUM HAS BEEN CONSTRUCTED
    drumKit->insertRows(0, 1, QModelIndex());
    //GETTING THE DRUM ADDRESS
    Drum *drum = drumKit->data(drumKit->index(0, 0, QModelIndex()), Qt::DisplayRole).value<Drum *>();
    //SETTING THE WIDTH AS OBSERVER AND DRUM AS SUBJ
    auto *drumWidget = new DrumWidget(this);
    drumWidget->setDrum(drum);
    drum->addObserver(drumWidget);
    drumWidgets.push_back(drumWidget);
    //FIRST NOTIFY
    drum->notify();
    //SETTING THE LAYOUT
    layout->addWidget(drumWidget);

}

DrumKit *DrumKitWidget::getDrumKit() const {
    return drumKit;
}

void DrumKitWidget::setDrumKit(DrumKit *drKit) {
    DrumKitWidget::drumKit = drKit;
}

void DrumKitWidget::obsUpdate() {
}
