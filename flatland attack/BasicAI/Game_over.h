#ifndef _GAME_OVER_H_
#define _GAME_OVER_H_

#include "Game.h"
#include "Audio.h"
#include "Scene.h"
#include "Background.h"
#include "Player.h"
#include "Hud.h"

// ------------------------------------------------------------------------------
//enum Musics { GAMEOVERVOICE, GAMEOVERTHEME };//continuar
// ------------------------------------------------------------------------------
class Game_over : public Game
{
public:
    

    void Init();                        // inicializa��o
    void Update();                      // atualiza��o
    void Draw();                        // desenho
    void Finalize();                    // finaliza��o
    
private:
    Sprite* background = nullptr;    
};



#endif