#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>


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

	void configureResponses() {
		// description goes here
	}

	void FileReading() {
		// description goes here

		string resp;
		ifstream myFile;
		myFile.open("datafile.txt");

		while(!myFile.eof()) {
			getline(myFile,resp);
			cout<<resp<<endl;
		}

		myFile.close();
	}
};

namespace chatter {
using namespace std;

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

}


using namespace std;
using namespace chatter;
void main()
{
	// data declarations
	Chatbot Alice;
	string keywords;
	int i = 0;

	// read keyword file and push responses to memory
	Alice.FileReading();

	do {
		cout << "Enter Dialogue: ";
		keywords = getKeywords();
		cout << keywords;
		i++;
	}while (i < 5);

}
