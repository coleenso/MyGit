#include "neuro_local_window.h"
#include "ui_neuro_local_window.h"
#include <QKeyEvent>

NeuroLocalWindow::NeuroLocalWindow(QWidget *parent, PatientHistory *patientHistory)
    : QDialog(parent)
    , ui(new Ui::NeuroLocalWindow)
    , _patientHistory(patientHistory) {
    ui->setupUi(this);
    setlocale(LC_ALL, "Russian");
}

NeuroLocalWindow::~NeuroLocalWindow() {
    delete ui;
}

void NeuroLocalWindow::on_comboBoxPartOfTheBody_textActivated(const QString &arg) {
    std::string partOfTheBody = arg.toStdString();
    _neuroLocalData.setPartOfTheBody(partOfTheBody);

    ui->labelPartOfTheBody->setStyleSheet("QLabel#labelPartOfTheBody { background-color: rgba(144, 238, 144, 180); }");

    if (_neuroLocalData.isFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxClarification->clear();
    ui->comboBoxSurface->clear();

    if (arg == "Спина") {
        ui->comboBoxClarification->addItem("Копчиковый отдел");
        ui->comboBoxClarification->addItem("Кресцовый отдел");
        ui->comboBoxClarification->addItem("Поясничный отдел");
        ui->comboBoxClarification->addItem("Грудной отдел");
        ui->comboBoxClarification->addItem("Шейный отдел");
        _neuroLocalData.setSurface("0");
    } else if (arg == "Нога") {
        ui->comboBoxClarification->addItem("Таз");
        ui->comboBoxClarification->addItem("Бедро (Внутреняя сторона)");
        ui->comboBoxClarification->addItem("Бедро (Внешняя сторона)");
        ui->comboBoxClarification->addItem("Колено");
        ui->comboBoxClarification->addItem("Подколенная область");
        ui->comboBoxClarification->addItem("Голиностоп");
        ui->comboBoxClarification->addItem("Пятка");
        ui->comboBoxClarification->addItem("Стопа");
        ui->comboBoxClarification->addItem("Пальцы");
        ui->comboBoxClarification->addItem("Паховая область");
        ui->comboBoxClarification->addItem("Пятка");
        ui->comboBoxSurface->addItem("Внутренняя");
        ui->comboBoxSurface->addItem("Внешняя");
        ui->comboBoxSurface->addItem("Передняя");
        ui->comboBoxSurface->addItem("Задняя");
    } else if (arg == "Рука") {
        ui->comboBoxClarification->addItem("Плечо");
        ui->comboBoxClarification->addItem("Локоть");
        ui->comboBoxClarification->addItem("Запястье");
        ui->comboBoxClarification->addItem("Кончики пальцев");
        ui->comboBoxClarification->addItem("Пальцы");
        ui->comboBoxClarification->addItem("Предплечье");
        ui->comboBoxClarification->addItem("Ключица");
        _neuroLocalData.setSurface("0");
    } else if (arg == "Голова") {
        ui->comboBoxClarification->addItem("Лобная часть");
        ui->comboBoxClarification->addItem("Теменная часть");
        ui->comboBoxClarification->addItem("Затылочная часть");
        ui->comboBoxClarification->addItem("Височная часть");
        ui->comboBoxClarification->addItem("Лицевая часть");
        ui->comboBoxSurface->addItem("Внутренняя");
        ui->comboBoxSurface->addItem("Внешняя");
        ui->comboBoxSurface->addItem("Передняя");
        ui->comboBoxSurface->addItem("Задняя");
    } else if (arg == "Тело") {
        ui->comboBoxClarification->addItem("Грудина");
        ui->comboBoxClarification->addItem("За грудиной ");
        ui->comboBoxClarification->addItem("Под лопаткой");
        ui->comboBoxClarification->addItem("Межреберье");
        ui->comboBoxClarification->addItem("Брюшная область");
        _neuroLocalData.setSurface("0");
    } else if (arg == "Нет") {
        _neuroLocalData.setClarification("0");
        _neuroLocalData.setSurface("0");
    }

    if (arg == "Нет") {
        ui->comboBoxSide->setFocus();
        QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
        qApp->postEvent(ui->comboBoxSide, eve1);
    } else {
        ui->comboBoxClarification->setFocus();
        QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
        qApp->postEvent(ui->comboBoxClarification, eve1);
    }
}

void NeuroLocalWindow::on_comboBoxClarification_textActivated(const QString &arg) {
    std::string clarification = arg.toStdString();
    _neuroLocalData.setClarification(clarification);

    ui->labelClarification->setStyleSheet("QLabel#labelClarification { background-color: rgba(144, 238, 144, 180); }");

    if (_neuroLocalData.isFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxSide->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxSide, eve1);
}

void NeuroLocalWindow::on_comboBoxSide_textActivated(const QString &arg) {
    std::string side = arg.toStdString();
    _neuroLocalData.setSide(side);

    ui->labelSide->setStyleSheet("QLabel#labelSide { background-color: rgba(144, 238, 144, 180); }");

    if (_neuroLocalData.isFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    if (_neuroLocalData.getSurface() == "0") {
        ui->comboBoxDisorder->setFocus();
        QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
        qApp->postEvent(ui->comboBoxDisorder, eve1);
    } else {
        ui->comboBoxSurface->setFocus();
        QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
        qApp->postEvent(ui->comboBoxSurface, eve1);
    }
}

void NeuroLocalWindow::on_comboBoxSurface_textActivated(const QString &arg) {
    std::string surface = arg.toStdString();
    _neuroLocalData.setSurface(surface);

    ui->labelSurface->setStyleSheet("QLabel#labelSurface { background-color: rgba(144, 238, 144, 180); }");

    if (_neuroLocalData.isFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxDisorder->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxDisorder, eve1);
}

void NeuroLocalWindow::on_comboBoxDisorder_textActivated(const QString &arg) {
    std::string disorder = arg.toStdString();
    _neuroLocalData.setDisorder(disorder);

    ui->comboBoxView->clear();

    if (arg == "Двигательные функции") {
        ui->comboBoxView->addItem("Парез");
        ui->comboBoxView->addItem("Паралич");
    } else if (arg == "Чувствительность") {
        ui->comboBoxView->addItem("Парастезия");
        ui->comboBoxView->addItem("Гиперстезия");
        ui->comboBoxView->addItem("Гипостезия");
        ui->comboBoxView->addItem("Дистезия");
    } else if (arg == "Нет") {
        _neuroLocalData.setView("0");
    }

    ui->labelDisorder->setStyleSheet("QLabel#labelDisorder { background-color: rgba(144, 238, 144, 180); }");

    if (_neuroLocalData.isFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    if (_neuroLocalData.getView() != "0") {
        ui->comboBoxView->setFocus();
        QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
        qApp->postEvent(ui->comboBoxView, eve1);
    } else {
        ui->buttonOk->setFocus();
    }
}

void NeuroLocalWindow::on_comboBoxView_textActivated(const QString &arg) {
    std::string view = arg.toStdString();
    _neuroLocalData.setView(view);
    ui->labelView->setStyleSheet("QLabel#labelView { background-color: rgba(144, 238, 144, 180); }");

    if (_neuroLocalData.isFull()) {
        ui->labelTitle->setStyleSheet("QLabel#labelTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->buttonOk->setFocus();
}

void NeuroLocalWindow::on_buttonOk_clicked() {
    if (_neuroLocalData.isFull()) {
        _patientHistory->getPatientDiseaseData()->setDiseaseManifestation(_neuroLocalData.getNeuroLocalData());
        _patientHistory->getPatientInjuryData()->setLocalNeuroData(_neuroLocalData.getNeuroLocalData());
        this->close();
    }
}

