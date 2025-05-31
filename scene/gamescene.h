#ifndef GAMESCENE_H_INCLUDED
#define GAMESCENE_H_INCLUDED
#include "scene.h"

/*
   [game scene object]
*/
typedef enum EleType
{
    Floor_L,
    Teleport_L,
    questNode_L,
    Character_L,
    Projectile_L,
    startButton_L
} EleType;

typedef struct _GameScene
{
    ALLEGRO_BITMAP *background;

} GameScene;
Scene *New_gamescene(int label);
void gamescene_update(Scene *self);
void gamescene_draw(Scene *self);
void gamescene_destroy(Scene *self);

#endif
