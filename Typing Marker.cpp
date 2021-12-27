/**
	AUTHOR 		:	TEERTHA DEB
	STOP_STALK 	:	stopstalk.com/user/profile/Teertha_Deb
	GitHub		:	github.com/TeerthaDeb
**/
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;
int width = 119, height = 28; //default for windows 10
bool run = false;
int main(); //all other functions can use the main function

class player 																											//default template of each players
{
private:
	//variables:
	int total_time;
	float average, total_score;
	char name[50];
	//functions:

public:
	player()
	{
	}
	~player()
	{
	}
	//setters:
	void set_total_time(int Total_Time)
	{
		total_time = Total_Time;
	}
	void set_total_score(float Total_Score)
	{
		total_score = Total_Score;
	}
	void set_average(float Average)
	{
		average = Average;
	}
	void set_name(string Name)
	{
		strcpy(name, Name.c_str());
	}
	//getters:
	int get_total_time()
	{
		return total_time;
	}
	float get_total_score()
	{
		return total_score;
	}
	float get_average()
	{
		return average;
	}
	string get_name()
	{
		return name;
	}
	void print_everything()
	{
		printf("name = %s , average = %f , score = %f , time = %d\n", name, average, total_score, total_time);
	}
	int get_name_length()
	{
		return strlen(name);
	}
	//friend functions:
};

void setcolor(int ForgC) 																								//set color function for setting the color of the powershell(includeing background color and text)
{
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}

void gotoxy(short col, short row) 																						//place the pointer at a specific location in the screen
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = {col, row};
	SetConsoleCursorPosition(h, position);
}

void box() 																												//make a box in the powershell to present the program in a good manner
{
	int i, j;
	gotoxy(0, 0);
	printf("%c", 201);
	for (i = 0; i < width - 1; i++)
		printf("%c", 205);
	printf("%c", 187); //!!!!!!print_the_up_line;
	for (i = 0; i < height; i++)
	{
		gotoxy(0, i + 1);
		printf("%c", 186);
		gotoxy(width, i + 1);
		printf("%c", 186);
	} //!!!!!!!!!print_side_lines
	gotoxy(0, height + 1);
	printf("%c", 200);
	for (i = 0; i < width - 1; i++)
		printf("%c", 205);
	printf("%c", 188);
}

void box2()																												//make a box in the powershell to present the scoreboard in a good manner
{
	int i, j, height = 29;
	gotoxy(0, 0);
	printf("%c", 201);
	for (i = 0; i < width - 1; i++)
		printf("%c", 205);
	printf("%c", 187); //!!!!!!print_the_up_line;
	for (i = 0; i < height; i++)
	{
		gotoxy(0, i + 1);
		printf("%c", 186);
		gotoxy(width, i + 1);
		printf("%c", 186);
	}
	gotoxy(0, height + 1);
	printf("%c", 200);
	for (i = 0; i < width - 1; i++)
		printf("%c", 205);
	printf("%c", 188);
}

void wait(int k)																										//loading screen
{
	for (int i = 0; i < 5; i++)
	{
		printf(" .");
		Sleep(k);
	}
}

bool compare_players(player &a, player &b)																				//extra perameter for sort function to sort the class instances according to their average score
{
	return a.get_average() > b.get_average();
}

