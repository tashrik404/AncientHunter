#ifndef IMAGE_H
#define IMAGE_H

#include<iostream>


#include<string>
#include<cstdlib>

using namespace std;


int mcAnimShower[20];
int bgMenuShower[20];
int settingMenuShower[40];
int mcIdleAnimShower[20];
int mcLeftAnimShower[20];
int mcAnimJumpShower[20];
int mcdeadAnimShower[20];
int levelImageShower[50];
int mcleftAnimJumpShower[20];
int mcAnimShootShower[10];
int enemyAnimShower[90];
int enemyatkAnimShower[70];
int bgAnimShower[150];
int tarenemyAnimShower[10];
int flyenemyAnimShower[10];
int flameAnimShower[10];
int bossAnimShower[20];
int bossatk1AnimShower[20];
int bossatk2AnimShower[20];
int laserAnimShower[20];
	char bgfile[150];
  char filename[80];
   
  char eatkfile[70];
  int bglevel2;
  int level2ImageShower[30];

  void  tileAnimSaver(){
	  level2ImageShower[0]=iLoadImage("level2\\Tile_0.png");
	   level2ImageShower[1]=iLoadImage("level2\\Tile_1.png");

	   level2ImageShower[2]=iLoadImage("level2\\spikes_1.png");
	   level2ImageShower[3]=iLoadImage("level2\\Tile_3.png");
	   level2ImageShower[4]=iLoadImage("level2\\ladder.png");
	   level2ImageShower[5]=iLoadImage("level2\\fallblade.png");
	   level2ImageShower[6]=iLoadImage("level2\\rock.png");
	   level2ImageShower[7]=iLoadImage("level2\\fplat.png");
	  
  }
  void bgAnimSaver(){
	  /*
	for(int i=1;i<113;i++){
		sprintf(bgfile,"bgAnim\\bgAnimation%05d.png",i);
		bgAnimShower[i]=iLoadImage(bgfile);
		
	}*/

	
	  bglevel2= iLoadImage("level2\\bglevel2.png");
  }
