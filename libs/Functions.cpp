#include "Functions.h"
using namespace std;

extern Chat chat1;

void DisplayValidUsers()
{
	cout << "Available users: " << endl
			 << "login: admin		login: A" << endl
		     <<	"password: admin		password: A" << endl;
}

string loginRequest()
{
	string login;
	cout << "Recipient's login: ";
	getline(cin, login);
	return login;
}

void Menu1()
{

	cout << "#####################" << endl
		<< "1: Register" << endl
		<< "2: Enter the chat" << endl
		<< "3: Exit" << endl
		<< "#####################" << endl
		<< ">";

}

void Menu2()
{
	cout << "\n 1 - Write a message to the general chat " << endl
		<< " 2 - Write a private message " << endl
		<< " 3 - Read general messages " << endl
		<< " 4 - Read private messages " << endl
		<< " 5 - View users " << endl
		<< " 6 - Delete account " << endl
		<< " 7 - Leave chat " << endl
			<< " >";
}

void ChatMenu()
{
	char ch = ' ';

	cout << "\n####Welcome#####\n" << endl;

	do
	{

		Menu2();

		(cin>>ch).ignore();
		//system("cls");
		cout << "\033[2J\033[1;1H";

			switch (ch)
			{
			case '1':
				chat1.WriteMessageToAll();
				break;
			case '2':
			{
				try
				{
					chat1.WritePrivateMessage(loginRequest());
				}
				catch (exception& e)
				{
					cout << e.what() << endl;
				}
			}
			break;
			case '3':
				chat1.CheckGeneralMessages();
				break;
			case '4':
				chat1.CheckPrivateMessages();
				break;
			case '5':
				chat1.DisplayUserList();
				break;
			case '6':
				try
				{
					chat1.DeleteUserFromChat();
				}
				catch (exception& e)
				{
					cout << e.what() << endl;
					ch = ' ';
				}
				break;
			case '7':
					break;
			default:
				ch = '7';
				break;
			}

	} while (ch != '6' && ch != '7');
}

void MainMenu()
{

	char ch = 0;

	do
	{
		DisplayValidUsers();
		Menu1();
		
		(cin >> ch).ignore();
		cout << "\033[2J\033[1;1H";
		
		//system("clear");
		switch (ch)
		{
		case '1':
			try
			{
				chat1.Registration();
			}
			catch (exception& e)
			{
				cout << e.what() << endl;
			}
			break;
		case '2':
			try
			{
				if (chat1.EnterChat())
				{
					ChatMenu();
				}
			} 
			catch (exception& e)
			{
				cout << e.what() << endl;
			}
			break;
		default:
			break;
		}

	} while (ch != '3');
}
