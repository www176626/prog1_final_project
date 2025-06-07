#ifndef questGame4_H_INCLUDED
#define questGame4_H_INCLUDED
#include "scene.h"

/*
   [game scene object]
*/
typedef enum QuestGameLakeEle
{
    d4
} QuestGameLakeEle;

typedef struct _questGame4
{
    ALLEGRO_BITMAP *background;

} questGameLake;
Scene *New_questGameLake(int label);
void questGameLake_update(Scene *self);
void questGamelake_draw(Scene *self);
void questGameLake_destroy(Scene *self);

#endif