void enemyAnimSaver(){
	for (int i = 0; i < 80; i++) {
     
    sprintf(filename, "enemy\\run_%03d.png", i); // Format number as 3 digits (000, 001, ..., 039)
    enemyAnimShower[i] = iLoadImage(filename);  // Use the formatted string
} 

	

		for (int j = 0; j < 62; j++) {
     
    sprintf(eatkfile, "enemy\\attack_%03d.png", j); 
    enemyatkAnimShower[j] = iLoadImage(eatkfile); 

	cout<<j<<endl;
	}
	

		tarenemyAnimShower[0]=iLoadImage("enemy\\turwalk0.png");
		tarenemyAnimShower[1]=iLoadImage("enemy\\turwalk1.png");
		tarenemyAnimShower[2]=iLoadImage("enemy\\turwalk2.png");
		tarenemyAnimShower[3]=iLoadImage("enemy\\turwalk3.png");
		tarenemyAnimShower[4]=iLoadImage("enemy\\tarbullet0.png");

		flyenemyAnimShower[0]=iLoadImage("enemy\\flyenemy0.png");
		flyenemyAnimShower[1]=iLoadImage("enemy\\flyenemy1.png");
		flyenemyAnimShower[2]=iLoadImage("enemy\\flyenemy2.png");
		flyenemyAnimShower[3]=iLoadImage("enemy\\flyenemy3.png");

		flameAnimShower[0]=iLoadImage("enemy\\falme0.png");
		flameAnimShower[1]=iLoadImage("enemy\\falme1.png");
		flameAnimShower[2]=iLoadImage("enemy\\falme2.png");
		flameAnimShower[3]=iLoadImage("enemy\\falme3.png");
		flameAnimShower[4]=iLoadImage("enemy\\falme4.png");
		flameAnimShower[5]=iLoadImage("enemy\\falme5.png");
		flameAnimShower[6]=iLoadImage("enemy\\falme6.png");
		flameAnimShower[7]=iLoadImage("enemy\\falme7.png");
		flameAnimShower[7]=iLoadImage("enemy\\falme8.png");


		bossAnimShower[0]=iLoadImage("enemy\\lbidle0.png");
		bossAnimShower[1]=iLoadImage("enemy\\lbidle1.png");
		bossAnimShower[2]=iLoadImage("enemy\\lbidle2.png");
		bossAnimShower[3]=iLoadImage("enemy\\lbidle3.png");

		bossatk1AnimShower[0]=iLoadImage("enemy\\lb1atk0.png");
		bossatk1AnimShower[1]=iLoadImage("enemy\\lb1atk1.png");
		bossatk1AnimShower[2]=iLoadImage("enemy\\lb1atk2.png");
		bossatk1AnimShower[3]=iLoadImage("enemy\\lb1atk3.png");

		bossatk1AnimShower[4]=iLoadImage("enemy\\lb1atk4.png");
		bossatk1AnimShower[5]=iLoadImage("enemy\\lb1atk5.png");
		bossatk1AnimShower[6]=iLoadImage("enemy\\lb1atk6.png");
		bossatk1AnimShower[7]=iLoadImage("enemy\\lb1atk7.png");
		bossatk1AnimShower[8]=iLoadImage("enemy\\lb1atk8.png");
		bossatk1AnimShower[9]=iLoadImage("enemy\\arm0.png");
	



		bossatk2AnimShower[0]=iLoadImage("enemy\\lb2atk0.png");
		bossatk2AnimShower[1]=iLoadImage("enemy\\lb2atk1.png");
		bossatk2AnimShower[2]=iLoadImage("enemy\\lb2atk2.png");
		bossatk2AnimShower[3]=iLoadImage("enemy\\lb2atk3.png");
		bossatk2AnimShower[4]=iLoadImage("enemy\\lb2atk4.png");
		bossatk2AnimShower[5]=iLoadImage("enemy\\lb2atk5.png");
		bossatk2AnimShower[6]=iLoadImage("enemy\\lb2atk6.png");



		laserAnimShower[0]=iLoadImage("enemy\\l0.png");
		laserAnimShower[1]=iLoadImage("enemy\\l1.png");
		laserAnimShower[2]=iLoadImage("enemy\\l2.png");
		laserAnimShower[3]=iLoadImage("enemy\\l3.png");
		laserAnimShower[4]=iLoadImage("enemy\\l4.png");
		laserAnimShower[5]=iLoadImage("enemy\\l5.png");
		laserAnimShower[6]=iLoadImage("enemy\\l6.png");
		laserAnimShower[7]=iLoadImage("enemy\\l7.png");
		laserAnimShower[8]=iLoadImage("enemy\\l8.png");
		laserAnimShower[9]=iLoadImage("enemy\\l9.png");
			laserAnimShower[10]=iLoadImage("enemy\\l10.png");

		
		
		
		
		


}
void mcIdleAnimSaver(){
	mcIdleAnimShower[0]=iLoadImage("MC\\Idle(1).png");
	mcIdleAnimShower[1]=iLoadImage("MC\\Idle(2).png");
	mcIdleAnimShower[2]=iLoadImage("MC\\Idle(3).png");
	mcIdleAnimShower[3]=iLoadImage("MC\\Idle(4).png");
	mcIdleAnimShower[4]=iLoadImage("MC\\Idle(5).png");
	mcIdleAnimShower[5]=iLoadImage("MC\\Idle(6).png");
	mcIdleAnimShower[6]=iLoadImage("MC\\Idle(7).png");
	mcIdleAnimShower[7]=iLoadImage("MC\\Idle(8).png");
	mcIdleAnimShower[8]=iLoadImage("MC\\Idle(9).png");
	mcIdleAnimShower[9]=iLoadImage("MC\\Idle(10).png");
	


}

void mcAnimWalkSaver(){
	
		mcAnimShower[0]=iLoadImage("MC\\Run(1).png");
	mcAnimShower[1]=iLoadImage("MC\\Run(2).png");
	mcAnimShower[2]=iLoadImage("MC\\Run(3).png");
	mcAnimShower[3]=iLoadImage("MC\\Run(4).png");
	mcAnimShower[4]=iLoadImage("MC\\Run(5).png");
	mcAnimShower[5]=iLoadImage("MC\\Run(6).png");
	mcAnimShower[6]=iLoadImage("MC\\Run(7).png");
	mcAnimShower[7]=iLoadImage("MC\\Run(8).png");
	mcdeadAnimShower[0]=iLoadImage("MC\\dead (1).png");
	mcdeadAnimShower[1]=iLoadImage("MC\\dead (2).png");
	mcdeadAnimShower[2]=iLoadImage("MC\\dead (3).png");
	mcdeadAnimShower[3]=iLoadImage("MC\\dead (4).png");
	mcdeadAnimShower[4]=iLoadImage("MC\\dead (5).png");
	mcdeadAnimShower[5]=iLoadImage("MC\\dead (6).png");
	mcdeadAnimShower[6]=iLoadImage("MC\\dead (7).png");
	mcdeadAnimShower[7]=iLoadImage("MC\\dead (8).png");
	mcdeadAnimShower[8]=iLoadImage("MC\\dead (9).png");
	mcdeadAnimShower[9]=iLoadImage("MC\\dead (10).png");
}

