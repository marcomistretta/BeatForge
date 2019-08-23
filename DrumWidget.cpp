
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
    //BUILDING PLAY-PAUSE-MUTE-SOLO

    muteButton = new QPushButton();
    QIcon playicon;
    playicon.addFile(QString("/home/gege/Studio/C++/png/playicon.png"));
    muteButton->setIcon(playicon);

    soloButton = new QPushButton();
    QIcon soloicon;
    soloicon.addFile(QString("/home/gege/Studio/C++/png/pauseicon.png"));
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




