#include "user.hpp"

User::User(){}

User::User(std::string username, std::string passcode){
    this->username = username;
    this->passcode = passcode;
}


void User::setUsername(std::string userName){
    this->username = userName;
}

void User::setPasscode(std::string passcode){
    this->passcode = passcode;
}


std::string User::getUsername(){
    return username;
}

std::string User::getPasscode(){
    return passcode;
}


void User::writeRawData(){
    std::ifstream readFile;
    std::ofstream writeFile;
    readFile.open("names.txt");
    writeFile.open("rawdata.txt");
    std::string name, passscode;
    while(!readFile.eof()){
        readFile >> name;
        readFile.ignore(256, '\n');
        writeFile << '\n';
        passcode = generatePasscode();
        writeFile << name << ' ' << passcode;
    }

    readFile.close();
    writeFile.close();
}

std::string User::generatePasscode(){

    static const char letters[] = "abcdefghijklmnopqrstuvwxyz";
    std::string password;
    for(int i = 0; i < 9; i++)
        password+=(letters[(rand() % 26)]);
    return password;
}

void User::encryptData(std::string key){
    std::ifstream readFile;
    std::ofstream writeFile;
    readFile.open("rawdata.txt");  
    writeFile.open("encrypteddata.txt");
    std::string name, passscode;
    while(!readFile.eof()){
        readFile >> name;       
        readFile >> passcode;
        passcode = VNCipher(passcode, key);
        writeFile << name << ' ' << passcode << '\n';
    }
}

std::string User::VNCipher(std::string passcode, std::string key){
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int indexKey = 0;
    int indexPasscode;
    for(long unsigned int i = 0; i < passcode.size(); i++){
        if(i <= key.size()-1){
            indexKey = alphabet.find(key.at(i));
            indexPasscode = alphabet.find(passcode.at(i));
            if(indexKey > indexPasscode){
                indexPasscode += 26;
            }
            indexPasscode -= indexKey;
            passcode.at(i) = alphabet.at(indexPasscode);
        }
        else if(i > key.size()-1){
            indexKey = alphabet.find(key.at(i - key.size()));
            indexPasscode = alphabet.find(passcode.at(i));
            if(indexKey > indexPasscode){
                indexPasscode += 26;
            }
            indexPasscode -= indexKey;
            passcode.at(i) = alphabet.at(indexPasscode);
        }
    }
    return passcode;
}