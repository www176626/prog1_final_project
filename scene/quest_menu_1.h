#ifndef QUEST_MENU_1_H_INCLUDED
#define QUEST_MENU_1_H_INCLUDED
#include "scene.h"

/*
   [game scene object]
*/
typedef enum q1Eletype
{
    StartButton_L
} q1Eletype;

typedef struct _quest_1_menu
{
    ALLEGRO_BITMAP *background;

} quest_1_menu;
Scene *New_quest_1_menu(int label);
void quest_1_menu_update(Scene *self);
void quest_1_menu_draw(Scene *self);
void quest_1_menu_destroy(Scene *self);

#endif
