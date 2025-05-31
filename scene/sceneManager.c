#include "sceneManager.h"
#include "menu.h"
#include "gamescene.h"
#include "quest_gamescene_1.h"
#include "quest_gamescene_2.h"
#include "quest_gamescene_3.h"
#include "quest_gamescene_4.h"
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
    case quest_menu_2_L:
        scene = New_quest_1_menu(quest_menu_2_L);
        break;
    case quest_menu_3_L:
        scene = New_quest_1_menu(quest_menu_3_L);
        break;
    case quest_menu_4_L:
        scene = New_quest_1_menu(quest_menu_4_L);
        break;
    case quest_gameScene_1_L:
        scene = New_questGame1(quest_gameScene_1_L);
        break;
    case quest_gameScene_2_L:
        scene = New_questGame2(quest_gameScene_2_L);
        break;
    case quest_gameScene_3_L:
        scene = New_questGame3(quest_gameScene_3_L);
        break;
    case quest_gameScene_4_L:
        scene = New_questGame4(quest_gameScene_4_L);
        break;
    
    
    default:
        break;
    }
}
