#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <QLabel>
#include <QFontMetrics>
#include <QPainter>
#include <cmath>
#include <vector>
#include <algorithm>
#include <QString>

void convert(QPushButton* buttons[], int numButtons, QPushButton* button31) {
    int numberGreenButtons = 0;

    for (int i = 0; i < numButtons; ++i) {
        QString styleSheet = buttons[i]->styleSheet();
        if (styleSheet.contains("stop: 0 green") && styleSheet.contains("stop: 1 lightgreen")) {
            numberGreenButtons++;
        }
    }
    if (numberGreenButtons == 2) {
        button31->show();
    }
}
void buttonsBack(QPushButton* button){
    button->setStyleSheet(R"(
QPushButton {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 silver, stop: 1 white);
    border: 1px solid #000000;
    border-radius: 5px; color: black;
    font-weight: bold;
}
 QPushButton:hover {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 white stop: 1 silver);
}
QPushButton:pressed {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 black, stop: 1 white);
 } )");
}
void blueButtonsUnits(QPushButton* button){
    button->setStyleSheet(R"(
QPushButton {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 blue, stop: 1 cyan);
    border: 1px solid #000000;
    border-radius: 10px; color: white;
    font-weight: bold;
}
QPushButton:hover {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 cyan, stop: 1 blue);
}
QPushButton:pressed {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 SteelBlue, stop: 1 Aqua);
 } )");
}
void blueButtons(QWidget* button){
    button->setStyleSheet(R"(
QPushButton {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 blue, stop: 1 cyan);
    border: 1px solid #000000;
    color: white;
    font-weight: bold;
}
 QPushButton:hover {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 cyan, stop: 1 blue);
} )");
}
void greenButtons(QWidget* button){
    button->setStyleSheet(R"(
QPushButton {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 green, stop: 1 lightgreen);
    border: 1px solid #000000;
    color: white;
    font-weight: bold;
} )");
}
void selectGreenButton(QPushButton* button, std::vector<QPushButton*>& buttonsUnits);

void hideAllWidgets(QWidget* window) {
    const auto widgets = window->findChildren<QWidget*>();
    for (QWidget* widget : widgets) {
        widget->hide();
    }
}
void menu(QPushButton *button1, QPushButton* button2, QLabel* label1){
    button1->show();
    button2->show();
    label1->show();
}
double convertation_aL(double unity){return unity*(pow(10, -18));}
double convertation_fL(double unity){return unity*(pow(10, -15));}
double convertation_pL(double unity){return unity*(pow(10, -12));}
double convertation_nL(double unity){return unity*(pow(10, -9));}
double convertation_µL(double unity){return unity*(pow(10, -6));}
double convertation_mL(double unity){return unity*0.001;}
double convertation_cL(double unity){return unity*0.01;}
double convertation_dL(double unity){return unity*0.01;}
double convertation_L(double unity){return unity;}
double convertation_daL(double unity){return unity*10;}
double convertation_hL(double unity){return unity*100;}
double convertation_m³(double unity){return unity*1000;}
double convertation_ML(double unity){return unity*1000000;}
double convertation_km³(double unity){return unity*1000000000;}
double convertation_EL(double unity){return unity*(pow(10, 18));}

double convertation_in_aL(double unity){return unity/(pow(10, -18));}
double convertation_in_fL(double unity){return unity/(pow(10, -15));}
double convertation_in_pL(double unity){return unity/(pow(10, -12));}
double convertation_in_nL(double unity){return unity/(pow(10, -9));}
double convertation_in_µL(double unity){return unity/(pow(10, -6));}
double convertation_in_mL(double unity){return unity/0.001;}
double convertation_in_cL(double unity){return unity/0.01;}
double convertation_in_dL(double unity){return unity/0.01;}
double convertation_in_L(double unity){return unity;}
double convertation_in_daL(double unity){return unity/10;}
double convertation_in_hL(double unity){return unity/100;}
double convertation_in_m³(double unity){return unity/1000;}
double convertation_in_ML(double unity){return unity/1000000;}
double convertation_in_km³(double unity){return unity/1000000000;}
double convertation_in_EL(double unity){return unity/(pow(10, 18));}

typedef double (*ConversionFunction)(double);

ConversionFunction convertationFunctions1[] = {
    convertation_aL, convertation_fL, convertation_pL, convertation_nL, convertation_µL,
    convertation_mL, convertation_cL, convertation_dL, convertation_L, convertation_daL,
    convertation_hL, convertation_m³, convertation_ML, convertation_km³, convertation_EL};

