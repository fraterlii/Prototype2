#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// globally defined data declarations
string alice_kw_Array[] = {"DRUGS", "GUNS", "KIDNAP", "PARKING", "PAO", "ROBBERY"};
int alice_kw_ArrayLength = sizeof(alice_kw_Array) / sizeof(string);

string noMatchResponsesArray[] = {"Wanna run that by me again?", "Please be more direct.\n       Get to the point already...", "Is this some kind of mind game?", "What?", "I don't see what you're getting at..."};
int noMatchResponsesArrayLength = sizeof(noMatchResponsesArray) / sizeof(string);


public class ResponseNode
{
public:
	// ResponseNode local data declarations
	string response;
	int outputCount;

	// ResponseNode local member functions
	string responseOutput(){
		// returns response and increments outputCount by 1

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


namespace mainAssets {
using namespace std;

	// namespace data declarations									//how we guide the conversation is something to think about, and how he gets caught. 
	ResponseNode alice_RNArray[18][5];

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
		alice_RNArray[3][0].manualConstructor("Is it a crime to be in a public parking lot?", 0);
		alice_RNArray[3][1].manualConstructor("I was just sitting in the car with Clay...", 0);
		alice_RNArray[3][2].manualConstructor("Where is this going?\n       There's nothing illegal about being in a public place.", 0);
		alice_RNArray[3][3].manualConstructor("You know what?  I think I'd like to remain silent...", 0);
		alice_RNArray[3][4].manualConstructor("Clay was overdosing.\n       I thought he was going to die, officer.\n       What was I supposed to do?", 0);

		// PAO
		alice_RNArray[4][0].manualConstructor("20% your semester grade.", 0);
		alice_RNArray[4][1].manualConstructor("20% your semester grade.", 0);
		alice_RNArray[4][2].manualConstructor("20% your semester grade.", 0);
		alice_RNArray[4][3].manualConstructor("20% your semester grade.", 0);
		alice_RNArray[4][4].manualConstructor("20% your semester grade.", 0);

		// Robbery
		alice_RNArray[5][0].manualConstructor("I was not involved in that Bank robbery on 1st National Bank.", 0);
		alice_RNArray[5][1].manualConstructor("I am a working class citizen of this country, i don't rob people.", 0);
		alice_RNArray[5][2].manualConstructor("What?, me a robber, no way.", 0);
		alice_RNArray[5][3].manualConstructor("I have nothing to do with no robbery.", 0);
		alice_RNArray[5][4].manualConstructor("Why are you asking me? I didn't do anything.", 0);

		//Arson
		alice_RNArray[6][0].manualConstructor("I was not involved in that Bank robbery on 1st National Bank.", 0);
		alice_RNArray[6][1].manualConstructor("I am a working class citizen of this country, i don't rob people.", 0);
		alice_RNArray[6][2].manualConstructor("What?, me a robber, no way.", 0);
		alice_RNArray[6][3].manualConstructor("I have nothing to do with no robbery.", 0);
		alice_RNArray[6][4].manualConstructor("Why are you asking me? I didn't do anything.", 0);

		//DWI -Drunkenness
		alice_RNArray[7][0].manualConstructor("I was not driving over the speed limit.", 0);
		alice_RNArray[7][1].manualConstructor("I didn't have a single shot today.", 0);
		alice_RNArray[7][2].manualConstructor("Drunk? What are you talking about officer, I don't drink.", 0);
		alice_RNArray[7][3].manualConstructor("I had a few, but I'm sober.", 0);
		alice_RNArray[7][4].manualConstructor("I was just hanging out with friends, only had like a glass of wine.", 0);

		//Forgery or Couterfeiting
		alice_RNArray[8][0].manualConstructor("I was not involved in that forgery.", 0);
		alice_RNArray[8][1].manualConstructor("I am loyal to my country, I would never make counterfiet money.", 0);
		alice_RNArray[8][2].manualConstructor("What?, me counterfeiting, no way.", 0);
		alice_RNArray[8][3].manualConstructor("I have nothing to do with counterfeit money flowing in the market.", 0);
		alice_RNArray[8][4].manualConstructor("Why are you asking me? I didn't do anything.", 0);

		//Gambling
		alice_RNArray[9][0].manualConstructor("I am not promoting gambling, why would you say that?", 0);
		alice_RNArray[9][1].manualConstructor("I did not acquire my wealth from illegal gambling.", 0);
		alice_RNArray[9][2].manualConstructor("I don gamble, but only legally.", 0);
		alice_RNArray[9][3].manualConstructor("No officer, I don't engage or promote illegal gambling.", 0);
		alice_RNArray[9][4].manualConstructor("I don't own illegal gambling houses, thats absurd. I am an honest legal gambler.", 0);

		//Murder or Manslaughter
		alice_RNArray[10][0].manualConstructor("I was not involved in that murder you are talking about.", 0);
		alice_RNArray[10][1].manualConstructor("No, I wasn't even at the location at that time.", 0);
		alice_RNArray[10][2].manualConstructor("What?, me killing someone, no way, I can't even kill a fly.", 0);
		alice_RNArray[10][3].manualConstructor("No, I had nothing to do with a murder.", 0);
		alice_RNArray[10][4].manualConstructor("Why would you think, I killed a man?", 0);

		//Weapons Law Violation
		alice_RNArray[11][0].manualConstructor("I don't own any illegal weapons.", 0);
		alice_RNArray[11][1].manualConstructor("Officer, I have licenses for all of my weapons.", 0);
		alice_RNArray[11][2].manualConstructor("What? thats not right, I am an honest guy.", 0);
		alice_RNArray[11][3].manualConstructor("I don't manufacture weapons, nor do I sell them.", 0);
		alice_RNArray[11][4].manualConstructor("Why are you asking me? I don't carry deadly weapons.", 0);

		//Disorderly Conduct-Vandalism
		alice_RNArray[12][0].manualConstructor("No, I didn't kill his cow.", 0);
		alice_RNArray[12][1].manualConstructor("I did not start a riot.", 0);
		alice_RNArray[12][2].manualConstructor("I had not burn his store.", 0);
		alice_RNArray[12][3].manualConstructor("No, my conduct is good.", 0);
		alice_RNArray[12][4].manualConstructor("Why are you asking me? I didn't do anything.", 0)

		//Hate Crime
		alice_RNArray[13][0].manualConstructor("I love people, I wouldn't do such a thing", 0);
		alice_RNArray[13][1].manualConstructor("I had no involvement with such an organization.", 0);
		alice_RNArray[13][2].manualConstructor("What?no way, I don't get involved with such people.", 0);
		alice_RNArray[13][3].manualConstructor("I am a liberal, I believe in piece.", 0);
		alice_RNArray[13][4].manualConstructor("Plaese, officer I am good with everyone.", 0);

		//Larceny-theft
		alice_RNArray[14][0].manualConstructor("I didn't pick his pocket, no way", 0);
		alice_RNArray[14][1].manualConstructor("I am not a thief sir, I am a good man.", 0);
		alice_RNArray[14][2].manualConstructor("What?, me a thief, no way.", 0);
		alice_RNArray[14][3].manualConstructor("I did not steal his stereo", 0);
		alice_RNArray[14][4].manualConstructor("I am not a car thief, I have never stolen a car.", 0);

		//Family Violence
		alice_RNArray[15][0].manualConstructor("I love my family, I wouldn't.", 0);
		alice_RNArray[15][1].manualConstructor("I did not beat my son.", 0);
		alice_RNArray[15][2].manualConstructor("What?, my wife takes care of me, I wouldn't do such a thing.", 0);
		alice_RNArray[15][3].manualConstructor("We are a happy family.", 0);
		alice_RNArray[15][4].manualConstructor("Why are you asking me? I didn't do anything.", 0);

		//Sex Offenses
		alice_RNArray[16][0].manualConstructor("No I am not a sex offender.", 0);
		alice_RNArray[16][1].manualConstructor("I was once in prison but not for this reason.", 0);
		alice_RNArray[16][2].manualConstructor("What?, I havegood morals.", 0);
		alice_RNArray[16][3].manualConstructor("Not that again.", 0);
		alice_RNArray[16][4].manualConstructor("NO.", 0);

		//Terrorism
		alice_RNArray[17][0].manualConstructor("I am not a terrorist, I love this country.", 0);
		alice_RNArray[17][1].manualConstructor("Just because I look like this, doesn't mean I am a terrorist.", 0);
		alice_RNArray[17][2].manualConstructor("What? A terrorist, no way i am a peaceful person.", 0);
		alice_RNArray[17][3].manualConstructor("I wasn't involved, nor did I know anything about this incident.", 0);
		alice_RNArray[17][4].manualConstructor("I was only carrying it, didn't know what was there.", 0);

		//The thief is Caught
		alice_RNArray[18][0].manualConstructor("Oh no, I didn't mean that", 0);
		alice_RNArray[18][1].manualConstructor("That was a slip of tongue, I didn't mean it.", 0);
		alice_RNArray[18][2].manualConstructor("Oh no, what am I saying, I am so dumb.", 0);
		alice_RNArray[18][3].manualConstructor("No really, I was only kidding, shit", 0);
		alice_RNArray[18][4].manualConstructor("Oh, you caught me, nnooo", 0);
	}
	
	int compareKeywords(string buf) {
		// checks the string parameter (user input) against the string values in alice_kw_Array[]
		// if a match is found, the index of the match is returned
		// otherwise, a value of -1 is returned

		if (buf == "HINT" | buf == "QUIT") {
			return -5;
		}

		for (int i=0; i < 5; i++){
			if (buf == alice_kw_Array[i]){
				return i;
			}
		}
		return -1;
	}

	string input2UPPER(){
		// gets user input and standardizes it in preparation for subsequent keyword comparison

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
		// outputs the available Keywords stored in alice_kw_Array[] 

		cout << "Case Points: ";
		for(int i=0; i < 4; i++){
			cout << alice_kw_Array[i];
			if(i<4-1) cout << ", ";
		}
		cout << endl;
	}

	bool running(string buf){
		// returns the boolean value that controls the lifespan of our game loop

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

	void show_AliceExposition() {
		// displays introductory, expository information that will be used to question the chatbot
		// hints at case points without explicitly naming them

		cout << "Suspect Name, Age, Sex, D.O.B.:  " << "\n\n  Alice Kremieux\n  23, Female\n  Feb. 3rd, 1989\n" << endl;
		cout << "Suspect was found unconscious in driver's seat of vehicle." << endl;
		cout << "Police had been notified of strange activity in parking lot of Taco Bell." << endl;
		cout << "Her boyfriend, Clay Alders, was hyperventilating from apparent drug overdose." << endl;
		cout << "Bath salts were found scattered throughout the vehicle." << endl;
		cout << "Two revolver-style pistols were identified in the trunk." << endl;
		cout << "A young boy, approximately five years of age, was found crying in the backseat." << endl;
		cout << "Neither Alice nor Clay are legal guardians of the boy." << endl;
		cout << "Possible kidnapping." << endl;
		

		cout << "\nMove on to questioning...";
		cin.get();
		cout << "\n\n";
	}

	/* testing this algorithm 
	inline void splitString(char c[])
{
	char tempchar1[NUM] = " ";
	char tempchar2[NUM] = " ";
	char tempchar3[NUM] = " ";

	for(int i = 0; i < NUM;i++)
	{
		tempchar1[i] = c[i];

		if(c[i + 1] == ' ')
		{
			for(int r = i + 2;r < NUM;r++)
			{
				tempchar2[r - (i + 2)] = c[r];

				if(c[r + 1] == ' ')
				{
					for(int q = r + 2; q < NUM;q++)
					{
						tempchar3[q - (r + 2)] = c[q];
					}
					r = NUM;
				}
			}
			i = NUM;
		}
		*/
	}
	
}


using namespace std;
using namespace mainAssets;
void main()
{
	// main() data declarations
	string buf;
	string keywords;
	string mainresponse;
	build_alice_RNArray();
	int kwIndex;

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
			kwIndex = compareKeywords(buf);
			if (kwIndex >= 0){
				mainresponse = alice_RNArray[kwIndex][rand() % 5].responseOutput();
				cout << "Alice: " << mainresponse << endl << "\n";
			}
			else 
				if(kwIndex < 0)
				{
					cout<<"Alice: "<< "Pardon Me" <<endl <<"\n";
				}
			
		} outputFile.close();
	}while (running(buf));
	
}
