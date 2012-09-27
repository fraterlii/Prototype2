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
		alice_RNArray[0][4].manualConstructor("I might have had a bump before leaving the party, but nothing major...", 0);

		// GUNS
		alice_RNArray[1][0].manualConstructor("What guns?", 0);
		alice_RNArray[1][1].manualConstructor("I don't own any guns.", 0);
		alice_RNArray[1][2].manualConstructor("What exactly are you accusing me of?", 0);
		alice_RNArray[1][3].manualConstructor("I have a right to silence.  I'm done answering these questions.", 0);
		alice_RNArray[1][4].manualConstructor("It's my boyfriend's car!\nI'm not responsible for anything you found in there!", 0);

		// KIDNAP
		alice_RNArray[2][0].manualConstructor("kidnap1", 0);
		alice_RNArray[2][1].manualConstructor("kidnap2", 0);
		alice_RNArray[2][2].manualConstructor("kidnap3", 0);
		alice_RNArray[2][3].manualConstructor("kidnap4", 0);
		alice_RNArray[2][4].manualConstructor("kidnap5", 0);

		// CAR
		alice_RNArray[3][0].manualConstructor("car1", 0);
		alice_RNArray[3][1].manualConstructor("car2", 0);
		alice_RNArray[3][2].manualConstructor("car3", 0);
		alice_RNArray[3][3].manualConstructor("car4", 0);
		alice_RNArray[3][4].manualConstructor("car5", 0);

		// PAO
		alice_RNArray[4][0].manualConstructor("Twenty percent of your semester grade.", 0);
		alice_RNArray[4][1].manualConstructor("I cannot.", 0);
		alice_RNArray[4][2].manualConstructor("I try to help you.", 0);
		alice_RNArray[4][3].manualConstructor("You tell me, is it fair?", 0);
		alice_RNArray[4][4].manualConstructor("Wooow!", 0);
	}
	
	int compareKeywords(string buf) {
		// checks the string parameter (user input) against the string values in kwDummy[]
		// if a match is found, the index of the match is returned
		// otherwise, a value of -1 is returned

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
	
	// member functions
	do {
		
		keywords = getKeywords();
		//cin.get();
		stringstream ss(keywords);
		vector<string> tokens;
		ofstream outputFile;
		outputFile.open("datafile.txt");


		while(ss>>buf){
			tokens.push_back(buf);
			outputFile<<buf+"\n";
			//cout<<buf+"\n";
			kw = compareKeywords(buf);
			if (kw >= 0){
				int selection = rand() % 5;
				mainresponse = alice_RNArray[kw][selection].responseOutput();
				cout << "Alice: " << mainresponse << endl << "\n";
			}
		} outputFile.close();
	}while (running(buf));
	
}
