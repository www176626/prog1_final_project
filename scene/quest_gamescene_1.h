#ifndef questGame1_H_INCLUDED
#define questGame1_H_INCLUDED
#include "scene.h"

/*
   [game scene object]
*/
typedef enum QuestGame1Ele
{
    d1
} QuestGame1Ele;

typedef struct _questGame1
{
    ALLEGRO_BITMAP *background;

} questGame1;
Scene *New_questGame1(int label);
void questGame1_update(Scene *self);
void questGame1_draw(Scene *self);
void questGame1_destroy(Scene *self);

#endif
