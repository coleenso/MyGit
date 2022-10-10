#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "patient_history_data_clasess/patient_history.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void on_lineEditSurname_editingFinished();
    void on_lineEditName_editingFinished();
    void on_lineEditPatronymic_editingFinished();
    void on_dateEditBirthday_userDateChanged(const QDate &date);
    void on_comboBoxSex_textActivated(const QString &arg);
    void on_lineEditAge_editingFinished();
    void on_textEditAddition_textChanged();

    void on_buttonDisease_clicked();
    void on_buttonInjury_clicked();

    void on_dateEditBirthday_editingFinished();

private:
    Ui::MainWindow *ui;
    PatientHistory patientHistory;
};
#endif // MAINWINDOW_H
