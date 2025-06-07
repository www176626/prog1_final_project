#include "sceneManager.h"
#include "menu.h"
#include "gamescene.h"
#include "quest_gamescene_phys.h"
#include "quest_gamescene_2.h"
#include "quest_gamescene_3.h"
#include "quest_gamescene_lake.h"
#include "quest_menu.h"

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
    case quest_menu_phys_L:
        scene = New_quest_menu(quest_menu_phys_L);
        break;
    case quest_menu_2_L:
        scene = New_quest_menu(quest_menu_2_L);
        break;
    case quest_menu_3_L:
        scene = New_quest_menu(quest_menu_3_L);
        break;
    case quest_menu_lake_L:
        scene = New_quest_menu(quest_menu_lake_L);
        break;
    case quest_gameScene_phys_L:
        scene = New_questGamePhys(quest_gameScene_phys_L);
        break;
    case quest_gameScene_2_L:
        scene = New_questGame2(quest_gameScene_2_L);
        break;
    case quest_gameScene_3_L:
        scene = New_questGame3(quest_gameScene_3_L);
        break;
    case quest_gameScene_lake_L:
        scene = New_questGameLake(quest_gameScene_lake_L);
        break;
    
    
    default:
        break;
    }
}
