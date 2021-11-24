/**********************************************************************************
// BasicAI (Código Fonte)
// 
// Criação:     23 Out 2012
// Atualização: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Demonstração de todas as IAs

//
**********************************************************************************/

#include "Resources.h"
#include "BasicAI.h"
#include "Engine.h"    
#include "Delay.h"
#include "Game_over.h"
#include "Tela_inicial.h"

// ------------------------------------------------------------------------------

Player * BasicAI::player  = nullptr;
Audio  * BasicAI::audio   = nullptr;
Scene  * BasicAI::scene   = nullptr;
bool     BasicAI::viewHUD = false;
Image  * BasicAI::blue    = nullptr;
Image  * BasicAI::green   = nullptr;
Image  * BasicAI::magenta = nullptr;
Image  * BasicAI::orange  = nullptr;
Image  * BasicAI::white = nullptr;

// ------------------------------------------------------------------------------

void BasicAI::Init() 
{
    // cria sistema de áudio
    audio = new Audio();
   
    audio->Add(START, "Resources/Start.wav");
    audio->Add(THEME, "Resources/Theme.wav");
    audio->Add(FIRE, "Resources/Fire.wav", 2);
    audio->Add(HITWALL, "Resources/Hitwall.wav", 5);
    audio->Add(EXPLODE, "Resources/Explode.wav", 3);
    audio->Add(ORANGE, "Resources/Orange.wav", 1);
    audio->Add(MAGENTA, "Resources/Magenta.wav", 2);
    audio->Add(BLUE, "Resources/Blue.wav", 2);
    audio->Add(GREEN, "Resources/Green.wav", 2);

    // ajusta volumes
    audio->Volume(START, 0.20f);
    audio->Volume(THEME, 1.0f);
    audio->Volume(FIRE, 0.1f);
    audio->Volume(EXPLODE, 0.1f);
    audio->Volume(ORANGE, 0.50f);
    audio->Volume(MAGENTA, 0.50f);
    audio->Volume(BLUE, 0.50f);
    audio->Volume(GREEN, 0.5f);
    

    // carrega imagens das geometrias
    blue    = new Image("Resources/quad.png");
    green   = new Image("Resources/circle.png");
    magenta = new Image("Resources/triangle.png");
    orange  = new Image("Resources/x.png");
    white = new Image("Resources/white.png");
   
    // carrega/incializa objetos
    backg   = new Background("Resources/earth.jpg");
    player  = new Player();
    scene   = new Scene();  
    hud     = new Hud();

    // adiciona objetos na cena
    scene->Add(player, MOVING);
    scene->Add(new Delay(), STATIC);
    
    // ----------------------
    // inicializa a viewport
    // ----------------------

    // calcula posição para manter viewport centralizada
    float difx = (game->Width() - window->Width()) / 2.0f;
    float dify = (game->Height() - window->Height()) / 2.0f;

    // inicializa viewport para o centro do mundo
    viewport.left = 0.0f + difx;
    viewport.right = viewport.left + window->Width();
    viewport.top = 0.0f + dify;
    viewport.bottom = viewport.top + window->Height();
}

// ------------------------------------------------------------------------------

void BasicAI::Update()
{
   
    
    // sai com o pressionamento da tecla ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza cena e calcula colisões
    scene->Update();
    scene->CollisionDetection();

    // ---------------------------------------------------
    // atualiza a viewport
    // ---------------------------------------------------

    viewport.left   = player->X() - window->CenterX();
    viewport.right  = player->X() + window->CenterX();
    viewport.top    = player->Y() - window->CenterY();
    viewport.bottom = player->Y() + window->CenterY();
            
    if (viewport.left < 0)
    {
        viewport.left  = 0;
        viewport.right = window->Width();
    }
    else if (viewport.right > game->Width())
    {  
        viewport.left  = game->Width() - window->Width();
         viewport.right = game->Width();
    }
                  
    if (viewport.top < 0)
    {
        viewport.top  = 0;
        viewport.bottom = window->Height();
    }
    else if (viewport.bottom > game->Height())
    {
        viewport.top = game->Height() - window->Height();
        viewport.bottom = game->Height();
    }

    // ---------------------------------------------------

    // atualiza o painel de informações
    hud->Update();

    // ativa ou desativa a bounding box
    if (window->KeyPress('B'))
        viewBBox = !viewBBox;

    // ativa ou desativa o heads up display
    if (window->KeyPress('H'))
        viewHUD = !viewHUD;

    /*
    if (window->KeyDown('P'))
    {

        audio->Stop(START);
        audio->Stop(THEME);
        audio->Stop(FIRE);
        audio->Stop(EXPLODE);
        audio->Stop(ORANGE);
        audio->Stop(MAGENTA);
        audio->Stop(BLUE);
        audio->Stop(GREEN);

        Engine::Next<Game_over>();
    }
    */

} 

// ------------------------------------------------------------------------------

void BasicAI::Draw()
{
    // desenha pano de fundo
    backg->Draw(viewport);

    // desenha a cena
    scene->Draw();

    // desenha o painel de informações
    if (viewHUD)
        hud->Draw();

    // desenha bounding box
    //if (viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void BasicAI::Finalize()
{
    
    delete hud;
    delete scene;
    delete backg;

    delete blue;
    delete green;
    delete magenta;
    delete orange;
    delete white;
    
    
    delete audio;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
                     _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    // cria motor do jogo
    Engine * engine = new Engine();

    // configura janela
    //engine->window->Mode(WINDOWED);
    //engine->window->Size(2200, 1464);
    engine->window->Mode(BORDERLESS);
    engine->window->Color(0, 0, 0);
    engine->window->Title("Flatland Attack");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    engine->window->HideCursor(true);
    //engine->graphics->VSync(true);

    // cria o jogo
    //Game * game = new BasicAI();
    Game * game = new  BasicAI();


    // configura o jogo
    game->Size(2200, 1464);
    
    // inicia execução
    int status = engine->Start(game);

    // destrói motor 
    delete engine;

    // encerra
    return status;
}

// ----------------------------------------------------------------------------