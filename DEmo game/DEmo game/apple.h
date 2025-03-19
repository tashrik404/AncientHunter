#ifndef APPLE_H
#define APPLE_H



#include <iostream>

using namespace std;

#include "image.h"


 struct apple{
	
	 int  pos_x;
	int pos_y;
	
	int width;
	int height;

	
	bool active;
	bool hactive;



	//float heatlh;

	// int attack;

	 apple(int pos_x,int pos_y,int width ,int height){
		 this ->pos_x= pos_x;

		 this ->pos_y = pos_y;
		 this -> width =width;
		 this ->height =height;
		 active =true;
		 hactive=true;
		 

	 }

	void  showapple(){
		if(active){
		iShowImage(pos_x,pos_y,width,height, levelImageShower[32]);
		}
	 }


	void showheart(){

		iShowImage(pos_x,pos_y,width,height,levelImageShower[22]);
		if(hactive){
			iShowImage(pos_x,pos_y,width,height,levelImageShower[23]);
		}
			
		
	}

 }app(80,620,40,40),h1(50,700,50,50),h2(100,700,50,50),h3(150,700,50,50),h4(50,700,50,50),h5(100,700,50,50),h6(150,700,50,50);


















#endif