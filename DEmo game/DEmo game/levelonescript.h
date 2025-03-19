#ifndef LEVELONESCRIPT_H
#define LEVELONESCRIPT_H
#include <iostream>
using namespace std;
#include "levelone.h"
#include "MC.h"
#include "GameObject.h"
#include "apple.h"
#include "CollisionDetector.h"
#include <vector>


int life =1;
int gamephase=0;
bool boxcollider=false,crposcheck=false;
string bganimname;
int dir=1;

int resWidth=1000;
int resHeight=800;
int tempo;

bool appleinidet=true;
bool lvl2appleinidet=true;

int applecounter=0;

 
int k=0,l=2,m=4,aboutindex=6,settingindex=4,exitindex=6,newgamemenuindex=8,continuemenuindex=10,settingmenuindex=12,exitmenuindex=14,bgindex=1,moveindex=0,jump=0;

int posx;
int posy=50;


int tempposx;
int tempposy;

bool lvl1complete=false;
bool musicController=true;
bool hovermusiccontroller = true;
bool passivemainmusicon =true;
bool jumpdec=false,jumpdec0=false;
int  movementdetector;
int bulletindex=0;
bool losemenu=false;



//bool boxcollider=false,crposcheck=false;
bool dec;
int temp;
bool hitdec=false;


int subgamephase=0;
bool eatk =false;
vector<apple> apples;
vector<apple> lvl2apples;

void initializelvl2Apples() {
    // Define specific positions for level 2 apples
    int positionsX[] = {100, 150, 200, 250, 300, 350, 400, 450, 500, 550, 600, 650, 700, 750};
    int positionsY[] = {250, 250, 300, 300, 350, 350, 400, 400, 450, 450, 500, 500, 550, 550};

    lvl2apples.clear();

    for (int i = 0; i < 14; i++) {
        lvl2apples.push_back(apple(positionsX[i], positionsY[i], 20, 20));
    }
}

void showAlllvl2Apples() {
    for (int i = 0; i < lvl2apples.size(); i++) {
        lvl2apples[i].showapple();
    }
}

void lvl2AppleCount() {
    for (int i = 0; i < lvl2apples.size(); i++) {
        if (c1.collider(p2collcheck, lvl2apples[i])) {
            if (lvl2apples[i].active) {
                applecounter++;
            }
            lvl2apples[i].active = false;
        }
    }
}



void initializeApples() {
    // Define specific positions for apples using separate arrays
    int positionsX[] = {200,250, 300,350,400, 450, 500,550,600,650,700,750,820,850};
    int positionsY[] = {180, 180, 180, 200,230,240,200,400,400,300,300,300,650,650};

  
    apples.clear();
    
   
    for (int i = 0; i < 14; i++) {
		
        apples.push_back(apple(positionsX[i], positionsY[i], 20, 20));
    }
}

void showAllApples() {
    for (int i = 0; i < apples.size(); i++) {
        apples[i].showapple();
    }
}


void applecount(){

	for(int i=0;i<apples.size();i++){
		if(c1.collider(p1collcheck,apples[i])){
			if(apples[i].active){
			applecounter++;
			}
			apples[i].active=false;

		}

	}
}

void lvl1initialize(){
			p1collcheck.pos_x=150;
		 p1collcheck.pos_y=140;
		 p1.pos_x=120;
		 p1.pos_y=140;
		 p1botline.pos_x=150;
		 p1botline.pos_y=150;
		 crate.pos_x=70;
		 crate.pos_y=250;
		 crtopline.pos_x=70;
		 crtopline.pos_y=300;
			 
}


void lvl1fullinitialize(){
	lvl1initialize();
	appleinidet=true;
	h1.hactive=true;
	h2.hactive=true;
	h3.hactive=true;
	applecounter=0;
}

void drawText() {

	app.showapple();
    char scoreText[20];
	
    sprintf(scoreText, ": %d",  applecounter);
    iText(120, 630, scoreText, GLUT_BITMAP_TIMES_ROMAN_24);
}


void showcompletemenu(){
			 iShowImage(150,125, 700,450,settingMenuShower[1]);
			iShowImage(190,185, 600,350,settingMenuShower[2]);
			iShowImage(150,550,700,150,settingMenuShower[25]);
			iShowImage(350,350,50,50,settingMenuShower[28]);
			iShowImage(450,350,50,50,settingMenuShower[18]);
			iShowImage(550,350,50,50,settingMenuShower[27]);
}

