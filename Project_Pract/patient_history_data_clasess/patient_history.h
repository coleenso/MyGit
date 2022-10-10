#ifndef PATIENTHISTORY_H
#define PATIENTHISTORY_H

#include "patient_data.h"
#include "patient_disease_data.h"
#include "patient_injury_data.h"

class PatientHistory {
public:
    PatientHistory();
    ~PatientHistory();

    PatientData *getPatientData();
    PatientDiseaseData *getPatientDiseaseData();
    PatientInjuryData *getPatientInjuryData();

private:
    PatientData _patientData;
    PatientDiseaseData _patientDiseaseData;
    PatientInjuryData _patientInjuryData;
};

#endif // PATIENTHISTORY_H
