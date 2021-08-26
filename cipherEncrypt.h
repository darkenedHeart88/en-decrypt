#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


using namespace std;



void ceaserCipher(string filename, string outputfile, string fileformat, string passcode)
{
	int passcodeLength = passcode.size();
	if(fileformat == "textfile")
	{

		string ch;

		ofstream outputFile(outputfile);
		if(!outputfile.is_open())
		{
			cout << "ERROR: " << outputfile << " , cannot be opened." << endl;
		}

		//outputFile.close();

		ifstream inputFile(inputfile);

		if(!inputfile.is_open())
		{
			cout << "ERROR: " << inputfile << " , cannot be opened." << endl;
		}

		while(inputFile >> noskipws >> ch)
		{
			inputFile >> ch;
			bool cipherImplement = 0;
			while(cipherImplement == 0)
			{
				if(ch == "")
				{
					cipherImplement = 1;
				}

				for(int i = 0; i < sizeof(alphaRegLow); i++)
				{
					string value = alphaRegLow[i];
					if(to_string(ch) == value)
					{
						int initialPos = i;
						int newPos = i + passcodeLength;
						if(newPos > sizeof(alphaRegLow))
						{
							int finalPos = newPos - sizeof(alphaRegLow));
							ch = alphaRegLow[finalPos];
							cipherImplement = 1;
						} else {
							ch = alphaRegLow[newPos];
							cipherImplement = 1;
						}
					}
				}

				for(int i = 0; i < sizeof(alphaRegUp); i++)
				{
					string value = alphaRegUp[i];
					if(to_string(ch) == value)
					{
						int initialPos = i;
						int newPos = i + passcodeLength;
						if(newPos > sizeof(alphaRegUp))
                                                {
                                                        int finalPos = newPos - sizeof(alphaRegUp);
                                                        ch = alphaRegUp[finalPos];
                                                        cipherImplement = 1;
                                                } else {
                                                        ch = alphaRegUp[newPos];
                                                        cipherImplement = 1;
                                                }
					}
				}

				for(int i = 0; i < sizeof(numRegSeq); i++)
                                {
                                        string value = numRegSeq[i];
                                        if(to_string(ch) == value)
                                        {
                                                int initialPos = i;
                                                int newPos = i + passcodeLength;
                                                if(newPos > sizeof(numRegSeq))
                                                {
                                                        int finalPos = newPos - sizeof(numRegSeq);
                                                        ch = alphaRegUp[finalPos];
                                                        cipherImplement = 1;
                                                } else {
                                                        ch = alphaRegUp[newPos];
                                                        cipherImplement = 1;
                                                }
                                        }
                                }

				for(int i = 0; i < sizeof(altCh); i++)
                                {
                                        string value = altCh[i];
                                        if(to_string(ch) == value)
                                        {
                                                int initialPos = i;
                                                int newPos = i + passcodeLength;
                                                if(newPos > sizeof(altCh))
                                                {
                                                        int finalPos = newPos - sizeof(altCh);
                                                        ch = alphaRegUp[finalPos];
                                                        cipherImplement = 1;
                                                } else {
                                                        ch = alphaRegUp[newPos];
                                                        cipherImplement = 1;
                                                }
                                        }
                                }

			}

			outputFile << ch;

		}

		inputFile.close();
		outputFile.close();

	}

}


void monoAlphaCipher(string filename, string fileformat, string passcode)
{
	int passcodeLength = passcode.size();
        if(fileformat == "textfile")
        {

                string ch;

                ofstream outputFile(outputfile);
                if(!outputfile.is_open())
                {
                        cout << "ERROR: " << outputfile << " , cannot be opened." << endl;
                }

                //outputFile.close();

                ifstream inputFile(inputfile);

                if(!inputfile.is_open())
                {
                        cout << "ERROR: " << inputfile << " , cannot be opened." << endl;
                }

                while(inputFile >> noskipws >> ch)
                {
                        inputFile >> ch;
                        bool cipherImplement = 0;
                        while(cipherImplement == 0)
                        {
                                if(ch == "")
                                {
                                        cipherImplement = 1;
                                }

                                for(int i = 0; i < sizeof(modAlphaLow_1); i++)
                                {
                                        string value = alphaRegLow[i];
                                        if(to_string(ch) == value)
                                        {
                                                int initialPos = i;
                                                int newPos = i + passcodeLength;
                                                if(newPos > sizeof(alphaRegLow))
                                                {
                                                        int finalPos = newPos - sizeof(alphaRegLow));
                                                        ch = alphaRegLow[finalPos];
                                			cipherImplement = 1;
						} else {
							ch = alphaRegLow[i];
							cipherImplement = 1;
						}
					}
				}

				for(int i = 0; i < sizeof(alphaRegUp); i++)
                                {
                                        string value = alphaRegUp[i];
                                        if(to_string(ch) == value)
                                        {
                                                int initialPos = i;
                                                int newPos = i + passcodeLength;
                                                if(newPos > sizeof(alphaRegUp))
                                                {
                                                        int finalPos = newPos - sizeof(alphaRegUp);
                                                        ch = alphaRegUp[finalPos];
                                                        cipherImplement = 1;
                                                } else {
                                                        ch = alphaRegUp[newPos];
                                                        cipherImplement = 1;
                                                }
                                        }
                                }

                                for(int i = 0; i < sizeof(numRegSeq); i++)
                                {
                                        string value = numRegSeq[i];
                                        if(to_string(ch) == value)
                                        {
                                                int initialPos = i;
                                                int newPos = i + passcodeLength;
                                                if(newPos > sizeof(numRegSeq))
                                                {
                                                        int finalPos = newPos - sizeof(numRegSeq);
                                                        ch = alphaRegUp[finalPos];
                                                        cipherImplement = 1;
                                                } else {
                                                        ch = alphaRegUp[newPos];
                                                        cipherImplement = 1;
                                                }
                                        }
                                }

                                for(int i = 0; i < sizeof(altCh); i++)
                                {
                                        string value = altCh[i];
                                        if(to_string(ch) == value)
                                        {
                                                int initialPos = i;
                                                int newPos = i + passcodeLength;
                                                if(newPos > sizeof(altCh))
                                                {
                                                        int finalPos = newPos - sizeof(altCh);
                                                        ch = alphaRegUp[finalPos];
                                                        cipherImplement = 1;
                                                } else {
                                                        ch = alphaRegUp[newPos];
                                                        cipherImplement = 1;
                                                }
                                        }
                                }

                        }

			outputFile << ch;
		}

		outputFile.close();
		inputFile.close();

	}
}


void  homophonicSubCipher(string filename, string fileformat, string passcode)
{


}


void polygramSubCipher(string filename, string fileformat, string passcode)
{


}


void polyAlphaCipher(string filename, string fileformat, string passcode)
{


}


void playFairCipher(string filename, string fileformat, string passcode)
{


}


void  hillCipher(string filename, string fileformat, string passcode)
{

}
