#include "sceneManager.h"
#include "menu.h"
#include "gamescene.h"
#include "quest_menu_1.h"

Scene *scene = NULL;
void create_scene(SceneType type)
{
    switch (type)
    {
    case Menu_L:
        scene = New_Menu(Menu_L);
        break;
    case GameScene_L:
        scene = New_gamescene(GameScene_L);
        break;
    case quest_menu_1_L:
        scene = New_quest_1_menu(quest_menu_1_L);
        break;
    default:
        break;
    }
}
