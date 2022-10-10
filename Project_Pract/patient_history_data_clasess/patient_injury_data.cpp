#include "patient_injury_data.h"

PatientInjuryData::PatientInjuryData()
    : _injuryData(21, "")
    , _localPainData(1, "")
    , _localNeuroData(1, "") {}

PatientInjuryData::~PatientInjuryData() {}

std::string PatientInjuryData::getDate() {
    return _injuryData[0];
}

std::string PatientInjuryData::getRecieved() {
    return _injuryData[1];
}

std::string PatientInjuryData::getMechanism() {
    return _injuryData[2];
}

std::string PatientInjuryData::getLocalization() {
    return _injuryData[3];
}

std::string PatientInjuryData::getCharacter() {
    return _injuryData[4];
}

std::string PatientInjuryData::getView() {
    return _injuryData[5];
}

std::string PatientInjuryData::getPower() {
    return _injuryData[6];
}

std::string PatientInjuryData::getWhereChange() {
    return _injuryData[7];
}

std::string PatientInjuryData::getPain() {
    return _injuryData[8];
}

std::string PatientInjuryData::getNeuro() {
    return _injuryData[9];
}

std::string PatientInjuryData::getCanMove() {
    return _injuryData[10];
}

std::string PatientInjuryData::getCanMove_1() {
    return _injuryData[11];
}

std::string PatientInjuryData::getCanUp() {
    return _injuryData[12];
}

std::string PatientInjuryData::getCanWalk() {
    return _injuryData[13];
}

std::string PatientInjuryData::getHelp() {
    return _injuryData[14];
}

std::string PatientInjuryData::getHelp_1() {
    return _injuryData[15];
}

std::string PatientInjuryData::getFirstHelp() {
    return _injuryData[16];
}

std::string PatientInjuryData::getTransport() {
    return _injuryData[17];
}

std::string PatientInjuryData::getPosition() {
    return _injuryData[18];
}

std::string PatientInjuryData::getImmobilization() {
    return _injuryData[19];
}

std::string PatientInjuryData::getAddition() {
    return _injuryData[20];
}

const std::vector<std::string> &PatientInjuryData::getInjuryData() {
    return _injuryData;
}


void PatientInjuryData::setDate(std::string date) {
    _injuryData[0] = date;
}

void PatientInjuryData::setRecieved(std::string recieved) {
    _injuryData[1] = recieved;
}

void PatientInjuryData::setMechanism(std::string mechanism) {
    _injuryData[2] = mechanism;
}

void PatientInjuryData::setLocalization(std::string localization) {
    _injuryData[3] = localization;
}

void PatientInjuryData::setCharacter(std::string character) {
    _injuryData[4] = character;
}

void PatientInjuryData::setView(std::string view) {
    _injuryData[5] = view;
}

void PatientInjuryData::setPower(std::string power) {
    _injuryData[6] = power;
}

void PatientInjuryData::setWhereChange(std::string whereChanged) {
    _injuryData[7] = whereChanged;
}

void PatientInjuryData::setPain(std::string pain) {
    _injuryData[8] = pain;
}

void PatientInjuryData::setNeuro(std::string neuro) {
    _injuryData[9] = neuro;
}

void PatientInjuryData::setCanMove(std::string canMove) {
    _injuryData[10] = canMove;
}

void PatientInjuryData::setCanMove_1(std::string canMove) {
    _injuryData[11] = canMove;
}

void PatientInjuryData::setCanUp(std::string canUp) {
    _injuryData[12] = canUp;
}

void PatientInjuryData::setCanWalk(std::string canWalk) {
    _injuryData[13] = canWalk;
}

void PatientInjuryData::setHelp(std::string help) {
    _injuryData[14] = help;
}

void PatientInjuryData::setHelp_1(std::string help) {
    _injuryData[15] = help;
}

void PatientInjuryData::setFirstHelp(std::string firstHelp) {
    _injuryData[16] = firstHelp;
}

void PatientInjuryData::setTransport(std::string transport) {
    _injuryData[17] = transport;
}

void PatientInjuryData::setPosition(std::string position) {
    _injuryData[18] = position;
}

void PatientInjuryData::setImmobilization(std::string immobilization) {
    _injuryData[19] = immobilization;
}

void PatientInjuryData::setAddition(std::string immobilization) {
    _injuryData[20] = immobilization;
}

void PatientInjuryData::setLocalPainData(std::vector<std::string> data) {
    _localPainData = data;
}

void PatientInjuryData::setLocalNeuroData(std::vector<std::string> data) {
    _localNeuroData = data;
}

bool PatientInjuryData::injuryDataIsFull() {
    bool result = true;
    for (int i = 0; i < _injuryData.size() - 1 && result; i++) {
        if (_injuryData[i] == "") {
            result = false;
        }
    }
    return result;
}

