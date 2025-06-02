#include <allegro5/allegro_audio.h>
#include "gamescene.h"
#include "../element/element.h"
#include "../element/charater.h"
#include "../element/floor.h"
#include "../element/teleport.h"
#include "../element/questNode.h"
#include "../element/projectile.h"
#include "../element/button.h"
#include "sceneManager.h"
/*
   [GameScene function]
*/
Scene *New_gamescene(int label)
{
    GameScene *pDerivedObj = (GameScene *)malloc(sizeof(GameScene));
    Scene *pObj = New_Scene(label);
    // setting derived object member
    pDerivedObj->background = al_load_bitmap("assets/image/map.png");
    pObj->pDerivedObj = pDerivedObj;
    // register element
    
    _Register_elements(pObj, New_questNode(questNode1_L, 0, 250, quest_menu_1_L));
    _Register_elements(pObj, New_questNode(questNode1_L, 250, 50, quest_menu_2_L));
    _Register_elements(pObj, New_questNode(questNode1_L, 500, 150, quest_menu_3_L));
    _Register_elements(pObj, New_questNode(questNode1_L, 700, 380, quest_menu_4_L));
    

    _Register_elements(pObj, New_Character(Character_L));
    

    // setting derived object function
    pObj->Update = gamescene_update;
    pObj->Draw = gamescene_draw;
    pObj->Destroy = gamescene_destroy;
    return pObj;
}
void gamescene_update(Scene *self)
{
    // update every element
    ElementVec allEle = _Get_all_elements(self);
    for (int i = 0; i < allEle.len; i++)
    {
        Elements *ele = allEle.arr[i];
        ele->Update(ele);
    }
    // run interact for every element
    for (int i = 0; i < allEle.len; i++)
    {
        Elements *ele = allEle.arr[i];
        ele->Interact(ele);
    }
    // remove element
    for (int i = 0; i < allEle.len; i++)
    {
        Elements *ele = allEle.arr[i];
        if (ele->dele)
            _Remove_elements(self, ele);
    }
}
void gamescene_draw(Scene *self)
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
    GameScene *gs = ((GameScene *)(self->pDerivedObj));
    al_draw_bitmap(gs->background, 0, 0, 0);
    ElementVec allEle = _Get_all_elements(self);
    for (int i = 0; i < allEle.len; i++)
    {
        Elements *ele = allEle.arr[i];
        ele->Draw(ele);
    }
}
void gamescene_destroy(Scene *self)
{
    GameScene *Obj = ((GameScene *)(self->pDerivedObj));
    ALLEGRO_BITMAP *background = Obj->background;
    al_destroy_bitmap(background);
    ElementVec allEle = _Get_all_elements(self);
    for (int i = 0; i < allEle.len; i++)
    {
        Elements *ele = allEle.arr[i];
        ele->Destroy(ele);
    }
    free(Obj);
    free(self);
}
