#include <iostream>
#include "Rival.h"
#include "Point2D.h"
#include "GameObject.h"
#include "Pokemon.h"
#include "string.h"
using namespace std;

Rival :: Rival (string name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int id, Point2D in_loc):GameObject(in_loc, id, 'R')
{
	this->name=name; //check this pointer
	this->speed=speed;
	health=hp;
	physical_damage=phys_dmg;
	magical_damage=magic_dmg;
	defense=def;
	id_num=id;
	location=in_loc;
	current_arena=NULL; 
	is_in_arena=false;
	state=ALIVE_RIVAL; 
	cout<<"Rival constructed\n";
}

void Rival :: TakeHit(double physical_damage, double magical_damage, double defense)
{
	int random=rand()%2;
	int damage;
	if (random==1)
	{
		damage=(100.0 - defense)/100 * physical_damage;
		health=health-damage;
	}
	else
	{
		damage=(100.0 - defense)/100 * magical_damage;
		health=health-damage;
	}
}

double Rival :: get_phys_dmg()
{
	return physical_damage;
}

double Rival:: get_magic_dmg()
{
	return magical_damage;
}
double Rival::get_defense()
{
	return defense;
}
double Rival::get_health()
{
	return health; 
}
bool Rival :: IsAlive()
{
	if (health <=0)
	{
		state=FAINTED_RIVAL;
		current_arena->RemoveOneRival(); //check where to put it. 
		return false; 

	}
	else
	{
		state=ALIVE_RIVAL; 
		return true; 
	}
}
bool Rival :: Update()
{
	if (state==ALIVE_RIVAL)
	{
		return false;
	}
	else if (state==FAINTED_RIVAL)
	{
		//check 
		//health<=0; 
		return true;
		//finish
	}
return false; 
}

bool Rival::ShouldBeVisible()
{
	return true; 
}

int Rival::GetId()
{
	return id_num; 
}

void Rival :: ShowStatus()
{
	cout<<name<< " status:";
	GameObject::ShowStatus();
	if (state==ALIVE_RIVAL)
	{
		cout<<" alive\n";
	}
	else if(state==FAINTED_RIVAL)
	{
		cout<<" dead, RIP... \n"; 
	}
	cout<<"\t"<<"Health: "<<health<<endl;
	cout<<"\t"<<"Physical Damage: "<<physical_damage<<endl;
	cout<<"\t"<<"Magical Damage: "<<magical_damage<<endl; 
	cout<<"\t"<<"Defense: "<<defense<<endl; 
}