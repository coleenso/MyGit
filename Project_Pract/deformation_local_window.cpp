#include "deformation_local_window.h"
#include "ui_deformation_local_window.h"
#include <QKeyEvent>

DeformationLocalWindow::DeformationLocalWindow(QWidget *parent, PatientHistory *patientHistory)
    : QDialog(parent)
    , ui(new Ui::DeformationLocalWindow)
    , _patientHistory(patientHistory) {
    ui->setupUi(this);
    setlocale(LC_ALL, "Russian");
}

DeformationLocalWindow::~DeformationLocalWindow() {
    delete ui;
}

void DeformationLocalWindow::on_comboBoxDeformationLocalInfo_textActivated(const QString &arg) {
    std::string deformationLocalInfo = arg.toStdString();
    _deformationLocalData.setDeformationLocalInfo(deformationLocalInfo);

    ui->labelDeformationLocal->setStyleSheet("QLabel#labelDeformationLocal { background-color: rgba(144, 238, 144, 180); }");

    ui->comboBoxView->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxView, eve1);
}

void DeformationLocalWindow::on_comboBoxView_textActivated(const QString &arg) {
    std::string view = arg.toStdString();
    _deformationLocalData.setView(view);
    ui->labelView->setStyleSheet("QLabel#labelView { background-color: rgba(144, 238, 144, 180); }");

    ui->comboBoxDegree->clear();
    if (arg == "Сколиоз") {
        ui->comboBoxDegree->addItem("Не выявлено");
        ui->comboBoxDegree->addItem("1 степени");
        ui->comboBoxDegree->addItem("2 степени");
        ui->comboBoxDegree->addItem("3 степени");
        ui->comboBoxDegree->addItem("4 степени");
    } else if (arg == "Кифоз") {
        ui->comboBoxDegree->addItem("Не выявлено");
        ui->comboBoxDegree->addItem("1 степени");
        ui->comboBoxDegree->addItem("2 степени");
        ui->comboBoxDegree->addItem("3 степени");
    } else if (arg == "Лордоз") {
        ui->comboBoxDegree->addItem("Не выявлено");
        ui->comboBoxDegree->addItem("Гиперлордоз");
        ui->comboBoxDegree->addItem("Гиполордоз");
    } else if (arg == "Ротация") {
        ui->comboBoxDegree->addItem("Не выявлено");
        ui->comboBoxDegree->addItem("0 степени");
        ui->comboBoxDegree->addItem("1 степени");
        ui->comboBoxDegree->addItem("2 степени");
        ui->comboBoxDegree->addItem("3 степени");
        ui->comboBoxDegree->addItem("4 степени");
    } else if (arg == "Не определено") {
        ui->comboBoxDegree->addItem("Не выявлено");
    }

    ui->comboBoxSide->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxSide, eve1);
}

void DeformationLocalWindow::on_comboBoxSide_textActivated(const QString &arg) {
    std::string side = arg.toStdString();
    _deformationLocalData.setSide(side);
    ui->labelSide->setStyleSheet("QLabel#labelSide { background-color: rgba(144, 238, 144, 180); }");

    ui->comboBoxDegree->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxDegree, eve1);
}

void DeformationLocalWindow::on_comboBoxDegree_textActivated(const QString &arg) {
    std::string degree = arg.toStdString();
    _deformationLocalData.setDegree(degree);

    ui->labelDegree->setStyleSheet("QLabel#labelDegree { background-color: rgba(144, 238, 144, 180); }");
    ui->labelPreviouslyInstalled->setStyleSheet("QLabel#labelPreviouslyInstalled { background-color: rgba(144, 238, 144, 180); }");
    ui->buttonOk->setFocus();
}

void DeformationLocalWindow::on_buttonOk_clicked() {
    if (_deformationLocalData.isFull()) {
        _patientHistory->getPatientDiseaseData()->setDiseaseManifestation(_deformationLocalData.getDeformationLocalData());
        this->close();
    }
}

