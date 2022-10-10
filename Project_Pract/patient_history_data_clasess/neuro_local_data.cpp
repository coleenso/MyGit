#include "neuro_local_data.h"

NeuroLocalData::NeuroLocalData()
    : _neuroLocalData(6, "") {
    setlocale(LC_ALL, "Russian");
}

NeuroLocalData::~NeuroLocalData() {}

std::string NeuroLocalData::getPartOfTheBody() {
    return _neuroLocalData[0];
}

std::string NeuroLocalData::getClarification() {
    return _neuroLocalData[1];
}

std::string NeuroLocalData::getSide() {
    return _neuroLocalData[2];
}

std::string NeuroLocalData::getSurface() {
    return _neuroLocalData[3];
}

std::string NeuroLocalData::getDisorder() {
    return _neuroLocalData[4];
}

std::string NeuroLocalData::getView() {
    return _neuroLocalData[5];
}

const std::vector<std::string> &NeuroLocalData::getNeuroLocalData() {
    return _neuroLocalData;
}

void NeuroLocalData::setPartOfTheBody(std::string partOfTheBody) {
    _neuroLocalData[0] = partOfTheBody;
}

void NeuroLocalData::setClarification(std::string clarification) {
    _neuroLocalData[1] = clarification;
}

void NeuroLocalData::setSide(std::string side) {
    _neuroLocalData[2] = side;
}

void NeuroLocalData::setSurface(std::string surface) {
    _neuroLocalData[3] = surface;
}

void NeuroLocalData::setDisorder(std::string disorder) {
    _neuroLocalData[4] = disorder;
}

void NeuroLocalData::setView(std::string view) {
    _neuroLocalData[5] = view;
}

bool NeuroLocalData::isFull() {
    bool result = true;
    for (int i = 0; i < _neuroLocalData.size() && result; i++) {
        if (_neuroLocalData[i] == "") {
            result = false;
        }
    }
    return result;
}
