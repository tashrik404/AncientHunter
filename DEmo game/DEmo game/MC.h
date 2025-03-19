#ifndef MC_H

#define MC_H


#include<iostream>
#include<string>
#include"image.h"

using namespace std;

int  i;
int j;
bool posleftdetector;
int jumpindex=0;
int idleindex=0;
int shootindex=0;
bool jumpdetector=false;
bool idledetector=true;
bool inAir=false;
bool onground=true,onground1=true,onground2=true;
int  init_posy=0;
int init_posx=120;
int  counter=0;
//bool shootdec= false;
int deadindex=0;




class Mc {
public:
	int  pos_x;
	float pos_y;
	
	int width;
	int height;

	int health;
	int life;
	float healthbarwidth;
	bool active;
	int cinAir;
	bool cposleftdetector;
	bool cjumpdec;
	int cjumpindex;
	bool shootdec;



	//float heatlh;

	// int attack;

	 Mc(int pos_x,int pos_y,int width ,int height){
		 this ->pos_x= pos_x;

		 this ->pos_y = pos_y;
		 this -> width =width;
		 this ->height =height;
		 active =true;
		 health=100;
		 healthbarwidth=200;
		 life=3;
		 shootdec=false;

	 }


	 


	 void charecterIdle(){

		 if(idledetector && ( !cinAir)){
			 iShowImage(pos_x,pos_y,width,height,mcIdleAnimShower[idleindex]);

		 }


	 }
	  void lvl2charecterIdle(){

		 if(idledetector && ( !inAir)){
			 iShowImage(pos_x,pos_y,width,height,mcIdleAnimShower[idleindex]);

		 }


	 }

	 void charecterRun(){

		
		if(( !cinAir) && !idledetector){ 	
	if(posleftdetector==false){
	iShowImage(pos_x,pos_y,width,height,mcAnimShower[i]);
	}
	
	else if(posleftdetector==true){
	iShowImage(pos_x,pos_y,width,height, mcLeftAnimShower[j]);
	}
		
	 }

		
	 }

	  void lvl2charecterRun(){

		
		if(!inAir && !idledetector){ 	
	if(posleftdetector==false){
	iShowImage(pos_x,pos_y,width,height,mcAnimShower[i]);
	}
	
	else if(posleftdetector==true){
	iShowImage(pos_x,pos_y,width,height, mcLeftAnimShower[j]);
	}
		
	 }
	  }

		


	 void charectershoot(){
		 if(shootdec){
			 iShowImage(pos_x,pos_y,width,height,mcAnimShootShower[shootindex]);
		 }
	 }

	 

	 void  forcegravitation(){
		 if(!onground ){

				pos_y-=.1;

				cinAir=true;
				

				
			 

		 }

	




		 else{
			 cinAir=false;

		 }


		 //cout<<inAir<<endl;

	 }

	  void  forcegravitation1(){
		 if(!onground1 ){

				pos_y-=.08;

			
				

				
			 

		 }

	  }

	 void lvl2forcegravitation(){

		 if(!onground2 ){

				pos_y-=.05;

				//inAir=true;
				

				
			 

		 }

	




		 else{
			 inAir=false;

		 }
		 }




		
	 void advcharecterjump(){
		 	if(cinAir && !posleftdetector){
			 iShowImage(pos_x,pos_y,width,height,mcAnimJumpShower[cjumpindex]);
				}

				if(cinAir && posleftdetector){
					iShowImage(pos_x,pos_y,width,height,mcleftAnimJumpShower[cjumpindex]);

				}

	 }


	 

	 

	 void charecterjump(){

				if(inAir && !posleftdetector){
			 iShowImage(pos_x,pos_y,width,height,mcAnimJumpShower[jumpindex]);
				}

				if(inAir && posleftdetector){
					iShowImage(pos_x,pos_y,width,height,mcleftAnimJumpShower[jumpindex]);

				}

		 }
	 void charecterdead(){
		 iShowImage(pos_x,pos_y,width,height,mcdeadAnimShower[deadindex]);
	 }

	 
	  void pseudoimage(){
			iSetColor(255,0,0);
		  iFilledRectangle(pos_x,pos_y,width,height);
	  }

	 void showhealth(){
			float healthbar = (float)health/100;
			 
		   iShowImage(10,700,50,50,levelImageShower[31]);
		  iShowImage(50,700,(healthbarwidth-5)*healthbar,30,levelImageShower[29]);
		   //iShowImage(50,700,healthbarwidth+5,32,levelImageShower[30]);

	  }
	 


} p1(120,140,120,100),p1collcheck(150,140,50,90),p1botline(150,150,30,1),p2(0,100,120,100),p2collcheck(30,100,50,90),p3(0,100,120,100),p3collcheck(0,100,120,100),p4(0,100,120,100),p4collcheck( 0,100,120,100);

#endif