void score_board(float average, float total_score, int total_time)														//Score board function to represent the score board
{
	system("cls");
	system("Color 0D");
	int i;
	vector<player> plr(10);
	player temp;
	fstream file_ptr("score.txt", ios::in);
	if (file_ptr){																										//if File pointer finds the file , it would load the file data to the player class instances
		plr.clear();
		for (i = 0; i < 10; i++){
			file_ptr.read(reinterpret_cast<char *>(&temp), sizeof(temp));
			plr.push_back(temp);
		}
	}
	else{																												//if File pointer fails to open a file , then it would create it's own record.
		for (i = 0; i < 10; i++){
			plr[i].set_name("Teertha Deb");
			plr[i].set_total_score((float)i + 1);
			plr[i].set_total_time(i + 1);
			plr[i].set_average((float)i + 1);
		}
		plr[i].set_name("Teertha Deb");
		plr[i].set_total_score((float)i + 1);
		plr[i].set_total_time(i + 1);
		plr[i].set_average((float)1000);
	}
	file_ptr.close();
	if (average and total_score and total_time){																	//if scoreboard was not called from main menu , then it would sure ask for players name
		printf("Enter Players name : ");
		char name[50];
		cin.ignore();
		cin.getline(name, 50);
		temp.set_name(name);
		temp.set_average(average);
		temp.set_total_score(total_score);
		temp.set_total_time(total_time);
		plr.push_back(temp);
	}
	sort(plr.begin(), plr.end(), compare_players);																	//Sort players according to their average score.
	system("cls");
	box2();
	gotoxy(2, 3);
	file_ptr.open("score.txt", ios::out);
	int h = 2;
	for (i = 0; i < 10; i++){
		file_ptr.write(reinterpret_cast<char *>(&plr[i]), sizeof(plr[i]));											//Write the data in the record
		gotoxy(width / 2 - plr[i].get_name_length() - 14, h - 1), cout << "Rank : " << i + 1;
		gotoxy(width / 2 - 11, h - 1), cout << ";     >>>>>>>>>Name = " << plr[i].get_name() << " <<<<<<<<<";
		gotoxy(width / 2 - 25, h), cout << "average = " << plr[i].get_average();
		gotoxy(width / 2 - 10, h), cout << " , total score = " << plr[i].get_total_score();
		gotoxy(0, h + 1), printf("%c", 204 - 4*(i == 9)), gotoxy(width, h + 1), printf("%c", 185 + 3*(i == 9));
		for (int j = 1; j < width; j++){
			gotoxy(j, h + 1), printf("%c", 205);
		}
		gotoxy(width / 2 + 11, h), cout << " , total time = " << plr[i].get_total_time(), h += 3;
	}
	file_ptr.close();
	plr.clear();																									//clear all the datas from memory
	gotoxy(0, h);
	printf("Press any key to go to main menu...\b");
	getch();
	wait(300);
	main();
}

