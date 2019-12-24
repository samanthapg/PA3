#include "Model.h"
#include "GameObject.h"
#include "Pokemon.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "View.h"
#include "BattleArena.h"
#include "Rival.h"
#include <cstdlib>
#include <iostream>
#include <string>
	
Model::Model() {
    time = 0;
    //Pikachu 1
    pokemon_ptrs[0] = new Pokemon("Pikachu", 1, 'P', 2.0, Point2D(5, 1));
    object_ptrs[0] = pokemon_ptrs[0];
    //Pikachu 2
    pokemon_ptrs[1] = new Pokemon("Bulbasaur", 2, 'P', 1.0, Point2D(10, 1));
    object_ptrs[1] = pokemon_ptrs[1];
    //PokemonCenter 1
    center_ptrs[0] = new PokemonCenter(1, 1, 100, Point2D(1, 20));
    object_ptrs[2] = center_ptrs[0];
    //PokemonCenter 2
    center_ptrs[1] = new PokemonCenter(2, 2, 200,  Point2D(10, 20));
    object_ptrs[3] = center_ptrs[1];
    //PokemonGym
    gym_ptrs[0] = new PokemonGym(10, 1.0,
                                 2.0, 3, 1, Point2D(0, 0));
    object_ptrs[4] = gym_ptrs[0];
    gym_ptrs[1] = new PokemonGym(20, 5,
                                 7.5, 8, 2, Point2D(5, 5));
    object_ptrs[5] = gym_ptrs[1];

    rival_ptrs[0]=new Rival("burhack", 2, 16,3, 7.2, 20, 1,Point2D(15,12));
    rival_ptrs[1]=new Rival("mmark9", 1, 29, 4, 5.2, 12, 2, Point2D(15,12));
    rival_ptrs[2]=new Rival("Densmore", 3 , 41, 6, 8.2,18, 3, Point2D(15,12));
    object_ptrs[6]=rival_ptrs[0];
    object_ptrs[7]=rival_ptrs[1];
    object_ptrs[8]=rival_ptrs[2];
    battle_ptrs[0]=new BattleArena(3,3,2.5,1,Point2D(15,12));
    object_ptrs[9]=battle_ptrs[0];
    num_objects = 10;
    num_pokemon = 2;
    num_centers = 2;
    num_gyms = 2;
    num_rivals=3;
    num_arena=1; 

    cout << "Model default constructed. " << endl;
}
	/*Pokemon * p1=new Pokemon("Pikachu",2, 23, 3, 6, 12, 1, 'P',locp1); 
	Pokemon * p2=new Pokemon("Bulbasur",1,26, 4,3.7,16, 2, 'P', locp2);
	pokemon_ptrs[0]=p1;
	pokemon_ptrs[1]=p2;
	PokemonCenter * c1=new PokemonCenter(1, 1, 100, locc1);
	PokemonCenter * c2=new PokemonCenter(2, 2, 200, locc2);
	center_ptrs[0]=c1;
	center_ptrs[1]=c2;
	PokemonGym * g1=new PokemonGym(10, 1, 2.0, 3, 1, locg1);
	PokemonGym * g2=new PokemonGym(20, 5, 7.5, 8, 2, locg2);
	gym_ptrs[0]=g1;
	gym_ptrs[1]=g2;
	BattleArena * b1=new BattleArena(3,3,2.5,1,locb1);
	battle_ptrs[0]=b1;
	Rival * r1=new Rival("burhack", 2, 16,3, 7.2, 20, 1,locb1);
	Rival * r2=new Rival("mmark9", 1, 29, 4, 5.2, 12, 2, locb1);
	Rival * r3=new Rival("Densmore", 3 , 41, 6, 8.2,18, 3, locb1);
	rival_ptrs[0]=r1;
	rival_ptrs[1]=r2;
	rival_ptrs[3]=r3; 

	object_ptrs.push_back(p1);
	object_ptrs.push_back(p2);
	object_ptrs.push_back(c1);
	object_ptrs.push_back(c2);
	object_ptrs.push_back(g1);
	object_ptrs.push_back(g2);
	object_ptrs.push_back(r1);
	object_ptrs.push_back(r2);
	object_ptrs.push_back(r3);
	object_ptrs.push_back(b1); */


Model::~Model() {
    for (int i = 0; i < num_objects; i++) {
        delete object_ptrs[i];
    }
    cout << "Model destructed. " << endl;
}

Pokemon *Model::GetPokemonPtr(int id) {
    for (int i = 0; i < num_pokemon; i++) {
        if (id == pokemon_ptrs[i]->GetId()) {
            return pokemon_ptrs[i];
        }
    }
    return 0;
}

PokemonCenter *Model::GetPokemonCenterPtr(int id) {
    for (int i = 0; i < num_centers; i++) {
        if (id == center_ptrs[i]->GetId()) {
            return center_ptrs[i];
        }
    }
    return 0;
}

PokemonGym *Model::GetPokemonGymPtr(int id) {
    for (int i = 0; i < num_gyms; i++) {
        if (id == gym_ptrs[i]->GetId()) {
            return gym_ptrs[i];
        }
    }
    return 0;
}

Rival * Model::GetRivalPtr(int id){
	for (int i = 0; i < num_rivals; i++) {
        if (id == rival_ptrs[i]->GetId()) {
            return rival_ptrs[i];
        }
    }
    return 0;
}

BattleArena * Model::GetArenaPtr(int id){
	for (int i = 0; i < num_arena; i++) {
        if (id == battle_ptrs[i]->GetId()) {
            return battle_ptrs[i];
        }
    }
    return 0;
}

bool Model::Update() {
    time++;
    int gyms_beaten = 0;
    int pokemon_exhausted = 0;
    //Calculating number of gyms beaten
    if (gyms_beaten != num_gyms) {
        for (int i = 0; i < num_gyms; i++) {
            if (gym_ptrs[i]->GetState() == BEATEN)
                gyms_beaten++;
        }
    }
    // Calculating number of pokemon that are tired
    if (pokemon_exhausted != num_pokemon) {
        for (int i = 0; i < num_pokemon; i++) {
            if (pokemon_ptrs[i]->IsExhausted())
                pokemon_exhausted++;
        }
    }
    bool event = false;
    // continue to update all
    if (gyms_beaten == num_gyms) {
        cout << "GAME OVER: You win! All Pokemon Gyms beaten!" << endl;
        exit(EXIT_SUCCESS);
    }
    if (pokemon_exhausted == num_pokemon) {
        cout << "GAME OVER: You lose! All of your Pokemon are exhausted!" << endl;
        exit(EXIT_SUCCESS);
    }
    // update if winning condition is not met
    for (int i = 0; i < num_objects; i++) {
        bool temp = object_ptrs[i]->Update();
        if (temp) {
            event = temp;
        }
    }
    return event;
}

void Model::Display(View &view) {
    view.Clear();
    for (int i = 0; i < num_objects; i++) {
        if (object_ptrs[i]->ShouldBeVisible()) {
            view.Plot(object_ptrs[i]);
        }
    }
    view.Draw();
}

void Model::ShowStatus() {
    cout << "Time: " << time << endl;
    for (int i = 0; i < num_objects; i++) {
        object_ptrs[i]->ShowStatus();
    }
}
