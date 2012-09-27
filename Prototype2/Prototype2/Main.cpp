#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// globally defined data declarations
string kwDummy[] = {"DRUGS", "GUNS", "KIDNAP", "CAR", "PAO"};
string negativeResponses[] = {"Wanna run that by me again?", "SPEAK CLEARLY!", "Is this some kind of mind game?", "What?", "I don't understand what you're getting at..."};

public class ResponseNode
{
public:
	// local data declarations
	string response;
	int outputCount;

	// local member functions
	string responseOutput(){
		// returns response string for output and increments outputCount by 1

		outputCount = outputCount +1;
		return response;
	}

	void manualConstructor(string constructorString, int constructorInt){
		// use this to initialize the ResponseNode objects

		response = constructorString;
		outputCount = constructorInt;
	}

	// class constructor
	ResponseNode() {};
};

using namespace std;
public class Chatbot
{
public:
	// data declarations
	string cbOutput;

	// member functions
	void showChatbotOutput() {
		// prints the string value of cbOutput

		cout << cbOutput << endl;
	}
};

namespace mainMethods {
using namespace std;

	// namespace data declarations
	ResponseNode alice_RNArray[5][5];

	// namespace member functions
	void build_alice_RNArray() {
		// Initializes each value within the alice_RNArray[5][5] variable

		// DRUGS
		alice_RNArray[0][0].manualConstructor("What drugs?", 0);
		alice_RNArray[0][1].manualConstructor("I don't do drugs.", 0);
		alice_RNArray[0][2].manualConstructor("What exactly are you accusing me of?", 0);
		alice_RNArray[0][3].manualConstructor("I don't know what you're talking about, and I'm not saying another word.", 0);
		alice_RNArray[0][4].manualConstructor("I might have had a hit before driving, but it's nothing major...", 0);

		// GUNS
		alice_RNArray[1][0].manualConstructor("What guns?", 0);
		alice_RNArray[1][1].manualConstructor("I don't own any guns.", 0);
		alice_RNArray[1][2].manualConstructor("What exactly are you accusing me of?", 0);
		alice_RNArray[1][3].manualConstructor("I have a right to silence...\n       I'm not answering any more questions.", 0);
		alice_RNArray[1][4].manualConstructor("It's my boyfriend's car!\n       I'm not responsible for anything you found in there!", 0);

		// KIDNAP
		alice_RNArray[2][0].manualConstructor("WHAT?!...\n       A KIDNAPPING?!\n       Clay said that kid was his nephew!", 0);
		alice_RNArray[2][1].manualConstructor("How could you even...\n       I would NEVER do something like that!", 0);
		alice_RNArray[2][2].manualConstructor("Who do you think I am?\n       What do you think you're accusing me of officer?", 0);
		alice_RNArray[2][3].manualConstructor("I don't have to listen to this anymore!\n       I'm done talking to you.", 0);
		alice_RNArray[2][4].manualConstructor("Honestly, officer, I would never do that.\n       I swear to you, I don't know anything about a kidnapping.", 0);

		// CAR
		alice_RNArray[3][0].manualConstructor("car1", 0);
		alice_RNArray[3][1].manualConstructor("car2", 0);
		alice_RNArray[3][2].manualConstructor("car3", 0);
		alice_RNArray[3][3].manualConstructor("car4", 0);
		alice_RNArray[3][4].manualConstructor("car5", 0);

		// PAO
		alice_RNArray[4][0].manualConstructor("20% your semester grade.", 0);
		alice_RNArray[4][1].manualConstructor("20% your semester grade.", 0);
		alice_RNArray[4][2].manualConstructor("20% your semester grade.", 0);
		alice_RNArray[4][3].manualConstructor("20% your semester grade.", 0);
		alice_RNArray[4][4].manualConstructor("20% your semester grade.", 0);
	}
	
	int compareKeywords(string buf) {
		// checks the string parameter (user input) against the string values in kwDummy[]
		// if a match is found, the index of the match is returned
		// otherwise, a value of -1 is returned

		if (buf == "HINT" | buf == "QUIT") {
			return -5;
		}

		for (int i=0; i < 5; i++){
			if (buf == kwDummy[i]){
				return i;
			}
		}
		return -1;
	}

	string input2UPPER(){
		string s;
		getline (cin, s);
		cout << endl;

		for(int i; i< s.length(); i++){
			if( int(s.at(i)) <= int('z') && int(s.at(i)) >= int('a')){
				s.at(i) = char(int(s.at(i)) + int('A') - int('a'));
			}
			else if (!(int(s.at(i)) <= int('Z') && int(s.at(i)) >= int('A'))){
				s.at(i) = ' ';
			}
		}
		return s;
	}

	string getKeywords(){
		// returns the punctuation-trimmed, capitalized Keyword values

		cout << "Echevvery: ";
		return input2UPPER();
	}

	void showCasePoints() {
		cout << "Case Points: ";
		for(int i=0; i < 4; i++){
			cout << kwDummy[i];
			if(i<4-1) cout << ", ";
		}
		cout << endl;
	}

	bool running(string buf){
		if (buf == "QUIT") {
		cout << "\n\n\nDo you want to continue? (y or n): ";
		return (input2UPPER() != "N");
		}
		else if (buf == "HINT") {
			showCasePoints();
			return true;
		}
		else {
			return true;
		}
	}

	void getResponseNode(){
		// description goes here
	}

	void show_AliceExposition() {
		cout << "Suspect Name, Age, Sex, D.O.B.:  " << "\n\n  Alice Kremieux\n  23, Female\n  Feb. 3rd, 1989" << endl;
		

		cout << "\nMove on to questioning...";
		cin.get();
		cout << "\n\n";
	}

}


using namespace std;
using namespace mainMethods;
void main()
{
	string mainresponse;
	// data declarations
	build_alice_RNArray();
	Chatbot Alice;
	string keywords;
	string buf;
	int kw;

	show_AliceExposition();
	

	do {
		
		keywords = getKeywords();
		stringstream ss(keywords);
		vector<string> tokens;
		ofstream outputFile;
		outputFile.open("datafile.txt");


		while(ss>>buf){
			tokens.push_back(buf);
			outputFile<<buf+"\n";
			kw = compareKeywords(buf);
			if (kw >= 0){
				mainresponse = alice_RNArray[kw][rand() % 5].responseOutput();
				cout << "Alice: " << mainresponse << endl << "\n";
			}
			else if (kw == -1) {
				cout << "Alice: " << negativeResponses[rand() % 5] << endl << "\n";
				break;
			}
		} outputFile.close();
	}while (running(buf));
	
}
