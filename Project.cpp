

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <string>
#include <fstream>
#include <ctime>
#include <chrono>


using namespace std;


//This function Validates user ID
bool Validate_ID(string ID)
{
	int i = 0;
	while (i < 3)
	{
		if (isalpha(ID[0]) && ID.find("A") != string::npos && isdigit(ID[1]) && isdigit(ID[2]) && isdigit(ID[3]) && isdigit(ID[4]) && ID.size() == 5)
		{
			cout << "Your User ID was accepted, you may enter the quiz" << endl;
			i = 4;
			return true;
		}
		else
		{
			cout << "Your User ID is not valid, please try again" << endl;
			cin >> ID;
			i++;
		}
	}

	if (i == 3)
	{
		return false;
	}

}

//This Function Checks for Duplicate Questions
int Check_Q(int g, int f)
{
	if (g == f)
	{
		return f = rand() % 100 + 1;
	}

	else
	{
		return f;
	}
}


int main()
{


	string name;
	string answer;
	char answerstart;
	string userID;
	
	int count = 0;
	int score = 0;
	int k = 0;
	int h = 0;

	string qanswer;
	string QA[10] = {};
	string Q[100] = {};
	string A[100] = {};


	string line1;
	int i = 0;
	ifstream QFile("Q_array.txt");

	string line2;
	int j = 0;
	ifstream AFile("A_Array.txt");

	srand(time(0));
	chrono::time_point<chrono::system_clock> start, end;







	cout << "Welcome to the quiz: would you like to continue? Enter 'yes' or 'no': ";
	cin >> answer;
	
	



	//Step 3: Open, validate, and close files for questions and answers, put into arrays

	if (QFile.is_open())
	{
		cout << "Question File loaded" << endl;

		while (!QFile.eof())
		{
			getline(QFile, line1);
			Q[i] = line1;
			i++;
		}

	}
	else
	{
		cout << "Question File failed to load" << endl;
		answer = "no";
	}


	if (AFile.is_open())
	{
		cout << "Answer File loaded" << endl;

		while (!AFile.eof())
		{
			getline(AFile, line2);
			A[j] = line2;
			j++;
		}

	}
	else
	{
		cout << "Answer File failed to load" << endl;
		answer = "no";
	}







	while (answer == "Y" || answer == "Yes" || answer == "yes" || answer == "y" || answer == "YES")
	{

		//step 1: Start program and Obtain user input for:
			//a. First/Last name
			//b. userID

		cout << "Please enter your first and last name : ";
		cin.ignore();
		getline(cin, name);
		cout << "Welcome, " << name << ": ";




		//Step 2: Validate user input:
			//a. Check String for name
			//b. Check for character and integers in userID

		cout << "Please enter your userID: ";
		cin >> userID;
		if (Validate_ID(userID) == false)
		{
			answer = "no";
			break;
		}

		else
		{

			

			cout << "Ensure you type in either TRUE or FALSE for your answer: Hit any key to start the Quiz";
			cin.ignore();
			cin.get(answerstart);
			start = chrono::system_clock::now();


			//Step 4: while in question array:
				//a. Display one question randomly and start timer
				//b. Obtain user input for answer
				//c. validate answer for user input
				//d. Repeat for 10 questions and stop timer

			//Step 5: While in answer array:
				//a. Check and Display Score (out of 10)
				//b. Display Time elapsed
				//c. Display Question with corresponding answer and repeat for the 10 questions	


			while (count < 10)
			{
				k = rand() % 100;
				Check_Q(h, k);
				cout << Q[k] << ": ";
				cout << endl;
				getline(cin, qanswer);
		

				

				if(A[k].find("FALSE") != string::npos)
				{
					if (qanswer == "FALSE" || qanswer == "f" || qanswer == "F" || qanswer == "false")
					{
						QA[count] = "Correct";
						score++;

					}

					else
					{
						QA[count] = "Incorrect";
					}
					

				}

				else if (A[k].find("TRUE") != string::npos)
				{

				
					if (qanswer == "TRUE" || qanswer == "t" || qanswer == "t" || qanswer == "true")
					{
						QA[count] = "Correct";
						score++;

					}

					else
					{
						QA[count] = "Incorrect";
					}


				}

				else
				{
					QA[count] = "Error";
				}


				h = k;
				count++;
			}

		
			end = chrono::system_clock::now();
			chrono::duration<double> timer = end - start;
			cout << endl << "Quiz Completed, here is your total score: " << score << "/10" << endl;
			cout << "The time it took you to complete: " << timer.count() << ": seconds" << endl;
			cout << "This is what you got correct and incorrect: " << endl;
			for (int c = 0; c < 10; c++)
			{
				cout << "Question " << c+1 << ": " << QA[c] << endl;
			}

			score = 0;
			count = 0;
			cout << endl << endl;

			cout << "This is the end of the quiz, would you like to restart? Enter 'yes' or 'no': ";
			cin >> answer;

		}
	
	}



	if (answer == "N" || answer == "No" || answer == "no" || answer == "n" || answer == "NO")
	{
		cout << "Goodbye!";
		AFile.close();
		QFile.close();
	}

	else
	{
		cout << "Goodbye!";
		AFile.close();
		QFile.close();
	}

	return 0;
}
