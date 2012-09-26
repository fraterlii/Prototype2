#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
public class ResponseNode
{
public:
	// data declarations
	string response;
	int outputCount;

	// member functions
	string responseOutput(){
		// returns response string for output and increments outputCount by 1

		outputCount = outputCount +1;
		return response;
	}

	void manualConstructor(string constructorString, int constructorInt){
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

	// data declarations
	ResponseNode alice_RNArray[5][5];

	// member functions
	void build_alice_RNArray() {
		// Initializes each value within the alice_RNArray[5][5] variable

		// DRUGS
		alice_RNArray[0][0].manualConstructor("What drugs?", 0);
		alice_RNArray[0][1].manualConstructor("I don't do drugs!", 0);
		alice_RNArray[0][2].manualConstructor("What exactly are you accusing me of?", 0);
		alice_RNArray[0][3].manualConstructor("I don't know what you're talking about.", 0);
		alice_RNArray[0][4].manualConstructor("I'm not saying another word.", 0);

		// GUNS

		// KIDNAP

		// CAR

		// PAO
	}
	
	void compareKeywords() {
		// description goes here

		String word = getString();

}

	string input2UPPER(){
		string s;
		getline (cin, s);
		cout << endl;

		for(int i; i< s.length(); i++){
			if( int(s.at(i)) <= int('z') && int(s.at(i)) >= int('a')){
				s.at(i) = char(int(s.at(i)) + int('A') - int('a'));
			}
		}
		return s;
}

	string getKeywords(){
		string kwDummy[] = {"DRUGS", "GUNS", "KIDNAP", "CAR", "PAO"};

		cout << "Available keywords: ";
		for(int i=0; i < 5; i++){
			cout << kwDummy[i];
			if(i<5-1) cout << ", ";
		}
		cout << endl;

		cout << "You: ";
		return input2UPPER();
}

	bool running(){
		cout << "Do you want to continue? (yes or no): ";
		return (input2UPPER() != "NO");
	}

	void getResponseNode(){
		// description goes here
	}

}


using namespace std;
using namespace mainMethods;
void main()
{
	// data declarations
	build_alice_RNArray();
	Chatbot Alice;
	string keywords;
	string buf;
	
	// member functions
	do {
		
		keywords = getKeywords();
		cin.get();
		stringstream ss(keywords);
		vector<string> tokens;
		ofstream outputFile;
		outputFile.open("datafile.txt");
		while(ss>>buf){
			tokens.push_back(buf);
			outputFile<<buf+"\n";
			cout<<buf+"\n";
		} outputFile.close();
	}while (running());
	
}
