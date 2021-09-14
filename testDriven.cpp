#include "user.hpp"
#include "hashTable.hpp"

void testAssignedUser(std::string username, std::string passcode);

int main(){
    std::cout << ("Lol this actuaally barely works\n");
    //User.cpp Tests
    testAssignedUser("testName", "testCode");
    //hastTable.cpp Tests

}

void testAssignedUser(std::string username,std::string passcode){
    //Manually places username/passcode, makes sure they match actual assignments
    User testUser(username, passcode);
    
    if(testUser.getUsername() != username)
        std::cout << "testUserClass :: username FAILED\n";
    else 
        std::cout << "testUsernameClass :: username PASSED\n";
    if(testUser.getPasscode() != passcode)
        std::cout << "testUserClass :: passcode FAILED\n";
    else
        std::cout << "testUserClass :: passcode PASED\n";
}