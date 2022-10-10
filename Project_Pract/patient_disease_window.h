#ifndef PATIENTDISEASEWINDOW_H
#define PATIENTDISEASEWINDOW_H

#include <QDialog>
#include <QKeyEvent>
#include "patient_history_data_clasess/patient_history.h"
#include "pain_local_window.h"
#include "deformation_local_window.h"
#include "neuro_local_window.h"
#include "patient_history_data_clasess/document_writer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PatientDiseaseWindow; }
QT_END_NAMESPACE


class PatientDiseaseWindow : public QDialog {
    Q_OBJECT

public:
    explicit PatientDiseaseWindow(QWidget *parent = nullptr, PatientHistory *patientHistory = nullptr);
    ~PatientDiseaseWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void on_dateTimeEditDiseaseStart_dateChanged(const QDate &date);
    void on_comboBoxOccurrenceOfDisease_textActivated(const QString &arg);
    void on_comboBoxManifestationOfDisease_textActivated(const QString &arg);
    void on_comboBoxRevealed_textActivated(const QString &arg);
    void on_dateTimeEditFirstWentToMedicalFacility_dateChanged(const QDate &date);
    void on_comboBoxMedicalFacility_textActivated(const QString &arg);
    void on_lineEditTreatmentTimeInDays_editingFinished();
    void on_comboBoxTypeOfTreatment_textActivated(const QString &arg);
    void on_comboBoxTypeOfTreatmentAddition_textActivated(const QString &arg);
    void on_comboBoxTreatmentResult_textActivated(const QString &arg);
    void on_comboBoxNewDisease_textActivated(const QString &arg);
    void on_comboBoxWentToOtherMedicalFacility_textActivated(const QString &arg);
    void on_textEditAddition_textChanged();

    void on_buttonClose_clicked();

    void on_buttonResult_clicked();

    void on_dateTimeEditDiseaseStart_editingFinished();

    void on_dateTimeEditFirstWentToMedicalFacility_editingFinished();

private:
    Ui::PatientDiseaseWindow *ui;
    PatientHistory *_patientHistory;
};

#endif // PATIENTDISEASEWINDOW_H
