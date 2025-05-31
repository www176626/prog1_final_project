#include "button.h"
#include "../shapes/Rectangle.h"
#include "../scene/sceneManager.h"
#include "../scene/quest_menu_1.h"
#include "../shapes/Shape.h"
#include "../shapes/Point.h"


Elements *New_button(int label, int x, int y, ALLEGRO_BITMAP *img, int change_scene){
    button *pDerivedObj = (button*)malloc(sizeof(button));
    Elements* pobj = New_Elements(label);
    
    pDerivedObj->x=x;
    pDerivedObj->y=y;
    pDerivedObj->img=img;
    pDerivedObj->change_scene=change_scene;
    pDerivedObj->width = al_get_bitmap_width(img);
    pDerivedObj->height = al_get_bitmap_height(img);
    pDerivedObj->hitbox = New_Rectangle(pDerivedObj->x + pDerivedObj->width / 3,
                                        pDerivedObj->y + pDerivedObj->height / 3,
                                        pDerivedObj->x + 2 * pDerivedObj->width / 3,
                                        pDerivedObj->y + 2 * pDerivedObj->height / 3);

    pobj->pDerivedObj=pDerivedObj;
    pobj->Update=button_update;
    pobj->Interact=button_interact;
    pobj->Draw=button_draw;
    pobj->Destroy=button_destroy;

    return pobj;
}

// bool mouse_clicked(double x1, double y1, double x2, double y2){
//     if(mouse.x>=rec->x1 && mouse.x<=rec->x2
//     && mouse.y>=rec->y1 && mouse.y<=rec->y2
//     && event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
//         return true;
//     }
//     return false;
// }

void button_update(Elements *self){
    
    button *obj = (button*)self->pDerivedObj;
    // printf("%d", obj->hitbox->overlap(New_Rectangle(mouse.x-1, mouse.y-1, mouse.x+1, mouse.y+1), obj->hitbox));
    ALLEGRO_MOUSE_STATE state;
    al_get_mouse_state(&state);
    if(obj->hitbox->overlap(New_Point(mouse.x, mouse.y), obj->hitbox) && (state.buttons & 1)){
        scene->scene_end=true;
        window=obj->change_scene;
    }
    
}

void button_interact(Elements *self){

    
}


void button_draw(Elements *self){

    button *obj = (button*)self->pDerivedObj;
    al_draw_bitmap(obj->img, obj->x, obj->y, 0);
}

void button_destroy(Elements *self){
    button *obj=(button*)self->pDerivedObj;
    al_destroy_bitmap(obj->img);
    free(obj->hitbox);
    free(obj);
    free(self);
}
