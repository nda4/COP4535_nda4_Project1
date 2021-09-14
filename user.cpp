#include "user.hpp"

User::User(){
}

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
        passcode = generatePasscode();
        writeFile << name << ' ' << passcode << '\n';
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