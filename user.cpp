#include "user.hpp"



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


void User::writeRawData(std::string fileName){
    std::ifstream()
}