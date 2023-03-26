
#include <string>
#include <iostream>
class Users
{
public:
	Users(std::string& name, std::string& nick, std::string& psw)
		:_name(name), _nick(nick), _psw(psw)
	{};
	void  getNick()
	{
	}


private:

	std::string _name;
	std::string _nick;
	std::string _psw;
	// int _index_user;

};


class Messages
{
private:
	std::string _text;
	std::string _sender;
	std::string _receiver;
};
class Chat
{
};


int main()
{
	Users both();
	int x, y;
	x = 1;
	y = 7;
	std::cout << "x= " << x << " y= " << y << "\n";
	(x < y ? x : y) = 9;
	std::cout << "x= " << x << " y= " << y << "\n";
	std::cout << "Hello World!\n";
}

/*






*/