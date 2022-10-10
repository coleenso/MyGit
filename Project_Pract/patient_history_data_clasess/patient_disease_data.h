#ifndef PATIENTDISEASEDATA_H
#define PATIENTDISEASEDATA_H

#include <string>
#include "illness_code.h"

class PatientDiseaseData {
public:
    PatientDiseaseData();
    ~PatientDiseaseData();

    std::string getDiseaseStartTime();
    std::string getOccurrenceOfDisease();
    std::string getManifestationOfDisease();
    std::string getRevealed();
    std::string getFirstWentToMedicalFacility();
    std::string getMedicalFacility();
    std::string getTreatmentTimeInDays();
    std::string getTypeOfTreatment();
    std::string getTypeOfTreatmentAddition();
    std::string getTreatmentResult();
    std::string getNewDisease();
    std::string getWentToOtherMedicalFacility();
    std::string getAddition();
    const std::vector<std::string> &getDiseaseData();
    const std::vector<std::string> &getDiseaseManifestation();

    void setDiseaseStartTime(std::string time);
    void setOccurrenceOfDisease(std::string occurrence);
    void setManifestationOfDisease(std::string manifestation);
    void setRevealed(std::string revealed);
    void setFirstWentToMedicalFacility(std::string time);
    void setMedicalFacility(std::string medicalFacility);
    void setTreatmentTimeInDays(std::string time);
    void setTypeOfTreatment(std::string type);
    void setTypeOfTreatmentAddition(std::string typeAddition);
    void setTreatmentResult(std::string result);
    void setNewDisease(std::string newDisease);
    void setWentToOtherMedicalFacility(std::string wentToOtherMedicalFacility);
    void setAddition(std::string addition);
    void setDiseaseManifestation(std::vector<std::string> diseaseManifestation);

    bool diseaseDataIsFull();
    bool diseaseManifestationIsFull();
    std::string makeText(std::string sex);

private:
    std::vector<std::string> _diseaseData;
    std::vector<std::string> _diseaseManifestation;
};

#endif // PATIENTDISEASEDATA_H
