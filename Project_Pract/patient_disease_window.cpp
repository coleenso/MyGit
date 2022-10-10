#include "patient_disease_window.h"
#include "ui_patient_disease_window.h"
#include <iostream>

PatientDiseaseWindow::PatientDiseaseWindow(QWidget *parent, PatientHistory *patientHistory)
    : QDialog(parent)
    , ui(new Ui::PatientDiseaseWindow)
    , _patientHistory(patientHistory) {
    setlocale(LC_ALL, "Russian");
    ui->setupUi(this);
    ui->labelPatientHistoryWithSpinalDisease->setFocus();
}

PatientDiseaseWindow::~PatientDiseaseWindow() {
    delete ui;
}

void PatientDiseaseWindow::on_dateTimeEditDiseaseStart_dateChanged(const QDate &date) {
    std::string diseaseStart = date.toString().toStdString();
    _patientHistory->getPatientDiseaseData()->setDiseaseStartTime(diseaseStart);


}

void PatientDiseaseWindow::on_dateTimeEditDiseaseStart_editingFinished() {
    std::string diseaseStart = ui->dateTimeEditDiseaseStart->dateTime().toString().toStdString();
    _patientHistory->getPatientDiseaseData()->setDiseaseStartTime(diseaseStart);
    ui->labelDiseaseStartTime->setStyleSheet("QLabel#labelDiseaseStartTime { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientDiseaseData()->diseaseDataIsFull()) {
        ui->labelPatientHistoryWithSpinalDisease->setStyleSheet("QLabel#labelPatientHistoryWithSpinalDisease { background-color: rgba(144, 238, 144, 180) }");
    }
    ui->comboBoxOccurrenceOfDisease->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxOccurrenceOfDisease, eve1);
}

