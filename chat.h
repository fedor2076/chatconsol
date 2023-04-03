#pragma once
#include <iostream>
//#include <map>
#include "message.h"
#include <vector>
#include <exception>
#include <windows.h>
//#include "user.h"
//#include <string>

class Chat
{
public:
	void start() { _chatOn = true; };//ready
	bool chatWork() { return _chatOn; };//ready

	std::shared_ptr<User> getCurrentUser() const
	{
		return _currentUser;
	}
	void loginMenu()
	{
		char operation;
		_currentUser = nullptr;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "1 - login: 2 - signup: 3 - exit: \n";

		do
		{


			std::cin >> operation;

			switch (operation)
			{
			case '1':
				login();
				break;
			case '2':
				signUp();
				break;
			case '3':
				_chatOn = false;
				SetConsoleTextAttribute(hConsole, 15);
				break;
			default:
				SetConsoleTextAttribute(hConsole, 14);
				std::cout << "1 - login: 2 - signup: 3 - exit: \n";

				std::cin.ignore();


				break;
			}

		} while (!_currentUser && _chatOn);
	}
	void chatMenu()
	{
		char operation;



		std::cout << _currentUser->getLogin() << ": " << "\n";
		while (_currentUser)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 14);

			std::cout << "1-show chat: 2-send message: 3-chat menu:\n";

			SetConsoleTextAttribute(hConsole, 11);

			std::cin >> operation;
			switch (operation)
			{
			case '1':
				showChat();
				break;
			case '2':
				sendMessage();
				break;
			case '3':
				loginMenu();
				break;
			default:
				break;

			}
		}

	};

private:
	bool _chatOn = false;
	std::vector<User> _users;
	std::vector<Message> _messages;
	std::shared_ptr<User> _currentUser = nullptr;
	//ready
	void login() {
		std::string login, password;
		char  operation;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 6);
		do
		{
			std::cout << "login: ";
			std::cin >> login; 
			std::cout << "\n";
			std::cout << "password: ";//std::cin >> password;
			std::cin >> password;
			_currentUser = getUserByLogin(login);

			if (_currentUser == nullptr || (password != _currentUser->getPsw()))
			{
				_currentUser = nullptr;

				std::cout << "login failed __ " << "\n";
				std::cout << "3 - exit or any key __ " << "\n";

				//getline(std::cin, operation);
				std::cin >> operation;

				if (operation == '3')
					break;

			}
			std::cout << "login ------------\n";
		} while (!_currentUser);

	};
	//ready
	void signUp()
	{
		std::string login, password, name;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "login:\n";
		std::cin >> login;
		//	getline(std::cin, login);
		std::cout << "password:\n";
		std::cin >> password;
		//getline(std::cin, password);
		std::cout << "name:\n";
		std::cin >> name;
		// getline(std::cin, name);
		/*
		if (getUserByLogin(login) || login=="all")
		{
		throw UserLoginExp();
		}

		*/

		User user{ name, login, password };
		_users.push_back(user);
		_currentUser = std::make_shared<User>(user);
		std::cout << "signUp ------------\n";

	};
	//ready
	void showChat() const
	{
		std::string from, to;
		std::cout << " -----------chat-------  \n";
		for (auto& mess : _messages)
		{
			if (_currentUser->getLogin() == mess.getFrom() || _currentUser->getLogin() == mess.getTo() || mess.getTo() == "all")
			{
				from = (_currentUser->getLogin() == mess.getFrom()) ? "me" : getUserByLogin(mess.getFrom())->getName();

				if (mess.getTo() == "all")
				{
					to = "(all)";
				}
				else
				{
					to = (_currentUser->getLogin() == mess.getTo()) ? "me" : getUserByLogin(mess.getTo())->getName();
				}
				std::cout << "message from " << from << ": to " << to << "\n";
				std::cout << " - " << mess.getText() << " - \n";
			}
		}
		std::cout << "---------------------------\n";
	};
	//	void showAllUsersName() const;
	void sendMessage()
	{
		std::string to, text;
		std::cout << "to (name or all) - ";
		std::cin >> to;
		std::cout << "text - ";
		std::cin.ignore();
		getline(std::cin, text);

		if (!(to == "all" || getUserByName(to))) {
			std::cout << "error no such user  -- " << to << "\n";
			return;
		}
		if (to == "all")
			_messages.push_back(Message(_currentUser->getLogin(), "all", text));
		else
			_messages.push_back(Message(_currentUser->getLogin(), getUserByName(to)->getLogin(), text));
		std::cout << "message send -  " << to << ":\n ";
	};
	std::vector<User>& getAllUsers() { return _users; }
	std::vector<Message>& getAllMessages() { return _messages; }
	//ready
	std::shared_ptr<User> getUserByLogin(const std::string& login) const
	{
		for (auto& user : _users)
		{
			if (login == user.getLogin())
				return std::make_shared<User>(user);
		}
		return nullptr;
	};
	//ready
	std::shared_ptr<User> getUserByName(const std::string& name) const
	{
		for (auto& user : _users)
		{
			if (name == user.getName())
				return std::make_shared<User>(user);
		}
		return nullptr;
	};
};
