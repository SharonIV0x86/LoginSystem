#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;
char password_attempts, pin_attempts = 1;
char password_tries = 4;
// The password is: SharonIV
// The PIN is: 6969
std::string pin_array[3] = {"1234", " 5678", "6969"};
std::string right_pin = pin_array[2];

std::string password_array[3] = {"lmao", "kek", "SharonIV"};
std::string right_password = password_array[2];

class Login
{
public:
    int checkCREDS(string pin, string password, string NickName)
    {

        if (pin != right_pin)
        {
            password_correct_pin_wrong(pin, password, NickName);
        }
        else if (password != right_password)
        {
            pin_correct_password_wrong(pin, password, NickName);
        }
        else if (pin == right_pin || password == right_password)
        {
            clear_screen_cross_platform();
            std::cout << "\n\n\tLOGIN SUCCESS! WELCOME! " << NickName;
        }
        else if (pin != right_pin || password != right_password)
        {
            clear_screen_cross_platform();
            std::cout << "\n\n\tPASSWORD or PIN wrong, please re-enter the credentials! ";
            takeCREDS();
        }
        else
        {
            clear_screen_cross_platform();
            std::cout << "\n\n\tUnexpected Error Occured, Please Enter The Credentials Again. ";
            std::cout << "\n\n\tHere is the error code: 0xffx98. ";

            takeCREDS();
        }
        return 0;
    }

    void takeCREDS()
    {
        std::string pin_main_input;
        std::string password_main_input, NickName;

        std::cout << "\n\n\tEnter Your NickName ";
        std::getline(std::cin, NickName);
        if (NickName.empty())
        {

            clear_screen_cross_platform();
            std::cout << "\n\n\tNickName field cannot be empty! ";
            takeCREDS();
        }
        std::cout << "\n\n\tEnter the password: ";
        std::getline(cin, password_main_input);
        if (password_main_input.empty())
        {

            clear_screen_cross_platform();

            std::cout << "\n\n\tPASSWORD field cannot be empty! ";
            takeCREDS();
        }
        std::cout << "\n\n\tChecking password please wait....";

        delay_only_delay();

        std::cout << "\n\n\tEnter the PIN: ";
        std::getline(std::cin, pin_main_input);
        if (pin_main_input.empty())
        {
            
            clear_screen_cross_platform();
            std::cout << "\n\n\tPIN field cannot be empty! ";
            takeCREDS();
        }
        std::cout << "\n\n\tChecking PIN please wait...";
        delay_only_delay();

        checkCREDS(pin_main_input, password_main_input, NickName);
    }
    void pin_correct_password_wrong(string pin_2, string password_2, string NickName_2)
    {
        std::cout << "\n\n\tInvalid Password. Please re-enter the creds: ";

        std::getline(std::cin, password_2);

        while (password_2 != right_password)
        {
            password_tries--;
            password_attempts++;
            std::cout << "\n\n\tInvalid PASSWORD, please re-enter PASSWORD you have only " << password_tries << " attempts left: ";
            std::cin.ignore();
            std::getline(std::cin, password_2);
            if (password_attempts > 3)
            {
                std::cout << "\n\n\tToo many wrong  attempts! ";
                delay_cross_platform_and_errors();
                takeCREDS();
                break;
            }
        }
        if (password_2 == right_password)
        {
            std::cout << "\n\n\tNow! Enter the PIN! ";
            std::getline(std::cin, pin_2);
            std::cin.ignore();

            if (pin_2 == right_pin)
            {
                std::cout << "\n\n\tTest PASSWORD";
                clear_screen_cross_platform();
                std::cout << "\n\n\tLOGIN SUCCESS! WELCOME! " << NickName_2;
            }
            else if (pin_2 != right_pin)
            {
                std::cout << "\n\n\tEnter the credentails again! ";
                takeCREDS();
            }
        }
    }
    void password_correct_pin_wrong(string pin_1, string password_1, string NickName_1)
    {

        std::cout << "\n\n\tInvalid PIN, Please re-enter the creds: ";
        std::getline(std::cin, pin_1);

        while (pin_1 != right_pin)
        {
            int pin_tries = 4;
            pin_tries--;
            pin_attempts++;

            std::cout << "\n\n\tInvalid PIN. please re-enter the PIN! you have only:  " << pin_tries << " attempts left: ";
            std::cin >> pin_1;
            std::cin.ignore();
            if (pin_attempts > 3)
            {
                std::cout << "\n\n\tToo many wrong attempts! ";
                delay_cross_platform_and_errors();
                takeCREDS();
                break;
            }
        }
        if (pin_1 == right_pin)
        {
            std::cout << "\n\n\tNow! Enter The Password! ";
            std::cin.ignore();
            std::getline(std::cin, password_1);
            std::cin.ignore();
            if (password_1 == right_password)
            {

                clear_screen_cross_platform();
                std::cout << "\n\n\tLOGIN SUCCESS! WELCOME! " << NickName_1;
                hold_screen();
            }
            else if (password_1 != right_password)
            {
                clear_screen_cross_platform();
                std::cout << "\n\n\tEnter the credentials again! ";
                takeCREDS();
            }
        }
    }
    void delay_cross_platform_and_errors()
    {
#ifdef _WIN32
        {

            long delay = 1000;
            for (int i = 10; i > 0; i--)
            {
                std::cout << "\nPlease wait for " << i << " seconds before trying again! " << std::endl;
                Sleep(delay);
                clear_screen_cross_platform();
            }
        }
#else
        {
            for (int i = 20; i > 0; i--)
            {
                std::cout << "Please wait for " << i << " seconds before trying again." << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }
#endif
    }
    void clear_screen_cross_platform()
    {
#ifdef _WIN32
        std::system("cls");

#else
        std::system("clear");
#endif
    }
    void hold_screen()
    {
#ifdef _WIN32
        _getch();

#else
        std::cin.get();

#endif
    }
    void delay_only_delay()
    {
#ifdef _WIN32
        {
            Sleep(3000);
        }
#else
        {
            std::this_thread::sleep_for(std::chrono::seconds(3));
        }
#endif
    }
};

int main()
{
    Login l1;
    l1.takeCREDS();
    return 0;
}