void start_typing()																										//Start typing<main program>
{
	float actual_score = 0, average = 0;
	int time = 0;
	system("cls");
	system("Color 2F");
	box();
	//Selection box menu
	{
		gotoxy((width / 2 - 17), 2);
		printf(">>>Enter your selection:<<<");
		gotoxy((width / 2 - 17), 7);
		printf("[1] Capital Letters Only");
		gotoxy((width / 2 - 17), 10);
		printf("[2] Small Letters only");
		gotoxy((width / 2 - 17), 13);
		printf("[3] Small and Capital mix");
		gotoxy((width / 2 - 17), 16);
		printf("[4] Back to Main Menu");
		gotoxy((width / 2 - 17), 18);
		printf("press (1-4) : ");
	}
	char start_typing_character, required_char, given_char;
	long long int n, score = 0, wrong = 0;
	start_typing_character = getch();
	if (start_typing_character == '1'){															//Capital letters typing zone
		system("cls");
		box();
		gotoxy((width / 2 - 25), 13);
		printf("How many characters to would you like to try : ");
		cin >> n;
		system("cls");
		box();
		using namespace std::chrono;
		auto start = high_resolution_clock::now(); 												//place this at the begaining of counting time
		while (n--){
			required_char = required_char + rand() + n + rand() % 25 + 'A';
			while (required_char > 'Z' or required_char < 'A'){									//The letter should be between 'A' and 'Z'
				required_char = required_char + rand() + n + rand() % 25 + 'A';
			}
			gotoxy((width / 2 - 17), 13);
			printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			gotoxy((width / 2 - 15), 13);
			printf("Press %c : ", required_char);
			given_char = getch();
			if (given_char == required_char)
				score++;
			else
				wrong++, printf("\a");
			gotoxy((width / 2 - 17), height - 2);
			printf("\b\b\b\b\b\b\b\b\b\b\b\b");
			gotoxy((width / 2 - 17), height - 2);
			printf("Remaining Characters: %lld", n);
		}
		auto stop = high_resolution_clock::now();				   //place this at the end of counting time
		auto duration = duration_cast<microseconds>(stop - start); //time is stored int duration
		system("cls");
		box();
		actual_score = (float)score - ((float)wrong * (float)0.2);
		average = ((float)score - ((float)wrong * (float)0.2)) / (float)(duration.count() / (1e+6));
		gotoxy((width / 2 - 19), 8);
		printf("Your Score = %d and wrong keys pressed = %d", score, wrong);
		gotoxy((width / 2 - 15), 10);
		printf("Time taken : ");
		time = duration.count();
		cout << time << " microseconds" << '\n';
		gotoxy((width / 2 - 9), 14);
		printf("Net Score = %f", actual_score);
		gotoxy((width / 2 - 8), 16);
		printf("Average = %f", average);
	}
	else if (start_typing_character == '2'){												//Small letter
		system("cls");
		box();
		gotoxy((width / 2 - 25), 13);
		printf("How many characters to would you like to try : ");
		cin >> n;
		system("cls");
		box();
		using namespace std::chrono;
		auto start = high_resolution_clock::now(); //place this at the begainig of counting time
		while (n--){
			required_char = required_char + n + rand() + rand() % 25 + 'a';
			while (required_char > 'z' or required_char < 'a')
			{
				required_char = required_char + n + rand() + rand() % 25 + 'a';
			}
			gotoxy((width / 2 - 17), 13);
			printf("\b\b\b\b\b\b\b\b\b\b\b\b");
			gotoxy((width / 2 - 15), 13);
			printf("Press %c : ", required_char);
			given_char = getch();
			if (given_char == required_char)
				score++;
			else
				wrong++, printf("\a");
			gotoxy((width / 2 - 17), height - 2);
			printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			gotoxy((width / 2 - 17), height - 2);
			printf("Remaining Characters: %lld", n);
		}
		auto stop = high_resolution_clock::now();				   //place this at the end of counting time
		auto duration = duration_cast<microseconds>(stop - start); //time is stored int duration
		system("cls");
		box();
		actual_score = (float)score - ((float)wrong * (float)0.2);
		average = ((float)score - ((float)wrong * (float)0.2)) / (float)(duration.count() / (1e+6));
		gotoxy((width / 2 - 19), 8);
		printf("Your Score = %d and wrong keys pressed = %d", score, wrong);
		gotoxy((width / 2 - 15), 10);
		printf("Time taken : ");
		time = duration.count();
		cout << time << " microseconds" << '\n';
		gotoxy((width / 2 - 9), 14);
		printf("Net Score = %f", actual_score);
		gotoxy((width / 2 - 8), 16);
		printf("Average = %f", average);
	}

	else if (start_typing_character == '3')														//Small and capital mixed
	{
		system("cls");
		box();
		gotoxy((width / 2 - 25), 13);
		printf("How many characters to would you like to try : ");
		cin >> n;
		system("cls");
		box();
		using namespace std::chrono;
		auto start = high_resolution_clock::now(); //place this at the begainig of counting time
		while (n--)
		{
			required_char = rand() % 57 + 'A';
			while (required_char > 90 and required_char < 96)
			{
				required_char = rand() % 57 + 'A';
			}
			gotoxy((width / 2 - 17), 13);
			printf("\b\b\b\b\b\b\b\b\b\b\b\b");
			gotoxy((width / 2 - 15), 13);
			printf("Press %c : ", required_char);
			given_char = getch();
			if (given_char == required_char)
				score++;
			else
				wrong++, printf("\a");
			gotoxy((width / 2 - 17), height - 2);
			printf("\b\b\b\b\b\b\b\b\b\b\b\b");
			gotoxy((width / 2 - 17), height - 2);
			printf("Remaining Characters: %lld", n);
		}
		auto stop = high_resolution_clock::now();				   //place this at the end of counting time
		auto duration = duration_cast<microseconds>(stop - start); //time is stored int duration
		system("cls");
		box();
		actual_score = (float)score - ((float)wrong * (float)0.2);
		average = ((float)score - ((float)wrong * (float)0.2)) / (float)(duration.count() / (1e+6));
		gotoxy((width / 2 - 19), 8);
		printf("Your Score = %d and wrong keys pressed = %d", score, wrong);
		gotoxy((width / 2 - 15), 10);
		printf("Time taken : ");
		time = duration.count();
		cout << time << " microseconds" << '\n';
		gotoxy((width / 2 - 9), 14);
		printf("Net Score = %f", actual_score);
		gotoxy((width / 2 - 8), 16);
		printf("Average = %f", average);
	}
	else
	{
		system("cls");
		box();
	}
	gotoxy((width / 2 - 18), 18);
	printf("press any key to go to scoreboard. . .\b");
	getch();
	gotoxy((width / 2 - 6), 20);
	wait(250);
	score_board(average, actual_score, time / 1000000);
}

