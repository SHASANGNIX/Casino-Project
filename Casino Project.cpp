#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void drawLine(int n, char symbol)
{
    for (int i = 0; i < n; i++)
        cout << symbol;
    cout << "\n";
}
void rules()
{
    system("cls");
    cout << "\n\n";
    drawLine(80, '-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(80, '-');
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 10 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(80, '-');
}
class detail
{
protected:
    string playername;
    char id[10];
    float balance = 100.00;

public:
    void information()
    {
        cout << "Enter player name :";
        getline(cin, playername);

    }
    void show()
    {
        cout << "Name :" << playername << endl;

        cout << "Congtrats You have $100 bonus" << endl;
        cout << "Balance =" << balance << endl;
    }
    void deposit()
    {
        float deposit;
        cout << "Enter deposit amount :" << endl;
        cin >> deposit;
        balance = balance + deposit;
        cout << "New Balance = " << balance << endl;

    }

    void withdraw()
    {
        float withdraw1;
        cout << "Your Balance is :"<<balance<<endl<<"Enter withdraw amount (must be less than balance) :" << endl;
        cin >> withdraw1;
        if (withdraw1 > balance)
        {
            cout << "Enter less amount !!" << endl;
        }
        else
        {
            balance = balance - withdraw1;
            cout << "New balance = " << balance << endl;
        }

    }
};


class games : virtual public detail
{
protected:
    string symbols[6] = {"Cherry", "Orange", "Plum", "Bell", "Melon", "Bar"};
    int payouts[6] = {2, 4, 6, 10, 20, 50};
    float bettingAmount;
    int guess, dice;
    char choice;

public:
    void luck_game(float &b, string &p)
    {
        do
        {
            rules();
            cout << "\n\nYour current balance is  " << b << "\n";


            do
            {
                cout << p << ", enter money to bet : ";
                cin >> bettingAmount;
                if (bettingAmount > b)
                    cout << "Your betting amount is more than your current balance\n"
                         << "\nRe-enter data\n ";
            } while (bettingAmount > b);


            do
            {
                cout << "Guess your number to bet between 1 to 10 :";
                cin >> guess;
                if (guess <= 0 || guess > 10)
                    cout << "Please check the number!! should be between 1 to 10\n"
                         << "\nRe-enter data\n ";
            } while (guess <= 0 || guess > 10);

            dice = rand() % 10 + 1;

            if (dice == guess)
            {
                cout << "\n\nGood Luck!! You won Rs." << bettingAmount * 10;
                b = b + bettingAmount * 10;
            }
            else
            {
                cout << "Bad Luck this time !! You lost  " << bettingAmount << "\n";
                b = b - bettingAmount;
            }

            cout << "\nThe winning number was : " << dice << "\n";
            cout << "\n"
                 << p << ", You have  " << b << "\n";
            if (b == 0)
            {
                cout << "You have no money to play ";
                break;
            }
            cout << "\n\n-->Do you want to play again (y/n)? ";
            cin >> choice;
        } while (choice == 'Y' || choice == 'y');
    }
    void roll_game(float &B,string &P)
    {
       system("cls");
        cout << "Welcome to the Slot Machine!\n"
             << endl;
        cout << "You have " << B << " amount.\n"
             << endl;
        cout << "Each spin costs 1 .\n"
             << endl;

        while (B > 0)
        {

            cout << "Do you want to spin? (y/n): ";
            cin >> choice;

            if (choice == 'y' || choice == 'Y')
            {
                cout << "Spinning the reels..." << endl;
                int index1 = rand() % 6;
                int index2 = rand() % 6;
                int index3 = rand() % 6;
                cout << setw(10) << symbols[index1] << setw(10) << symbols[index2] << setw(10) << symbols[index3] << endl;


                if (index1 == index2 && index2 == index3)
                {
                    B += payouts[index1];
                    cout << "Congratulations! You won " << payouts[index1] << " tokens." << endl;
                }
                else
                {
                    cout << "Sorry, you didn't win this time." << endl;
                }
                B--;
                cout << "You have " << B << " amount left." << endl;
            }
            else if (choice == 'n' || choice == 'N')
            {
                cout << "Thanks for playing!" << endl;
                break;
            }
            else
            {
                cout << "Invalid choice. Please enter 'y' or 'n'." << endl;
            }
        }

        cout << "Game over. You finished with " << B << " amount." << endl;
    }

};

class casino : public games
{
protected:
    int ch;

public:
    void display()
    {
        drawLine(60, '_');
        cout << "\n\n\n\t\tCASINO\n";
        cout << "\n\n\t\t1.CASINO GAME\n";
        cout << "\n\t\t2.ADD MONEY \n";
        cout << "\n\t\t3.WITHDRAW MONEY \n";
        cout<<"\n\t\t4.EXIT\n";
        drawLine(60, '_');
    }
    void game()
    {
        cout << "\t\t\tCASINO GAME\t\t\t\n";
        cout << "\t 1.Guessing Game \n";
        cout << "\t 2.Rolling Game \n\n";
        cout << "Enter the choice :";
        cin >> ch;
        if (ch == 1)
            luck_game(balance,playername);
        if (ch == 2)
            roll_game(balance,playername);
    }
    void depo()
    {
        deposit();

    }
    void with()
    {
        withdraw();

    }
    void info()
    {
        information();
        show();
    }

};
int main()
{
    srand(time(0));

    casino c;
    c.info();
here:
    c.display();
    int co;

    cout << "Enter a choice: ";
    cin >> co;
    if (co==1)
     {
     c.game();
     goto here;
     }
   else if (co==2)
     {
     c.depo();
     goto here;
     }
    else if (co==3)
    {
     c.with();
     goto here;
    }
    else if(co==4)
    {
     cout<<"Thank you for playing and visit again (please give us good marks)";
    }
    else
    {
        cout<<"Enter valid choise";
    }

}
