#ifndef LEVELTWO_H
#define LEVELTWO_H
#include <iostream>

using namespace std;
int dx;
int dy;
 void tileShower2(){
	iShowImage(0+dx,0+dy,50,50,level2ImageShower[0]);
	iShowImage(50+dx,0+dy,50,50,level2ImageShower[0]);


	 
			
		
	iShowImage(100+dx,0,50,50,level2ImageShower[0]);
	iShowImage(150+dx,0,50,50,level2ImageShower[0]);
	iShowImage(200+dx,0,50,50,level2ImageShower[0]);

	iShowImage(250+dx,0,50,50,level2ImageShower[0]);

	iShowImage(300+dx,0,50,50,level2ImageShower[0]);

	iShowImage(350+dx,0,50,50,level2ImageShower[0]);

	//iShowImage(400,0,50,50,levelImageShower[0]);
	//iShowImage(450,0,50,50, levelImageShower[0]);
	//iShowImage(500,0,50,50,levelImageShower[0]);
	/*iShowImage(550+dx,0,50,50,level2ImageShower[0]);
	iShowImage(600+dx,0,50,50,level2ImageShower[0]);
	iShowImage(650+dx,0,50,50,level2ImageShower[0]);*/

	iShowImage(700+dx,0,50,50,level2ImageShower[0]);

	iShowImage(750+dx,0,50,50,level2ImageShower[0]);

	iShowImage(800+dx,0,50,50,level2ImageShower[0]);
	iShowImage(850+dx,0,50,50,level2ImageShower[0]);
		iShowImage(900+dx,0,50,50,level2ImageShower[0]);


	iShowImage(950+dx,0,50,50,level2ImageShower[0]);
	iShowImage(1000+dx,0,50,50,level2ImageShower[0]);

	//iShowImage(850,0,50,50,levelImageShower[0]);
	//iShowImage(900,0,50,50,levelImageShower[0]);
	//iShowImage(950,0,50,50,levelImageShower[0]);
	//iShowImage(1000,0,50,50,levelImageShower[0]);

	// previous block of code add the firstlayer of soil

	iShowImage(0+dx,50,50,50, level2ImageShower[1]);
	iShowImage(50+dx,50,50,50,level2ImageShower[1]);
	iShowImage(100+dx,50,50,50,level2ImageShower[1]);
	iShowImage(150+dx,50,50,50,level2ImageShower[1]);
	iShowImage(200+dx,50,50,50,level2ImageShower[1]);

	iShowImage(250+dx,50,50,50,level2ImageShower[1]);
		
	iShowImage(350+dx,50,50,50,level2ImageShower[1]);
	//spike
	iShowImage(100+dx,100,50,50,level2ImageShower[2]);
	iShowImage(720+dx,100,50,50,level2ImageShower[2]);

	iShowImage(300+dx,50,50,50,level2ImageShower[1]);

	//iShowImage(350,50,50,50,levelImageShower[1]);

	//iShowImage(400,50,50,50,levelImageShower[1]);
	//iShowImage(450,50,50,50, levelImageShower[1]);
	//iShowImage(500,50,50,50,levelImageShower[1]);
	/*iShowImage(550+dx,50,50,50,level2ImageShower[1]);
	iShowImage(600+dx,50,50,50,level2ImageShower[1]);
	iShowImage(650+dx,50,50,50,level2ImageShower[1]);*/

	iShowImage(700+dx,50,50,50,level2ImageShower[1]);

	iShowImage(750+dx,50,50,50,level2ImageShower[1]);

	iShowImage(800+dx,50,50,50,level2ImageShower[1]);
	iShowImage(850+dx,50,50,50,level2ImageShower[1]);
	iShowImage(900+dx,50,50,50,level2ImageShower[1]);
	iShowImage(950+dx,50,50,50,level2ImageShower[1]);

	/*iShowImage(850,50,50,50,levelImageShower[0]);
	iShowImage(900,50,50,50,levelImageShower[0]);
	iShowImage(950,50,50,50,levelImageShower[0]);
	iShowImage(1000,50,50,50,levelImageShower[0]);*/




	/*iShowImage(550,100,50,50,level2ImageShower[0]);
	iShowImage(600,100,50,50,level2ImageShower[0]);
	iShowImage(650,100,50,50,level2ImageShower[0]);

	iShowImage(700,100,50,50,level2ImageShower[0]);

	iShowImage(750,100,50,50,level2ImageShower[0]);

	iShowImage(800,100,50,50,level2ImageShower[0]);


	iShowImage(550,150,50,50,level2ImageShower[0]);
	iShowImage(600,150,50,50,level2ImageShower[0]);
	iShowImage(650,150,50,50,level2ImageShower[0]);

	iShowImage(700,150,50,50,level2ImageShower[0]);

	iShowImage(750,150,50,50,level2ImageShower[0]);

	iShowImage(800,150,50,50,level2ImageShower[0]);*/


	iShowImage(100+dx,300,50,50,level2ImageShower[3]);
	iShowImage(150+dx,300,50,50,level2ImageShower[3]);
	iShowImage(200+dx,300,50,50,level2ImageShower[3]);
	iShowImage(250+dx,300,50,50,level2ImageShower[3]);
	//iShowImage(300,300,50,50,level2ImageShower[3]);
	iShowImage(350+dx,300,50,50,level2ImageShower[3]);
	iShowImage(400+dx,300,50,50,level2ImageShower[3]);
	//iShowImage(450+dx,300,50,50,level2ImageShower[3]);
	//iShowImage(500+dx,300,50,50,level2ImageShower[3]);


	//ladder

			iShowImage(300+dx,100,50,50,level2ImageShower[4]);
			iShowImage(300+dx,150,50,50,level2ImageShower[4]);
			iShowImage(300+dx,200,50,50,level2ImageShower[4]);
			iShowImage(300+dx,250,50,50,level2ImageShower[4]);
			iShowImage(300+dx,300,50,50,level2ImageShower[4]);

			//blade
			//iShowImage(230+dx,250,50,50,level2ImageShower[5]);

			//rock 
			iShowImage(200+dx,340,80,80,level2ImageShower[6]);

			//plat 
			//iShowImage(500+dx,250,50,10,level2ImageShower[7]);
			//iShowImage(600+dx ,150,50,10,level2ImageShower[7]);
			//iShowImage(700+dx,250,50,10,level2ImageShower[7]);
			

 }
#endif