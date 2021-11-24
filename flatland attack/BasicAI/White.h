/**********************************************************************************
// White (Arquivo de Cabeçalho)
// 
// Criação:     10 Out 2012
// Atualização: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Objeto faz um perseguição direta
//
**********************************************************************************/

#ifndef _BASICAI_WHITE_H_
#define _BASICAI_WHITE_H_

// ---------------------------------------------------------------------------------

#include "Object.h"    
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

class White : public Object
{
private:
    Sprite * sprite;                            // sprite do objeto
    Player * player;                            // ponteiro para jogador
    Vector speed;                               // velocidade e direção
    
public:
    White(float pX, float pY, Player * p);    // construtor
    ~White();                                 // destrutor
    
    void OnCollision(Object * obj);             // resolução da colisão
    void Update();                              // atualização
    void Draw();                                // desenho
}; 

// ---------------------------------------------------------------------------------

inline void White::Draw()
{ sprite->Draw(x, y, Layer::LOWER, scale, rotation); }

// ---------------------------------------------------------------------------------


#endif