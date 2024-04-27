#include "Personne.h"

void initPerso(Personne *p){
    char chemin_image[30];
    int i,j;

    p->direction=0;
    p->frame=0;
    p->vitesse=0;
    p->acceleration=0;
    p->Yspeed=0;
    p->position.x=40;
    p->position.y=200;

    for ( i = 0; i < 12; i++)
    {
        for ( j = 0; j < 12; j++)
        {
            sprintf(chemin_image,"animation/%d/%d.png",i,j);
            p->tab_imgs[i][j]=IMG_Load(chemin_image);
        }
        
    }
    
}


void afficherPerso(Personne p, SDL_Surface * screen){
    SDL_BlitSurface(p.tab_imgs[p.direction][p.frame],NULL,screen,&p.position);
}


void animerPerso (Personne* p){
    p->frame++;
    if (p->frame>=12) p->frame=0;   
}



void deplacerPerso (Personne *p, int dt){
    double dx;
    dx= 0.5 * dt *dt *p->acceleration + p->vitesse * dt ;
    if (p->direction==2) p->position.x += dx;
    if (p->direction==3) p->position.x -= dx;
}


void saut (Personne* p) {
    p->Yspeed= -60;
}