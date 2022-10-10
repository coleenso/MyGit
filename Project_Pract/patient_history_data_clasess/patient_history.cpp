#include "patient_history.h"

PatientHistory::PatientHistory() {
    setlocale(LC_ALL, "Russian");
}

PatientHistory::~PatientHistory() {}

PatientData *PatientHistory::getPatientData() {
    return &_patientData;
}

PatientDiseaseData *PatientHistory::getPatientDiseaseData() {
    return &_patientDiseaseData;
}

PatientInjuryData *PatientHistory::getPatientInjuryData() {
    return &_patientInjuryData;
}
