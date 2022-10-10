#ifndef INJURY_WINDOW_H
#define INJURY_WINDOW_H

#include <QDialog>
#include "patient_history_data_clasess/patient_history.h"

QT_BEGIN_NAMESPACE
namespace Ui { class InjuryWindow; }
QT_END_NAMESPACE

class InjuryWindow : public QDialog {
    Q_OBJECT

public:
    explicit InjuryWindow(QWidget *parent = nullptr, PatientHistory *patientHistory = nullptr);
    ~InjuryWindow();

private slots:
    void on_comboBoxReceived_textActivated(const QString &arg);
    void on_comboBoxMechanism_textActivated(const QString &arg);
    void on_comboBoxLocalization_textActivated(const QString &arg);
    void on_comboBoxCharacter_textActivated(const QString &arg);
    void on_comboBoxView_textActivated(const QString &arg);
    void on_comboBoxPower_textActivated(const QString &arg);
    void on_comboBoxWhereChange_textActivated(const QString &arg);

    void on_buttonResult_clicked();

    void on_dateTimeEdit_editingFinished();

    void on_comboBoxPain_textActivated(const QString &arg1);

    void on_comboBoxNeuro_textActivated(const QString &arg1);

    void on_comboBoxCanMove_1_textActivated(const QString &arg1);

    void on_comboBoxCanMove_2_textActivated(const QString &arg1);

    void on_comboBoxCanUp_textActivated(const QString &arg1);

    void on_comboBoxCanWalk_textActivated(const QString &arg1);

    void on_comboBoxHelp_1_textActivated(const QString &arg1);

    void on_comboBoxHelp_2_textActivated(const QString &arg1);

    void on_comboBoxFirstHelp_textActivated(const QString &arg1);

    void on_comboBoxTransport_textActivated(const QString &arg1);

    void on_comboBoxPosition_textActivated(const QString &arg1);

    void on_comboBoxImmobilization_textActivated(const QString &arg1);

    void on_textEditAddition_textChanged();

private:
    Ui::InjuryWindow *ui;
    PatientHistory *_patientHistory;
};

#endif // INJURY_WINDOW_H
