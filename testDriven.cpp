
/* 
    I do not have personal experience doing test Driven development.
    this .cpp is really just a small test for myself to see if I can just
    make it up. I dont actually know if I am approaching this correctly.
    If not, please let me know. I must not be because there are some methods
    I am not sure how to make tests for...such as User::generatePasscode
*/

#include "user.hpp"
#include "hashTable.hpp"

void testAssignedUser(std::string username, std::string passcode);
void testWriteRawData();
void testGeneratePasscode();

int main(){
    std::cout << ("Lol this actuaally barely works\n");
    //User.cpp Tests
    testAssignedUser("testName", "testCode");
    testGeneratePasscode();
    testWriteRawData();
    //hashTable.cpp Tests

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
        std::cout << "testUserClass :: passcode PASSED\n";
}

void testGeneratePasscode(){
    User testUser1;
    User testUser2;
    std::cout << "Generate Passcode Test (next 2 lines are passcodes) :: \n";
    std::cout << "testUser1 passcode :: " << testUser1.generatePasscode() << std::endl;
    std:: cout << "testUser2 passcode :: " << testUser2.generatePasscode() << std::endl;
}

void testWriteRawData(){

    //Tests multiple portions of User::writeRawData
    User testUser;
    testUser.writeRawData();
    std::ifstream itest;
    itest.open("names.txt");

    //States names.txt successfully opened
    if(itest.is_open())
        std::cout << "Open names.txt :: PASSED\n";
    else{
        std::cout << "Open names.txt :: FAILED\n";
        return;
    }
    std::string name1, name2;
    itest >> name1;
    itest.ignore(256, '\n');
    itest >> name2;

    //States names.txt has correct info and was read correctly
    if(name1 == "SMITH" && name2 == "JOHNSON")
        std::cout << "Names.txt names test :: PASSED\n";
    else
        std::cout << "Names.txt names test :: FAILED\n";
    std::ifstream otest;
    otest.open("rawdata.txt");

     //States rawdata.txt successfully opened
    if(otest.is_open())
        std::cout << "Open rawdata.txt :: PASSED\n";
    else{
        std::cout << "Open rawdata.txt :: FAILED\n";
        return;
    }
    
    //States rawdata.txt contains same names as names.txt
    std::string rawname1, rawname2;
    otest >> rawname1;
    otest.ignore(256, '\n');
    otest >> rawname2;
    if(rawname1 == name1 && rawname2 == name2)
        std::cout << "Names.txt and RawData.txt names match test :: PASSED\n";
    else
        std::cout << "Names.txt and RawData.txt names match test :: FAILED\n";
}

