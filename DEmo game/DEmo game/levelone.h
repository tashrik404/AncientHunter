#ifndef LEVELONE_H

#define LEVELONE_H

#include <iostream>
#include <string>
 using namespace std;

#include "image.h"
#include "GameObject.h"
#include "CollisionDetector.h"
#include "MC.h"
 int posbgx;
int posbgy;
int a;

void tileShower()
{
		iShowImage(posbgx,posbgy,1000,800,a);
		iShowImage(300,0,50,50,levelImageShower[5]);
		iShowImage(300,50,50,50,levelImageShower[5]);
			
		iShowImage(0,0,50,50, levelImageShower[0]);
		iShowImage(50,0,50,50,levelImageShower[0]);
		iShowImage(100,0,50,50,levelImageShower[0]);
		iShowImage(150,0,50,50,levelImageShower[0]);
		iShowImage(200,0,50,50,levelImageShower[0]);

		iShowImage(250,0,50,50,levelImageShower[0]);

		iShowImage(300,0,50,50,levelImageShower[8]);

		//iShowImage(350,0,50,50,levelImageShower[0]);

		//iShowImage(400,0,50,50,levelImageShower[0]);
		//iShowImage(450,0,50,50, levelImageShower[0]);
		//iShowImage(500,0,50,50,levelImageShower[0]);
		iShowImage(550,0,50,50,levelImageShower[0]);
		iShowImage(600,0,50,50,levelImageShower[0]);
		iShowImage(650,0,50,50,levelImageShower[0]);

		iShowImage(700,0,50,50,levelImageShower[0]);

		iShowImage(750,0,50,50,levelImageShower[0]);

		iShowImage(800,0,50,50,levelImageShower[0]);

		//iShowImage(850,0,50,50,levelImageShower[0]);
		//iShowImage(900,0,50,50,levelImageShower[0]);
		//iShowImage(950,0,50,50,levelImageShower[0]);
		//iShowImage(1000,0,50,50,levelImageShower[0]);

		// previous block of code add the firstlayer of soil

		iShowImage(0,50,50,50, levelImageShower[0]);
		iShowImage(50,50,50,50,levelImageShower[0]);
		iShowImage(100,50,50,50,levelImageShower[0]);
		iShowImage(150,50,50,50,levelImageShower[0]);
		iShowImage(200,50,50,50,levelImageShower[0]);

		iShowImage(250,50,50,50,levelImageShower[0]);

		iShowImage(300,50,50,50,levelImageShower[8]);

		//iShowImage(350,50,50,50,levelImageShower[0]);

		//iShowImage(400,50,50,50,levelImageShower[0]);
		//iShowImage(450,50,50,50, levelImageShower[0]);
		//iShowImage(500,50,50,50,levelImageShower[0]);
		iShowImage(550,50,50,50,levelImageShower[0]);
		iShowImage(600,50,50,50,levelImageShower[0]);
		iShowImage(650,50,50,50,levelImageShower[0]);

		iShowImage(700,50,50,50,levelImageShower[0]);

		iShowImage(750,50,50,50,levelImageShower[0]);

		iShowImage(800,50,50,50,levelImageShower[0]);

		/*iShowImage(850,50,50,50,levelImageShower[0]);
		iShowImage(900,50,50,50,levelImageShower[0]);
		iShowImage(950,50,50,50,levelImageShower[0]);
		iShowImage(1000,50,50,50,levelImageShower[0]);*/




		iShowImage(550,100,50,50,levelImageShower[0]);
		iShowImage(600,100,50,50,levelImageShower[0]);
		iShowImage(650,100,50,50,levelImageShower[0]);

		iShowImage(700,100,50,50,levelImageShower[0]);

		iShowImage(750,100,50,50,levelImageShower[0]);

		iShowImage(800,100,50,50,levelImageShower[0]);


		iShowImage(550,150,50,50,levelImageShower[0]);
		iShowImage(600,150,50,50,levelImageShower[0]);
		iShowImage(650,150,50,50,levelImageShower[0]);

		iShowImage(700,150,50,50,levelImageShower[0]);

		iShowImage(750,150,50,50,levelImageShower[0]);

		iShowImage(800,150,50,50,levelImageShower[0]);


		//previous block of code add the second layer of soil;
		
		iShowImage(0,100,50,50, levelImageShower[0]);
		iShowImage(50,100,50,50,levelImageShower[0]);
		iShowImage(100,100,50,50,levelImageShower[0]);
		iShowImage(150,100,50,50,levelImageShower[1]);
		iShowImage(200,100,50,50,levelImageShower[1]);

		iShowImage(250,100,50,50,levelImageShower[1]);

		iShowImage(300,100,50,50,levelImageShower[9]);

		/*iShowImage(350,100,50,50,levelImageShower[1]);

		iShowImage(400,100,50,50,levelImageShower[1]);
		iShowImage(450,100,50,50, levelImageShower[1]);
		iShowImage(500,100,50,50,levelImageShower[1]);*/
		iShowImage(550,200,50,50,levelImageShower[1]);
		iShowImage(600,200,50,50,levelImageShower[1]);
		iShowImage(650,200,50,50,levelImageShower[1]);

		iShowImage(700,200,50,50,levelImageShower[1]);

		iShowImage(750,200,50,50,levelImageShower[1]);

		iShowImage(800,200,50,50,levelImageShower[1]);

		/*iShowImage(850,100,50,50,levelImageShower[1]);
		iShowImage(900,100,50,50,levelImageShower[1]);
		iShowImage(950,100,50,50,levelImageShower[1]);
		iShowImage(1000,100,50,50,levelImageShower[1]);*/
		//previous block code add the third layer of  grass

		iShowImage(0,150,50,50,levelImageShower[0]);
		iShowImage(50,150,50,50,levelImageShower[0]);
		iShowImage(100,150,50,50,levelImageShower[8]);


		iShowImage(0,200,50,50,levelImageShower[1]);
		iShowImage(50,200,50,50,levelImageShower[1]);
		iShowImage(100,200,50,50,levelImageShower[9]);

		iShowImage(10,250,50,50,levelImageShower[16]);
		iShowImage(5,250,20,20,levelImageShower[14]);
		iShowImage(0,250,10,10,levelImageShower[15]);
		
		

		
		


		// previous block code add the layer of the starting point of the mc 

		iShowImage(80,150,250,270,levelImageShower[4]);
		iShowImage(120,150,282,301,levelImageShower[3]);
		iShowImage(150,150,20,20,levelImageShower[15]);
		iShowImage(170,150,10,10,levelImageShower[15]);
		iShowImage(300,150,20,20,levelImageShower[15]);
		iShowImage(310,150,30,30,levelImageShower[14]);
		iShowImage(180,150,40,30,levelImageShower[10]);
		
		
		// previous block code add two tree

	
		iShowImage(350,0,50,50,levelImageShower[5]);

		iShowImage(400,0,50,50,levelImageShower[5]);
		iShowImage(450,0,50,50, levelImageShower[5]);
		iShowImage(500,0,50,50,levelImageShower[5]);

		//previous block of code add first layer of water;
		
		iShowImage(350,30,50,50,levelImageShower[5]);

		iShowImage(400,30,50,50,levelImageShower[5]);
		iShowImage(450,30,50,50, levelImageShower[5]);
		iShowImage(500,30,50,50,levelImageShower[5]);
		
		// previous block of code add second layer of water


		iShowImage(350,60,50,50,levelImageShower[6]);

		iShowImage(400,60,50,50,levelImageShower[6]);
		iShowImage(450,60,50,50, levelImageShower[6]);
		iShowImage(500,60,50,50,levelImageShower[6]);

		// previous block of code add wave


		iShowImage(850,0,50,50,levelImageShower[5]);

		iShowImage(900,0,50,50,levelImageShower[5]);
		iShowImage(950,0,50,50, levelImageShower[5]);
		iShowImage(1000,0,50,50,levelImageShower[5]);

		iShowImage(850,30,50,50,levelImageShower[5]);

		iShowImage(900,30,50,50,levelImageShower[5]);
		iShowImage(950,30,50,50, levelImageShower[5]);
		iShowImage(1000,30,50,50,levelImageShower[5]);
		
		iShowImage(850,60,50,50,levelImageShower[6]);

		iShowImage(900,60,50,50,levelImageShower[6]);
		iShowImage(950,60,50,50, levelImageShower[6]);
		iShowImage(1000,60,50,50,levelImageShower[6]);

		// previous block of code add wave 
		iShowImage(240,150,30,30,levelImageShower[13]);

	//	iShowImage(80,150,50,50,levelImageShower[7]);

		iShowImage(850,550,50,50,levelImageShower[0]);
		iShowImage(900,550,50,50,levelImageShower[0]);
		iShowImage(950,550,50,50,levelImageShower[0]);
		iShowImage(850,600,50,50,levelImageShower[1]);
		iShowImage(900,600,50,50,levelImageShower[1]);
		iShowImage(950,600,50,50,levelImageShower[1]);


		iShowImage(50,250,20,20,levelImageShower[24]);

}



#endif