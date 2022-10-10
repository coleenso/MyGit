#include "pain_local_window.h"
#include "ui_pain_local_window.h"
#include <QKeyEvent>

PainLocalWindow::PainLocalWindow(QWidget *parent, PatientHistory *patientHistory)
    : QDialog(parent)
    , ui(new Ui::PainLocalWindow)
    , _patientHistory(patientHistory) {
    ui->setupUi(this);
    setlocale(LC_ALL, "Russian");
}

PainLocalWindow::~PainLocalWindow() {
    delete ui;
}

void PainLocalWindow::on_comboBoxPartOfTheBodyLocalization_textActivated(const QString &arg) {
    std::string partOfTheBodyLocalization = arg.toStdString();
    _painLocalData.setPartOfTheBodyLocalization(partOfTheBodyLocalization);
    ui->comboBoxClarification->clear();
    ui->comboBoxSurface->clear();

   if (arg == "Спина") {
       ui->comboBoxClarification->addItem("Копчиковый отдел");
       ui->comboBoxClarification->addItem("Кресцовый отдел");
       ui->comboBoxClarification->addItem("Поясничный отдел");
       ui->comboBoxClarification->addItem("Грудной отдел");
       ui->comboBoxClarification->addItem("Шейный отдел");
       _painLocalData.setSurface("0");
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
       ui->comboBoxSurface->addItem("Внутренняя");
       ui->comboBoxSurface->addItem("Внешняя");
       ui->comboBoxSurface->addItem("Передняя");
       ui->comboBoxSurface->addItem("Задняя");
   } else if (arg == "Голова") {
       ui->comboBoxClarification->addItem("Лобная часть");
       ui->comboBoxClarification->addItem("Теменная часть");
       ui->comboBoxClarification->addItem("Затылочная часть");
       ui->comboBoxClarification->addItem("Височная часть");
       ui->comboBoxClarification->addItem("Лицевая часть");
        _painLocalData.setSurface("0");
   } else if (arg == "Тело") {
       ui->comboBoxClarification->addItem("Грудина");
       ui->comboBoxClarification->addItem("За грудиной ");
       ui->comboBoxClarification->addItem("Под лопаткой");
       ui->comboBoxClarification->addItem("Межреберье");
       ui->comboBoxClarification->addItem("Брюшная область");
       _painLocalData.setSurface("0");
   }

   QString a = "Сколиоз";
   qDebug() << a.toUtf8();

   if (arg == "Нет") {
       ui->labelPartOfTheBodyLocalization->setStyleSheet("QLabel#labelPartOfTheBodyLocalization { background-color: rgba(144, 238, 144, 180); }");

       if (_painLocalData.localIsFull()) {
           ui->labelLocalizationTitle->setStyleSheet("QLabel#labelLocalizationTitle { background-color: rgba(144, 238, 144, 180) }");
       }

       ui->comboBoxSide->setFocus();
       QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
       qApp->postEvent(ui->comboBoxSide, eve1);
       _painLocalData.setClarification("0");
       _painLocalData.setSurface("0");
   } else {
       ui->labelPartOfTheBodyLocalization->setStyleSheet("QLabel#labelPartOfTheBodyLocalization { background-color: rgba(144, 238, 144, 180); }");

       if (_painLocalData.localIsFull()) {
           ui->labelLocalizationTitle->setStyleSheet("QLabel#labelLocalizationTitle { background-color: rgba(144, 238, 144, 180) }");
       }

       ui->comboBoxClarification->setFocus();
       QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
       qApp->postEvent(ui->comboBoxClarification, eve1);
   }
}

