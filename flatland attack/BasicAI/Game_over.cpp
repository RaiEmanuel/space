#include "Game_over.h"
#include "Tela_inicial.h"
#include "BasicAI.h"
#include "Engine.h"




void Game_over::Init()
{
    OutputDebugString("Chegou no init de gameover\n");

    
    background = new Sprite("Resources/game_over.jpg");
    OutputDebugString("saiu do init de gameover\n");
    
    
}
// ------------------------------------------------------------------------------
void Game_over::Update()
{
    // sai com o pressionamento do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    if (window->KeyPress('P')) {
        
        Engine::Next<Tela_inicial>();
    }

}
// ------------------------------------------------------------------------------
void Game_over::Draw()
{
    background->Draw(window->CenterX(), window->CenterY(), Layer::FRONT);
}
// ------------------------------------------------------------------------------
void Game_over::Finalize()
{
    
    delete background;
    
}
// ----------------------------------------------------------------------------