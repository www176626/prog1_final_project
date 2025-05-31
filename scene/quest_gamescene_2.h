#ifndef questGame2_H_INCLUDED
#define questGame2_H_INCLUDED
#include "scene.h"

/*
   [game scene object]
*/
typedef enum QuestGame2Ele
{
    d2
} QuestGame2Ele;

typedef struct _questGame2
{
    ALLEGRO_BITMAP *background;

} questGame2;
Scene *New_questGame2(int label);
void questGame2_update(Scene *self);
void questGame2_draw(Scene *self);
void questGame2_destroy(Scene *self);

#endif
