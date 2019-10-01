//
// Created by Guglielmo Fratticioli on 29/09/19.
//
//TODO CHECK
#include <QTest>
//#include <QtTest/QtTest>
#include <QVector>
#include "../src/MainWindow.h"
#include "../src/DrumKitWidget.h"
#include "../src/DrumKit.h"
#include "../src/DrumWidget.h"
#include "../src/Drum.h"
#include "../src/DisplayWidget.h"
#include "../src/StepButton.h"
#include "../src/Enum.h"

class UnitTest : public QObject {

Q_OBJECT
private slots:

    void test() {
        mainWindow = new MainWindow();
        //Has layout Been Initialised?
        QVERIFY(mainWindow->getUpperWidget() != nullptr);
        QVERIFY(mainWindow->getMidWidget() != nullptr);
        QVERIFY(mainWindow->getBottomWidget() != nullptr);

        //Has DrumKit,DrumKitWidget Been Constructed?
        QVERIFY(mainWindow->getDrumKit() != nullptr);
        QVERIFY(mainWindow->getDrumKitWidget() != nullptr);

        drumKit = mainWindow->getDrumKit();
        drumKitWidget = mainWindow->getDrumKitWidget();


    }

    void testAdd() {

        //FIRST DRUM
        int count = drumKitWidget->getLayout()->count();
        int size;
        int ndrums;
        QTest::mouseClick(drumKitWidget->getAddbutton(), Qt::LeftButton);
        //Has Drum Been Constructed ?
        QVERIFY(drumKit->getDrums().size() == (size = 1));
        QVERIFY(drumKit->getDrums()[ndrums = 0] != nullptr);

        //Has DrumWidget Been Constructed ?
        QVERIFY(drumKitWidget->getDrumWidgets().size() == size);
        QVERIFY(drumKitWidget->getDrumWidgets()[ndrums] != nullptr);

        //Has Layout Been Edited ?
        QVERIFY(drumKitWidget->getLayout()->count() == count + 1);

        drums.push_back(drumKit->getDrums()[ndrums]);

        //SECOND DRUM
        count = drumKitWidget->getLayout()->count();

        QTest::mouseClick(drumKitWidget->getAddbutton(), Qt::LeftButton);
        //Has Drum Been Constructed ?
        QVERIFY(drumKit->getDrums().size() == ++size);
        QVERIFY(drumKit->getDrums()[++ndrums] != nullptr);

        //Has DrumWidget Been Constructed ?
        QVERIFY(drumKitWidget->getDrumWidgets().size() == size);
        QVERIFY(drumKitWidget->getDrumWidgets()[ndrums] != nullptr);

        //Has Layout Been Edited ?
        QVERIFY(drumKitWidget->getLayout()->count() == count + 1);

        drums.push_back(drumKit->getDrums()[ndrums]);

        //THIRD DRUM
        count = drumKitWidget->getLayout()->count();

        QTest::mouseClick(drumKitWidget->getAddbutton(), Qt::LeftButton);
        //Has Drum Been Constructed ?
        QVERIFY(drumKit->getDrums().size() == ++size);
        QVERIFY(drumKit->getDrums()[++ndrums] != nullptr);

        //Has DrumWidget Been Constructed ?
        QVERIFY(drumKitWidget->getDrumWidgets().size() == size);
        QVERIFY(drumKitWidget->getDrumWidgets()[ndrums] != nullptr);

        //Has Layout Been Edited ?
        QVERIFY(drumKitWidget->getLayout()->count() == count + 1);

        drums.push_back(drumKit->getDrums()[ndrums]);

        //FOURTH DRUM
        count = drumKitWidget->getLayout()->count();

        QTest::mouseClick(drumKitWidget->getAddbutton(), Qt::LeftButton);
        //Has Drum Been Constructed ?
        QVERIFY(drumKit->getDrums().size() == ++size);
        QVERIFY(drumKit->getDrums()[++ndrums] != nullptr);

        //Has DrumWidget Been Constructed ?
        QVERIFY(drumKitWidget->getDrumWidgets().size() == size);
        QVERIFY(drumKitWidget->getDrumWidgets()[ndrums] != nullptr);

        //Has Layout Been Edited ?
        QVERIFY(drumKitWidget->getLayout()->count() == count + 1);

        drums.push_back(drumKit->getDrums()[ndrums]);

    }
    void testStyle() {
    //Is Pop Default Style?
    QVERIFY(drumKit->getDrumStyle() == POP);

    //Pressing To_LeftStyle (ROCK)
    QTest::mouseClick(mainWindow->getDisplayWidget()->getLeftStyle(), Qt::LeftButton);

    //Is Style Been Changed?
    QVERIFY(drumKit->getDrumStyle() == ROCK);

    //Are Sample_Path Updated?
    QVERIFY(drums[0]->getDrumStyle() == ROCK);
    QVERIFY(drums[1]->getDrumStyle() == ROCK);
    QVERIFY(drums[2]->getDrumStyle() == ROCK);
    QVERIFY(drums[3]->getDrumStyle() == ROCK);

}


    void testType() {
        int i;
        //Pressing FIRST Drum Menu
        QTest::mouseClick(drumKitWidget->getDrumWidgets()[i = 0]->getMenu(), Qt::LeftButton);
        //Pressing Kick

        //Is Type Changed?
        QVERIFY(drums[i]->getDrumType() == KICK);

        //Pressing SECOND Drum Menu
        QTest::mouseClick(drumKitWidget->getDrumWidgets()[++i]->getMenu(), Qt::LeftButton);
        //Pressing Snare

        //Is Type Changed?
        QVERIFY(drums[i]->getDrumType() == SNARE);

        //Pressing THIRD Drum Menu
        QTest::mouseClick(drumKitWidget->getDrumWidgets()[++i]->getMenu(), Qt::LeftButton);
        //Pressing Hat

        //Is Type Changed?
        QVERIFY(drums[i]->getDrumType() == HAT);

        //Pressing FOURTH Drum Menu
        QTest::mouseClick(drumKitWidget->getDrumWidgets()[++i]->getMenu(), Qt::LeftButton);
        //Pressing Tom

        //Is Type Changed?
        QVERIFY(drums[i]->getDrumType() == TOM);

    }

    void TestPattern() {

}
private:

    void testMute() {

    }

    void testVolume() {

    }

    void testTypeChange() {

    }

    void testStyleChange() {

    }
    QVector<Drum*> drums;
    MainWindow *mainWindow;
    Drum *drum;
    DrumKit *drumKit;
    DrumKitWidget *drumKitWidget;
};

QTEST_MAIN(UnitTest)

#include "UnitTest.moc"
