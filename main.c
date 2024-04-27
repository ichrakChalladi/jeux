#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#include "Personne.h"

int main()
{
    //-------------partie declaration des variables ------------//
SDL_Surface *screen;
SDL_Event event;
SDL_Surface *back;
Personne p;
Uint32 dt, t_prev;//t_prev :temps de debut d boucle
//dt = temps actuel - t_prev
int continuer=1,up=0,die=0;//etat d jump


//-------------inittialisations----------------//
screen=SDL_SetVideoMode (1000,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_Init(SDL_INIT_VIDEO);
SDL_WM_SetCaption("personnage\t1",NULL);//titre de la fenetre
back=IMG_Load("back.png");
initPerso(&p);


SDL_EnableKeyRepeat(20,20);
while (continuer)
{
    t_prev = SDL_GetTicks();
    //--------- gestion de linput-----------//
    while(SDL_PollEvent(&event))
{
    switch (event.type)
    {
    case SDL_QUIT:
        continuer=0;
        break;

    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                p.direction=2;
                p.vitesse=3;
                p.acceleration+= 0.002;                
                break;
            case SDLK_LEFT:
                p.acceleration+=0.002;
                p.vitesse=3;
                p.direction=3;                
                break;
            case SDLK_UP:
                up=1;
                break;
            case SDLK_a:
                if ((p.direction==0)||(p.direction==2))
                {
                    p.direction=4;
                }
                if ((p.direction==1)||(p.direction==3))
                {
                    p.direction=5;
                }
                break;
            case SDLK_d:
                if ((p.direction==0)||(p.direction==2))
                {
                    p.direction=8;
                }
                if ((p.direction==1)||(p.direction==3))
                {
                    p.direction=9;
                }
                break;
                
            case SDLK_z:
                if ((p.direction==0)||(p.direction==2))
                {
                    p.direction=10;
                }
                if ((p.direction==1)||(p.direction==3))
                {
                    p.direction=11;
                } 
                break;  
            case SDLK_q:
                if ((p.direction==0)||(p.direction==2))
                {
                    p.direction=6;
                }
                if ((p.direction==1)||(p.direction==3))
                {
                    p.direction=7;
                } 
                die=1;
                continuer=0;
                break;      
                    
        }
    break;

    case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
            case SDLK_RIGHT:
                p.direction=0;
                p.acceleration=0;
                p.vitesse=0;
                break;
            case SDLK_LEFT:
                p.direction=1;
                p.acceleration=0;
                p.vitesse=0;
                break;
            case SDLK_UP:
                up=0;
                break;
            default:
            if (p.direction % 2 == 0) p.direction=0;
            else p.direction = 1; 
            break;           
        }
    break;
    
    }
}//fin de linput
    
//-----------update--------------//
animerPerso(&p);
deplacerPerso(&p,dt);

if ((up==1)&&(p.position.y==200))  saut(&p);

p.position.y += p.Yspeed;
p.Yspeed += 10; //diminiuer le vitesse vertical

if (p.position.y>=200)
{
    p.position.y = 200;
    p.Yspeed = 0;
}






//-----------affichage----------------//


    SDL_BlitSurface(back,NULL,screen,NULL);
    afficherPerso(p,screen);
    SDL_Flip(screen);
       dt = SDL_GetTicks() - t_prev;
    SDL_Delay(50);
}





if (die==1)
{
for ( p.frame = 0; p.frame < 12; p.frame++)
{
    SDL_BlitSurface(back,NULL,screen,NULL);
    afficherPerso(p,screen);
    SDL_Flip(screen);
    SDL_Delay(50);

}
SDL_Delay(400);
}


}