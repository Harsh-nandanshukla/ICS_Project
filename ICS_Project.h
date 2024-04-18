#ifndef ICS_PROJECT_H
#define ICS_PROJECT_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"cJSON.h"
#include"cJSON.c"




//Structures

// Define the Inventory structure
typedef struct {
    int size; // Size of the inventory
    char **items; // Array of items in the inventory
} Inventory;

// Define the Player structure
typedef struct {
    char *id; // Player's id
    char *name;
    int level; // Player's level
    Stats *stats; // Player's stats (e.g., HP, attack, defense)
    Inventory *inventory; // Player's inventory
    int wtdLevel; // Wantedted level
    int xp; // Player's experience points
    int gold; // Player's gold
    char *currentLocation; // Player's current location as string
    char **activeQuests; // Player's active quests
    int **npcInfo;//players' active 
} Player;

// Define a structure to hold string-function mappings
typedef struct {
    char *str;
    void (*func)();
} StringFunctionPair;

typedef enum
{
    SOLDIER,
    SHOPKEEPER,
    FIGHTER,
    CITIZEN,
    ///Add more as needed
}TypeOfNpc;

typedef struct 
{
    int HP;
    int atk;
    int def;
    int agi;
    int str;
    int dex;
    int intel;
    int luck;
}Stats;

typedef enum
{
    WEAPON,
    ARMOR,
    POTION,
    QUEST_ITEM,
    RING,
    CONSUMABLE,
// ADD MORE AS NEEDED

}Itemtype;

typedef enum {
    NO_BUFF,
    ATT_INC,
    ATT_DEC,
    DEF_INC,
    DEF_DEC,
    HP_INC,
    HP_DEC,
    AGI_INC,
    AGI_DEC,
    STR_INC,
    STR_DEC,
    DEX_INC,
    DEX_DEC,
    INT_INC,
    INT_DEC,
    LUCK_INC,
    LUCK_DEC,
    // Add more buffs and debuffs as needed
} TypeOfBuff;

typedef struct {
    TypeOfBuff effect;
    int duration;
    int valueType; // 0 for direct value change, 1 for percentage change
    int type;      //ACTIVE(0) OR PASSIVE(1)
    int value;
} BUFF;

typedef enum
{
    COMMON,
    UNCOMMON,
    RARE,
    UNIQUE,
    LEGENDARY,
    MYTHICAL,
// ADD MORE AS NEEDED
}Grade;

typedef struct 
{
    char *name;  //Use strdup
    char *description;
    int durability;
    Grade grade;
    BUFF buff;
    Itemtype type;
}Item;

typedef enum
{
    QUEST_LVL,
    QUEST_STATUS,
    RELATONSHIP,
}QuestManager;

typedef struct
{
    int xp;
    int gold;
    BUFF buff;
}Reward;





//From world.h

void printRules();

Player* gameInitializer(char *PlayerID);

void selectState(int *state);

void processState(Player *player,int *state);




//From player.h

// Function to create a new player
Player *createNewPlayer(char *playerID);

void savePlayerData(Player *player);

Player *loadPlayerData(char *playerID);

int playMinigame(Player *player,char *gameName);




//From characters.h

int getNpcNumber();




//From item.h

// Function prototypes

// void createItem(Item *item,const char name[],const char desc[],Grade grade,Itemtype itemtype,TypeOfBuff effect,int duration,int valueType,int type,int value);
// void modifyItem(Item *item,const char name[],const char desc[],Grade grade,Itemtype itemtype,TypeOfBuff effect,int duration,int valueType,int type,int value);

// void inspectItem(Item item);//generates item data
// void useItem(Player *player,Item *item);
// void destroyItem(Item *item);

// void serializeItem(Item item, FILE *file);
// void deserializeItem(Item *item, FILE *file);





//From locations.h

void navigationMode(Player *player,int *state);




//From quest.h

void questMode(Player *player,int *state);




//From story.h


#endif