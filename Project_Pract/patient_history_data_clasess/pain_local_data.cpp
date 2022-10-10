#include "pain_local_data.h"

PainLocalData::PainLocalData()
    : _painLocalData(8, "") {
    setlocale(LC_ALL, "Russian");
}
PainLocalData::~PainLocalData() {}

std::string PainLocalData::getPartOfTheBodyLocalization() {
    return _painLocalData[0];
}

std::string PainLocalData::getClarification() {
    return _painLocalData[1];
}

std::string PainLocalData::getSide() {
    return _painLocalData[2];
}

std::string PainLocalData::getSurface() {
    return _painLocalData[3];
}

std::string PainLocalData::getIntensity() {
    return _painLocalData[4];
}

std::string PainLocalData::getCharacter() {
    return _painLocalData[5];
}

std::string PainLocalData::getPartOfTheBodyIrradiation() {
    return _painLocalData[6];
}

std::string PainLocalData::getLocalization() {
    return _painLocalData[7];
}

const std::vector<std::string> &PainLocalData::getPainLocalData() {
    return _painLocalData;
}


void PainLocalData::setPartOfTheBodyLocalization(std::string partOfTheBodyLocalization) {
    _painLocalData[0] = partOfTheBodyLocalization;
}

void PainLocalData::setClarification(std::string clarification) {
    _painLocalData[1] = clarification;
}

void PainLocalData::setSide(std::string side) {
    _painLocalData[2] = side;
}

void PainLocalData::setSurface(std::string surface) {
    _painLocalData[3] = surface;
}

void PainLocalData::setIntensity(std::string intensity) {
    _painLocalData[4] = intensity;
}

void PainLocalData::setCharacter(std::string character) {
    _painLocalData[5] = character;
}

void PainLocalData::setPartOfTheBodyIrradiation(std::string partOfTheBodyIrradiation) {
    _painLocalData[6] = partOfTheBodyIrradiation;
}

void PainLocalData::setLocalization(std::string localization) {
    _painLocalData[7] = localization;
}

bool PainLocalData::localIsFull() {
    bool result = true;
    for (int i = 0; i < 4 && result; i++) {
        if (_painLocalData[i] == "") {
            result = false;
        }
    }
    return result;
}

bool PainLocalData::characterIsFull() {
    bool result = true;
    for (int i = 4; i < 6 && result; i++) {
        if (_painLocalData[i] == "") {
            result = false;
        }
    }
    return result;
}

bool PainLocalData::irradIsFull() {
    bool result = true;
    for (int i = 6; i < 8 && result; i++) {
        if (_painLocalData[i] == "") {
            result = false;
        }
    }
    return result;
}
