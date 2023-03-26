#pragma once
#include "users.h"
class Messages
{
public:
	Messages(std::string& sender, std::string& receiver, std::string& text) {};

	std::string getSender();
	std::string getReceiver();
	std::string getText();
	void setSender();
	void setReceiver();
	void setText();

private:
	std::string _text;
	std::string _sender;
	std::string _receiver;
};