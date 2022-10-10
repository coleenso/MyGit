#include "main_window.h"
#include "ui_main_window.h"
#include "patient_disease_window.h"
#include "injury_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setlocale(LC_ALL, "Russian");
    ui->lineEditSurname->setFocus();

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_lineEditSurname_editingFinished() {
    std::string surname = ui->lineEditSurname->text().toStdString();
    patientHistory.getPatientData()->setSurname(surname);
    if (ui->lineEditSurname->text() == "") {
        ui->labelSurname->setStyleSheet("QLabel#labelSurname { background-color: rgba(255, 255, 255, 120); }");
    } else {
        ui->labelSurname->setStyleSheet("QLabel#labelSurname { background-color: rgba(144, 238, 144, 180); }");
    }

    if (patientHistory.getPatientData()->isFull()) {
        ui->labelPatienData->setStyleSheet("QLabel#labelPatienData { background-color: rgba(144, 238, 144, 180) }");
    }
}

void MainWindow::on_lineEditName_editingFinished() {
    std::string name = ui->lineEditName->text().toStdString();
    patientHistory.getPatientData()->setName(name);
    if (ui->lineEditName->text() == "") {
        ui->labelName->setStyleSheet("QLabel#labelName { background-color: rgba(255, 255, 255, 120); }");
    } else {
        ui->labelName->setStyleSheet("QLabel#labelName { background-color: rgba(144, 238, 144, 180); }");
    }

    if (patientHistory.getPatientData()->isFull()) {
        ui->labelPatienData->setStyleSheet("QLabel#labelPatienData { background-color: rgba(144, 238, 144, 180) }");
    }
}

void MainWindow::on_lineEditPatronymic_editingFinished() {
    std::string patronymic = ui->lineEditPatronymic->text().toStdString();
    patientHistory.getPatientData()->setPatronymic(patronymic);
    if (ui->lineEditPatronymic->text() == "") {
        ui->labelPatronymic->setStyleSheet("QLabel#labelPatronymic { background-color: rgba(255, 255, 255, 120); }");
    } else {
        ui->labelPatronymic->setStyleSheet("QLabel#labelPatronymic { background-color: rgba(144, 238, 144, 180); }");
    }

    if (patientHistory.getPatientData()->isFull()) {
        ui->labelPatienData->setStyleSheet("QLabel#labelPatienData { background-color: rgba(144, 238, 144, 180) }");
    }
}

void MainWindow::on_dateEditBirthday_userDateChanged(const QDate &date) {
    std::string birthday = date.toString().toStdString();
    patientHistory.getPatientData()->setBirthday(birthday);
}

void MainWindow::on_comboBoxSex_textActivated(const QString &arg) {
    std::string sex = arg.toStdString();
    patientHistory.getPatientData()->setSex(sex);
    ui->labelSex->setStyleSheet("QLabel#labelSex { background-color: rgba(144, 238, 144, 180); }");

    if (patientHistory.getPatientData()->isFull()) {
        ui->labelPatienData->setStyleSheet("QLabel#labelPatienData { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->lineEditAge->setFocus();
}

void MainWindow::on_lineEditAge_editingFinished() {
    std::string age = ui->lineEditAge->text().toStdString();
    patientHistory.getPatientData()->setAge(age);
    if (ui->lineEditAge->text() == "") {
        ui->labelAge->setStyleSheet("QLabel#labelAge { background-color: rgba(255, 255, 255, 120); }");
    } else {
        ui->labelAge->setStyleSheet("QLabel#labelAge { background-color: rgba(144, 238, 144, 180); }");
    }

    if (patientHistory.getPatientData()->isFull()) {
        ui->labelPatienData->setStyleSheet("QLabel#labelPatienData { background-color: rgba(144, 238, 144, 180) }");
    }

}

void MainWindow::on_textEditAddition_textChanged() {
    std::string addition = ui->textEditAddition->toPlainText().toStdString();
    patientHistory.getPatientData()->setAddition(addition);
    ui->labelAddition->setStyleSheet("QLabel#labelAddition { background-color: rgba(144, 238, 144, 180); }");
}

void MainWindow::on_buttonDisease_clicked() {
    if (patientHistory.getPatientData()->isFull()) {
        ui->labelHistoryTaking->setText("Сбор анамнеза");
        PatientDiseaseWindow window(nullptr, &patientHistory);
        window.setModal(true);
        window.exec();
    } else {
        ui->labelHistoryTaking->setText("Не все обязательные поля заполнены!");
    }
}

void MainWindow::on_buttonInjury_clicked() {
    if (patientHistory.getPatientData()->isFull()) {
        ui->labelHistoryTaking->setText("Сбор анамнеза");
        InjuryWindow window(this, &patientHistory);
        window.setModal(true);
        window.exec();
    } else {
        ui->labelHistoryTaking->setText("Не все обязательные поля заполнены!");
    }
}

void MainWindow::on_dateEditBirthday_editingFinished() {
    std::string birthday = ui->dateEditBirthday->date().toString().toStdString();
    patientHistory.getPatientData()->setBirthday(birthday);
    ui->labelBirthday->setStyleSheet("QLabel#labelBirthday { background-color: rgba(144, 238, 144, 180); }");
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Return && ui->lineEditSurname->hasFocus()) {
        ui->lineEditName->setFocus();
    } else if (event->key() == Qt::Key_Return && ui->lineEditName->hasFocus()) {
        ui->lineEditPatronymic->setFocus();
    } else if (event->key() == Qt::Key_Return && ui->lineEditPatronymic->hasFocus()) {
        ui->dateEditBirthday->setFocus();
    } else if (event->key() == Qt::Key_Return && ui->dateEditBirthday->hasFocus()) {
        ui->comboBoxSex->setFocus();
        ui->comboBoxSex->show();
        QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier)  ;
        qApp->postEvent(ui->comboBoxSex, eve1);
    } else if (event->key() == Qt::Key_Return && ui->comboBoxSex->hasFocus()) {
        ui->lineEditAge->setFocus();
    } else if (event->key() == Qt::Key_Return && ui->lineEditAge->hasFocus()) {
        ui->textEditAddition->setFocus();
    } else if (event->key() == Qt::Key_Return && ui->textEditAddition->hasFocus()) {
        ui->lineEditSurname->setFocus();
    }
}


