#include "patient_data.h"

PatientData::PatientData()
    : _data(8, "") {
    setlocale(LC_ALL, "Russian");
}

PatientData::~PatientData() {}

std::string PatientData::getSurname() {
    return _data[0];
}

std::string PatientData::getName() {
    return _data[1];
}

std::string PatientData::getPatronymic() {
    return _data[2];
}

std::string PatientData::getBirthday() {
    return _data[3];
}

std::string PatientData::getSex() {
    return _data[4];
}

std::string PatientData::getAge() {
    return _data[5];
}

std::string PatientData::getComplaint() {
    return _data[6];
}

std::string PatientData::getAddition()   {
    return _data[7];
}

const std::vector<std::string> &PatientData::getData() {
    return _data;
}

void PatientData::setSurname(std::string surname) {
    _data[0] = surname;
}

void PatientData::setName(std::string name) {
    _data[1] = name;
}

void PatientData::setPatronymic(std::string patronymic) {
    _data[2] = patronymic;
}

void PatientData::setBirthday(std::string birthday) {
    _data[3] = birthday;
}

void PatientData::setSex(std::string sex) {
    _data[4] = sex;
}

void PatientData::setAge(std::string age) {
    _data[5] = age;
}

void PatientData::setComplaint(std::string complaint) {
    _data[6] = complaint;
}

void PatientData::setAddition(std::string addition) {
    _data[7] = addition;
}

bool PatientData::isFull() {
    bool result = true;
    for (int i = 0; i < _data.size() - 2 && result; i++) {
        if (_data[i] == "") {
            result = false;
        }
    }
    return result;
}

std::string PatientData::makeText() {
    std::vector<std::string> data = _data;
    std::string firstStrToDoc = "Пациент:\n" + data[0] + " " + data[1] + " " + data[2] + ", ";

    std::string sex = data[4];
    if (sex == "Мужской") {
        sex = "мужского";
    } else if (sex == "Женский") {
        sex = "женского";
    }

    firstStrToDoc += sex + " пола, ";

    std::string day = data[3].substr(data[3].size() - 7, 2);
    std::string month = data[3].substr(data[3].size() - 11, 3);
    std::string year = data[3].substr(data[3].size() - 4, 4);

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

    firstStrToDoc += "родился " + day + "-го " + month + " " + year + "-го года, ";
    std::string age = data[5];
    if (age[age.size() - 1] == '1' || age[age.size() - 1] == '2' || age[age.size() - 1] == '3' || age[age.size() - 1] == '4') {
        age += " года";
    } else {
        age += " лет";
    }
    firstStrToDoc += "(" + age + ").\n";

//    std::string complaints = data[6];
//    if (complaints == "Боль") {
//        complaints = "боль";
//    } else if (complaints == "Деформация") {
//        complaints = "деформацию";
//    } else if (complaints == "Изменение силы") {
//        complaints = "изменение силы";
//    } else if (complaints == "Отсутствие движений") {
//        complaints = "отсутствие движений";
//    } else if (complaints == "Нарушение чувствительности") {
//        complaints = "нарушение чувствительности";
//    } else if (complaints == "Наличие парастезий") {
//        complaints = "наличие парастезий";
//    } else if (complaints == "Нарушение мочеиспускания") {
//        complaints = "нарушение мочеиспускания";
//    } else if (complaints == "Нарушение дефикации") {
//        complaints = "нарушение дефикации";
//    } else if (complaints == "Нарушение половой функции") {
//        complaints = "нарушение половой функции";
//    }

//    firstStrToDoc += "жалуется на " + complaints + ".\n";

    std::string addition_str = data[7];
    if (addition_str == "") {
        addition_str = "-";
    }

    firstStrToDoc += "Дополнительные сведения : " + addition_str + "\n";

    return firstStrToDoc;
}
