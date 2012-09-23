#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>


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

	// class constructor
	ResponseNode(string constructorString, int constructorInt){
		response = constructorString;
		outputCount = constructorInt;
	}
};

using namespace std;
public class Chatbot
{
public:
	// chatbot-related data declarations
	string cbOutput;

	// member functions
	void showChatbotOutput() {
		// prints the string value of cbOutput

		cout <<cbOutput << endl;
	}
};

namespace mainMethods {
using namespace std;




void buildAliceArray(){
	// builds a 2D array of Keywords and ResponseNodes appropriate to the Alice Chatbot
}

void compareKeywords() {
	// description goes here
}

string getKeywords(){
    string s;
    getline (cin, s);

    for(int i; i< s.length(); i++){
        if( int(s.at(i)) <= int('z') && int(s.at(i)) >= int('a')){
            s.at(i) = char(int(s.at(i)) + int('A') - int('a'));
        }
    }
    return s;
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
	Chatbot Alice;
	string keywords;
	int i = 0;

	// read keyword file and push responses to memory
	do {
		cout << "Enter Dialogue: ";
		keywords = getKeywords();
		cout << keywords;
		i++;
	}while (i < 5);

}
