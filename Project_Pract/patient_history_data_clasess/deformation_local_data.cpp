#include "deformation_local_data.h"

DeformationLocalData::DeformationLocalData()
    : _deformationLocalData(4, "") {
    setlocale(LC_ALL, "Russian");
}

DeformationLocalData::~DeformationLocalData() {}

std::string DeformationLocalData::getDeformationLocalInfo() {
    return _deformationLocalData[0];
}

std::string DeformationLocalData::getView() {
    return _deformationLocalData[1];
}

std::string DeformationLocalData::getSide() {
    return _deformationLocalData[2];
}

std::string DeformationLocalData::getDegree() {
    return _deformationLocalData[3];
}

const std::vector<std::string> &DeformationLocalData::getDeformationLocalData() {
    return _deformationLocalData;
}

void DeformationLocalData::setDeformationLocalInfo(std::string deformationLocalInfo) {
    _deformationLocalData[0] = deformationLocalInfo;
}

void DeformationLocalData::setView(std::string view) {
    _deformationLocalData[1] = view;
}

void DeformationLocalData::setSide(std::string side) {
    _deformationLocalData[2] = side;
}

void DeformationLocalData::setDegree(std::string degree) {
    _deformationLocalData[3] = degree;
}

bool DeformationLocalData::isFull() {
    bool result = true;
    for (int i = 0; i < _deformationLocalData.size() && result; i++) {
        if (_deformationLocalData[i] == "") {
            result = false;
        }
    }
    return result;
}
