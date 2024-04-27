#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct Personne
{

SDL_Rect position;
SDL_Surface *tab_imgs[12][12];
/*
les directions :
0,1:repos
2,3:walking
4,5:attack
6,7:dying
8,9: hurt
10,11:spells
*/
int direction, Yspeed,frame;
double vitesse , acceleration;

}Personne;


void initPerso(Personne *p);
void afficherPerso(Personne p, SDL_Surface * screen);
void deplacerPerso (Personne *p, int dt);
void animerPerso (Personne* p);
void saut (Personne* p) ;



#endif
