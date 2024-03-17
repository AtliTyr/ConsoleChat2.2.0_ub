#include "Chat.h"

Chat::Chat()
{
	//Registration("admin", "admin", "admin");
	//Registration("A", "A", "A");

 	//WriteTestMessages();
}
Chat::~Chat() = default;

void Chat::Registration()
{
			cout << "Register" << endl;
			User user;
			char ch = ' ';
			do
			{
				cout << "To exit, enter '0': ";
				//ch = getch();
				(cin>>ch).ignore();
				if (ch == '0')
					throw bad_Registration();

				cout << "\033[2J\033[1;1H";

				user.setUserData();
				if (base.findUserIndex(user.getLogin()) != -1)
				{
					cout << "The entered login is busy" << endl;
				}

			} while (base.findUserIndex(user.getLogin()) != -1);
				

				cout << "User successfully registered" << endl;
				base.addUserToUserBase(user);
				
}

void Chat::Registration(std::string name, std::string login, std::string password)
{
	User user(name, password, login);
	base.addUserToUserBase(user);
	
}
bool Chat::EnterChat()
{
				
				std::string password;
				std::string login;
				char ch;
				do
				{
					cout << "Log in" << endl;

					cout << "To exit, enter '0': ";
					//ch = getch();
					(cin >> ch).ignore();
					if (ch == '0')
						throw bad_Authorization();

					//	system("cls");
					cout << "\033[2J\033[1;1H";

					cout << "Enter login: ";
					cin >> login;

					cout << "Enter password: ";
					std::cin >> password;
				} while (!base.authorization(login, password));

					//system("cls");
					cout << "\033[2J\033[1;1H";
					cout << "Authorization successful" << endl;
					authorized = base[base.findUserIndex(login)];
					return true;
}

void Chat::DisplayUserList() // For testing. Then delete
{
	base.displayUserBase();
}

void Chat::DeleteUserFromChat()
{
	if (authorized.getLogin() == "admin" || authorized.getLogin() == "A")
	{
		throw bad_Delete();
	}
	else
	{
		base.deleteUserFromUserBase(authorized.getLogin());
		cout << "Account deleted" << endl;
	}
}

void Chat::WriteMessageToAll()
{
	cout << "<" << authorized.getLogin() << "> : ";
	string msg="";
	getline(cin,msg,'\n');

	m_base.AddMessageToChat(Message(authorized.getLogin(), "", msg));
	//	chat.emplace_back(Message(authorized.getLogin(), "", msg));
}
void Chat::WritePrivateMessage(std::string login)
{
	if (authorized.getLogin() == login)
	{
		throw bad_Recepient();
	}

	if (base.findUserIndex(login) != -1)
	{
		cout << "<" << authorized.getLogin() << "> to <" << login << "> :";
		string msg;
		getline(cin, msg);
	
		m_base.AddMessageToChat(Message(authorized.getLogin(), login, msg));	
	//	chat.emplace_back(Message(authorized.getLogin(),login, msg));
	}
	else
	{
		throw bad_Recepient();
	}
}
void Chat::CheckGeneralMessages()
{
	m_base.DisplayChat();
}
void Chat::CheckPrivateMessages()
{
	m_base.DisplayChat(authorized);
}


void Chat::WriteTestMessages()
{
	m_base.AddMessageToChat(Message("", "", "Test Message"));
	m_base.AddMessageToChat(Message("", "", "Test Message1"));
	m_base.AddMessageToChat(Message("", "", "Test Message2"));
}
