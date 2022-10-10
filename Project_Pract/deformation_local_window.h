#ifndef DEFORMATION_LOCAL_WINDOW_H
#define DEFORMATION_LOCAL_WINDOW_H

#include <QDialog>
#include "patient_history_data_clasess/patient_history.h"
#include "patient_history_data_clasess/deformation_local_data.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DeformationLocalWindow; }
QT_END_NAMESPACE

class DeformationLocalWindow : public QDialog {
    Q_OBJECT

public:
    DeformationLocalWindow(QWidget *parent = nullptr, PatientHistory *patientHistory = nullptr);
    ~DeformationLocalWindow();

private slots:
    void on_comboBoxDeformationLocalInfo_textActivated(const QString &arg);
    void on_comboBoxView_textActivated(const QString &arg);
    void on_comboBoxSide_textActivated(const QString &arg);
    void on_comboBoxDegree_textActivated(const QString &arg);

    void on_buttonOk_clicked();

private:
    Ui::DeformationLocalWindow *ui;
    PatientHistory *_patientHistory;
    DeformationLocalData _deformationLocalData;
};

#endif // DEFORMATION_LOCAL_WINDOW_H
