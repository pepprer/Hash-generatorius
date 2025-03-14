//
// Created by Patryk on 2020-09-27.
//

#include "../hFiles/ReadWrite.h"

void ReadWrite::readFile() {
    string fileName;

    cout << "Iveskite failo pavadinima: ";

    cin >> fileName;

    ifstream fd;
    fd.open(fileName);
    do {
        try {
            if (fd.fail()) {
                throw runtime_error("Nepavyko atidaryti failo!\n");
            }
        }
        catch (const runtime_error &e) {
            cout << e.what();
            fileName = "";
            cin.ignore(256, '\n');
            cout << "Veskite dar karta failo pavadinima: ";
            cin >> fileName;
            fd.open(fileName);
        }
    } while (fd.fail());

    input.assign((istreambuf_iterator<char>(fd)),
                       (istreambuf_iterator<char>()));

    fd.close();
}

void ReadWrite::write() {
    cout << "Sekmingai uzsifruotas: " << output << endl;
}

ReadWrite::ReadWrite() {
    readFile();
}

string ReadWrite::checkInput(const string &value1, const string &value2) {
    string helper;
    string m = "\nBlogas ivedimas, turi buti ";
    m += "'" + value1 + "'";
    m += " arba ";
    m += "'" + value2 + "'";
    m += " !\n";

    cin >> helper;
    do {
        try {
            if (helper != value1 && helper != value2) {
                throw runtime_error(m);
            }
        }
        catch (const runtime_error &e) {
            cout << e.what();
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Veskite duomeni dar karta: ";
            cin >> helper;
        }

    } while (helper != value1 && helper != value2);

    return helper;
}

string ReadWrite::getInput() {
    return input;
}

void ReadWrite::setOutput(string str) {
    output = str;
}


