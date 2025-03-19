#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
using namespace std;
int enemyindex,lenemyindex=40;
int enemyatkindex;
bool lposdet;
class Enemy{
public:
	float  pos_x;
	float pos_y;
	int width;
	int height;
	int health;
	bool active;
	int enemyatkindex;
	int enemyindex;
	int lenemyindex;
	bool isAttacking;
	int tarindex;
	bool lposdet;
	bool  firedet;
	int bpos_x;
	int bpos_y;
	int fbpos_x;
	int fbpos_y;
	int fbwidth;
	int fbheight;

	int bactive;
	int bwidth;
	int bheight;
	int flyindex;

	int bindex;
	


	Enemy(){

	}
	 Enemy(int pos_x,int pos_y,int width ,int height,int health){
		 this ->pos_x= pos_x;

		 this ->pos_y = pos_y;
		 this -> width =width;
		 this ->height =height;
		 this -> health = health;
		 enemyatkindex = 0;
		 enemyindex=0;
		lenemyindex=40;
		isAttacking =false;
		tarindex=0;
		lposdet=false;
		bpos_x=pos_x;
		bpos_y=150;
		bactive=false;
		bwidth=20;
		bheight=10;
		flyindex=0;
		bindex=0;

		fbpos_x=pos_x;
		fbpos_y=pos_y;
		fbwidth=30;
		fbheight=30;





	 }

	 Enemy(int pos_x,int pos_y, int width,int height,int health ,bool active){
		 this ->pos_x= pos_x;

		 this ->pos_y = pos_y;
		 this -> width =width;
		 this ->height =height;
		 this -> health = health;
		 this -> active = active;
		  enemyatkindex = 0;
		 
		 lenemyindex=40;
		 isAttacking =false;
		 tarindex=0;
		 bpos_x=pos_x;
		bpos_y=150;
		bactive=false;
		bwidth=20;
		bheight=10;
		flyindex=0;
		bindex=0;
		fbpos_x=pos_x;
		fbpos_y=pos_y;
		fbwidth=30;
		fbheight=30;


	 }

	void showenemy() {
        if (active) {
            // Show attack animation if attacking
            
                if (lposdet) {
                    iShowImage(pos_x, pos_y, width, height, enemyAnimShower[enemyindex]);
				}
                 else {
                    iShowImage(pos_x, pos_y, width, height, enemyAnimShower[lenemyindex]);
                }
            }
        }

	void showtarenemy(){

		iShowImage(pos_x,pos_y,width,height,tarenemyAnimShower[tarindex]);
	}

	void showbtar(){
		iShowImage(bpos_x,bpos_y,bwidth,bheight,tarenemyAnimShower[4]);
	}

	void showflyenemy(){
		iShowImage(pos_x,pos_y,width,height,flyenemyAnimShower[flyindex]);
	}
    void showbfly(){
		iShowImage(fbpos_x,fbpos_y,fbwidth,fbheight,flameAnimShower[bindex]);
	}

    void showenemyatk() {
        if (active) {
            iShowImage(pos_x, pos_y, width, height, enemyatkAnimShower[enemyatkindex]);
          
        }
    }

	void pseudoimage(){
		iSetColor(255,0,0);
		iFilledRectangle(pos_x,pos_y,width,height);
	}
};



class Boss{
public:
	int pos_x;
	int pos_y;

	int height;
	int width;
	
	int idleindex;
	int atk1index;
	int atk2index;

	bool idleactive;
	bool atk1active;
	bool atk2active;

	int bpos_x;
	int bpos_y;


	int bactive;
	int bwidth;
	int bheight;
	

	int b2index;
	int b2pos_x;
	int b2pos_y;


	int b2active;
	int b2width;
	int b2height;

	int health;
	bool active;
	

	
	
	Boss(int pos_x,int pos_y,int height,int width){
		this-> pos_x=pos_x;
		this-> pos_y=pos_y;
		this ->width = width;
		this->height =height;
		idleactive =true;

		atk1active=false;
		atk2active=false;
		idleindex=0;
	 atk1index=0;
	 atk2index=0;
	 bpos_x=pos_x;
	 bpos_y=150;
	 bactive=false;
	 bwidth =50;
	 bheight=50;
	  b2pos_x=pos_x-10;
	 b2pos_y=150+10;
	 b2active=false;
	 b2width =50;
	 b2height=50;
	 b2index=0;
	 health=500;
	 active=true;
	}




	void showidle(){

		if(idleactive){
			iShowImage(pos_x,pos_y,width,height,bossAnimShower[idleindex]);
		}
	}

	void showatk1(){
		if(atk1active){
			iShowImage(pos_x,pos_y,width ,height,bossatk1AnimShower[atk1index]);
		}

	}

	void showbullet(){
		if(bactive){
			iShowImage(bpos_x,bpos_y,bwidth,bheight,bossatk1AnimShower[9]);
		}
	}

	void showbullet2(){
		if(b2active){
			iShowImage(b2pos_x,b2pos_y,b2width,b2height,laserAnimShower[b2index]);
		}
	}
	void showatk2(){
		if(atk2active){
			iShowImage(pos_x,pos_y,width ,height,bossatk2AnimShower[atk2index]);
		}

	}


	

	





}boss(400,120,120,100);




	struct CountdownBar {
    int startTime;
    int timeLimit;
    float barWidth;
    int barHeight;
    int posX, posY;
    bool isActive;
    bool hasStarted;  // New flag to track if the timer has started once

    CountdownBar(int x, int y, int limit) {
        posX = x;
        posY = y;
        timeLimit = limit;
        barWidth = 200;
        barHeight = 20;
        isActive = false;
        hasStarted = false;  // Initially false
        startTime = 0;
    }

    void start() {
        if (!hasStarted) {  // Only start if it has not started before
            startTime = glutGet(GLUT_ELAPSED_TIME);
            isActive = true;
            hasStarted = true;  // Mark as started
        }
    }

    void reset() {
        isActive = false;
        hasStarted = false;  // Allow restarting in the next game phase if needed
    }

    void draw() {
        if (!isActive) return;

        int currentTime = glutGet(GLUT_ELAPSED_TIME);
        int elapsedTime = currentTime - startTime;
        int remainingTime = timeLimit - elapsedTime;

        if (remainingTime <= 0) {
            remainingTime = 0;
            isActive = false;  // Stop the timer when time runs out
        }

        float timePercentage = remainingTime / (float)timeLimit;
        float currentBarWidth = barWidth * timePercentage;

        iSetColor(0, 0, 0);
        iRectangle(posX, posY, barWidth, barHeight);

        iSetColor(0, 255, 0);
        iFilledRectangle(posX, posY, currentBarWidth, barHeight);
    }
}timer404(50,650,50000);


// Create a countdown bar (Example: 2-minute timer at position 50,500)



#endif