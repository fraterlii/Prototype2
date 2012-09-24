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

		cout << cbOutput << endl;
	}
};

namespace mainMethods {
using namespace std;


void compareKeywords() {
	// description goes here
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
	Chatbot Alice;
	string keywords;
	string buf;

	// read keyword file and push responses to memory
	do {
		
		keywords = getKeywords();
		//cout << keywords;
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
