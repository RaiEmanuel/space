/**********************************************************************************
// WaveM (C�digo Fonte)
//
// Cria��o:     06 Ago 2019
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Cria uma onda de inimigos Magenta
//
**********************************************************************************/

#include "WaveW.h"
#include "BasicAI.h"
#include "White.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

WaveW::WaveW() : posX(50, window->Width()-50), posY(50, game->Height()-50), secs(2.0f, 4.0f)
{
    // posi��o dos inimigos
    pX = posX.Rand();
    pY = posY.Rand();

    // atraso para a pr�xima onda 
    delay = secs.Rand();
}

// ------------------------------------------------------------------------------

WaveW::~WaveW()
{

}

// -------------------------------------------------------------------------------

void WaveW::Update()
{
    // se passou o tempo de atraso
    if (timer.Elapsed(delay) && Hud::whites < 5)
    {
        // toca som de nova onda
        //BasicAI::audio->Play(MAGENTA);

        // adiciona novo inimigo
        BasicAI::scene->Add(new White(pX, pY, BasicAI::player), MOVING);

        // nova posi��o do inimigo
        pX = posX.Rand();
        pY = posY.Rand();

        // reinicia o timer
        timer.Start();
    }
}

// -------------------------------------------------------------------------------

void WaveW::Draw()
{
    
}

// -------------------------------------------------------------------------------
