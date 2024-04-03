#include <iostream>
#include <string>
#define random(min,max) (min + rand() % (max - min + 1))
using namespace std;
const char NUMBERS[] = { '0','1','2','3','4','5','6','7','8','9' };
const string firstNameArr[] = { "" };
const string lastNameArr[] = { "" };
class Client;
class Bank;


class Client {
    friend class Bank;
private:
    static int lastId;

    string firstName;
    string lastName;
    int age;
    string bankAccount;
    double balance = 0;
    int id;

public:
    Client() {}

    Client(string firstName, string lastName, int age) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->id = lastId++;

    }

    void setFirstName(string firstName) {
        this->firstName = firstName;
    }

    void setLastName(string lastName) {
        this->lastName = lastName;
    }

    void setAge(int age) {
        this->age = age;
    }

    void showInfo() {
        cout << "First name: " << this->firstName << endl;
        cout << "Last name: " << this->lastName << endl;
        cout << "Age: " << this->age << endl;
        cout << "ID: " << this->id << endl;
        cout << "Balance: " << this->balance << endl;
        cout << "\n\n";
    }

    string getFirstName() {
        return this->firstName;
    }

    string getLastName() {
        return this->lastName;
    }

    int getAge() {
        return this->age;
    }

    string getBankAccount() {
        return this->bankAccount;
    }

    double  getBalance() {
        return this->balance;
    }

};


class Bank {
private:
    Client** clients = new Client * [0];
public:
    string name;
    int size = 0;
    Bank() {

    }

    Bank(string bankName) {
        this->name = bankName;
    }

    bool checkBankAcc(string newBankAcc, string** clients) {
        for (int i = 0; i < size; i++) {
            if (newBankAcc == this->clients[i]->getBankAccount()) {
                return false;
            }
        }
        return true;
    }

    void createBankAccount() {
        bool flag = true;
        string bankAccount = "";

        while (flag) {
            for (int i = 0; i < 8; i++)
            {
                bankAccount += NUMBERS[random(0, 9)];

            }
        }
    }
};

int Client::lastId = 1;

int main()
{
    srand(time(NULL));

    Client* cl1 = new Client(firstNameArr[random(0, 9)], lastNameArr[random(0, 9)], random(18, 70));
    cl1->showInfo();

    Client* cl2 = new Client(firstNameArr[random(0, 9)], lastNameArr[random(0, 9)], random(18, 70));
    cl2->showInfo();

    Client* cl3 = new Client(firstNameArr[random(0, 9)], lastNameArr[random(0, 9)], random(18, 70));
    cl3->showInfo();

}