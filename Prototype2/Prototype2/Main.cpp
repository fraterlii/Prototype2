#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;
public class ResponseNode
{
public:
string response;
int outputCount;
//this is me
// class constructor
ResponseNode(string init) {
response = init;
int outputCount = 0;
}

ResponseNode() {
int outputCount = 0;
}
};



using namespace std;
public class Chatbot
{
private:

public:
// chatbot-related data declarations
string cbOutput;
ResponseNode x[5];

// user-related data declarations
string uInput;
string uKeywordsArray[];

// class constructor
Chatbot() {
//configureResponses();
	
	showChatbotOutput();
}

// member functions
void showChatbotOutput() {
cout <<cbOutput << endl;
}

void configureResponses() {

}

void FileReading()
{
	string resp;
	ifstream myFile;
	myFile.open("datafile.txt");

		while(!myFile.eof())
		{
			getline(myFile,resp);
			cout<<resp<<endl;
		}

	myFile.close();
}
};

namespace chatter {
#include <string>
using namespace std;

string outputCB;
string greetingsArrayCB[4] = {"WHERE WERE THE OTHER DRUGS GOING?!", "SWEAR TO ME!", "DO I LOOK LIKE A COP?!", "WHERE ARE THEY?!"};

// Displays the std::string value of ChatBot variable 'outputCB'
void showOutputCB(){
cout<< outputCB << endl;
	}
}

string getInput(){
    string s;
    getline (cin, s);

    for(int i; i< s.length(); i++){
        if( int(s.at(i)) <= int('z') && int(s.at(i)) >= int('a')){
            s.at(i) = char(int(s.at(i)) + int('A') - int('a'));
        }
    }

    return s;
}


using namespace std;
void main()
{

	string input;
	Chatbot Alice;
	Alice.FileReading();
	int i = 0;

	do {
		cout << "Enter Dialogue: ";
		input = getInput();
		i++;

	}while (i < 5);

	//system ("pause");

}