bool PatientInjuryData::localPainDataIsFull() {
    bool result = true;
    for (int i = 0; i < _localPainData.size() - 1 && result; i++) {
        if (_localPainData[i] == "") {
            result = false;
        }
    }
    return result;
}

bool PatientInjuryData::localNeuroDataIsFull() {
    bool result = true;
    for (int i = 0; i < _localNeuroData.size() - 1 && result; i++) {
        if (_localNeuroData[i] == "") {
            result = false;
        }
    }
    return result;
}

std::string PatientInjuryData::makeText(std::string sex) {
    std::string result{""};
    result += "Анамнез по травме позвоночника:\n\n";

    std::string day = _injuryData[0].substr(_injuryData[0].size() - 15, 2);
    std::string month = _injuryData[0].substr(_injuryData[0].size() - 19, 3);
    std::string year = _injuryData[0].substr(_injuryData[0].size() - 4, 4);
    std::string time = _injuryData[0].substr(_injuryData[0].size() - 13, 5);

    if (month == "Dec") {
        month = "Декабря";
    } else if ("Jan") {
        month = "Января";
    } else if ("Feb") {
        month = "Февраля";
    } else if ("Mar") {
        month = "Марта";
    } else if ("Apr") {
        month = "Апреля";
    } else if ("May") {
        month = "Мая";
    } else if ("Jun") {
        month = "Июня";
    } else if ("Jul") {
        month = "Июля";
    } else if ("Aug") {
        month = "Августа";
    } else if ("Sep") {
        month = "Сентября";
    } else if ("Oct") {
        month = "Октября";
    } else if ("Nov") {
        month = "Ноября";
    }
    result += "Дата и время получения травмы: " + day + "-го " + month + " " + year + "-го года, " + time + "\n";

    result += "Травма получена ";
    if (_injuryData[1] == "На производстве") {
        result += "на производстве.\n";
    } else if (_injuryData[1] == "На улице") {
        result += "на улице.\n";
    } else if (_injuryData[1] == "В транспорте") {
        result += "в транспорте.\n";
    } else if (_injuryData[1] == "В автодорожном происшествии") {
        result += "в автодорожном происшествии.\n";
    } else if (_injuryData[1] == "В быту") {
        result += "в быту.\n";
    } else if (_injuryData[1] == "При занятиях спортом") {
        result += "при занятиях спортом.\n";
    } else if (_injuryData[1] == "В школе") {
        result += "в школе.\n";
    } else if (_injuryData[1] == "Прочее") {
        result += "при уточняемых обстоятельствах.\n";
    }
    result += "Описание травмы:\n";
    result += "  Механизм травмы - " + _injuryData[2] + ";\n";
    result += "  Характер травмы - " + _injuryData[3] + ";\n";
    result += "  Локализация травмы - " + _injuryData[4] + ";\n";
    result += "  По виду травмы - " + _injuryData[5] + ";\n";
    result += "  Приложение силы привело к ";
    if (_injuryData[6] == "Сгибание") {
        result += "сгибанию;\n";
    } else if (_injuryData[6] == "Разгибание") {
        result += "разгибанию;\n";
    } else if (_injuryData[6] == "Вертикальное нагружение") {
        result += "вертикальному нагружению;\n";
    } else if (_injuryData[6] == "Ротация") {
        result += "ротации;\n";
    } else if (_injuryData[6] == "Ротация со сгибанием") {
        result += "ротации со сгибанием;\n";
    } else if (_injuryData[6] == "Боковой сдвиг") {
        result += "боковому сдвигу;\n";
    } else if (_injuryData[6] == "боковой наклон") {
        result += "боковому наклону;\n";
    }
    if (_injuryData[7] == "Нет") {
        result += "  Изменений нет;\n";
    } else if (_injuryData[7] == "Крестцовом отделе") {
        result += "  Изменения произошли в крестцовом отделе;\n";
    } else if (_injuryData[7] == "Поясничном отделе") {
        result += "  Изменения произошли в поясничном отделе;\n";
    } else if (_injuryData[7] == "Грудном отделе") {
        result += "  Изменения произошли в грудном отделе;\n";
    } else if (_injuryData[7] == "Шейном отделе") {
        result += "  Изменения произошли в шейном отделе;\n";
    }
    if (_injuryData[8] == "Да") {
        result += "  Возникла боль, локализация прилагается (см. ниже):\n ";
        result += "   *Локализация:\n       Часть тела: " + _localPainData[0] + "\n";
        if (_localPainData[0] == "Нет") {
            result += "       Сторона: " + _localPainData[2] + "\n";
        } else if (_localPainData[0] == "Спина" || _localPainData[0] == "Голова" || _localPainData[0] == "Тело"){
            result += "       Уточнение: " + _localPainData[1] + "\n";
            result += "       Сторона: " + _localPainData[2] + "\n";
        } else {
            result += "       Уточнение: " + _localPainData[1] + "\n";
            result += "       Сторона: " + _localPainData[2] + "\n";
            result += "       Поверхность: " + _localPainData[3] + "\n";
        }
        result += "   *Характеристика:\n       Интенсивность: " + _localPainData[4] + "\n";
        result += "       Характер: " + _localPainData[5] + "\n";
        result += "   *Иррадиация:\n       Часть тела: " + _localPainData[6] + "\n";
        if (_localPainData[6] == "Нет") {
            result += "\n\n";
        } else {
            result += "       Локализация: " + _localPainData[7] + "\n";
        }
    } else {
        result += "  Боль не возникала;\n";
    }
    if (_injuryData[9] == "Да") {
        result += "  Возникли неврологические нарушения, локализация прилагается (см. ниже):\n ";
        result += "      Часть тела : " + _localNeuroData[0] + "\n";
        if (_localNeuroData[1] != "0") {
            result += "      Уточнение: " + _localNeuroData[1] + "\n";
        }
        result += "      Сторона: " + _localNeuroData[2] + "\n";
        if (_localNeuroData[3] != "0") {
            result += "      Поверхность: " + _localNeuroData[3] + "\n";
        }
        result += "      Нарушение: " + _localNeuroData[4] + "\n";
        if (_localNeuroData[5] != "0") {
            result += "      Вид: " + _localNeuroData[5] + "\n\n";
        } else {
            result += "\n\n";
        }
    } else {
        result += "  Неврологические нарушения не возникали.\n";
    }

    if (_injuryData[10] == "Нет") {
        result += "Пациент не может самостоятельно осуществлять движение ";
        if (_injuryData[11] == "Левая рука") {
            result += "левой рукой.\n";
        } else if (_injuryData[11] == "Правая рука") {
            result += "правой рукой.\n";
        } else if (_injuryData[11] == "Левая нога") {
            result += "левой ногой.\n";
        } else if (_injuryData[11] == "Правая нога") {
            result += "правой ногой.\n";
        }
    } else {
        result += "Пациент может самостоятельно осуществлять движение конечностями.\n";
    }

    if (_injuryData[12] == "Нет") {
        result += "Пациент не может самостоятельно передвигаться.\n";
    } else {
        result += "Пациент может самостоятельно передвигаться.\n";
    }

    if (_injuryData[13] == "Нет") {
        result += "Пациент не может самостоятельно подняться.\n";
    } else {
        result += "Пациент может самостоятельно подняться.\n";
    }

    if (_injuryData[14] == "Нет") {
        result += "Первичного оказания помощи не было.\n";
    } else {
        result += "Первичная помощь была оказана ";
        if (_injuryData[15] == "Взаимопомощь") {
             result += "неравнодушными людьми.\n";
        } else if (_injuryData[15] == "Врач скорой помощи") {
            result += "врачом скорой помощи.\n";
        }
    }

    if (_injuryData[16] == "Нет") {
        result += "Первичного обращения за помощью не было.\n";
    } else if (_injuryData[16] == "Поликлиника") {
        result += "Было первичное обращение за помощью в поликлинику.\n";
    } else if (_injuryData[16] == "Стационар") {
        result += "Было первичное обращение за помощью в стационар.\n";
    } else if (_injuryData[16] == "Травмпункт") {
        result += "Было первичное обращение за помощью в травмпункт.\n";
    }

    if (_injuryData[17] == "Нет") {
        result += "Транспортировки не было.\n";
    } else if (_injuryData[17] == "Самостоятельно") {
        result += "Транспортировка производилась самостоятельно.\n";
    } else if (_injuryData[17] == "Скорой помощью") {
        result += "Транспортировка производилась скорой помощью.\n";
    } else if (_injuryData[17] == "Попутным транспортом") {
        result += "Транспортировка производилась попутным транспортом.\n";
    } else if (_injuryData[17] == "В сопровождении") {
        result += "Транспортировка производилась в сопровождении.\n";
    }

    if (_injuryData[18] == "На собственных ногах" && _injuryData[17] != "Нет") {
        result += "  Положение при транспортировке - на собственных ногах.\n";
    } else if (_injuryData[18] == "Сидя" && _injuryData[17] != "Нет") {
        result += "  Положение при транспортировке - сидя.\n";
    } else if (_injuryData[18] == "Лежа на щите" && _injuryData[17] != "Нет") {
        result += "  Положение при транспортировке - лёжа на щите.\n";
    } else if (_injuryData[18] == "Лежа без щита" && _injuryData[17] != "Нет") {
        result += "  Положение при транспортировке - лежа без щита.\n";
    }

    result += "Иммобилизация шейного отдела - " + _injuryData[19] + ".\n";

    std::string addition_str = _injuryData[20];
    if (addition_str == "") {
        addition_str = "-";
    }
    result += "Дополнительные сведения: " + addition_str + "\n";

    return result;
}