void mcAnimLeftWalkSaver(){
	mcLeftAnimShower[0]=iLoadImage("MC\\Runleft(1).png");
	mcLeftAnimShower[1]=iLoadImage("MC\\Runleft(2).png");
	mcLeftAnimShower[2]=iLoadImage("MC\\Runleft(3).png");
	mcLeftAnimShower[3]=iLoadImage("MC\\Runleft(4).png");
	mcLeftAnimShower[4]=iLoadImage("MC\\Runleft(5).png");
	mcLeftAnimShower[5]=iLoadImage("MC\\Runleft(6).png");
	mcLeftAnimShower[6]=iLoadImage("MC\\Runleft(7).png");
	mcLeftAnimShower[7]=iLoadImage("MC\\Runleft(8).png");


}
void mcAnimJumpSaver(){

	mcAnimJumpShower[0]=iLoadImage("MC\\Jump(1).png");
	mcAnimJumpShower[1]=iLoadImage("MC\\Jump(2).png");
	mcAnimJumpShower[2]=iLoadImage("MC\\Jump(3).png");
	mcAnimJumpShower[3]=iLoadImage("MC\\Jump(4).png");
	mcAnimJumpShower[4]=iLoadImage("MC\\Jump(5).png");
	mcAnimJumpShower[5]=iLoadImage("MC\\Jump(6).png");
	mcAnimJumpShower[6]=iLoadImage("MC\\Jump(7).png");
	mcAnimJumpShower[7]=iLoadImage("MC\\Jump(8).png");
	mcAnimJumpShower[8]=iLoadImage("MC\\Jump(9).png");
	mcAnimJumpShower[9]=iLoadImage("MC\\Jump(10).png");

}


void leftAnimJumpSaver(){
	mcleftAnimJumpShower[0]=iLoadImage("MC\\Jumpleft(1).png");
	mcleftAnimJumpShower[1]=iLoadImage("MC\\Jumpleft(2).png");
	mcleftAnimJumpShower[2]=iLoadImage("MC\\Jumpleft(3).png");
	mcleftAnimJumpShower[3]=iLoadImage("MC\\Jumpleft(4).png");
	mcleftAnimJumpShower[4]=iLoadImage("MC\\Jumpleft(5).png");
	mcleftAnimJumpShower[5]=iLoadImage("MC\\Jumpleft(6).png");
	mcleftAnimJumpShower[6]=iLoadImage("MC\\Jumpleft(7).png");
	mcleftAnimJumpShower[7]=iLoadImage("MC\\Jumpleft(8).png");
	mcleftAnimJumpShower[8]=iLoadImage("MC\\Jumpleft(9).png");
	mcleftAnimJumpShower[9]=iLoadImage("MC\\Jumpleft(10).png");
}

void mcAnimShootSaver(){
	mcAnimShootShower[0]=iLoadImage("MC\\Shoot(1).png");
	mcAnimShootShower[1]=iLoadImage("MC\\Shoot(2).png");
	mcAnimShootShower[2]=iLoadImage("MC\\Shoot(3).png");
	mcAnimShootShower[3]=iLoadImage("MC\\bullet.png");


}
void bgMenuSaver(){
	bgMenuShower[0]=iLoadImage("bgMenu.png");
	bgMenuShower[1]=iLoadImage("AHtext2.png");
	bgMenuShower[2]=iLoadImage("buttonPlay2.png");
	bgMenuShower[3]=iLoadImage("buttonPlay1.png");
	bgMenuShower[4]=iLoadImage("ButtonSetting1.png");
	bgMenuShower[5]=iLoadImage("ButtonSetting2.png");
	bgMenuShower[6]=iLoadImage("ButtonAbout1.png");
	bgMenuShower[7]=iLoadImage("ButtonAbout2.png");
	




}


