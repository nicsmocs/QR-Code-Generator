#include "qrcodegen.h"
#include "nicsmocs.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace qrcodegen;

void writeToFile(const std::string& text, const std::string& path)
{
	const auto outFilePath = path + "/qrcode.svg";
	std::ofstream outputFile;
	outputFile.open(outFilePath);
	outputFile << text;
	outputFile.close();
	std::cout << "wrote output to file: " << outFilePath << std::endl;
}

void printWelcome()
{
	Init();
	std::cout << " _______  ______      _______  _______  ______   _______"		<< std::endl;
	std::cout << "|       ||    _ |    |   ____||       ||      | |       |"	<< std::endl;
	std::cout << "|   _   ||   | ||    |  |     |   _   ||  _    ||    ___|"	<< std::endl;
	std::cout << "|  | |  ||   |_||_   |  |     |  | |  || | |   ||   |___ "	<< std::endl;
	std::cout << "|  |_|  ||    __  |  |  |     |  |_|  || |_|   ||    ___|"	<< std::endl;
	std::cout << "|      | |   |  | |  |  |____ |       ||       ||   |___ "	<< std::endl;
	std::cout << "|____||_||___|  |_|  |_______||_______||______| |_______|"	<< std::endl;
	std::cout << " _______  _______  __    _  _______  ______    _______  _______  _______  ______"		<< std::endl;
	std::cout << "|       ||       ||  |  | ||       ||    _ |  |   _   ||       ||       ||    _ |"	<< std::endl;
	std::cout << "|    ___||    ___||   |_| ||    ___||   | ||  |  |_|  ||_     _||   _   ||   | ||"	<< std::endl;
	std::cout << "|   | __ |   |___ |       ||   |___ |   |_||_ |       |  |   |  |  | |  ||   |_||_"	<< std::endl;
	std::cout << "|   ||  ||    ___||  _    ||    ___||    __  ||       |  |   |  |  |_|  ||    __  |"	<< std::endl;
	std::cout << "|   |_| ||   |___ | | |   ||   |___ |   |  | ||   _   |  |   |  |       ||   |  | |"	<< std::endl;
	std::cout << "|_______||_______||_|  |__||_______||___|  |_||__| |__|  |___|  |_______||___|  |_|"	<< std::endl << std::endl;
	std::cout << "example call:\nqrcodegenerator https://nicsmocs.com C:/nicsmocs/pics" << std::endl;
}

int main(int argc, char* argv[])
{
	printWelcome();

	if (argc < 3)
	{
		std::cout << "ERROR: give 2 args: 1. text for qrCode, 2. path to save qr code as svg" << std::endl;
		return -1;
	}

	const auto text = argv[1];
	const std::string path = std::string(argv[2]);
	const QrCode::Ecc errCorLvl = QrCode::Ecc::LOW;
	const QrCode qr = QrCode::encodeText(text, errCorLvl);
	writeToFile(toSvgString(qr), path);
	return 0;
}