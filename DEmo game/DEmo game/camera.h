#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED




extern int posx;
extern int posbgx;

extern int tempposx;
extern int tempposy;



  
void mcFollow(){
	 tempposx= posx;
if(tempposx>=1000){

	tempposx=0;
}
posx=tempposx;
}



#endif
