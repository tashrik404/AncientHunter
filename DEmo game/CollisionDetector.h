#ifndef COLLISION_DETECTOR_H
#define COLLISION_DETECTOR_H

#include <iostream>
using namespace std;

#include "MC.h"

#include"GameObject.h"
#include "Enemy.h"
#include "apple.h"

class collision{
public:
bool collider(Mc obj1, Gameobject obj2) {
    if (obj1.pos_x < (obj2.pos_x + obj2.width) && (obj1.pos_x + obj1.width) > obj2.pos_x &&  obj1.pos_y < (obj2.pos_y + obj2.height) &&  (obj1.pos_y + obj1.height) > obj2.pos_y) {
        
        
        return true;
    } 
	
	else {
        return false;
    }
}

bool collider(Gameobject obj1 ,Gameobject obj2){
	 if (obj1.pos_x < (obj2.pos_x + obj2.width) && (obj1.pos_x + obj1.width) > obj2.pos_x &&  obj1.pos_y < (obj2.pos_y + obj2.height) &&  (obj1.pos_y + obj1.height) > obj2.pos_y) {
        
        
        return true;
    } 
	
	else {
        return false;
    }
}
	bool collider( Enemy obj1,Gameobject obj2){
		 if (obj1.pos_x < (obj2.pos_x + obj2.width) && (obj1.pos_x + obj1.width) > obj2.pos_x &&  obj1.pos_y < (obj2.pos_y + obj2.height) &&  (obj1.pos_y + obj1.height) > obj2.pos_y) {
        
        
        return true;
    } 
	
	else {
        return false;
    }
	}


	bool collider( Mc obj1,apple obj2){
		 if (obj1.pos_x < (obj2.pos_x + obj2.width) && (obj1.pos_x + obj1.width) > obj2.pos_x &&  obj1.pos_y < (obj2.pos_y + obj2.height) &&  (obj1.pos_y + obj1.height) > obj2.pos_y) {
        
        
        return true;
    } 
	
	else {
        return false;
    }
	}
	bool collider( Mc obj1,Enemy obj2){
		 if (obj1.pos_x < (obj2.pos_x + obj2.width) && (obj1.pos_x + obj1.width) > obj2.pos_x &&  obj1.pos_y < (obj2.pos_y + obj2.height) &&  (obj1.pos_y + obj1.height) > obj2.pos_y) {
        
        
        return true;
    } 

		 else if (obj1.pos_x < (obj2.bpos_x + obj2.bwidth) && (obj1.pos_x + obj1.width) > obj2.bpos_x &&  obj1.pos_y < (obj2.bpos_y + obj2.bheight) &&  (obj1.pos_y + obj1.height) > obj2.bpos_y) {
        
        
        return true;
    }  	 else if (obj1.pos_x < (obj2.fbpos_x + obj2.fbwidth) && (obj1.pos_x + obj1.width) > obj2.fbpos_x &&  obj1.pos_y < (obj2.fbpos_y + obj2.fbheight) &&  (obj1.pos_y + obj1.height) > obj2.fbpos_y) {
        
        
        return true;
    }  
	
	else {
        return false;
    }
	}


	bool collider( Mc obj1, Boss obj2){
		 if (obj1.pos_x < (obj2.pos_x + obj2.width) && (obj1.pos_x + obj1.width) > obj2.pos_x &&  obj1.pos_y < (obj2.pos_y + obj2.height) &&  (obj1.pos_y + obj1.height) > obj2.pos_y) {
        
        
        return true;
    } 

		 else if (obj1.pos_x < (obj2.bpos_x + obj2.bwidth) && (obj1.pos_x + obj1.width) > obj2.bpos_x &&  obj1.pos_y < (obj2.bpos_y + obj2.bheight) &&  (obj1.pos_y + obj1.height) > obj2.bpos_y) {
        
        
        return true;
    }  	 else if (obj1.pos_x < (obj2.b2pos_x + obj2.b2width) && (obj1.pos_x + obj1.width) > obj2.b2pos_x &&  obj1.pos_y < (obj2.b2pos_y + obj2.b2height) &&  (obj1.pos_y + obj1.height) > obj2.b2pos_y) {
        
        
        return true;
    }  
	
	else {
        return false;
    }
	}

	


	/*bool collider(Mc obj1, gameobject2 obj2){
		if (obj1.pos_x < (obj2.pos_x + obj2.width) && (obj1.pos_x + obj1.width) > obj2.pos_x &&  obj1.pos_y < (obj2.pos_y + obj2.height) &&  (obj1.pos_y + obj1.height) > obj2.pos_y) {
        
        
        return true;
    } 
	
	else {
        return false;
    }

	}*/

}c1,c2,c3;

/*void posholder(Mc p1, Gameobject obj){
		
	if(c1.collider(p1,obj) ){

		
		p1.pos_y = obj.pos_y;
	
		
		init_posy=obj.pos_y;
		
		

	}

	else{
		
		init_posy=0;

	}
		
	


	

		
		
	
}



void objposholder(Gameobject obj1, Gameobject obj2){
		
	if(c1.collider(obj1,obj2) ){

		
		obj1.pos_y = obj2.pos_y;
	
		
		initposy=obj1.pos_y;
		
		

	}

	else{
		
		initposy=0;
		
	}



		
		

}*/



#endif // COLLISION_DETECTOR_H