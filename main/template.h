#pragma once
//#include <string>
template<typename T>
class Chat
{
public:
	Chat(std::string& name, std::string& login, std::string& psw);

	const std::string& getLogin()  const;
	const std::string& getPsw() const;
	const std::string& getName() const;

	void  setLogin(const std::string& login);
	void  setPsw(const std::string& psw);
	void  setName(const std::string& name);

private:

	std::string _name;
	std::string _login;
	std::string _psw;


};