void PainLocalWindow::on_comboBoxClarification_textActivated(const QString &arg) {
    std::string clarification = arg.toStdString();
    _painLocalData.setClarification(clarification);

    ui->labelClarification->setStyleSheet("QLabel#labelClarification { background-color: rgba(144, 238, 144, 180); }");

    if (_painLocalData.localIsFull()) {
        ui->labelLocalizationTitle->setStyleSheet("QLabel#labelLocalizationTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxSide->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxSide, eve1);
}

void PainLocalWindow::on_comboBoxSide_textActivated(const QString &arg) {
    std::string side = arg.toStdString();
    _painLocalData.setSide(side);

    ui->labelSide->setStyleSheet("QLabel#labelSide { background-color: rgba(144, 238, 144, 180); }");

    if (_painLocalData.localIsFull()) {
        ui->labelLocalizationTitle->setStyleSheet("QLabel#labelLocalizationTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxSurface->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxSurface, eve1);
}

void PainLocalWindow::on_comboBoxSurface_textActivated(const QString &arg) {
    std::string surface = arg.toStdString();
    _painLocalData.setSurface(surface);

    ui->labelSurface->setStyleSheet("QLabel#labelSurface { background-color: rgba(144, 238, 144, 180); }");

    if (_painLocalData.localIsFull()) {
        ui->labelLocalizationTitle->setStyleSheet("QLabel#labelLocalizationTitle { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxIntensity->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxIntensity, eve1);
}

void PainLocalWindow::on_comboBoxIntensity_textActivated(const QString &arg) {
    std::string intensity = arg.toStdString();
    _painLocalData.setIntensity(intensity);

    ui->labelIntensity->setStyleSheet("QLabel#labelIntensity { background-color: rgba(144, 238, 144, 180); }");

    if (_painLocalData.characterIsFull()) {
        ui->labelCharacteristic->setStyleSheet("QLabel#labelCharacteristic { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxCharacter->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxCharacter, eve1);
}

void PainLocalWindow::on_comboBoxCharacter_textActivated(const QString &arg) {
    std::string character = arg.toStdString();
    _painLocalData.setCharacter(character);

    ui->labelCharacter->setStyleSheet("QLabel#labelCharacter { background-color: rgba(144, 238, 144, 180); }");

    if (_painLocalData.characterIsFull()) {
        ui->labelCharacteristic->setStyleSheet("QLabel#labelCharacteristic { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->comboBoxPartOfTheBodyIrradiation->setFocus();
    QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
    qApp->postEvent(ui->comboBoxPartOfTheBodyIrradiation, eve1);
}

void PainLocalWindow::on_comboBoxPartOfTheBodyIrradiation_textActivated(const QString &arg) {
    std::string partOfTheBodyIrradiation = arg.toStdString();
    _painLocalData.setPartOfTheBodyIrradiation(partOfTheBodyIrradiation);

    ui->comboBoxLocaliztion->clear();

   if (arg == "Спина") {
       ui->comboBoxLocaliztion->addItem("Копчиковый отдел");
       ui->comboBoxLocaliztion->addItem("Кресцовый отдел");
       ui->comboBoxLocaliztion->addItem("Поясничный отдел");
       ui->comboBoxLocaliztion->addItem("Грудной отдел");
       ui->comboBoxLocaliztion->addItem("Шейный отдел");
   } else if (arg == "Нога") {
       ui->comboBoxLocaliztion->addItem("Бедро (Внутреняя сторона)");
       ui->comboBoxLocaliztion->addItem("Бедро (Внешняя сторона)");
       ui->comboBoxLocaliztion->addItem("Колено");
       ui->comboBoxLocaliztion->addItem("Подколенная область");
       ui->comboBoxLocaliztion->addItem("Голиностоп");
       ui->comboBoxLocaliztion->addItem("Пятка");
       ui->comboBoxLocaliztion->addItem("Стопа");
       ui->comboBoxLocaliztion->addItem("Пальцы");
       ui->comboBoxLocaliztion->addItem("Паховая область");
       ui->comboBoxLocaliztion->addItem("Пятка");
   } else if (arg == "Рука") {
       ui->comboBoxLocaliztion->addItem("Плечо");
       ui->comboBoxLocaliztion->addItem("Локоть");
       ui->comboBoxLocaliztion->addItem("Запястье");
       ui->comboBoxLocaliztion->addItem("Кончики пальцев");
       ui->comboBoxLocaliztion->addItem("Пальцы");
       ui->comboBoxLocaliztion->addItem("Предплечье");
       ui->comboBoxLocaliztion->addItem("Ключица");
   } else if (arg == "Голова") {
       ui->comboBoxLocaliztion->addItem("Лобная часть");
       ui->comboBoxLocaliztion->addItem("Теменная часть");
       ui->comboBoxLocaliztion->addItem("Затылочная часть");
       ui->comboBoxLocaliztion->addItem("Височная часть");
       ui->comboBoxLocaliztion->addItem("Лицевая часть");

   } else if (arg == "Тело") {
       ui->comboBoxLocaliztion->addItem("Грудина");
       ui->comboBoxLocaliztion->addItem("За грудиной ");
       ui->comboBoxLocaliztion->addItem("Под лопаткой");
       ui->comboBoxLocaliztion->addItem("Межреберье");
       ui->comboBoxLocaliztion->addItem("Брюшная область");
   }

   if (arg == "Нет") {
       ui->labelPartOfTheBodyIrradiation->setStyleSheet("QLabel#labelPartOfTheBodyIrradiation { background-color: rgba(144, 238, 144, 180); }");

       if (_painLocalData.characterIsFull()) {
           ui->labelIrradiation->setStyleSheet("QLabel#labelIrradiation { background-color: rgba(144, 238, 144, 180) }");
       }
       _painLocalData.setLocalization("0");
       ui->pushOk->setFocus();
   } else {
       ui->labelPartOfTheBodyIrradiation->setStyleSheet("QLabel#labelPartOfTheBodyIrradiation { background-color: rgba(144, 238, 144, 180); }");

       if (_painLocalData.characterIsFull()) {
           ui->labelIrradiation->setStyleSheet("QLabel#labelIrradiation { background-color: rgba(144, 238, 144, 180) }");
       }

       ui->comboBoxLocaliztion->setFocus();
       QKeyEvent * eve1 = new QKeyEvent (QEvent::KeyPress,Qt::Key_F4, Qt::NoModifier);
       qApp->postEvent(ui->comboBoxLocaliztion, eve1);
   }
}

void PainLocalWindow::on_comboBoxLocaliztion_textActivated(const QString &arg) {
    std::string localization = arg.toStdString();
    _painLocalData.setLocalization(localization);

    ui->labelLocaliztion->setStyleSheet("QLabel#labelLocaliztion { background-color: rgba(144, 238, 144, 180); }");

    if (_painLocalData.characterIsFull()) {
        ui->labelIrradiation->setStyleSheet("QLabel#labelIrradiation { background-color: rgba(144, 238, 144, 180) }");
    }

    ui->pushOk->setFocus();
}

void PainLocalWindow::on_pushOk_clicked() {
    if (_painLocalData.localIsFull() && _painLocalData.characterIsFull() && _painLocalData.irradIsFull()) {
        _patientHistory->getPatientDiseaseData()->setDiseaseManifestation(_painLocalData.getPainLocalData());
        _patientHistory->getPatientInjuryData()->setLocalPainData(_painLocalData.getPainLocalData());
        this->close();
    }
}

