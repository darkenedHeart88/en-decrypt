#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <cstdlib>
#include <string>

//#include "ciphers/ceaserCipher.h"

//#include <bits/stdc++.h>

using namespace std;

int testVal = 0;

string alphaRegLow[26] = {
	"a","b","c","d","e",
	"f","g","h","i","j",
	"k","l","m","n","o",
	"p","q","r","s","t",
	"u","v","w","x","y",
	"z"
};




string alphaRegUp[26] = {
	"A","B","C","D","E",
	"F","G","H","I","J",
	"K","L","M","N","O",
	"P","Q","R","S","T",
	"U","V","W","X","Y",
	"Z"
};

string numRegSeq[10] = {
	"0","1","2","3","4",
	"5","6","7","8","9"
};


string altChar[37] = {
	"@","#","$","_","&","-",
	"+","(",")","/","*","""",
	"'",":",";","!","?","~",
	"`","|","•","√","π","÷",
	"×","¶","∆","£","¢","€",
	"¥","^","°","=","%","©"
	//"®","™","✓","[","]","\",
	//"{","}","<",">"
};

string modAlphaLow_1[26] = {

	"k","w","a","x","o",
	"y","v","q","u","l",
	"m","f","h","e","i",
	"r","p","b","g","n",
	"s","z","c","j","t",
	"d","

}

string modAlphaUp_1[26] = {

	"L","E","U","W","S",
	"B","V","O","N","A",
	"K","S","I","Z","T",
	"Y","C","H","M","D",
	"F","G","P","R","X",
	"J"

};

string modNumSeq_1[10] = {
	"8","3","6","0","5",
	"1","4","9","2","7"
};


string modAltChar[] = {};

void ceaserCipher(string passphrase)
{
	string c_cipher;
	int char_counter = 0;
	int passphraseCount = passphrase.size();
}

void basicReadOutReadInFunction()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	int a,b;
	cin >> a >> b;
	cout << a+b << endl;

}


void output2file(string filename)
{
	ofstream outputFile;
	outputFile.open(filename);
	outputFile << "writing this to file\n";
	outputFile.close();

}

void createTestFile()
{
	int randNum =  rand() % 100 + 1;
	int i = 0;

	ofstream test;
  	test.open("test.txt");

	if(test.is_open())
	{
		cout << "file opened!" << endl;
	}

	while(i < randNum)
	{

		test << "hello world!";
		i++;
	}

	test << " " << randNum;
	test.close();

}

void readFile()
{
	ifstream file;
	file.open("test.txt");

	if(file.is_open())
	{
		cout << "file is open" << endl;
	}

	string line;

	while(getline(file, line))
	{
		file >> line;
		cout << line << endl;
	}

	file.close();

}

void readFileCharacterByCharacter()
{
	ifstream file;
	file.open("test.txt");

	if(file.is_open())
	{
		cout << "file opened!" << endl;
	}

	char ch;

	while(file  >> noskipws >> ch)
	{
		cout << ch << endl;
	}

	file.close();

}


void beginEncryption(string filename, string fileformat, string passcode)
{



}

void beginDecryption(string filename, string fileformat, string passcode)
{



}


int main(int argc, char* argv[])
{

	cout << "option[encrypt/decrypt]   filename[]	fileformat[hex/plaintext]   passcode[+12 A/a/#/&]" << endl;

	string option = argv[1];
	string filename = argv[2];
	string fileformat = argv[3];
	string passcode = argv[4];

	if(option == "encrypt")
	{
		if(!filename.empty() && !fileformat.empty() && !passcode.empty())
		{
			bool passcodeCheck = 0;

			bool alphaLower = 0;
			bool alphaUpper = 0;
			bool numSeq = 0;
			bool altCh = 0;

			int varCount = 0;

			while(passcodeCheck == 0)
			{
				for(int i = 0; i < passcode.size(); i++)
				{
					char ch = passcode[i];
		 			for(int j = 0; j < sizeof(alphaRegLow); j++)
					{
						string comp = alphaRegLow[j];
						if(to_string(ch) == comp)
						{
							if(alphaLower == 0)
							{
								alphaLower = 1;
								varCount++;
							}
						}
					}
					for(int j = 0; j < sizeof(alphaRegUp); j++)
					{
						string comp = alphaRegUp[j];
						if(to_string(ch) == comp)
						{
							if(alphaUpper == 0)
							{
								alphaUpper = 1;
								varCount++;
							}
						}
					}
					for(int j = 0; j < sizeof(numRegSeq); j++)
					{
						string comp = numRegSeq[j];
						if(to_string(ch) == comp)
						{
							if(numSeq == 0)
							{
								numSeq = 1;
								varCount++;
							}
						}
					}
					for(int j = 0; j < sizeof(altChar); j++)
					{
						string comp = altChar[j];
						if(to_string(ch) == comp)
						{
							if(altCh == 0)
							{
								altCh = 1;
								varCount++;
							}
						}

					}

					if(alphaLower == 1 && alphaUpper == 1 && numSeq == 1 && altCh == 1)
					{
						if(varCount == 4)
						{
							passcodeCheck = 1;
						}
					}
				}
			}
			beginEncryption(filename,fileformat,passcode);

		}else{
			if(!filename.empty())
			{
				cout << "NO FILENAME ";
			} else {
				cout << filename << " ";
			}
			if(!fileformat.empty())
			{
				cout << "NO FORMAT ";
			} else {
				cout << fileformat << " ";
			}
			if(!passcode.empty())
			{
				cout << "NO PASSCODE ";
			} else {
				cout << passcode << " ";
			}
		}
	}
        //else if (option == "decrypt")
	if(option == "decrypt")
	{
		if(!filename.empty() && !fileformat.empty() && !passcode.empty())
		{

			bool passcodeCheck = 0;

                        bool alphaLower = 0;
                        bool alphaUpper = 0;
                        bool numSeq = 0;
                        bool altCh = 0;

                        int varCount = 0;

			while(passcodeCheck == 0)
                        {
				                                                                                                                                     for(int i = 0; i < passcode.size(); i++)
                       	         for(int i = 0; i < passcode.size(); i++)
				 {
                                        char ch = passcode[i];
					for(int j = 0; j < sizeof(alphaRegLow); j++)                                                                                                             for(int j = 0; j < sizeof(alphaRegLow); j++)
                                        {
                                                string comp = alphaRegLow[j];                                                                                                                 if(to_string(ch) == comp)
                                		if(to_string(ch) == comp)
				                {                                                                                                                                                     if(alphaLower == 0)
                                                        {
								alphaLower = 1;                                                                                                                                                     alphaLower = 1;
                                                                varCount++;
                                                        }
                                                }
                                        }
                                        for(int j = 0; j < sizeof(alphaRegUp); j++)
                                        {
                                                string comp = alphaRegUp[j];
                                                if(to_string(ch) == comp)
                                                {
                                                        if(alphaUpper == 0)
                                                        {
                                                                alphaUpper = 1;
                                                                varCount++;
                                                        }
                                                }
                                        }
                                        for(int j = 0; j < sizeof(numRegSeq); j++)
                                        {
                                                string comp = numRegSeq[j];
                                                if(to_string(ch) == comp)
                                                {
                                                        if(numSeq == 0)
                                                        {
                                                                numSeq = 1;
                                                                varCount++;
                                                        }
                                                }
                                        }
					for(int j = 0; j < sizeof(altChar); j++)
                                        {
                                                string comp = altChar[j];
                                                if(to_string(ch) == comp)
                                                {
                                                        if(altCh == 0)
                                                        {
                                                                altCh = 1;
                                                                varCount++;
                                                        }
                                                }                                                                                                                                     }
					}

                                        if(alphaLower == 1 && alphaUpper == 1 && numSeq == 1 && altCh == 1)
                                        {
                                                if(varCount == 4)
                                                {
                                                        passcodeCheck = 1;
                                                }
                                        }
                                }
                        }
			beginDecryption(filename,fileformat,passcode);

		}else{
			if(!filename.empty())
                        {
                                cout << "NO FILENAME ";
                        } else {
				cout << filename << " ";                                                                                                                                              cout << filename << " ";
			}

                        if(!fileformat.empty())
                        {
                                 cout << "NO FORMAT ";
                        } else {
				cout << fileformat << " ";                                                                                                                                              cout << fileformat << " ";
                        }

                        if(!passcode.empty())
                        {
                                cout << "NO PASSCODE ";
                        } else {
                                cout << passcode << " ";
                        }
		}

	} else {
		cout << option << "   :  not a valid option" << endl;
	}


	//createTestFile();
	//readFile();
	//readFileCharacterByCharacter();
	return 0;

}
