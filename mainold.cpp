#include <iostream>
#include <stdlib.h>
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonGym.h"
#include "PokemonCenter.h"
#include "Pokemon.h"
#include "Model.h"
#include "GameCommand.h" 
#include "BattleArena.h"
#include "Rival.h"
#include "View.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <fstream>
using namespace std; 

const string POKEMON_BANNER = "                                  ,'\\\n"
                              "    _.----.        ____         ,'  _\\   ___    ___     ____\n"
                              "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`.\n"
                              "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |\n"
                              " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |\n"
                              "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |\n"
                              "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |\n"
                              "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |\n"
                              "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |\n"
                              "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |\n"
                              "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |\n"
                              "                                `'                            '-._|";

int main()
{
	cout<<"EC327: Introduction to Software Engineering\n";
	cout<<"Fall 2019\n";
	cout<<"Programming Assignment 4\n";       
	cout << POKEMON_BANNER << endl;                    
	char comm; 
	Model model1;
	View view1; 
	model1.ShowStatus(); 
	model1.Display(view1); 
	while (true)
	{
		//cin.clear();
	cout<<"Enter command: ";
	cin>>comm;
		switch (comm)
		{
			case 'm':
			{
				int ID;
				double x1;
				double y1;
				cin>>ID;
				if (cin.fail())
				{
					cin.clear();
					break; 
				}
				cin>>x1;
				if (cin.fail())
				{
					cin.clear();
					break;
				}
				cin>>y1;
				if (cin.fail())
				{
					cin.clear();
					break;
				}
				Point2D p1(x1,y1);
				if (ID<3 && !cin.fail())
				{
					DoMoveCommand(model1,ID,p1);
					model1.Display(view1); 
				}
				else
				{
					cout<<"Invalid ID\n";
				}
				cin.clear();
				//cin.ignore(numeric_limits<streamsize>::max(),'\n');
				break;
			}
			case 'g':
			{
				int ID1;
				int ID2; 
				cin>> ID1;
				if (cin.fail())
				{
					cin.clear();
					break;
				}
				cin>> ID2;
				if (cin.fail())
				{
					cin.clear();
					break;
				}
				if (ID1<3 && ID2<3)
				{
					DoMoveToGymCommand(model1, ID1, ID2); 
					model1.Display(view1);
				}
				else
				{
					cout<<"Invalid ID\n";
				}
				cin.clear();
				//cin.ignore(numeric_limits<streamsize>::max(),'\n');
				break;
			}
			case 'c':
			{
				int ID1;
				int ID2;
				cin>>ID1;
				if (cin.fail())
				{
					cin.clear();
					break;
				}
				cin>>ID2;
				if (cin.fail())
				{
					cin.clear();
					break;
				}
				if (ID1<3 && ID2<3)
				{
					DoMoveToCenterCommand(model1, ID1, ID2);
					model1.Display(view1);
				}
				else
				{
					cout<<"Invalid ID\n";
				}
				//cin.clear();
			//	cin.ignore(numeric_limits<streamsize>::max(),'\n');
				break;
			}
			case 's':
			{
				int ID;
				//int ID2;
				cin>>ID;
				if (cin.fail())
				{
					cin.clear();
					break;
				}
				//cin>>ID2;
				if (ID<3)
				{
					DoStopCommand(model1, ID);
					model1.Display(view1);
				}
				else
				{
					cout<<"Invalid ID\n"; 
				}
				cin.clear();
			//	cin.ignore(numeric_limits<streamsize>::max(),'\n');
				break;
			}
			case 'r':
			{
				int ID1;
				//int ID2;
				cin>>ID1;
				if (cin.fail())
				{
					cin.clear();
					break; 
				}
				//cin>>ID2;
				//cout<<"ID1 "<<ID1;
				unsigned int stamina_amount;
				cin>>stamina_amount; 
				if (cin.fail())
				{
					cin.clear();
					break;
				}
				//cout<<"stamina is "<<stamina_amount;
				if (ID1<3)
				{
					DoRecoverInCenterCommand(model1, ID1, stamina_amount);	
					model1.Display(view1);
				}
				else
				{
					cout<<"Invalid ID\n"; 
				}
				cin.clear();
			//	cin.ignore(numeric_limits<streamsize>::max(),'\n');			
				break;

			}
			case 't':
			{
				int ID1;
				unsigned int unit_amount;
				//int ID2;
				cin>>ID1;
				if (cin.fail())
				{
					cin.clear();
					break; 
				}
				//cin>>ID2;
				cin>>unit_amount;
				if (cin.fail())
				{
					cin.clear();
					break;
				}
				if (ID1<3)
				{
					DoTrainInGymCommand(model1, ID1,unit_amount);
					model1.Display(view1);
				}
				cin.clear();
			//	cin.ignore();
				break;

			}
			case 'v':
			{
				DoGoCommand(model1, view1); 
			cin.clear();
			//	cin.ignore(numeric_limits<streamsize>::max(),'\n');
				break;
				
			}
			case 'x':
			{ 
				DoRunCommand(model1, view1); 
			cin.clear();
			//	cin.ignore(numeric_limits<streamsize>::max(),'\n');
				break;
			}
			case 'q':
			{
			cin.clear();
			cout<<"Terminating program\n"; 
			//	cin.ignore(numeric_limits<streamsize>::max(),'\n');
				return 0; 
				break; 
			}
			case 'b':
			{
				int ID1;
				cin >> ID1;
				if (cin.fail())
				{
					cin.clear();
					break;
				}
				int ID2;
				cin>> ID2; 
				if (cin.fail())
				{
					cin.clear();
					break;
				}
				if (ID1<3 && ID2<4)
				{
					DoReadyToBattleCommand(model1, ID1, ID2);
					model1.Display(view1);
				}
				else
				{
					cout<<"Invalid ID\n";
				}
				break; 

			}
			case 'a':
			{
				int ID1;
				cin >> ID1;
				if (cin.fail())
				{
					cin.clear();
					break;
				}
				int ID2;
				cin>>ID2; 
				if (cin.fail())
				{
					cin.clear();
					break;
				}
				if (ID1<3 && ID2<3)
				{
					DoMoveToArenaCommand(model1, ID1, ID2);
					model1.Display(view1);
				}
				else
				{
					cout<<"Invalid ID\n";
				}
				break; 
			}
			default:
			{
				break; 
			}
		}
	}

	return 0; 
}
