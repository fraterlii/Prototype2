#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

string kwDummy[] = {"DRUGS", "GUNS", "KIDNAP", "CAR", "PAO"};

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
		alice_RNArray[0][3].manualConstructor("I don't know what you're talking about, and I'm not saying another word.", 0);
		alice_RNArray[0][4].manualConstructor("I might have had a bump before leaving the party, but nothing major...", 0);

		// GUNS
		alice_RNArray[1][0].manualConstructor("What guns?", 0);
		alice_RNArray[1][1].manualConstructor("I don't own any guns!", 0);
		alice_RNArray[1][2].manualConstructor("What exactly are you accusing me of?", 0);
		alice_RNArray[1][3].manualConstructor("I have a right to silence.  I'm done answering these questions.", 0);
		alice_RNArray[1][4].manualConstructor("It's my boyfriend's car!  I'm not responsible for anything you found in there!", 0);

		// KIDNAP
		alice_RNArray[2][0].manualConstructor("", 0);
		alice_RNArray[2][1].manualConstructor("", 0);
		alice_RNArray[2][2].manualConstructor("", 0);
		alice_RNArray[2][3].manualConstructor("", 0);
		alice_RNArray[2][4].manualConstructor("", 0);

		// CAR
		alice_RNArray[3][0].manualConstructor("", 0);
		alice_RNArray[3][1].manualConstructor("", 0);
		alice_RNArray[3][2].manualConstructor("", 0);
		alice_RNArray[3][3].manualConstructor("", 0);
		alice_RNArray[3][4].manualConstructor("", 0);

		// PAO
		alice_RNArray[4][0].manualConstructor("", 0);
		alice_RNArray[4][1].manualConstructor("", 0);
		alice_RNArray[4][2].manualConstructor("", 0);
		alice_RNArray[4][3].manualConstructor("", 0);
		alice_RNArray[4][4].manualConstructor("", 0);
	}
	
	void compareKeywords(string buf) {
		
		for (int i=0; i < 5; i++){
			if (buf == kwDummy[i]){
				cout << "There is a match: " << kwDummy[i] << endl;
				
			}
		}
	}

	string input2UPPER(){
		string s;
		getline (cin, s);
		cout << endl;

		for(int i; i< s.length(); i++){
			if( int(s.at(i)) <= int('z') && int(s.at(i)) >= int('a')){
				s.at(i) = char(int(s.at(i)) + int('A') - int('a'));
			}
			else {
				s.at(i) = ' ';
			}
		}
		return s;
}

	string getKeywords(){
		

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
	string mainresponse;
	// data declarations
	build_alice_RNArray();
	Chatbot Alice;
	string keywords;
	string buf;
	
	// member functions
	do {
		
		keywords = getKeywords();
		//cin.get();
		stringstream ss(keywords);
		vector<string> tokens;
		ofstream outputFile;
		outputFile.open("datafile.txt");

		int selection = rand() % 5;
		mainresponse = alice_RNArray[0][selection].responseOutput();
		cout <<mainresponse <<endl;

		while(ss>>buf){
			tokens.push_back(buf);
			outputFile<<buf+"\n";
			cout<<buf+"\n";
			compareKeywords(buf);
		} outputFile.close();
	}while (running());
	
}