void PatientDiseaseWindow::on_comboBoxOccurrenceOfDisease_textActivated(const QString &arg) {
    std::string occurrence = arg.toStdString();
    _patientHistory->getPatientDiseaseData()->setOccurrenceOfDisease(occurrence);
    ui->labelOccurrenceOfDisease->setStyleSheet("QLabel#labelOccurrenceOfDisease { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientDiseaseData()->diseaseDataIsFull()) {
        ui->labelPatientHistoryWithSpinalDisease->setStyleSheet("QLabel#labelPatientHistoryWithSpinalDisease { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxManifestationOfDisease->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxManifestationOfDisease, eve1);
}

void PatientDiseaseWindow::on_comboBoxManifestationOfDisease_textActivated(const QString &arg) {\
    std::string manifestation = arg.toStdString();
    _patientHistory->getPatientDiseaseData()->setManifestationOfDisease(manifestation);
    ui->labelManifestationOfDisease->setStyleSheet("QLabel#labelManifestationOfDisease { background-color: rgba(144, 238, 144, 180); }");
    if (arg == "Боли") {
        PainLocalWindow window(this, _patientHistory);
        window.setModal(true);
        window.exec();
    } else if (arg == "Деформация туловища") {
        DeformationLocalWindow window(this, _patientHistory);
        window.setModal(true);
        window.exec();
    } else if (arg == "Неврологические нарушения") {
        NeuroLocalWindow window(this, _patientHistory);
        window.setModal(true);
        window.exec();
    } else if (arg == "Не проявляет") {
        ui->labelManifestationOfDisease->setStyleSheet("QLabel#labelManifestationOfDisease { background-color: rgba(144, 238, 144, 180); }");

        if (_patientHistory->getPatientDiseaseData()->diseaseDataIsFull()) {
            ui->labelPatientHistoryWithSpinalDisease->setStyleSheet("QLabel#labelPatientHistoryWithSpinalDisease { background-color: rgba(144, 238, 144, 180) }");
        }
    }

    ui->comboBoxRevealed->setFocus();
}

void PatientDiseaseWindow::on_comboBoxRevealed_textActivated(const QString &arg) {
    std::string revealed = arg.toStdString();
    _patientHistory->getPatientDiseaseData()->setRevealed(revealed);
    ui->labelRevealed->setStyleSheet("QLabel#labelRevealed { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientDiseaseData()->diseaseDataIsFull()) {
        ui->labelPatientHistoryWithSpinalDisease->setStyleSheet("QLabel#labelPatientHistoryWithSpinalDisease { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->dateTimeEditFirstWentToMedicalFacility->setFocus();
}

void PatientDiseaseWindow::on_dateTimeEditFirstWentToMedicalFacility_dateChanged(const QDate &date) {
    std::string firstWentToMedicalFacility = date.toString().toStdString();
    _patientHistory->getPatientDiseaseData()->setFirstWentToMedicalFacility(firstWentToMedicalFacility);
    ui->labelFirstWentToMedicalFacility->setStyleSheet("QLabel#labelFirstWentToMedicalFacility { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientDiseaseData()->diseaseDataIsFull()) {
        ui->labelPatientHistoryWithSpinalDisease->setStyleSheet("QLabel#labelPatientHistoryWithSpinalDisease { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxMedicalFacility->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxMedicalFacility, eve1);
}

void PatientDiseaseWindow::on_dateTimeEditFirstWentToMedicalFacility_editingFinished() {
    std::string firstWentToMedicalFacility = ui->dateTimeEditFirstWentToMedicalFacility->dateTime().toString().toStdString();
    _patientHistory->getPatientDiseaseData()->setFirstWentToMedicalFacility(firstWentToMedicalFacility);
    ui->labelFirstWentToMedicalFacility->setStyleSheet("QLabel#labelFirstWentToMedicalFacility { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientDiseaseData()->diseaseDataIsFull()) {
        ui->labelPatientHistoryWithSpinalDisease->setStyleSheet("QLabel#labelPatientHistoryWithSpinalDisease { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxMedicalFacility->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxMedicalFacility, eve1);
}

void PatientDiseaseWindow::on_comboBoxMedicalFacility_textActivated(const QString &arg) {
    std::string medicalFacility = arg.toStdString();
    _patientHistory->getPatientDiseaseData()->setMedicalFacility(medicalFacility);
    ui->labelMedicalFacility->setStyleSheet("QLabel#labelMedicalFacility { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientDiseaseData()->diseaseDataIsFull()) {
        ui->labelPatientHistoryWithSpinalDisease->setStyleSheet("QLabel#labelPatientHistoryWithSpinalDisease { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->lineEditTreatmentTimeInDays->setFocus();
}

void PatientDiseaseWindow::on_lineEditTreatmentTimeInDays_editingFinished() {
    std::string treatmentTimeInDays = ui->lineEditTreatmentTimeInDays->text().toStdString();
    _patientHistory->getPatientDiseaseData()->setTreatmentTimeInDays(treatmentTimeInDays);
    if (treatmentTimeInDays != "") {
        ui->labelTreatmentTimeInDays->setStyleSheet("QLabel#labelTreatmentTimeInDays { background-color: rgba(144, 238, 144, 180); }");
    } else {
        ui->labelTreatmentTimeInDays->setStyleSheet("QLabel#labelSurname { background-color: rgba(255, 255, 255, 120); }");
    }

    if (_patientHistory->getPatientDiseaseData()->diseaseDataIsFull()) {
        ui->labelPatientHistoryWithSpinalDisease->setStyleSheet("QLabel#labelPatientHistoryWithSpinalDisease { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxTypeOfTreatment->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxTypeOfTreatment, eve1);
}

void PatientDiseaseWindow::on_comboBoxTypeOfTreatment_textActivated(const QString &arg) {
    std::string typeOfTreatment = arg.toStdString();
    _patientHistory->getPatientDiseaseData()->setTypeOfTreatment(typeOfTreatment);

    if (arg == "Консервативное") {
        ui->comboBoxTypeOfTreatmentAddition->clear();
        ui->comboBoxTypeOfTreatmentAddition->addItem("Медикаментозное");
        ui->comboBoxTypeOfTreatmentAddition->addItem("Новокаиновые блокады");
        ui->comboBoxTypeOfTreatmentAddition->addItem("Физиолечение");
        ui->comboBoxTypeOfTreatmentAddition->addItem("Иглоукалывание");
        ui->comboBoxTypeOfTreatmentAddition->addItem("Вытяжение");
        ui->comboBoxTypeOfTreatmentAddition->addItem("Бальнеолечение");
        ui->comboBoxTypeOfTreatmentAddition->addItem("Корсетотерапия");
        ui->comboBoxTypeOfTreatmentAddition->addItem("ЛФК");
        ui->comboBoxTypeOfTreatmentAddition->addItem("Прочее");
    } else if (arg == "Оперативное") {
        ui->comboBoxTypeOfTreatmentAddition->clear();
        ui->comboBoxTypeOfTreatmentAddition->addItem("Вытяжение");
        ui->comboBoxTypeOfTreatmentAddition->addItem("На передних отделах позвоночника");
        ui->comboBoxTypeOfTreatmentAddition->addItem("На задних отделах позвоночника");
        ui->comboBoxTypeOfTreatmentAddition->addItem("Прочее");
    } else if (arg == "Санаторно - курортное") {
        ui->comboBoxTypeOfTreatmentAddition->clear();
        ui->comboBoxTypeOfTreatmentAddition->addItem("Санитарно - курортное");
    }

    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    if (typeOfTreatment == "Нет") {
        ui->labelTypeOfTreatment->setStyleSheet("QLabel#labelTypeOfTreatment { background-color: rgba(144, 238, 144, 180); }");
        ui->comboBoxTreatmentResult->setFocus();
        qApp->postEvent(ui->comboBoxTreatmentResult, eve1);
        _patientHistory->getPatientDiseaseData()->setTypeOfTreatmentAddition("0");
    } else {
        ui->comboBoxTypeOfTreatmentAddition->setFocus();
        qApp->postEvent(ui->comboBoxTypeOfTreatmentAddition, eve1);
    }

    if (_patientHistory->getPatientDiseaseData()->diseaseDataIsFull()) {
        ui->labelPatientHistoryWithSpinalDisease->setStyleSheet("QLabel#labelPatientHistoryWithSpinalDisease { background-color: rgba(144, 238, 144, 180) }");
    }
}

void PatientDiseaseWindow::on_comboBoxTypeOfTreatmentAddition_textActivated(const QString &arg) {
    std::string typeOfTreatmentAddition = arg.toStdString();
    _patientHistory->getPatientDiseaseData()->setTypeOfTreatmentAddition(typeOfTreatmentAddition);

    ui->labelTypeOfTreatment->setStyleSheet("QLabel#labelTypeOfTreatment { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientDiseaseData()->diseaseDataIsFull()) {
        ui->labelPatientHistoryWithSpinalDisease->setStyleSheet("QLabel#labelPatientHistoryWithSpinalDisease { background-color: rgba(144, 238, 144, 180) }");
    }

    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    ui->comboBoxTreatmentResult->setFocus();
    qApp->postEvent(ui->comboBoxTreatmentResult, eve1);
}

void PatientDiseaseWindow::on_comboBoxTreatmentResult_textActivated(const QString &arg) {
    std::string treatmentResult = arg.toStdString();
    _patientHistory->getPatientDiseaseData()->setTreatmentResult(treatmentResult);
    ui->labelTreatmentResult->setStyleSheet("QLabel#labelTreatmentResult { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientDiseaseData()->diseaseDataIsFull()) {
        ui->labelPatientHistoryWithSpinalDisease->setStyleSheet("QLabel#labelPatientHistoryWithSpinalDisease { background-color: rgba(144, 238, 144, 180) }");
    }

    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    ui->comboBoxNewDisease->setFocus();
    qApp->postEvent(ui->comboBoxNewDisease, eve1);
}

void PatientDiseaseWindow::on_comboBoxNewDisease_textActivated(const QString &arg) {
    std::string newDisease = arg.toStdString();
    _patientHistory->getPatientDiseaseData()->setNewDisease(newDisease);
    ui->labelNewDisease->setStyleSheet("QLabel#labelNewDisease { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientDiseaseData()->diseaseDataIsFull()) {
        ui->labelPatientHistoryWithSpinalDisease->setStyleSheet("QLabel#labelPatientHistoryWithSpinalDisease { background-color: rgba(144, 238, 144, 180) }");
    }

    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    ui->comboBoxWentToOtherMedicalFacility->setFocus();
    qApp->postEvent(ui->comboBoxWentToOtherMedicalFacility, eve1);
}

void PatientDiseaseWindow::on_comboBoxWentToOtherMedicalFacility_textActivated(const QString &arg) {
    std::string wentToOtherMedicalFacility = arg.toStdString();
    _patientHistory->getPatientDiseaseData()->setWentToOtherMedicalFacility(wentToOtherMedicalFacility);
    ui->labelWentToOtherMedicalFacility->setStyleSheet("QLabel#labelWentToOtherMedicalFacility { background-color: rgba(144, 238, 144, 180); }");

    if (_patientHistory->getPatientDiseaseData()->diseaseDataIsFull()) {
        ui->labelPatientHistoryWithSpinalDisease->setStyleSheet("QLabel#labelPatientHistoryWithSpinalDisease { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->textEditAddition->setFocus();
}

void PatientDiseaseWindow::on_textEditAddition_textChanged() {
    std::string addition = ui->textEditAddition->toPlainText().toStdString();
    _patientHistory->getPatientDiseaseData()->setAddition(addition);
    ui->labelAddition_2->setStyleSheet("QLabel#labelAddition_2 { background-color: rgba(144, 238, 144, 180); }");
}

void PatientDiseaseWindow::on_buttonClose_clicked() {
    this->close();
}

void PatientDiseaseWindow::on_buttonResult_clicked() {
    if (_patientHistory->getPatientDiseaseData()->diseaseDataIsFull() && _patientHistory->getPatientDiseaseData()->diseaseManifestationIsFull()) {
        IllnessCode illnessCode;
        std::vector<std::string> forCodeData = _patientHistory->getPatientDiseaseData()->getDiseaseData();
        std::string codeData = illnessCode.Encrypt(forCodeData);
        codeData += "|";

        std::vector<std::string> forCodeManifestation = _patientHistory->getPatientDiseaseData()->getDiseaseManifestation();
        std::string codeManifestation = illnessCode.Encrypt(forCodeManifestation);
        std::string result = codeData + codeManifestation;

        QString codeQStr = QString::fromStdString(result);
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
        std::string patientDisease = _patientHistory->getPatientDiseaseData()->makeText(sex);
        text += patientDisease;
        std::string age = _patientHistory->getPatientData()->getAge();
        std::vector<std::string> disMan = _patientHistory->getPatientDiseaseData()->getDiseaseManifestation();
        std::vector<std::string> dis = _patientHistory->getPatientDiseaseData()->getDiseaseData();
        if (disMan[0] == "Спина" && disMan[6] != "Спина" && dis[12].find("усталость") != std::string::npos
                && (age == "10" || age == "11" || age == "12" || age == "13" || age == "14" || age == "15" || age == "16")) {
                text += "Болезнь Шейермана-Мау.\n";
        }

        DocumentWriter doc;
        doc.writeToDocx(text);
    } else {
        ui->labelResult->setText("Не все обязательные поля заполнены!");
    }
}

void PatientDiseaseWindow::keyPressEvent(QKeyEvent *event) {

}


