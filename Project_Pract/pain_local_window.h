#ifndef PAINLOCALWINDOW_H
#define PAINLOCALWINDOW_H

#include <QDialog>
#include "patient_history_data_clasess/patient_history.h"
#include "patient_history_data_clasess/pain_local_data.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PainLocalWindow; }
QT_END_NAMESPACE

class PainLocalWindow : public QDialog {
    Q_OBJECT

public:
    PainLocalWindow(QWidget *parent = nullptr, PatientHistory *patientHistory = nullptr);
    ~PainLocalWindow();

private slots:
    void on_comboBoxPartOfTheBodyLocalization_textActivated(const QString &arg);
    void on_comboBoxClarification_textActivated(const QString &arg);
    void on_comboBoxSide_textActivated(const QString &arg);
    void on_comboBoxSurface_textActivated(const QString &arg);
    void on_comboBoxIntensity_textActivated(const QString &arg);
    void on_comboBoxCharacter_textActivated(const QString &arg);
    void on_comboBoxPartOfTheBodyIrradiation_textActivated(const QString &arg);
    void on_comboBoxLocaliztion_textActivated(const QString &arg);
    void on_pushOk_clicked();

private:
    Ui::PainLocalWindow *ui;
    PatientHistory *_patientHistory;
    PainLocalData _painLocalData;
};

#endif // PAINLOCALWINDOW_H
