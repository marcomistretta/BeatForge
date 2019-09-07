//
// Created by Guglielmo Fratticioli on 26/08/19.
//

#include "MetronomeWidget.h"
#include "Metronome.h"
#include <QDir>
#include <QDebug>

MetronomeWidget::MetronomeWidget(QWidget *parent) : Observer(), metronome(new Metronome()) {
    //adding observer
    metronome->addObserver(this);

    //setting the icon
    QIcon icon;
    icon.addFile(QString("../res/icons/metronome.png"));
    this->setIcon(icon);

    qDebug() << "Metronome Widget constructed";

    //TODO IMPLEMENT
    /*bpm_slider = new QSlider(this);
    bpm_slider->setValue( 20 ); //saranno 60 bpm
    vol_slider = new QSlider(this);
    vol_slider->setValue(100);*/

    //connecting methods
    connect(this, SIGNAL(clicked()), this, SLOT(on_pressed()));
    //connect( bpm_slider, SIGNAL(valueChanged(int)), this, SLOT(updateBpm(int)));
    //connect( vol_slider, SIGNAL(valueChanged(int)), this , SLOT(changeVolume(int)));
}

MetronomeWidget::~MetronomeWidget() {
    delete (metronome);
    qDebug() << "Metronome deleted";
}

void MetronomeWidget::obsUpdate() {
    qDebug() << "MetroWidget Updated";
    if (metronome->getState()) {
        //red
        qDebug() << "to Red";
        this->setBackground(QColor(217, 0, 0));
    } else {
        //light-green
        qDebug() << "to light green";
        this->setBackground(QColor(132, 176, 132));
    }
}

void MetronomeWidget::setBackground(const QColor &color) {
    qDebug() << "Backgroud changed";
    this->setStyleSheet(QString("background-color: %1").arg(color.name()));


}

void MetronomeWidget::on_pressed() {
    qDebug() << "Metronome pressed";
    obsUpdate();
    if (metronome->getState() == STATE::ON) {
        // metronome->setState(OFF);
        //this->setText("&stop");
        metronome->startStop();
    } else {
        //this->setText("&start");
        //metronome->setState(ON);
        metronome->startStop();
    }
}



/*DA FARE
connect( bpm_slider, SIGNAL(valueChanged(int)), this, SLOT(updateBpm(int)));
connect( vol_slider, SIGNAL(valueChanged(int)), this , SLOT(changeVolume(int)));
connect( start_button, SIGNAL(clicked()), this, SLOT(startStop()) );
connect( mute_button, SIGNAL(clicked()), this, SLOT(muteUnmute()) );
connect( metr_timer, SIGNAL(timeout()), this, SLOT(doBeep()) );
 */