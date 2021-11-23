#ifndef _TELA_INICIAL_H_
#define _TELA_INICIAL_H_

#include "Game.h"
#include "Audio.h"
#include "Scene.h"
#include "Background.h"
#include "Player.h"
#include "Hud.h"


class Tela_inicial : public Game
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