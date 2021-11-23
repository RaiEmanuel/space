/**********************************************************************************
// Blue (Arquivo de Cabe�alho)
// 
// Cria��o:     10 Out 2012
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto faz uma persegui��o suavizada
//
**********************************************************************************/

#ifndef _BASICAI_BLUE_H_
#define _BASICAI_BLUE_H_

// ---------------------------------------------------------------------------------

#include "Object.h"    
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

class Blue : public Object
{
private:
    Sprite * sprite;                            // sprite do objeto
    Player * player;                            // ponteiro para jogador
    Vector speed;                               // velocidade e dire��o
    float factor;                               // fator de escala
    const uint tiros_inimigo_especial = 5;      // quantidade maxima de tiros do inimigo especial
    uint tiros_tomados = 0;
    bool inimigo_especial = false;
    uint mudan�as_de_cor = 0;
public:
    Blue(float pX, float pY, Player * p);       // construtor
    ~Blue();                                    // destrutor
    
    void OnCollision(Object* obj);              // resolu��o da colis�o
    void Update();                              // atualiza��o
    void Draw();                                // desenho
}; 

// ---------------------------------------------------------------------------------

inline void Blue::Draw()
{ sprite->Draw(x, y, Layer::LOWER, scale, rotation); }


// ---------------------------------------------------------------------------------


#endif