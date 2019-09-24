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
#include <QMainWindow>

DrumKitWidget::DrumKitWidget(DrumKit *drumkit, QWidget *parent) : QWidget(parent), drumKit(drumkit) {
    this->setStyleSheet(QString("*{background-color: black);};"));
    drumKit->addObserver(this);
    //ADD BUTTON
    addbutton = new QPushButton(this);
    addbutton->setStyleSheet(QString("*{background: rgba(136,155,97);}"));
    addbutton->setText(QString("Add"));

    connect(addbutton, SIGNAL(clicked()), this, SLOT(on_add_pressed()));
    //LAYOUT
    layout = new QVBoxLayout(this);
    layout->setDirection(QBoxLayout::BottomToTop);
    layout->addStretch(0);
    layout->setSpacing(0);
    layout->setContentsMargins(0, this->height()/9.5, 0, 0);
    layout->addWidget(addbutton, Qt::AlignHCenter);
    layout->setAlignment(addbutton, Qt::AlignHCenter);
    this->setLayout(layout);
}

//TODO OBSERVER
void DrumKitWidget::on_add_pressed() {
    //DRUM HAS BEEN CONSTRUCTED BY QT
    drumKit->insertRows(0, 1, QModelIndex());

    //GETTING THE DRUM ADDRESS
    Drum *drum = drumKit->data(drumKit->index(0, 0, QModelIndex()), Qt::DisplayRole).value<Drum *>();

    //SETTING THE WIDTH AS OBSERVER AND DRUM AS SUBJ
    DrumWidget *drumWidget = new DrumWidget(this);
    drumWidget->setFixedHeight(this->height()/8.2);
    drumWidget->setFixedWidth(this->width());
    drumWidget->setDrum(drum);
    drum->addObserver(drumWidget);
    drumWidgets.push_back(drumWidget);

    //FIRST NOTIFY
    drum->notify();

    //SETTING THE LAYOUT
    layout->addWidget(drumWidget);
}

//TODO OBSERVER
void DrumKitWidget::obsUpdate() {
}
