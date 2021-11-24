/**********************************************************************************
// Magenta (Código Fonte)
// 
// Criação:     10 Out 2012
// Atualização: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Objeto faz um perseguição direta
//
**********************************************************************************/

#include "BasicAI.h"
#include "White.h"
#include "Random.h" 
#include "Hud.h"
#include "Explosion.h"

// ---------------------------------------------------------------------------------

White::White(float pX, float pY, Player * p)
{
    player = p;
    sprite = new Sprite(BasicAI::white);
    //BBox(new Circle(18.0f));

    Point vertex[6] =
    {
        Point(-20,0), Point(-15,20), Point(15,20), Point(20,0),Point(15,-20),Point(-15,-20)
    };

    BBox(new Poly(vertex, 6));
    
    speed.RotateTo(0);
    speed.ScaleTo(2.0f);
    
    MoveTo(pX, pY);
    type = WHITE;

    // incrementa contador
    ++Hud::whites;
}

// ---------------------------------------------------------------------------------

White::~White()
{
    delete sprite;

    // decrementa contador
    --Hud::whites;
}

// -------------------------------------------------------------------------------

void White::OnCollision(Object * obj)
{
    if (obj->Type() == MISSILE)
    {
        BasicAI::scene->Delete(obj, STATIC);
        BasicAI::scene->Delete(this, MOVING);
        BasicAI::scene->Add(new Explosion(x, y, 1,1,1,WHITE), STATIC);
        BasicAI::audio->Play(EXPLODE);
    }
}

// -------------------------------------------------------------------------------

void White::Update()
{
    // ajusta ângulo do vetor 
    speed.RotateTo(Line::Angle(Point(x, y), Point(player->X(), player->Y())));
    Rotate(200 * gameTime);

    // movimenta objeto pelo seu vetor velocidade
    Translate(speed.XComponent() * 60.0f * gameTime, -speed.YComponent() * 60.0f * gameTime);
}

// -------------------------------------------------------------------------------