void showlosemenu(){
			iShowImage(150,125, 700,450,settingMenuShower[1]);
			iShowImage(190,185, 600,350,settingMenuShower[2]);
			iShowImage(150,550,700,150,settingMenuShower[17]);
			iShowImage(450,350,50,50,settingMenuShower[18]);
			
}
void script(){
	{	
	
		tileShower();
		
		//p1.forcegravitation();
		//p1collcheck.forcegravitation();


		//p1botline.forcegravitation();

		if(!p1.cjumpdec){
		p1.forcegravitation();
		p1collcheck.forcegravitation();
		p1botline.forcegravitation();
		}
		
		airplat2.airplatshowimage();
		


			
			crate.objgravitation();
			boat.objgravitation1();

			crtopline.objgravitation();
		crate.showimage();
		airplat.airplatshowimage();
		airplat1.airplatshowimage();
		boat.showimage();
		enemy.showimage();
		//enemy.enemymovement();
		/*airplat.pseudoimage();
		crtopline.pseudoimage();
		obj.pseudoimage();
		obj1.pseudoimage();
		groundverline.pseudoimage();
		water.pseudoimage();
		//crate.pseudoimage();
		ground.pseudoimage();
		 //p1collcheck.pseudoimage();

		platline.pseudoimage();
		platline1.pseudoimage();
		p1botline.pseudoimage();
		platline2.pseudoimage();
		rockverline.pseudoimage();

		upground.pseudoimage();*/
		if(appleinidet){
		initializeApples();
		appleinidet=false;
		}

		showAllApples();
		//app.showapple();
		
		//boat.pseudoimage();
		// p1.pseudoimage();
		p1.charecterIdle();
	p1.charecterRun();
	//p1.charecterjump();
	 p1. advcharecterjump();

	airplat.platmovement();
	airplat1.platmovement1();
	airplat2.platmovement2();
	h1.showheart();
	h2.showheart();
	h3.showheart();
	applecount();
	drawText();

	/*iShowImage(50,700,50,50,levelImageShower[22]);
	iShowImage(50,700,50,50,levelImageShower[23]);
	iShowImage(100,700,50,50,levelImageShower[22]);
	iShowImage(100,700,50,50,levelImageShower[23]);
	iShowImage(150,700,50,50,levelImageShower[22]);
	iShowImage(150,700,50,50,levelImageShower[23]);*/
if (c1.collider(p1botline, ground) || c1.collider(p1botline, obj) || c1.collider(p1botline,obj1) || c1.collider(p1collcheck,crtopline)||c1.collider(p1botline,upground)) { 
    onground = true;  
	
} 


	else{
		onground=false;
		

	}

	if ( c1.collider(p1botline,platline) || c1.collider(p1botline,platline1)||c1.collider(p1botline,upground)||c1.collider(p1botline,platline2)) { 
		onground1=true;

		if(onground1){
			onground=true;
		
		
		}


	}

	else{
		onground1=false;
			
	}

	if(c1.collider(crate,obj) || c1.collider(crate,ground) ||c1.collider(crate,obj1) || c1.collider(crate,water)){
		ongroundobj=true;
		
	}

	else{
		ongroundobj =false;
	}

	if(c1.collider(upground,boat)){
		ongroundobj1=true;

	}

	else{
		ongroundobj1=false;
	}

	if(c1.collider(p1collcheck,crtopline)){
		if(crate.pos_x>=80 && crate.pos_x<200 ){
		crtopline.pos_x++;
		crate.pos_x++;
		}
	}
	
	if( c1.collider(crate,water)){
		crate.pos_x+=.009;
		crtopline.pos_x+=.009;
		if(crate.pos_x>=500){
			crate.pos_x=500;
			crtopline.pos_x=500;
		}
	}
	
	boxcollider = c2.collider(p1collcheck, crate);

	if(boxcollider && !posleftdetector){
		crate.pos_x+=3;
		crtopline.pos_x+=3;
		
	
	}

	if (boxcollider && posleftdetector){
		crate.pos_x-=3;
		crtopline.pos_x-=3;
	
	}

	}
	
      if(c1.collider(p1collcheck,groundverline)){
		   p1.pos_x=120;
		   p1collcheck.pos_x=150;
		   p1botline.pos_x=150;
	   }

	 if(c1.collider(crate,groundverline)){
		 crate.pos_x=150;
		 crtopline.pos_x=150;

	 }

	 

	
	 if(c1.collider(p1collcheck,enemy)){
		 p1.health-=10;

	 }

	 if(p1collcheck.pos_y<=0){
		 p1.life--;
		if(p1.life<=2){
			h3.hactive=false;
		}
		if(p1.life<=1){
			h2.hactive=false;
		}
		if(p1.life<=0){
			h1.hactive=false;
		}

		lvl1initialize();
		 
	 }
	

	 if(p1botline.pos_x>=800 && p1botline.pos_y>=650){
		 lvl1complete =true;

	 }


			if(lvl1complete){
				showcompletemenu();
			}
			
			
			cout<<lvl1complete<<endl;
			
	 

	 if(p1.life==0){
			losemenu=true;
	 }
		
			
			if(losemenu){
				showlosemenu();
			}

	 if(c1.collider(crate,rockverline)){
		 crate.pos_x=70;
		 crtopline.pos_x=70;
	 }

}

#endif
