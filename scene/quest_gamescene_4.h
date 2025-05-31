#ifndef questGame4_H_INCLUDED
#define questGame4_H_INCLUDED
#include "scene.h"

/*
   [game scene object]
*/
typedef enum QuestGame4Ele
{
    d4
} QuestGame4Ele;

typedef struct _questGame4
{
    ALLEGRO_BITMAP *background;

} questGame4;
Scene *New_questGame4(int label);
void questGame4_update(Scene *self);
void questGame4_draw(Scene *self);
void questGame4_destroy(Scene *self);

#endif
