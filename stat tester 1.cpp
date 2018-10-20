//#include "stdafx.h"
#include <iostream>

using namespace std;

bool validate_input(char);
int check_answers();
void get_incorrect_answ_qst();
void getOutput(int);

const int num_qsts =2;
const int passing_score = 2;
char correct_answer []{'b','a', 'd', 'c','b','a', 'd', 'c','b','a', 'd', 'c','b','a', 'd', 'c','b','a', 'd', 'c', 'c', 'd'};//you have to put correct answers in this section] {}


int INCORRECT_QST[num_qsts];
char user_answer[num_qsts];


int main()
{ 
//
	int correct_ans_count = 0;
	for(int i=0; i<num_qsts; i++)// increment counter- starting from 0 this counts up by 1 until it hits the number of questions you set
	{
		do{
			cout<<"\nAbel Allonzo, Director of HumanResources, is exploring the causes of employee absenteeism at Batesville Bottling during the last operating year (Janurary 1,1999 through December 31,1999). For this study the set of all employees who worked at Batesville Bottling during the last operating year is ___________. \n\n "
				<<" a) a paramerter\n"
				<<" b) a sample\n" 
				<<" c) the population\n"
				<<" d) the statistic\n"
				<<" e) the frame\n\n"
				<<" Select answer\n";
			cin>> user_answer[i];// class=character, 
			
			cout<<"\nA question in a survey of a microcomputer users asked:  Which operating sytem do you use most often: a.Apple OS 7,b. MS DOS, c. MS Windows 95, d. UNIX. The measurement level for this question is ________.\n\n"
				<<" a) nominal level\n"
				<<" b) ordinal level\n"
				<<" c) interval level\n"
				<<" d) ratio level \n"
				<<" e) relative level\n"
				<<" Select answer\n";
			cin>> user_answer[i];
		  }while(!validate_input(user_answer[i]));//validate input is assigned to character which is the user answer with the increment i to stop the loop once it hits num questions
	}
	
	correct_ans_count= check_answers();
	if(correct_ans_count < num_qsts)
		{
			get_incorrect_answ_qst();
		}
	getOutput(correct_ans_count);
	
	return 0;
}
void getOutput(int counter)
{
	cout<< "\nYOU HAVE " << (counter >= passing_score? "PASSED ": "FAILED ") << "THE TEST"<< endl;
	cout<<"You have answered " << counter<< " correctly and " <<  (num_qsts-counter) << " incorrectly"<< endl;
	// if some answers were wrong, which ones, what is the correct answer and what was the user answer?
	if(counter< num_qsts)
	{
		cout<<" The following qsts were answered incorrectly: \n";
		for(int i =0 ; i = num_qsts-counter; i++) 
		{
			cout<<"Qst #" << (INCORRECT_QST[i]+1)<< ". Correct answer was "<<
			correct_answer[INCORRECT_QST[i]]<< "Your answer was "<< user_answer[INCORRECT_QST[i]]<< endl;
			
		}
	}
	
}
void get_incorrect_answ_qst()
{

	int counter = 0; //index of the incorrectly answered qsts array >> looks like this : int INCORRECT_QST[num_qsts];
	for( int i=0; i< num_qsts; i++) 
	{
		if(correct_answer[i] != user_answer[i])
		{
			INCORRECT_QST[counter] = i; //make sure this variable is correct INCORRECT_QST- might be different variable 
			counter++;
		}
		
	}
}
int check_answers()
{
	int counter=0;
	for(int i =0; i<num_qsts; i++)
	{
		if(user_answer[i] == correct_answer[i])
			counter ++;
	}
	return counter;
}
			

bool validate_input(char answer)
	{
	if(answer !='a' && answer!='b'&& answer!='c'&& answer!='d'&& answer!='e')
	{
		cout<<"\nInvalid input ";
		return false;
	}
	
		return true; 
}
		
