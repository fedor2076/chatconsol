#include "chat.h"


int main()
{
	Chat chat;
	chat.start();

	
	while (chat.chatWork())
	{
		chat.loginMenu();
		

		while (chat.getCurrentUser())
		{
			
			chat.chatMenu();

		}
	}
}
//getline(std::cin, question);
	  //std::cout << question << "\n";
	 // bot_replay(question);

/*
 //  system("chcp1251>0");
  // setlocale(0, "");
  // SetConsoleOutputCP(1251);
  // SetConsoleCP(1251);
	//<windows.h>
  // bot_replay(question);
   // std::cout << "Hello World!\n";

   std::string question;
	bot_replay(question);
	while (question != "0")
	{

		getline(std::cin, question);
		std::cout << question << "\n";
		bot_replay(question);
	}

std::map<std::string, std::string>
user = {
	{"0","exit"},//выход
	{"1","sign up"},//регистрация
	{"2","login"}//вход

};

void bot_replay(std::string user_text)
{
	for (auto& _user : user)
	{
		std::cout << _user.first << " - " << _user.second << "\n";
	}


}

*/

