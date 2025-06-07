#ifndef questGamePhys_H_INCLUDED
#define questGamePhys_H_INCLUDED
#include "scene.h"

/*
   [game scene object]
*/
typedef enum QuestGamePhysEle
{
    AppleRight_L=0,
    AppleWrong_L=1,
    CharacterNewton_L
} QuestGamePhysEle;

typedef struct _questGamePhys
{
    ALLEGRO_BITMAP *background;

} questGamePhys;
Scene *New_questGamePhys(int label);
void questGamePhys_update(Scene *self);
void questGamePhys_draw(Scene *self);
void questGamePhys_destroy(Scene *self);
void addApple(Scene* self);
extern int score_of_phys_quest;


#endif
