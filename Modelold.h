#ifndef MODEL_H
#define MODEL_H
#include "GameObject.h"
#include "Pokemon.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "View.h"

class Model {
    
public:
    //simulation time
    int time;
    GameObject * object_ptrs[10];
    int num_objects;
    Pokemon * pokemon_ptrs[10];
    int num_pokemon;
    PokemonCenter * center_ptrs[10];
    int num_centers;
    PokemonGym * gym_ptrs[10];
    int num_gyms;
    int num_arena;
    BattleArena * battle_ptrs[10];
    int num_rivals;
    Rival * rival_ptrs[10];
    
public:
    Model();
    ~Model();
    Pokemon* GetPokemonPtr(int id);
    PokemonCenter* GetPokemonCenterPtr(int id);
    PokemonGym* GetPokemonGymPtr(int id);
    bool Update();
    void Display(View &view);
    void ShowStatus();
    BattleArena * GetArenaPtr(int id);
    Rival * GetRivalPtr(int id);
};


#endif