void settingMenuSaver(){
	settingMenuShower[0]=iLoadImage("settingBg0.png");
	settingMenuShower[1]=iLoadImage("settingBg1.png");
	settingMenuShower[2]=iLoadImage("table.png");
	settingMenuShower[3]=iLoadImage("92.png");
	settingMenuShower[4]=iLoadImage("96.png");
	settingMenuShower[5]=iLoadImage("95.png");
	settingMenuShower[6]=iLoadImage("ButtonExit1.png");
	settingMenuShower[7]=iLoadImage("ButtonExit2.png");
	settingMenuShower[8]=iLoadImage("newgameMenu1.png");
	settingMenuShower[9]=iLoadImage("newgameMenu2.png");
	settingMenuShower[10]=iLoadImage("continueMenu1.png");
	settingMenuShower[11]=iLoadImage("continueMenu2.png");
	settingMenuShower[12]=iLoadImage("settingMenu1.png");
	settingMenuShower[13]=iLoadImage("settingMenu2.png");
	settingMenuShower[14]=iLoadImage("exitMenu1.png");
	settingMenuShower[15]=iLoadImage("exitMenu2.png");
	settingMenuShower[16]=iLoadImage("bganim.png");
	settingMenuShower[17]=iLoadImage("lose.png");
	settingMenuShower[18]=iLoadImage("restart.png");
	settingMenuShower[19]=iLoadImage("lvlselect.png");
	settingMenuShower[20]=iLoadImage("1.png");
	settingMenuShower[21]=iLoadImage("2.png");
	settingMenuShower[22]=iLoadImage("3.png");
	settingMenuShower[23]=iLoadImage("4.png");
	settingMenuShower[24]=iLoadImage("dot_a.png");
	settingMenuShower[25]=iLoadImage("win.png");
	settingMenuShower[26]=iLoadImage("restart.png");
	settingMenuShower[27]=iLoadImage("next.png");
	settingMenuShower[28]=iLoadImage("close.png");


	
       levelImageShower[0]=iLoadImage("levelone\\soil.png");
	   levelImageShower[1]=iLoadImage("levelone\\grass.png");
	   levelImageShower[2]=iLoadImage("levelone\\puregrass.png");
	   levelImageShower[3]=iLoadImage("levelone\\tree_2.png");
	   levelImageShower[4]=iLoadImage("levelone\\tree_3.png");
	   levelImageShower[5]=iLoadImage("levelone\\water.png");
	   levelImageShower[6]=iLoadImage("levelone\\wave.png");
	    levelImageShower[7]=iLoadImage("levelone\\crate.png");
		levelImageShower[8]=iLoadImage("levelone\\soiledgeleft.png");
		levelImageShower[9]=iLoadImage("levelone\\rightedgegrass.png");
		levelImageShower[10]=iLoadImage("levelone\\Bush (1).png");
		levelImageShower[11]=iLoadImage("levelone\\Bush (2).png");
		levelImageShower[12]=iLoadImage("levelone\\Bush (3).png");
		levelImageShower[13]=iLoadImage("levelone\\Bush (4).png");
		levelImageShower[14]=iLoadImage("levelone\\Mushroom_1.png");
		levelImageShower[15]=iLoadImage("levelone\\Mushroom_2.png");
		levelImageShower[16]=iLoadImage("levelone\\Sign_2.png");
		levelImageShower[17]=iLoadImage("airplat(1).png");
		levelImageShower[18]=iLoadImage("airplat(2).png");
		levelImageShower[19]=iLoadImage("airplat(3).png");
		levelImageShower[20]=iLoadImage("boat.png");
		levelImageShower[21]=iLoadImage("enemy.png");
		levelImageShower[24]=iLoadImage("levelone\\Stone.png");

		levelImageShower[23]=iLoadImage("heart.png");
		levelImageShower[22]=iLoadImage("eheart.png");
		
		levelImageShower[29]=iLoadImage("bar.png");
		levelImageShower[30]=iLoadImage("ebar.png");
		levelImageShower[31]=iLoadImage("mchead.png");
		levelImageShower[32]=iLoadImage("apple.png");
		levelImageShower[33]=iLoadImage("bg4.jpg");
	

		




}




#endif