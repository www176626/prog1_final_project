#ifndef Button_H_INCLUDED
#define Button_H_INCLUDED
#include "../shapes/Shape.h"
#include "../element/element.h"

typedef struct button{
    int x;
    int y;
    int width, height;
    int change_scene;
    ALLEGRO_BITMAP *img;
    Shape *hitbox;
}button;

Elements *New_button(int label, int x, int y, ALLEGRO_BITMAP *img, int change_scene);
void button_update(Elements *self);
void button_interact(Elements *self);
void button_destroy(Elements *self);
void button_draw(Elements *self);
// bool mouse_clicked(Rectangle* rec);



#endif