ConversionFunction convertationFunctions2[] = {
    convertation_in_aL, convertation_in_fL, convertation_in_pL, convertation_in_nL, convertation_in_µL,
    convertation_in_mL, convertation_in_cL, convertation_in_dL, convertation_in_L, convertation_in_daL,
    convertation_in_hL, convertation_in_m³, convertation_in_ML, convertation_in_km³, convertation_in_EL
};
void menuSelectUnits(std::vector<QWidget*> buttons, QWidget* window){
    hideAllWidgets(window);
    for(QWidget* widget: buttons){
        widget->show();
    }
}
bool drawArrow = false;

class SimpleArrowWidget : public QWidget {
public:
    SimpleArrowWidget(QWidget *parent = nullptr) : QWidget(parent) {}

protected:
    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);

        if (drawArrow) {
            QPen pen(Qt::black, 5); // Устанавливаем толщину линии
            painter.setPen(pen);

            // Координаты для стрелки
            QPoint start(70, 75);
            QPoint end(160, 75);

            // Рисуем линию стрелки
            painter.drawLine(start, end);

            // Создаем наконечник стрелки
            QPoint arrowLeft(end.x() - 15, end.y() - 15);
            QPoint arrowRight(end.x() - 15, end.y() + 15);

            painter.drawLine(end, arrowLeft);
            painter.drawLine(end, arrowRight);
        }
    }
};
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    //window
    QWidget window;
    window.setGeometry(550, 200, 400, 200);
    window.setWindowTitle("Lol");
    window.setStyleSheet(R"(
QWidget {
background: qlineargradient(
x1: 0, y1: 0, x2: 1, y2: 1,
stop: 0 DeepSkyBlue, stop: 1 DodgerBlue ); } )");

    //Labels
    QLabel labelSelect("Select operation", &window);
    labelSelect.setGeometry(350, -10, 800, 400);
    labelSelect.setStyleSheet(R"(
QLabel {
    background-color: rgba(255, 255, 255, 0);
    font-size: 24px;
 } )");
    labelSelect.setAlignment(Qt::AlignCenter);

    QLabel labelResultText("Number of symbols: 0", &window);
    labelResultText.setGeometry(620, 450, 300, 30);
    labelResultText.setStyleSheet(R"(
QLabel {
    background-color: rgba(255, 255, 255, 0);
    font-size: 18px;
} )");
    labelResultText.setAlignment(Qt::AlignCenter);
    labelResultText.hide();

    QLabel labelSelectUnits("Units of measurement", &window);
    labelSelectUnits.setGeometry(600, 0, 800, 400);
    labelSelectUnits.setStyleSheet(R"(
QLabel {
    background-color: rgba(255, 255, 255, 0);
    font-size: 30px;
 } )");
    labelSelectUnits.hide();

    QLabel labelUnits1("", &window);
    labelUnits1.setGeometry(693, 484, 125, 60);
    labelUnits1.setStyleSheet(R"(
QLabel {
    background-color: rgba(255, 255, 255, 0);
    font-size: 15px;
 } )");
    labelUnits1.hide();

    //lines
    QLineEdit lineEditText(&window);
    lineEditText.setGeometry(620, 300, 300, 30);
    lineEditText.setPlaceholderText("Enter text here...");
    lineEditText.setStyleSheet(R"(
QLineEdit {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 blue, stop: 1 cyan);
    color: white;
    border: 1px solid black;
    border-radius: 5px;
} )");
    lineEditText.hide();

    QLineEdit lineUnits(&window);
    lineUnits.setGeometry(600, 500, 90, 30);
    lineUnits.setPlaceholderText("Enter...");
    lineUnits.setStyleSheet(R"(
QLineEdit {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 DeepSkyBlue, stop: 1 lightblue);
    color: black;
    border: 1px solid black;
    border-radius: 5px;
} )");
    lineUnits.hide();

    //buttons
    QPushButton buttonText("Text", &window);
    buttonText.setGeometry(500, 400, 100, 50);
    buttonText.setStyleSheet(
        R"(
QPushButton {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 blue, stop: 1 cyan);
    border: 1px solid black;
    border-radius: 24px;
    color: white;
    font-weight: bold;
}
 QPushButton:hover {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 cyan, stop: 1 blue);
    border: 1px solid black;
}
QPushButton:pressed {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 SteelBlue, stop: 1 Aqua);
 } )");

    QPushButton buttonConvertation("Convertation", &window);
    buttonConvertation.setGeometry(900, 400, 100, 50);
    buttonConvertation.setStyleSheet(
        R"(
QPushButton {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 blue, stop: 1 cyan);
    border: 1px solid black;
    border-radius: 24px;
    color: white;
    font-weight: bold;
}
 QPushButton:hover {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 cyan, stop: 1 blue);
    border: 1px solid black;
}
QPushButton:pressed {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 SteelBlue, stop: 1 Aqua);
 } )");

    QPushButton buttonCountText("Count", &window);
    buttonCountText.setGeometry(920, 300, 70, 30);
    buttonCountText.setStyleSheet(R"(
QPushButton {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 blue, stop: 1 cyan);
    border: 1px solid #000000;
    border-radius: 5px; color: white;
    font-weight: bold;
}
 QPushButton:hover {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 cyan, stop: 1 blue);
}
QPushButton:pressed {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 SteelBlue, stop: 1 Aqua);
 } )");
    buttonCountText.hide();
    QPushButton buttonClean("Clean", &window);
    buttonClean.setGeometry(920, 330, 70, 30);
    buttonClean.setStyleSheet(R"(
QPushButton {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 blue, stop: 1 cyan);
    border: 1px solid #000000;
    border-radius: 5px; color: white;
    font-weight: bold;
}
 QPushButton:hover {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 cyan, stop: 1 blue);
}
QPushButton:pressed {
    background: qlineargradient(
    x1: 0, y1: 0, x2: 1, y2: 1,
    stop: 0 SteelBlue, stop: 1 Aqua);
 } )");
    buttonClean.hide();

    QPushButton buttonBack("Back", &window);
    buttonBack.setGeometry(150, 700, 180, 30);
    buttonsBack(&buttonBack);
    buttonBack.hide();

    QPushButton buttonVolume("Volume", &window);
    buttonVolume.setGeometry(300, 400, 180, 30);
    blueButtonsUnits(&buttonVolume);
    buttonVolume.hide();

    QPushButton buttonTime("Time", &window);
    buttonTime.setGeometry(530, 400, 180, 30);
    blueButtonsUnits(&buttonTime);
    buttonTime.hide();

    QPushButton buttonMass("Mass", &window);
    buttonMass.setGeometry(760, 400, 180, 30);
    blueButtonsUnits(&buttonMass);
    buttonMass.hide();

    QPushButton buttonLength("Length", &window);
    buttonLength.setGeometry(990, 400, 180, 30);
    blueButtonsUnits(&buttonLength);
    buttonLength.hide();

    //buttonsUnits 1
    QPushButton buttonAttoliter1("attoliter", &window);
    buttonAttoliter1.setGeometry(360, 140, 140, 30);

    QPushButton buttonFemtoliter1("femtoliter", &window);
    buttonFemtoliter1.setGeometry(360, 170, 140, 30);

    QPushButton buttonPicoliter1("picoliter", &window);
    buttonPicoliter1.setGeometry(360, 200, 140, 30);

    QPushButton buttonNanoliter1("nanoliter", &window);
    buttonNanoliter1.setGeometry(360, 230, 140, 30);

    QPushButton buttonMicroliter1("microliter", &window);
    buttonMicroliter1.setGeometry(360, 260, 140, 30);

    QPushButton buttonMilliliter1("milliliters", &window);
    buttonMilliliter1.setGeometry(360, 290, 140, 30);

    QPushButton buttonCentiliter1("centiliters", &window);
    buttonCentiliter1.setGeometry(360, 320, 140, 30);

    QPushButton buttonDeciliter1("deciliters", &window);
    buttonDeciliter1.setGeometry(430, 350, 140, 30);

    QPushButton buttonLiter1("liters", &window);
    buttonLiter1.setGeometry(500, 320, 140, 30);

    QPushButton buttonDecaliter1("decaliters", &window);
    buttonDecaliter1.setGeometry(500, 290, 140, 30);

    QPushButton buttonHectoliter1("hectoliters", &window);
    buttonHectoliter1.setGeometry(500, 260, 140, 30);

    QPushButton buttonCubicMeter1("cubic meters", &window);
    buttonCubicMeter1.setGeometry(500, 230, 140, 30);

    QPushButton buttonMegaliter1("megaliters", &window);
    buttonMegaliter1.setGeometry(500, 200, 140, 30);

    QPushButton buttonCubicKilometer1("cubic kilometers", &window);
    buttonCubicKilometer1.setGeometry(500, 170, 140, 30);

    QPushButton buttonExaliter1("exaliters", &window);
    buttonExaliter1.setGeometry(500, 140, 140, 30);

    // buttonUnits 2
    QPushButton buttonAttoliter2("attoliter", &window);
    buttonAttoliter2.setGeometry(920, 140, 140, 30);

    QPushButton buttonFemtoliter2("femtoliter", &window);
    buttonFemtoliter2.setGeometry(920, 170, 140, 30);

    QPushButton buttonPicoliter2("picoliter", &window);
    buttonPicoliter2.setGeometry(920, 200, 140, 30);

    QPushButton buttonNanoliter2("nanoliter", &window);
    buttonNanoliter2.setGeometry(920, 230, 140, 30);

    QPushButton buttonMicroliter2("microliter", &window);
    buttonMicroliter2.setGeometry(920, 260, 140, 30);

    QPushButton buttonMilliliter2("milliliters", &window);
    buttonMilliliter2.setGeometry(920, 290, 140, 30);

    QPushButton buttonCentiliter2("centiliters", &window);
    buttonCentiliter2.setGeometry(920, 320, 140, 30);

    QPushButton buttonDeciliter2("deciliters", &window);
    buttonDeciliter2.setGeometry(990, 350, 140, 30);

    QPushButton buttonLiter2("liters", &window);
    buttonLiter2.setGeometry(1060, 320, 140, 30);

    QPushButton buttonDecaliter2("decaliters", &window);
    buttonDecaliter2.setGeometry(1060, 290, 140, 30);

    QPushButton buttonHectoliter2("hectoliters", &window);
    buttonHectoliter2.setGeometry(1060, 260, 140, 30);

    QPushButton buttonCubicMeter2("cubic meters", &window);
    buttonCubicMeter2.setGeometry(1060, 230, 140, 30);

    QPushButton buttonMegaliter2("megaliters", &window);
    buttonMegaliter2.setGeometry(1060, 200, 140, 30);

    QPushButton buttonCubicKilometer2("cubic kilometers", &window);
    buttonCubicKilometer2.setGeometry(1060, 170, 140, 30);

    QPushButton buttonExaliter2("exaliters", &window);
    buttonExaliter2.setGeometry(1060, 140, 140, 30);

    QPushButton buttonConvert("-->", &window);
    buttonConvert.setGeometry(748, 500, 50, 30);
    blueButtonsUnits(&buttonConvert);
    buttonConvert.hide();

    QPushButton buttonBack2("Back", &window);
    buttonBack2.setGeometry(150, 700, 180, 30);
    buttonsBack(&buttonBack2);
    buttonBack2.hide();

    QPushButton buttonCleanUnitsVolume("Clean", &window);
    buttonCleanUnitsVolume.setGeometry(650, 700, 220, 30);
    blueButtonsUnits(&buttonCleanUnitsVolume);
    buttonCleanUnitsVolume.hide();

    SimpleArrowWidget arrowWidget(&window);
    arrowWidget.setGeometry(670, 165, 220, 150);
    arrowWidget.setStyleSheet("background: transparent;");
    arrowWidget.hide();

    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setWindowTitle("Input error");
    msgBox.setText("Please enter only numbers.");
    msgBox.setStyleSheet(R"(
                                QMessageBox {
                                    background: qlineargradient(
                                    x1: 0, y1: 0, x2: 1, y2: 1,
                                    stop: 0 lightsalmon, stop: 1 lightcoral);
                                    color: #721c24;
                                }
                                QPushButton {
                                    background: qlineargradient(
                                    x1: 0, y1: 0, x2: 1, y2: 1,
                                    stop: 0 red, stop: 1 orange);
                                    color: black;
                                    border: 1px solid black;
                                    border-radius: 10px; color: white;
                                    padding: 5px 10px;
                                    font-size: 14px;
                                }
                                QPushButton:hover {
                                    background: qlineargradient(
                                    x1: 0, y1: 0, x2: 1, y2: 1,
                                    stop: 0 crimson, stop: 1 orangered);
                                }
                                QPushButton:pressed {
                                    background: qlineargradient(
                                    x1: 0, y1: 0, x2: 1, y2: 1,
                                    stop: 0 dark, stop: 1 red);
                                }
                            )");

    std::vector<QWidget*> buttonsUnitsMenu = {&buttonVolume, &buttonMass, &buttonLength, &buttonTime, &buttonBack, &labelSelectUnits};

    const char* units[] = {"aL", "fL", "pL", "nL", "µL", "mL", "cL", "dL", "L", "daL", "hL", "m³", "ML", "km³", "EL"};

    std::vector<QPushButton*> buttonsUnits = {&buttonAttoliter1, &buttonFemtoliter1, &buttonPicoliter1, &buttonNanoliter1, &buttonMicroliter1,
                                              &buttonMilliliter1, &buttonCentiliter1, &buttonDeciliter1, &buttonLiter1, &buttonDecaliter1,
                                              &buttonHectoliter1, &buttonCubicMeter1, &buttonMegaliter1, &buttonCubicKilometer1, &buttonExaliter1,
                                              &buttonAttoliter2, &buttonFemtoliter2, &buttonPicoliter2, &buttonNanoliter2, &buttonMicroliter2,
                                              &buttonMilliliter2, &buttonCentiliter2, &buttonDeciliter2, &buttonLiter2, &buttonDecaliter2,
                                              &buttonHectoliter2, &buttonCubicMeter2, &buttonMegaliter2, &buttonCubicKilometer2, &buttonExaliter2};
    for(QPushButton* button: buttonsUnits){
        blueButtons(button);
        button->hide();
    }

    std::vector<QPushButton*> buttonsUnits1 = {&buttonAttoliter1, &buttonFemtoliter1, &buttonPicoliter1, &buttonNanoliter1, &buttonMicroliter1,
                                               &buttonMilliliter1, &buttonCentiliter1, &buttonDeciliter1, &buttonLiter1, &buttonDecaliter1,
                                               &buttonHectoliter1, &buttonCubicMeter1, &buttonMegaliter1, &buttonCubicKilometer1, &buttonExaliter1};

    std::vector<QPushButton*> buttonsUnits2 = {&buttonAttoliter2, &buttonFemtoliter2, &buttonPicoliter2, &buttonNanoliter2, &buttonMicroliter2,
                                               &buttonMilliliter2, &buttonCentiliter2, &buttonDeciliter2, &buttonLiter2, &buttonDecaliter2,
                                               &buttonHectoliter2, &buttonCubicMeter2, &buttonMegaliter2, &buttonCubicKilometer2, &buttonExaliter2};
    QString textLabelNumberUnits;
    QLabel labelNumberUnits(textLabelNumberUnits, &window);
    labelNumberUnits.setStyleSheet(R"(
QLabel {
    background-color: rgba(255, 255, 255, 0);
    font-size: 15px;
} )");
    int textWidthlabelNumberUnits;

    QString textLabelUnits2 = "";
    QLabel labelUnits2(textLabelUnits2, &window);
    labelUnits2.setStyleSheet(R"(
QLabel {
    background-color: rgba(255, 255, 255, 0);
    font-size: 15px;
} )");
    int textWidthLabelUnits2;
    for (int i = 0; i < 15; ++i) {
        QObject::connect(buttonsUnits1[i], &QPushButton::clicked, [&, i]() {
            labelUnits1.setText(units[i]);
            labelUnits1.show();
            lineUnits.show();
            selectGreenButton(buttonsUnits1[i], buttonsUnits1);
            convert(buttonsUnits.data(), buttonsUnits.size(), &buttonConvert);
            labelNumberUnits.hide();
            labelUnits2.hide();
        });
        QObject::connect(buttonsUnits2[i], &QPushButton::clicked, [&, i]() {
            selectGreenButton(buttonsUnits2[i],buttonsUnits2);
            convert(buttonsUnits.data(), buttonsUnits.size(), &buttonConvert);
            labelNumberUnits.hide();

            textLabelUnits2 = QString(units[i]);
            labelUnits2.setText(textLabelUnits2);
            QFontMetrics metricsLabelUnits2(labelUnits2.font());
            textWidthLabelUnits2 = metricsLabelUnits2.horizontalAdvance(textLabelUnits2);
            labelUnits2.hide();
        });
    }
    QObject::connect(&buttonConvert, &QPushButton::clicked, [&]() {
        textLabelNumberUnits = lineUnits.text();
        bool ok;
        for (int i = 0; i < 15; ++i) {
            QString styleSheetButtonsVolume1 = buttonsUnits1[i]->styleSheet();
            if (styleSheetButtonsVolume1.contains("stop: 0 green") && styleSheetButtonsVolume1.contains("stop: 1 lightgreen")) {
                for(int a = 0; a < 15; ++a){
                    QString styleSheetButtonsVolume2 = buttonsUnits2[a]->styleSheet();
                    if (styleSheetButtonsVolume2.contains("stop: 0 green") && styleSheetButtonsVolume2.contains("stop: 1 lightgreen")) {
                        textLabelNumberUnits = QString::number(convertationFunctions2[a](convertationFunctions1[i](textLabelNumberUnits.toDouble(&ok))));
                        if(!ok){
                            labelNumberUnits.hide();
                            labelUnits2.hide();
                            msgBox.exec();
                        }
                    }
                }
            }
        }

        labelNumberUnits.setText(textLabelNumberUnits);
        QFontMetrics metricsLabelNumberUnits(labelNumberUnits.font());
        textWidthlabelNumberUnits = metricsLabelNumberUnits.horizontalAdvance(textLabelNumberUnits);
        labelNumberUnits.setGeometry(843, 484, textWidthlabelNumberUnits+3, 60);
        labelUnits2.setGeometry(850+textWidthlabelNumberUnits, 484, textWidthLabelUnits2+10, 60);
        if(ok){
            labelNumberUnits.show();
            labelUnits2.show();
        }
    });
    QObject::connect(&buttonText, &QPushButton::clicked, [&](){
        hideAllWidgets(&window);
        lineEditText.show();
        buttonCountText.show();
        labelResultText.show();
        buttonBack.show();
        buttonClean.show();
    });

    QObject::connect(&buttonConvertation, &QPushButton::clicked, [&](){
        hideAllWidgets(&window);
        buttonBack.show();
        buttonVolume.show();
        buttonMass.show();
        buttonTime.show();
        buttonLength.show();
        labelSelectUnits.show();
    });
    QObject::connect(&buttonCountText, &QPushButton::clicked, [&]() {
        QString text = lineEditText.text();
        int count = 0;
        for(QChar i: text){
            if (i != ' '){
                count+=1;
            }
        }
        labelResultText.setText("Number of symbols: " + QString::number(count));
    });
    QObject::connect(&buttonClean, &QPushButton::clicked, [&]() {
        lineEditText.setText("");
        labelResultText.setText("Number of symbols: 0");
    });
    QObject::connect(&buttonBack, &QPushButton::clicked, [&](){
        hideAllWidgets(&window);
        menu(&buttonText, &buttonConvertation, &labelSelect);
    });
    QObject::connect(&buttonBack2, &QPushButton::clicked, [&](){
        hideAllWidgets(&window);
        menuSelectUnits(buttonsUnitsMenu, &window);
        for(QPushButton* button: buttonsUnits){
            blueButtons(button);
        }
        labelUnits1.setText("");
        labelUnits1.hide();
        labelUnits2.setText("");
        labelUnits2.hide();
        labelNumberUnits.setText("");
        labelNumberUnits.hide();
        lineUnits.clear();
        lineUnits.hide();
        buttonConvert.hide();
    });
    QObject::connect(&buttonVolume, &QPushButton::clicked, [&](){
        hideAllWidgets(&window);
        buttonBack2.show();
        for(QPushButton* button: buttonsUnits){
            button->show();
        }
        buttonCleanUnitsVolume.show();
        arrowWidget.show();
        drawArrow = true;
        arrowWidget.update();
    });
    QObject::connect(&buttonCleanUnitsVolume, &QPushButton::clicked, [&](){
        for(QPushButton* button: buttonsUnits){
            blueButtons(button);
        }
        labelUnits1.setText("");
        labelUnits1.hide();
        labelUnits2.setText("");
        labelUnits2.hide();
        labelNumberUnits.setText("");
        labelNumberUnits.hide();
        lineUnits.clear();
        lineUnits.hide();
        buttonConvert.hide();
    });
    window.showMaximized();
    return app.exec();
}
void selectGreenButton(QPushButton* button, std::vector<QPushButton*>& buttonsUnits1){
    for(QPushButton* buttonInList: buttonsUnits1){
        if(buttonInList == button){
            greenButtons(buttonInList);
        }
        else{
            blueButtons(buttonInList);
        }
    }
}
