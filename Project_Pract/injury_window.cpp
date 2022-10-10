#include "injury_window.h"
#include "ui_injury_window.h"
#include <QKeyEvent>
#include "neuro_local_window.h"
#include "pain_local_window.h"
#include "patient_history_data_clasess/document_writer.h"

InjuryWindow::InjuryWindow(QWidget *parent, PatientHistory *patientHistory)
    : QDialog(parent)
    , ui(new Ui::InjuryWindow)
    , _patientHistory(patientHistory) {
    ui->setupUi(this);
    setlocale(LC_ALL, "Russian");
}

InjuryWindow::~InjuryWindow() {
    delete ui;
}

void InjuryWindow::on_dateTimeEdit_editingFinished() {
    std::string date = ui->dateTimeEdit->dateTime().toString().toStdString();
    _patientHistory->getPatientInjuryData()->setDate(date);
    ui->labelDate->setStyleSheet("QLabel#labelDate { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientInjuryData()->injuryDataIsFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxReceived->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxReceived, eve1);
}

void InjuryWindow::on_comboBoxReceived_textActivated(const QString &arg) {
    std::string recieved = arg.toStdString();
    _patientHistory->getPatientInjuryData()->setRecieved(recieved);

    ui->labelReceived->setStyleSheet("QLabel#labelReceived { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientInjuryData()->injuryDataIsFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxMechanism->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxMechanism, eve1);
}

void InjuryWindow::on_comboBoxMechanism_textActivated(const QString &arg) {
    std::string mechanism = arg.toStdString();
    _patientHistory->getPatientInjuryData()->setMechanism(mechanism);

    ui->labelMechanism->setStyleSheet("QLabel#labelMechanism { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientInjuryData()->injuryDataIsFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxLocalization->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxLocalization, eve1);
}

void InjuryWindow::on_comboBoxLocalization_textActivated(const QString &arg) {
    std::string localization = arg.toStdString();
    _patientHistory->getPatientInjuryData()->setLocalization(localization);

    ui->labelLocalization->setStyleSheet("QLabel#labelLocalization { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientInjuryData()->injuryDataIsFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxCharacter->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxCharacter, eve1);
}

void InjuryWindow::on_comboBoxCharacter_textActivated(const QString &arg) {
    std::string character = arg.toStdString();
    _patientHistory->getPatientInjuryData()->setCharacter(character);

    ui->labelCharacter->setStyleSheet("QLabel#labelCharacter { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientInjuryData()->injuryDataIsFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxView->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxView, eve1);
}

void InjuryWindow::on_comboBoxView_textActivated(const QString &arg) {
    std::string view = arg.toStdString();
    _patientHistory->getPatientInjuryData()->setView(view);

    ui->labelView->setStyleSheet("QLabel#labelView { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientInjuryData()->injuryDataIsFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxPower->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxPower, eve1);
}

void InjuryWindow::on_comboBoxPower_textActivated(const QString &arg) {
    std::string power = arg.toStdString();
    _patientHistory->getPatientInjuryData()->setPower(power);

    ui->labelPower->setStyleSheet("QLabel#labelPower { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientInjuryData()->injuryDataIsFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxWhereChange->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxWhereChange, eve1);
}

void InjuryWindow::on_comboBoxWhereChange_textActivated(const QString &arg) {
    std::string whereChange = arg.toStdString();
    _patientHistory->getPatientInjuryData()->setWhereChange(whereChange);

    ui->labelWhereChange->setStyleSheet("QLabel#labelWhereChange { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientInjuryData()->injuryDataIsFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxPain->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxPain, eve1);
}

void InjuryWindow::on_comboBoxPain_textActivated(const QString &arg) {
    std::string pain = arg.toStdString();
    _patientHistory->getPatientInjuryData()->setPain(pain);

    ui->labelPain->setStyleSheet("QLabel#labelPain { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientInjuryData()->injuryDataIsFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    if (arg == "Да") {
        PainLocalWindow window(this, _patientHistory);
        window.setModal(true);
        window.exec();
    }

    ui->comboBoxNeuro->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxNeuro, eve1);
}

void InjuryWindow::on_comboBoxNeuro_textActivated(const QString &arg) {
    std::string neuro = arg.toStdString();
    _patientHistory->getPatientInjuryData()->setNeuro(neuro);

    ui->labelNeuro->setStyleSheet("QLabel#labelNeuro { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientInjuryData()->injuryDataIsFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    if (arg == "Да") {
       NeuroLocalWindow window(this, _patientHistory);
       window.setModal(true);
       window.exec();
    }

    ui->comboBoxCanMove_1->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxCanMove_1, eve1);
}

void InjuryWindow::on_comboBoxCanMove_1_textActivated(const QString &arg) {
    std::string neuro = arg.toStdString();
    _patientHistory->getPatientInjuryData()->setCanMove(neuro);

    ui->labelCanMove->setStyleSheet("QLabel#labelCanMove { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientInjuryData()->injuryDataIsFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    if (arg == "Нет") {
       ui->comboBoxCanMove_2->clear();
       ui->comboBoxCanMove_2->addItem("Левая рука");
       ui->comboBoxCanMove_2->addItem("Правая рука");
       ui->comboBoxCanMove_2->addItem("Левая нога");
       ui->comboBoxCanMove_2->addItem("Правая нога");
    }

    if (arg == "Нет") {
        ui->comboBoxCanMove_2->setFocus();
        QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
        qApp->postEvent(ui->comboBoxCanMove_2, eve1);
    } else {
        ui->comboBoxCanUp->setFocus();
        QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
        qApp->postEvent(ui->comboBoxCanUp, eve1);
        _patientHistory->getPatientInjuryData()->setCanMove_1("0");
    }
}

void InjuryWindow::on_comboBoxCanMove_2_textActivated(const QString &arg) {
    std::string neuro = arg.toStdString();
    _patientHistory->getPatientInjuryData()->setCanMove_1(neuro);

    ui->labelCanMove->setStyleSheet("QLabel#labelCanMove { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientInjuryData()->injuryDataIsFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxCanUp->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxCanUp, eve1);
}

void InjuryWindow::on_comboBoxCanUp_textActivated(const QString &arg) {
    std::string neuro = arg.toStdString();
    _patientHistory->getPatientInjuryData()->setCanUp(neuro);

    ui->labelCanUp->setStyleSheet("QLabel#labelCanUp { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientInjuryData()->injuryDataIsFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxCanWalk->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxCanWalk, eve1);
}

void InjuryWindow::on_comboBoxCanWalk_textActivated(const QString &arg) {
    std::string neuro = arg.toStdString();
    _patientHistory->getPatientInjuryData()->setCanWalk(neuro);

    ui->labelCanWalk->setStyleSheet("QLabel#labelCanWalk { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientInjuryData()->injuryDataIsFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxHelp_1->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxHelp_1, eve1);
}

void InjuryWindow::on_comboBoxHelp_1_textActivated(const QString &arg) {
    std::string neuro = arg.toStdString();
    _patientHistory->getPatientInjuryData()->setHelp(neuro);

    ui->labelHelp->setStyleSheet("QLabel#labelHelp { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientInjuryData()->injuryDataIsFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    if (arg == "Да") {
        ui->comboBoxHelp_2->clear();
        ui->comboBoxHelp_2->addItem("Взаимопомощь");
        ui->comboBoxHelp_2->addItem("Врач скорой помощи");
    }

    if (arg == "Да") {
        ui->comboBoxHelp_2->setFocus();
        QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
        qApp->postEvent(ui->comboBoxHelp_2, eve1);
    } else {
        ui->comboBoxFirstHelp->setFocus();
        QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
        qApp->postEvent(ui->comboBoxFirstHelp, eve1);
        _patientHistory->getPatientInjuryData()->setHelp_1("0");
    }
}

void InjuryWindow::on_comboBoxHelp_2_textActivated(const QString &arg) {
    std::string neuro = arg.toStdString();
    _patientHistory->getPatientInjuryData()->setHelp_1(neuro);

    ui->labelHelp->setStyleSheet("QLabel#labelHelp { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientInjuryData()->injuryDataIsFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxFirstHelp->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxFirstHelp, eve1);

}

void InjuryWindow::on_comboBoxFirstHelp_textActivated(const QString &arg) {
    std::string neuro = arg.toStdString();
    _patientHistory->getPatientInjuryData()->setFirstHelp(neuro);

    ui->labelFirstHelp->setStyleSheet("QLabel#labelFirstHelp { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientInjuryData()->injuryDataIsFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxTransport->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxTransport, eve1);
}

void InjuryWindow::on_comboBoxTransport_textActivated(const QString &arg) {
    std::string neuro = arg.toStdString();
    _patientHistory->getPatientInjuryData()->setTransport(neuro);

    ui->labelTransport->setStyleSheet("QLabel#labelTransport { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientInjuryData()->injuryDataIsFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxPosition->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxPosition, eve1);
}

void InjuryWindow::on_comboBoxPosition_textActivated(const QString &arg) {
    std::string neuro = arg.toStdString();
    _patientHistory->getPatientInjuryData()->setPosition(neuro);

    ui->labelPosition->setStyleSheet("QLabel#labelPosition { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientInjuryData()->injuryDataIsFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxImmobilization->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxImmobilization, eve1);
}

void InjuryWindow::on_comboBoxImmobilization_textActivated(const QString &arg) {
    std::string neuro = arg.toStdString();
    _patientHistory->getPatientInjuryData()->setImmobilization(neuro);

    ui->labelImmobilization->setStyleSheet("QLabel#labelImmobilization { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientInjuryData()->injuryDataIsFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->textEditAddition->setFocus();
}

void InjuryWindow::on_textEditAddition_textChanged() {
    std::string neuro = ui->textEditAddition->toPlainText().toStdString();
    _patientHistory->getPatientInjuryData()->setAddition(neuro);

    ui->labelAddition_2->setStyleSheet("QLabel#labelAddition_2 { background-color: rgba(144, 238, 144, 180); }");
}

void InjuryWindow::on_buttonResult_clicked() {
    if (_patientHistory->getPatientInjuryData()->injuryDataIsFull()) {
        IllnessCode illnessCode;
        std::vector<std::string> forCodeData = _patientHistory->getPatientInjuryData()->getInjuryData();
        std::string codeData = illnessCode.Encrypt(forCodeData);

        QString codeQStr = QString::fromStdString(codeData);
        ui->labelResult->setText(codeQStr);

        std::string text;
        std::string firstStrToDoc = _patientHistory->getPatientData()->makeText();
        text += firstStrToDoc;

        text += "\n---------------------------------------------------------------------\n";

        std::string sex;
        if (_patientHistory->getPatientData()->getSex() == "Мужской") {
            sex = "man";
        } else {
            sex = "women";
        }
        std::string patientDisease = _patientHistory->getPatientInjuryData()->makeText(sex);
        text += patientDisease;

        text += "\n---------------------------------------------------------------------\n";
        text += "Предположительные диагнозы:\n";

        DocumentWriter doc;
        doc.writeToDocx(text);
    } else {
        ui->labelResult->setText("Не все обязательные поля заполнены!");
    }
}







