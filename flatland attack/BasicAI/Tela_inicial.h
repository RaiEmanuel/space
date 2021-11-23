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
   

    void Init();                        // inicialização
    void Update();                      // atualização
    void Draw();                        // desenho
    void Finalize();                    // finalização


private:
    Sprite* background = nullptr;
};



#endif