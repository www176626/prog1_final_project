#include <allegro5/allegro_audio.h>
#include "quest_menu_1.h"
#include "../element/element.h"
#include "../element/charater.h"
#include "../element/floor.h"
#include "../element/teleport.h"
#include "../element/questNode.h"
#include "../element/projectile.h"
#include "../element/button.h"
#include "sceneManager.h"
/*
   [quest_1_menu function]
*/
Scene *New_quest_1_menu(int label)
{
    quest_1_menu *pDerivedObj = (quest_1_menu *)malloc(sizeof(quest_1_menu));
    Scene *pObj = New_Scene(label);
    // setting derived object member
    switch(label){
        case quest_menu_1_L:
            pDerivedObj->background = al_load_bitmap("assets/image/quest_1_menu.jpg");
            _Register_elements(pObj, New_button(StartButton_L, 180,250, al_load_bitmap("assets/image/start_button.png"), quest_gameScene_1_L));
            break;
        case quest_menu_2_L:
            pDerivedObj->background = al_load_bitmap("assets/image/quest_1_menu.jpg");
            _Register_elements(pObj, New_button(StartButton_L, 100,50, al_load_bitmap("assets/image/start_button.png"), quest_gameScene_2_L));
            break;
        case quest_menu_3_L:
            pDerivedObj->background = al_load_bitmap("assets/image/quest_1_menu.jpg");
            _Register_elements(pObj, New_button(StartButton_L, 100,50, al_load_bitmap("assets/image/start_button.png"), quest_gameScene_3_L));
            break;
        case quest_menu_4_L:
            pDerivedObj->background = al_load_bitmap("assets/image/quest_1_menu.jpg");
            _Register_elements(pObj, New_button(StartButton_L, 100,50, al_load_bitmap("assets/image/start_button.png"), quest_gameScene_4_L));
            break;
        default:
            printf("menu label out of range: %d\n", label);
            break;

    }
    
    pObj->pDerivedObj = pDerivedObj;
    
    // register element
    
    
    // setting derived object function
    pObj->Update = quest_1_menu_update;
    pObj->Draw = quest_1_menu_draw;
    pObj->Destroy = quest_1_menu_destroy;
    return pObj;
}
void quest_1_menu_update(Scene *self)
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
void quest_1_menu_draw(Scene *self)
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
    quest_1_menu *gs = ((quest_1_menu *)(self->pDerivedObj));
    al_draw_bitmap(gs->background, 0, 0, 0);
    ElementVec allEle = _Get_all_elements(self);
    for (int i = 0; i < allEle.len; i++)
    {
        Elements *ele = allEle.arr[i];
        ele->Draw(ele);
    }
}
void quest_1_menu_destroy(Scene *self)
{
    quest_1_menu *Obj = ((quest_1_menu *)(self->pDerivedObj));
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
