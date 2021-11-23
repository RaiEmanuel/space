#include "Tela_inicial.h"
#include "BasicAI.h"
#include "Engine.h"
#include "Game_over.h"




void Tela_inicial::Init()
{
   

    background = new Sprite("Resources/tela_inicial.jpg");
    
}
// ------------------------------------------------------------------------------
void Tela_inicial::Update()
{
    // sai com o pressionamento do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    if (window->KeyPress('P')) {

        Engine::Next<BasicAI>();
    }

}
// ------------------------------------------------------------------------------
void Tela_inicial::Draw()
{
    background->Draw(window->CenterX(), window->CenterY(), Layer::FRONT);
}
// ------------------------------------------------------------------------------
void Tela_inicial::Finalize()
{


    delete background;
   
}
// ----------------------------------------------------------------------------