#pragma once
#include <iostream>
#include <fstream>
class Logger
{
private:
	std::ofstream log_file;
	
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;

	Logger() {
		log_file.open("log.txt", std::ios::app);
	}

	~Logger() {

		log_file.close();
	}
public:
	static Logger& get_instance() {
		static Logger instance;
		return instance;
	}

	void append_file(std::string msg) {
		log_file << msg << std::endl;
	}





};

