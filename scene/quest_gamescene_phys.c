#include <allegro5/allegro_audio.h>
#include "quest_gamescene_phys.h"
#include "../element/element.h"
#include "../element/characterNewton.h"
#include "../element/floor.h"
#include "../element/apple.h"
#include "../element/button.h"
#include <stdlib.h>
/*
   [questGamePhys function]
*/
Scene *New_questGamePhys(int label)
{
    questGamePhys *pDerivedObj = (questGamePhys *)malloc(sizeof(questGamePhys));
    Scene *pObj = New_Scene(label);
    // setting derived object member
    pDerivedObj->background = al_load_bitmap("assets/image/stage.jpg");
    pObj->pDerivedObj = pDerivedObj;

    // register element
    _Register_elements(pObj, New_CharacterNewton(CharacterNewton_L));
    

    // setting derived object function
    pObj->Update = questGamePhys_update;
    pObj->Draw = questGamePhys_draw;
    pObj->Destroy = questGamePhys_destroy;
    return pObj;
}
void questGamePhys_update(Scene *self)
{
    //add apple 
    double apple_time = al_get_timer_count(apple_timer);
    bool add = (100-apple_time)<=0; //time count:FPS
    // printf("apple_timer: %lf", apple_time);
    if(add){
        addApple(self);
        al_set_timer_count(apple_timer, 0);
    }

    
    

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
void questGamePhys_draw(Scene *self)
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
    questGamePhys *gs = ((questGamePhys *)(self->pDerivedObj));
    al_draw_bitmap(gs->background, 0, 0, 0);
    ElementVec allEle = _Get_all_elements(self);
    for (int i = 0; i < allEle.len; i++)
    {
        Elements *ele = allEle.arr[i];
        ele->Draw(ele);
    }
}
void questGamePhys_destroy(Scene *self)
{
    questGamePhys *Obj = ((questGamePhys *)(self->pDerivedObj));
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

void addApple(Scene* self){
    int type_of_apple = rand()%2;
    int pos_x = 150+rand()%(WIDTH-150);
    int pos_y = -100;
    _Register_elements(self, New_apple(type_of_apple, pos_x, pos_y, 3));
}
