
#include "DrumWidget.h"
#include "Drum.h"
#include "StepButton.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QSizePolicy>
#include <QPalette>
#include <QDebug>
DrumWidget::~DrumWidget() {
    drum->removeObserver(this);
}

DrumWidget::DrumWidget( QWidget *parent): QWidget(parent) {

    QPalette pal;
    pal.setColor(QPalette::Background,QColor(72,71,90));
    this->setPalette(pal);
    this->setAutoFillBackground(true);

    //DECLARING HORIZONTAL LAYOUT
    layout = new QHBoxLayout();

    //BUILDING INFO BOX
    drum_info = new QPushButton();
    drum_info->setStyleSheet("background: #23B400");
    layout->addWidget(drum_info);
    layout->setStretchFactor(drum_info, 3);

    //BUILDING MUTE-SOLO
    //FIXME cambiato playicon in muteicon
    muteButton = new QPushButton();
    QIcon muteicon;
    //FIXME funziona ma sarebbe meglio una path interna
    muteicon.addFile(QString("/home/misterm/Scrivania/PROGETTO/res/icon/muteicon.png"));
    muteButton->setIcon(muteicon);

    soloButton = new QPushButton();
    QIcon soloicon;
    //FIXME funziona ma sarebbe meglio una path interna
    soloicon.addFile(QString("/home/misterm/Scrivania/PROGETTO/res/icon/soloicon.png"));
    soloButton->setIcon(soloicon);


    layout->addWidget(muteButton,0,0);
    layout->addWidget(soloButton,1,0);



    //BUILDING STEP_BUTTONS
    for (int i = 0; i < 16; i++) {
        buttons[i] = new StepButton(this);
        buttons[i]->setStyleSheet("background: white");
        buttons[i]->setPosition(i);

        layout->addWidget(buttons[i]);
        layout->setStretchFactor(buttons[i], 1);
    }

    this->setLayout(layout);                                                                //SETTING THE LAYOUT
     }
void DrumWidget::obsUpdate() {
    qDebug()<<"Observer Updating";
    for(int pos = 0; pos<16; pos ++){
        if (drum->isChecked(pos))
            buttons[pos]->setBackground(Qt::red);
        else
            buttons[pos]->setBackground(Qt::white);
    }
}

//FIXME implement
void DrumWidget::on_mute_pressed() {
    connect(muteButton,SIGNAL(clicked()),this,SLOT(on_mute_pressed()));
}

void DrumWidget::on_solo_pressed() {
    connect(soloButton,SIGNAL(clicked()),this,SLOT(on_solo_pressed()));
}




