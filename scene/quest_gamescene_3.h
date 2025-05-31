#ifndef questGame3_H_INCLUDED
#define questGame3_H_INCLUDED
#include "scene.h"

/*
   [game scene object]
*/
typedef enum QuestGame3Ele
{
    d3
} QuestGame3Ele;

typedef struct _questGame3
{
    ALLEGRO_BITMAP *background;

} questGame3;
Scene *New_questGame3(int label);
void questGame3_update(Scene *self);
void questGame3_draw(Scene *self);
void questGame3_destroy(Scene *self);

#endif
