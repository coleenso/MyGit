#ifndef PATIENT_INJURY_DATA_H
#define PATIENT_INJURY_DATA_H

#include <string>
#include "illness_code.h"

class PatientInjuryData {
public:
    PatientInjuryData();
    ~PatientInjuryData();

    std::string getDate();
    std::string getRecieved();
    std::string getMechanism();
    std::string getLocalization();
    std::string getCharacter();
    std::string getView();
    std::string getPower();
    std::string getWhereChange();
    std::string getPain();
    std::string getNeuro();
    std::string getCanMove();
    std::string getCanMove_1();
    std::string getCanUp();
    std::string getCanWalk();
    std::string getHelp();
    std::string getHelp_1();
    std::string getFirstHelp();
    std::string getTransport();
    std::string getPosition();
    std::string getImmobilization();
    std::string getAddition();
    const std::vector<std::string> &getInjuryData();

    void setDate(std::string date);
    void setRecieved(std::string recieved);
    void setMechanism(std::string mechanism);
    void setLocalization(std::string localization);
    void setCharacter(std::string character);
    void setView(std::string view);
    void setPower(std::string power);
    void setWhereChange(std::string whereChanged);
    void setPain(std::string pain);
    void setNeuro(std::string neuro);
    void setCanMove(std::string canMove);
    void setCanMove_1(std::string canMove);
    void setCanUp(std::string canUp);
    void setCanWalk(std::string canWalk);
    void setHelp(std::string help);
    void setHelp_1(std::string help);
    void setFirstHelp(std::string firstHelp);
    void setTransport(std::string transport);
    void setPosition(std::string position);
    void setImmobilization(std::string immobilization);
    void setAddition(std::string immobilization);
    void setLocalPainData(std::vector<std::string> data);
    void setLocalNeuroData(std::vector<std::string> data);

    bool injuryDataIsFull();
    bool localPainDataIsFull();
    bool localNeuroDataIsFull();
    std::string makeText(std::string sex);

private:
    std::vector<std::string> _injuryData;
    std::vector<std::string> _localPainData;
    std::vector<std::string> _localNeuroData;
};

#endif // PATIENT_INJURY_DATA_H
