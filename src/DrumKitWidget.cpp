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

DrumKitWidget::DrumKitWidget(QWidget* parent): QWidget(parent), drumKit(new DrumKit(this)) {
    drumKit->insertRows(0,1, QModelIndex());                                                            //DRUM HAS BEEN CONSTRUCTED
    Drum* drum = drumKit->data(drumKit->index(0,0, QModelIndex()), Qt::DisplayRole).value<Drum*>();     //GETTING THE DRUM ADDRESS


    addbutton = new QPushButton(this);
    addbutton->setStyleSheet(QString("*{background: rgba(196,237,255);}"));
    addbutton->setText(QString("Add"));
    connect(addbutton, SIGNAL(clicked()), this, SLOT(on_add_pressed()));

    layout = new QVBoxLayout(this);
    layout->setDirection(QBoxLayout::BottomToTop);
    layout->addStretch(0);
    layout->setSpacing(0);
    layout->setContentsMargins(0,17,0,0);
    layout->addWidget(addbutton,Qt::AlignHCenter);
    layout->setAlignment(addbutton,Qt::AlignHCenter);
    this->setLayout(layout);
}
void DrumKitWidget::on_add_pressed(){
    drumKit->insertRows(0,1, QModelIndex());                                                            //DRUM HAS BEEN CONSTRUCTED
    Drum* drum = drumKit->data(drumKit->index(0,0, QModelIndex()), Qt::DisplayRole).value<Drum*>();     //GETTING THE DRUM ADDRESS

    DrumWidget* drumWidget = new DrumWidget(this);                                                      //SETTING THE WIDGT AS OBSERVER AND DRUM AS SUBJ
    drumWidget->setDrum(drum);
    drum->addObserver(drumWidget);
    drumWidgets.push_back(drumWidget);
    drum->notify();                                                                                     //FIRST NOTIFY

    layout->addWidget(drumWidget);                                                                      //SETTING THE LAYOUT

}
