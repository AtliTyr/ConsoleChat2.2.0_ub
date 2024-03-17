#pragma once
#include <vector>
#include "Message.h"
#include <fstream>
#include <filesystem>
#include <iostream>
#include "User.h"

namespace fs = std::filesystem;

const char MessageFilePath[] = "Logs/MessageBase.txt";

class MessageBase
{
private:
	std::vector <Message> chat; // Массив сообщений чата
	std::fstream mFile;
public:
	MessageBase();
	~MessageBase();

	void AddMessageToChat(const Message& message);

	void DisplayChat();
	void DisplayChat(User& user);

	void LoadMessagebaseFromFile();
};

