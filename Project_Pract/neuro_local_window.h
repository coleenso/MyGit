#ifndef NEURO_LOCAL_WINDOW_H
#define NEURO_LOCAL_WINDOW_H

#include <QDialog>
#include "patient_history_data_clasess/patient_history.h"
#include "patient_history_data_clasess/neuro_local_data.h"

QT_BEGIN_NAMESPACE
namespace Ui { class NeuroLocalWindow; }
QT_END_NAMESPACE

class NeuroLocalWindow : public QDialog {
    Q_OBJECT

public:
    explicit NeuroLocalWindow(QWidget *parent = nullptr, PatientHistory *patientHistory = nullptr);
    ~NeuroLocalWindow();

private slots:
    void on_comboBoxPartOfTheBody_textActivated(const QString &arg);
    void on_comboBoxClarification_textActivated(const QString &arg);
    void on_comboBoxSide_textActivated(const QString &arg);
    void on_comboBoxSurface_textActivated(const QString &arg);
    void on_comboBoxDisorder_textActivated(const QString &arg);
    void on_comboBoxView_textActivated(const QString &arg);

    void on_buttonOk_clicked();

private:
    Ui::NeuroLocalWindow *ui;
    PatientHistory *_patientHistory;
    NeuroLocalData _neuroLocalData;
};

#endif // NEURO_LOCAL_WINDOW_H