void exit()																												//exiting dialogue print in the screen.
{
	system("cls");
	system("7C");
	box();
	gotoxy(width / 2 - 20, height / 2), printf("Are you sure you want to exit?(Y/N) : ");
	char ch;
	ch = getch();
	if(ch == 'y' or ch == 'Y'){
        system("cls");
        box();
        gotoxy(width / 2 - 5, height / 2), printf("exiting .");
        wait(700);
        exit(0);
	}
	else if(ch == 'n' or ch == 'N'){
        gotoxy((width /2 - 17) , 17);
        printf("press any key to go to main menu. . .\b");
        getch();
        gotoxy((width / 2 - 15), 20);
        printf("going to main menu.");
        wait(350);
        main();
	}
    else{
        gotoxy((width /2 - 17) , 17);
        printf("Invalid selection");
        Sleep(1500);
        exit();
    }
}

void about()																											//about the author of the program and how player scores are marked.
{
	system("cls");
	system("Color B0");
	box();
	gotoxy((width / 2 - 17), 2);
	printf(">>>About the tutorial program :<<<");
	gotoxy((width / 2 - 14), 5);
	printf("Author : Maharaj Teertha Deb");
	gotoxy((width / 2 - 11), 7);
	printf("Started : 18th June 2021");
	gotoxy((width / 2 - 15), 9);
	printf("Finalized : 20th December , 2021\b");
	gotoxy((width / 2 - 10) , 13);
	printf("The marking critiria is :");
	gotoxy((width /2 - 20) , 15);
	printf("score = total score - wrong key pressed * 0.2");
	gotoxy((width /2 - 17) , 17);
	printf("press any key to go to main menu. . .\b");
	getch();
	gotoxy((width / 2 - 15), 20);
	printf("going to main menu ");
	wait(350);
	main();
}

void starting()																											//Starting
{
	system("Color 70");
	run = true;
	gotoxy(10, 5), printf("enter your windows version: ");
	gotoxy(10, 7), printf("[1] windows 7 (or previous version)");
	gotoxy(10, 9), printf("[2] windows 10(or later version after 7)");
	gotoxy(11, 15), printf("Enter choice: (1/2) : ");
	char choice;
	choice = getch();
	if (choice == '1')
	{ //Windows 7 powershell is small in size;
		width = 79, height = 22;
	}
}

int main()																												//Main menu
{
	if (run == false)
	{
		starting();
	}
	system("cls");
	box();
	//main menu selection box
	{
		system("Color 1F");
		gotoxy((width / 2 - 15), 2);
		printf(">>>Enter your selection:<<<");
		gotoxy((width / 2 - 15), 7);
		printf("[1] Start Typing");
		gotoxy((width / 2 - 15), 10);
		printf("[2] Detailed Score Board");
		gotoxy((width / 2 - 15), 13);
		printf("[3] About...");
		gotoxy((width / 2 - 15), 16);
		printf("[4] Exit");
		gotoxy((width / 2 - 15), 18);
		printf("press (1-4) : ");
	}
	char main_menu_choice;
	main_menu_choice = getch();
	switch (main_menu_choice)
	{
		case '1':{
			start_typing();
			break;
		}
		case '2':{
			score_board(0, 0, 0);
			break;
		}
		case '3':{
			about();
			break;
		}
		case '4':{
			exit();
			break;
		}
		default:{
			gotoxy(width / 2  - 23 , 20);
			printf("invalid Selection\a\a.Going to main menu again.");
			wait(350);
			main();
		}
	}
}
