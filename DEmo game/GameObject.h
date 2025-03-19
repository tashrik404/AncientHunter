#ifndef GAME_OBJECT_H

#define GAME_OBJECT_H


#include<iostream>
#include<string>
bool ongroundobj = true,ongroundobj1=true,ongroundobj2=true,ongroundobj3=true;

using namespace std;
int initposy=0;
int n=1;
int z1=1,z2=1,z3=1;
	bool firedec=false;







	

class  Gameobject {
public:
	float  pos_x;
	float  pos_y;
	int width;
	int height;
	int index;

	Gameobject(){

	}
	
	 Gameobject(int pos_x,int pos_y,int width ,int height){
		 this ->pos_x= pos_x;

		 this ->pos_y = pos_y;
		 this -> width =width;
		 this ->height =height;

	 }

	 Gameobject(int pos_x,int pos_y,int width ,int height,int index){
		  this ->pos_x= pos_x;

		 this ->pos_y = pos_y;
		 this -> width =width;
		 this ->height =height;
		 this -> index = index;
	 }
	
	 void objgravitation(){

		  if(!ongroundobj){

				pos_y-=.05;

				
				

				
			 

		 }

	 }
	 void objgravitation1(){

		  if(!ongroundobj1){

				pos_y-=.05;

				
				

				
			 

		 }

	 }

	


	 void lvl2objgravitation(){
		  if(!ongroundobj2){

				pos_y-=.05;

				
				

				
			 

		 }

	 }

	 void fallbladegravity(){
		 pos_y-=.05;

	 }
	 void fallplatgravity(){
		  pos_y-=.02;
	 }
	 


		void showimage(){
			
			iShowImage(pos_x,pos_y,width,height,levelImageShower[index]);
		}
		void airplatshowimage(){
			iShowImage(pos_x,pos_y,width,height,levelImageShower[17]);
			iShowImage(pos_x+30,pos_y,width,height,levelImageShower[18]);
			iShowImage(pos_x+60,pos_y,width,height,levelImageShower[19]);
		}

		void pseudoimage(){
			iSetColor(255,0,0);
			iFilledRectangle(pos_x,pos_y,width,height);

		}
		
		void  platmovement( ){
			  airplat.pos_x= airplat.pos_x+(.02*n);
			   platline.pos_x= airplat.pos_x+(.02*n);
			

		if(airplat.pos_x>=520 ){
			n=-1;
		}
		if(airplat.pos_x<=350){
			n=1;
		}

		}

		

		void  platmovement1( ){
			  airplat1.pos_x= airplat1.pos_x+(.02*z1);
			   platline1.pos_x= airplat1.pos_x+(.02*z1);

		if(airplat1.pos_x>=750 ){
			z1=-1;
		}
		if(airplat1.pos_x<=550){
			z1=1;
		}
		}
		void  platmovement2( ){
			  airplat2.pos_x= airplat2.pos_x+(.02*z3);
			   platline2.pos_x= airplat2.pos_x+(.02*z3);

		if(airplat2.pos_x>=650 ){
			z3=-1;
		}
		if(airplat2.pos_x<=550){
			z3=1;
		}
		

		}
		void enemymovement(){
			  enemy.pos_x= enemy.pos_x+(.05*z2);
			   

		if(enemy.pos_x>=850 ){
			z2=-1;
		}
		if(enemy.pos_x<=550){
			z2=1;
		}

		}


		 void showbullet(){
		  
			  iShowImage(pos_x,pos_y,width,height,mcAnimShootShower[3]);
		  

		 
	  }
		 void showlvl2platform(){
			 iShowImage(pos_x,pos_y,width,height,level2ImageShower[7]);
			
		 }

		 void showfallblade(){

			iShowImage(pos_x,pos_y,width,height,level2ImageShower[5]);
		 }



		  void fire(int pos_x,int pos_y,int width,int height){
			   this ->pos_x= pos_x;

		 this ->pos_y = pos_y;
		 this -> width =width;
		 this ->height =height;
		
		  }
		



}obj(0,250,130,1),obj1(550,250,300,1),obj2(200,250,400,150),ground(150,150,200,1),groundverline(150,150,1,90),water(350,70,200,1),crate(70,250,50,50,7),crtopline(70,300,50,1),airplat(300,300,30,30),airplat1(300,500,30,30),airplat2(400,400,30,30),platline(300,330,90,1),platline1(300,530,90,1),platline2(400,430,90,1),boat(850,650,100,50,20),enemy(550,250,40,40,21),upground(850,650,150,1),b(20,45,10,3),lvl2ground(0,100,400,1),lvl2upground(100,350,350,1),lvl2ground2(700,100,300,1),spike(100,120,50,1),spike2(720,120,50,1),fallblade(230,250,50,50),fallrange(230,100,50,1),climbverline(320,100,1,250),lvl2plat(600,250,50,10),lvl2plat2(500,300,50,10),rockverline(71,250,1,5);


//crline(200,140,1,50),crleftline(250,140,1,50)





#endif