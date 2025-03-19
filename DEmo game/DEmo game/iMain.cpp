#include "iGraphics.h"

#include"image.h"

#include "GameObject.h"

#include "CollisionDetector.h"

#include "MC.h"

#include "levelone.h"
#include "leveltwo.h"
#include "levelthree.h"
#include "levelfour.h"


# include <iostream>
# include <string>

# include "levelonescript.h"
#include "Enemy.h"
#include "apple.h"

#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>

using namespace std;
int bossindex=0;

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
int lvl2life=1;
bool bladelife=false;
bool lvl2inmenu=false;
bool lvl3inmenu=false;
bool lvl3complete=false;
bool lvl2complete=false;
vector<Enemy> enemies;
vector<Enemy>tarenemy;
vector<Enemy>flyenemy;
int timer = 60;

int temppos_y,ctemppos_y;
int sp=24;
bool bladefalldec=false,platfall1=false,platfall2=false;

 bool climbdec = false;
 






 #define BULLET_SPEED 20
#define MAX_BULLETS 10
#define BODY_SIZE 30
 #define ENEMY_COUNT 5 
 #define SPAWN_INTERVAL 10000

 














// Function to move all enemies
void showAllEnemies() {
	if(gamephase==3){
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i].active) {
            if (enemies[i].isAttacking) {
                enemies[i].showenemyatk(); // Show attack animation

            } 
        }
    }


	for(int i=0;i<enemies.size();i++){
		if(enemies[i].active){
			if(!enemies[i].isAttacking){
				enemies[i].showenemy();

			}
		}
	}

	for(int i=0;i<tarenemy.size();i++){

		if(tarenemy[i].active){
			tarenemy[i].showtarenemy();
		}

		if(tarenemy[i].bactive){
			tarenemy[i].showbtar();
		}
		
	}
	
	for(int i=0;i<flyenemy.size();i++){

		if(flyenemy[i].active){
			flyenemy[i].showflyenemy();
		}
		if(flyenemy[i].bactive){
			flyenemy[i].showbfly();
		}
		
	}
		
	}
}

// Function to remove off-screen enemies
void removeOffScreenEnemies() {
    for (int i = 0; i < enemies.size(); ) {

		
        if (enemies[i].pos_x + enemies[i].width < 0) {
            enemies.erase(enemies.begin() + i); // Erase the enemy at index i
        } else {
            i++; // Move to the next enemy
        }
    }
}







 
struct Bullet {
    float x, y;
    float velX, velY;
    bool active;
};
Bullet bullets[MAX_BULLETS];
int crosshairX = resWidth / 2, crosshairY = resHeight/ 2;

void initializeBullets() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        bullets[i].active = false;
    }
}

void drawBullets() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].active) {
			iShowImage(bullets[i].x,bullets[i].y,5,5,mcAnimShootShower[3]);
        }
    }
}

void drawCrosshair() {
    iSetColor(255, 0, 0);
    iLine(crosshairX - 10, crosshairY, crosshairX + 10, crosshairY);
    iLine(crosshairX, crosshairY - 10, crosshairX, crosshairY + 10);
}

bool bcoll (Bullet obj1 , Enemy obj2){
	 if (obj1.x < (obj2.pos_x + obj2.width) && (obj1.x + 5) > obj2.pos_x &&  obj1.y < (obj2.pos_y + obj2.height) &&  (obj1.y + 5) > obj2.pos_y) {
        
        
        return true;
    } 
	
	else {
        return false;
    }
}

void fireBullet() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (!bullets[i].active) {
            // Calculate direction to crosshair
			float dx = crosshairX - p3.pos_x;
            float dy = crosshairY - p3.pos_y;
            float distance = sqrt(dx * dx + dy * dy);
            
            if (distance > 0) {
                bullets[i].velX = (dx / distance) * BULLET_SPEED;
                bullets[i].velY = (dy / distance) * BULLET_SPEED;
            } else {
                bullets[i].velX = 0;
                bullets[i].velY = BULLET_SPEED;
            }
            
            bullets[i].x = p3.pos_x+50;
            bullets[i].y = p3.pos_y+40;
            bullets[i].active = true;
            break;
        }
    }
}

void bulletMovement() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].active) {
            bullets[i].x += bullets[i].velX;
            bullets[i].y += bullets[i].velY;
            
            // Deactivate bullets that go off-screen
            if (bullets[i].x < 0 || bullets[i].x > resWidth ||
                bullets[i].y < 0 || bullets[i].y > resHeight) {
                bullets[i].active = false;
            }
        }
    }
}

int lastSpawnTime = 0;
int tarlastSpawnTime=0;
int flylastSpawnTime=0;
void iTimeFunction() {
    // Spawn new enemies
	if(gamephase==3){
		
    int currentTime = glutGet(GLUT_ELAPSED_TIME);

    if (currentTime - lastSpawnTime >SPAWN_INTERVAL + (rand() % 500)) {
        enemies.push_back(Enemy(resWidth + rand() % 200, 100, 130, 100, 100));
		 lastSpawnTime = currentTime;
	}	if(currentTime -tarlastSpawnTime >SPAWN_INTERVAL + 8000 + (rand() % 3000)){
		tarenemy.push_back(Enemy(resWidth + rand() % 700, 100, 80, 70, 100,100));
		 tarlastSpawnTime = currentTime;
	}	if(currentTime -flylastSpawnTime >+ 12000 + (rand() % 4000)){
		flyenemy.push_back(Enemy(resWidth + rand() % 1000, 400, 80, 70, 100,100));
			flylastSpawnTime = currentTime;
	}
        
    

    // Move enemies
    for (int i = 0; i < enemies.size(); i++) {
         if (enemies[i].pos_x < p3.pos_x) { // Move towards the center of the screen
            enemies[i].pos_x += 2;
            lposdet = true;
        } else if (enemies[i].pos_x > p3.pos_x) {
            enemies[i].pos_x -= 2;
            lposdet = false;
        }

        // Check collision for each enemy
        if (c1.collider(p3, enemies[i])) {
            enemies[i].isAttacking = true; // Set attack state for this enemy
        } else {
            enemies[i].isAttacking = false; // Reset attack state
        }
    }

	for(int i = 0; i < tarenemy.size(); i++) {
    int distance = abs(tarenemy[i].pos_x - p3.pos_x);
    
    if (distance > 300) { 
        if (tarenemy[i].pos_x < p3.pos_x) { 
            tarenemy[i].pos_x += 2;
			tarenemy[i].bpos_x=tarenemy[i].pos_x ;
            tarenemy[i].lposdet = true;
        } else if (tarenemy[i].pos_x > p3.pos_x) {
            tarenemy[i].pos_x -= 2;
			tarenemy[i].bpos_x=tarenemy[i].pos_x ;
            tarenemy[i].lposdet = false;
			//tarenemy[i].bpos_y=100;
        }
    }

	else{
		tarenemy[i].bactive=true;
	}
		
		

	

	if(tarenemy[i].bactive){
		tarenemy[i].bpos_x-=2;
	}

	if(c1.collider(p3,tarenemy[i])){
		
		p3.health-=20;
		tarenemy[i].bpos_x=tarenemy[i].pos_x;
		
	}
	
	

	//cout<<tarenemy[i].bactive<<endl;
	
}

	 for (int i = 0; i < flyenemy.size(); i++) {
		  int distance = abs(flyenemy[i].pos_x - p3.pos_x);
         if (flyenemy[i].pos_x < p3.pos_x) { // Move towards the center of the screen
            flyenemy[i].pos_x += 2;
            flyenemy[i].lposdet = true;
			flyenemy[i].fbpos_x=flyenemy[i].pos_x;
        } else if (flyenemy[i].pos_x > p3.pos_x) {
            flyenemy[i].pos_x -= 2;
            flyenemy[i].lposdet = false;
			flyenemy[i].fbpos_x=flyenemy[i].pos_x;
        }

		if(distance<=0){
			flyenemy[i].bactive=true;
		}

	if(flyenemy[i].bactive){
			flyenemy[i].fbpos_y-=5;
		}
	 if(c1.collider(p3,flyenemy[i])){
		 if(flyenemy[i].bactive){
		p3.health-=20;
		flyenemy[i].fbpos_y=flyenemy[i].pos_y;
		 }
	}


	 }

	}
	
}

void lvl3initializeGame() {
    
    lastSpawnTime = 0;
    tarlastSpawnTime = 0;
    flylastSpawnTime = 0;

   
    enemies.clear();
    tarenemy.clear();
    flyenemy.clear();

    
    p3.health = 100; 
    p3.pos_x = 0;  
    p3.pos_y = 100;
	p3.active=true;
	timer404.reset();
    
}

// Function to check collision between bullets and enemies
void checkBulletEnemyCollisions() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].active) {
            // Check collision with normal enemies
            for (int j = 0; j < enemies.size(); j++) {
                if (enemies[j].active && bcoll(bullets[i], enemies[j])) {
                    enemies[j].health -= 20;
                    bullets[i].active = false;

                    if (enemies[j].health <= 0) {
                        enemies[j].active = false;
                        enemies.erase(enemies.begin() + j);
                        j--;
                    }
                    break;
                }
            }

            // Check collision with tarenemy
            for (int k = 0; k < tarenemy.size(); k++) {
                if (tarenemy[k].active && bcoll(bullets[i], tarenemy[k])) {
                    tarenemy[k].health -= 20;
                    bullets[i].active = false;

                    if (tarenemy[k].health <= 0) {
                        tarenemy[k].active = false;
                        tarenemy.erase(tarenemy.begin() + k);
                        k--;
                    }
                    break;
                }
            }

            // Check collision with flyenemy
            for (int m = 0; m < flyenemy.size(); m++) {
                if (flyenemy[m].active && bcoll(bullets[i], flyenemy[m])) {
                    flyenemy[m].health -= 20;
                    bullets[i].active = false;

                    if (flyenemy[m].health <= 0) {
                        flyenemy[m].active = false;
                        flyenemy.erase(flyenemy.begin() + m);
                        m--;
                    }
                    break;
                }
            }
        }
    }
}
void fireBulletP4() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (!bullets[i].active) {
            // Calculate direction to crosshair
            float dx = crosshairX - p4.pos_x;
            float dy = crosshairY - p4.pos_y;
            float distance = sqrt(dx * dx + dy * dy);

            if (distance > 0) {
                bullets[i].velX = (dx / distance) * BULLET_SPEED;
                bullets[i].velY = (dy / distance) * BULLET_SPEED;
            } else {
                bullets[i].velX = 0;
                bullets[i].velY = BULLET_SPEED;
            }

            bullets[i].x = p4.pos_x + 50; // Adjust offset as needed
            bullets[i].y = p4.pos_y + 40; // Adjust offset as needed
            bullets[i].active = true;
            break;
        }
    }
}

bool bcoll(Bullet obj1, Boss obj2) {
    // Check if the bullet collides with the boss
    if (obj1.x < (obj2.pos_x + obj2.width) && 
        (obj1.x + 5) > obj2.pos_x && 
        obj1.y < (obj2.pos_y + obj2.height) && 
        (obj1.y + 5) > obj2.pos_y) {
        return true; // Collision detected
    } else {
        return false; // No collision
    }
}

void checkBulletBossCollision() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i].active && bcoll(bullets[i], boss)) {
            // Collision detected between bullet and boss
            boss.health -= 20; // Reduce boss health (adjust damage as needed)
            bullets[i].active = false; // Deactivate the bullet

            // Check if the boss is defeated
            if (boss.health <= 0) {
                boss.active = false; // Deactivate the boss
                // Add additional logic for boss defeat (e.g., play animation, trigger event)
            }
        }
    }
}

	






int belaspedtime = 0; // Tracks the last time an attack was triggered
int duration = 5000;  // Cooldown duration in milliseconds (e.g., 3000ms = 5 seconds)
bool active = false;
bool bossmove = false;
int prevAtkPhase = 0; // Stores the last attack phase

void bossfunction() {
    int currentTime = glutGet(GLUT_ELAPSED_TIME); // Get the current time in milliseconds

    // Check if the cooldown duration has passed
    if (currentTime - belaspedtime >= duration) {
        int atkphase;

        // Ensure a new attack phase is chosen (no consecutive repeats)
        do {
            atkphase = rand() % 3 + 1;
        } while (atkphase == prevAtkPhase);

        prevAtkPhase = atkphase; // Store the current attack as the last attack

        if (atkphase == 1) {
            boss.atk1active = true;
            boss.atk2active = false;
            boss.idleactive = false;
            active = true;
            boss.bactive = true;
            boss.b2active = false;
            bossmove = false;
        } 
        else if (atkphase == 2) {
            boss.atk1active = false;
            boss.atk2active = true;
            boss.idleactive = false;
            boss.bactive = false;
            active = false;
            boss.b2active = true;
            bossmove = false;
        } 
        else if (atkphase == 3) {
            boss.atk1active = false;
            boss.atk2active = false;
            boss.idleactive = true;
            boss.bactive = false;
            active = false;
            boss.b2active = false;
            bossmove = true;
        }

        // Update the last attack time
        belaspedtime = currentTime;
    }

    float desiredDistance = 300.0f; // Adjust this value as needed

    // Ensure the boss stays to the right of p4
    if (boss.pos_x < p4.pos_x + desiredDistance) {
        boss.pos_x = p4.pos_x + desiredDistance;
        boss.bpos_x = boss.pos_x;
        boss.b2pos_x = boss.pos_x - 10;
    }

    if (c1.collider(p4, boss)) {
        boss.bpos_x = boss.pos_x;
    }

    checkBulletBossCollision();
    cout << boss.health << endl;
}

float healthBarWidth = 500;
void drawHealthBar(int x, int y) {
    
    float healthPercentage = (float)boss.health / 400;

    
    iSetColor(0, 0, 0);
    iRectangle(x, y, healthBarWidth, 17); 

    
    iSetColor(0, 255, 0);
    iFilledRectangle(x + 1, y + 1, (healthBarWidth - 2) * healthPercentage, 15); 

    
    if (healthPercentage < 0.3) {
        iSetColor(255, 0, 0); 
    }
}


void lvl2initialize(){
	p2.pos_x=0;
	p2collcheck.pos_x=0;
	p2.pos_y=100;
	p2collcheck.pos_y=100;
	lvl2plat.pos_x=600;
	lvl2plat.pos_y=250;
	lvl2plat.pos_x=500;
	lvl2plat.pos_y=300;
	fallblade.pos_x=230;
	fallblade.pos_y=250;
	


}

void iDraw()
{
	iClear();
	
	
	if(gamephase==0){
		 if(subgamephase==0){
		iShowImage(0,0,resWidth,resHeight,bgMenuShower[0]);
		iShowImage(350,250,300,250,bgMenuShower[1]);
		iShowImage(450,100,80,50,bgMenuShower[l]);
		iShowImage(900,550,80,50,bgMenuShower[m]);
		iShowImage(30,550,80,50,bgMenuShower[aboutindex]);
		
	
		

		 

		}
		  else if (subgamephase==1){
			iShowImage(0,0,resWidth,resHeight,settingMenuShower[0]);
			iShowImage(150,125, 700,450,settingMenuShower[1]);
			iShowImage(190,185, 600,350,settingMenuShower[2]);
			iShowImage(150,550,700,150,settingMenuShower[3]);
			iSetColor(0,0,0);
			iText(350,450,"Music", GLUT_BITMAP_TIMES_ROMAN_24);

			iText (350,400,"Sound",GLUT_BITMAP_TIMES_ROMAN_24);
			iShowImage (500,450,40,20,settingMenuShower[settingindex]);
			iShowImage(750,550,80,50,settingMenuShower[exitindex]);

			


		} 

		  else if(subgamephase==2){
			  iShowImage(0,0,resWidth,resHeight,settingMenuShower[0]);
			iShowImage(150,125, 700,450,settingMenuShower[1]);
			iShowImage(190,185, 600,350,settingMenuShower[2]);
			iShowImage(150,550,700,150,settingMenuShower[3]);
			
		  }

		  else if(subgamephase==3){
			 iShowImage(0,0,resWidth,resHeight,bgMenuShower[0]);
			  iShowImage(100 ,500,250,50,settingMenuShower[newgamemenuindex]);
			  iShowImage(100,430,250,50,settingMenuShower[continuemenuindex]);
			   iShowImage(100,360,250,50,settingMenuShower[settingmenuindex]);
			    iShowImage(100,290,250,50,settingMenuShower[exitmenuindex]);
			 


		  }


		  else if (subgamephase==4){

			 iShowImage(0,0,resWidth,resHeight,bgMenuShower[0]);
			 iShowImage(150,125, 700,450,settingMenuShower[1]);
			iShowImage(190,185, 600,350,settingMenuShower[2]);
			iShowImage(150,550,700,150,settingMenuShower[19]);
			iShowImage(290,330,60,60,settingMenuShower[24]);
			iShowImage(390,330,60,60,settingMenuShower[24]);
			iShowImage(490,330,60,60,settingMenuShower[24]);
			iShowImage(590,330,60,60,settingMenuShower[24]);

			iShowImage(300,350,30,30,settingMenuShower[20]);
			iShowImage(400,350,30,30,settingMenuShower[21]);
			iShowImage(500,350,30,30,settingMenuShower[22]);
			iShowImage(600,350,30,30,settingMenuShower[23]);

			
		  }


		
		

	}
	

	
	else if (gamephase==1){
		
		

	
	script();
	
	

}
	else if (gamephase==2){
		iShowImage(0,0,resWidth,resHeight,bglevel2);

		tileShower2();
		/*climbverline.pseudoimage();
		p2collcheck.pseudoimage();
		spike.pseudoimage();
		spike2.pseudoimage();
		lvl2upground.pseudoimage();
		p2.pseudoimage();
		lvl2ground.pseudoimage();
		
		lvl2ground2.pseudoimage();*/
	
			p2.lvl2charecterIdle();
		fallblade.showfallblade();
		lvl2plat.showlvl2platform();
		lvl2plat2.showlvl2platform();
		p2.lvl2charecterRun();
		p2.charecterjump();
		h4.showheart();
		h5.showheart();
		h6.showheart();
		if(lvl2appleinidet){
		initializelvl2Apples();
		lvl2appleinidet=false;
		}
		lvl2AppleCount();

		showAlllvl2Apples();
		
		
		if(!jumpdec){
		p2.lvl2forcegravitation();
		p2collcheck.lvl2forcegravitation();
		}

		if(c1.collider(p2,lvl2ground) || c1.collider(p2collcheck,lvl2upground) || c1.collider(p2collcheck,lvl2ground2)){
			onground2 =true;
			climbdec=false;
		   

		}

		else {
			onground2 = false;

		}


		if(c1.collider(p2collcheck,lvl2plat)){
			platfall1=true;
			onground2=true;
			climbdec=false;
			
		}
		if(c1.collider(p2collcheck,lvl2plat2)){
			platfall2=true;
			onground2=true;
			climbdec=false;
			
		}
		if(platfall1){
			lvl2plat.fallplatgravity();
		}
		if(platfall2){
			lvl2plat2.fallplatgravity();
		}
		

	if(c1.collider(p2collcheck,spike) || c1.collider(p2collcheck,spike2)){
		p2.life--;
		
		
		if(p2.life<=2){
			h6.hactive=false;
		}
		if(p2.life<=1){
			h5.hactive=false;
		}
		if(p2.life<=0){
			h4.hactive=false;
		}
		lvl2initialize();
	}

	 if(p2collcheck.pos_y<=0){
		 p2.life--;
		if(p2.life<=2){
			h6.hactive=false;
		}
		if(p2.life<=1){
			h5.hactive=false;
		}
		if(p2.life<=0){
			h4.hactive=false;
		}

		lvl2initialize();
		 
	 }
if(c1.collider(p2collcheck,fallrange)){
	bladefalldec=true;
}

	if(bladefalldec){
		fallblade.fallbladegravity();

	}
	if(fallblade.pos_y<=0 && lvl2life<=0){
		fallblade.pos_y=250;
		bladefalldec=false;
	}

	if(c1.collider(p2collcheck,fallblade)){
		
		if(bladelife){
		p2.life--;
		bladelife=false;
		}
		
		if(p2.life<=2){
			h6.hactive=false;
		}
		if(p2.life<=1){
			h5.hactive=false;
		}
		if(p2.life<=0){
			h4.hactive=false;
		}

		
	
	}

	if(c1.collider(p2collcheck, climbverline)){
		climbdec=true;
		onground2 =true;
		
	}

	 if(p2.life<=0){
			lvl2inmenu=true;
		
			iShowImage(150,125, 700,450,settingMenuShower[1]);
			iShowImage(190,185, 600,350,settingMenuShower[2]);
			iShowImage(150,550,700,150,settingMenuShower[17]);
			iShowImage(450,350,50,50,settingMenuShower[18]);
			
			//iShowImage (500,450,40,20,settingMenuShower[settingindex]);
			//iShowImage(750,550,80,50,settingMenuShower[exitindex]);

	 }

	 if(p2collcheck.pos_x>=850){
		 lvl2complete=true;
	 }

	 if(lvl2complete){
		 showcompletemenu();
	 }
	
	}
	

	else if (gamephase==3){

		
		tileShower3();
		
		
		 drawBullets();
		 drawCrosshair();
			//drawEnemies();
			
		// showAllEnemies();
		
		checkBulletEnemyCollisions();
		//enemyatk();

		/*for(int i=0;i< MAX_BULLETS;i++){
			if(bcoll(bullets[i],e1)){
				e1.health-=20;
				bullets[i].x=p3.pos_x;
				bullets[i].active=false;
			}
		}*/
		p3.showhealth();
		if(p3.active){
		p3.charecterIdle();
		p3.charecterjump();
		p3.charecterRun();
		p3.charectershoot();
		}

		if(!p3.active){
			p3.charecterdead();
		}
		cout<<"p3.health:"<<p3.health<<endl;
		showAllEnemies();
		
		//e1.showenemy();
		//e1.showtarenemy();

		 removeOffScreenEnemies();
		 if (gamephase == 3) {
		
        timer404.start();  // Start the timer only when gamephase == 3
    
    timer404.draw();

	if(!timer404.isActive && p3.health>0){
		lvl3complete=true;
	}

	if(lvl3complete){
		showcompletemenu();
	}
}
		//p3.pseudoimage();
		//e1.pseudoimage();
		//b.pseudoimage();
		 
		
		
	

		
	
	if(p3.health<=0){
			lvl3inmenu=true;
		
			iShowImage(150,125, 700,450,settingMenuShower[1]);
			iShowImage(190,185, 600,350,settingMenuShower[2]);
			iShowImage(150,550,700,150,settingMenuShower[17]);
			iShowImage(450,350,50,50,settingMenuShower[18]);
			
			//iShowImage (500,450,40,20,settingMenuShower[settingindex]);
			//iShowImage(750,550,80,50,settingMenuShower[exitindex]);

	 }

	
	
	

}
	


	if(gamephase==4){
		lvl4tileshower();
		drawBullets();
		 drawCrosshair();
		 

		p4.showhealth();
		if(p4.active){
		p4.charecterIdle();
		p4.charecterjump();
		p4.charecterRun();
		p4.charectershoot();
		}

		if(!p4.active){
			p4.charecterdead();
		}
		boss.showidle();
		boss.showatk1();
		boss.showatk2();
		bossfunction();
		boss.showbullet();
		boss.showbullet2();
		drawHealthBar(500,700);
		iShowImage(450,700,30,30,bossatk2AnimShower[5]);

		//iShowImage(100,100,250,150,bossAnimShower[bossindex]);
		//iShowImage(400,100,250,150,bossAnimShower[1]);


	}
}
	
	

/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	cout << "position mx :"<<mx<<endl;
	cout << "positon  my  :"<<my<<endl;

}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)



{	
	if(gamephase==3 || gamephase==4){

		 crosshairX=mx;
		crosshairY=my;



	}
	
	
	
	if(gamephase==0 && subgamephase==0){
	if(mx>=450 && mx<=530 && my>=100 && my<=150){
		l=2;
		
	}
	
	else if(mx>=900 && mx<=980 && my>=550 && my<=600){
		m=5;
	}

	else if(mx>=30 && mx<=110 && my>=550 && my<=600){
		aboutindex=7;
	
	}
	else{
		l=3;
		m=4;
		aboutindex=6;
	}
	
	}

		else if(gamephase==0&&subgamephase==1){
			if(mx>=750 && mx<=830 && my>=550 && my<=600){
				exitindex=7;
			}
			else{
				exitindex=6;
			}


		}

		else if(gamephase==1){
			if(mx>=750 && mx<=830 && my>=550 && my<=600){
				
				exitindex=7;
			}
			else{
				
				exitindex=6;
			}
		}

		else if (subgamephase==3){

			if(mx>=100 && mx<=350 && ((my>=500 && my<=550) ||( my>=430 && my<=470) || (my>=360 && my<=420) ||  (my>=290 && my<=340))){
				if(hovermusiccontroller){
					 PlaySound("sfx1", NULL, SND_ASYNC);
				}
					 hovermusiccontroller = false;
		}

			else{
				hovermusiccontroller =true;
	
				
			}
			if(mx>=100 && mx<=350 && my>=500 && my<=550){
					
						
					
				
				newgamemenuindex =9;
			}
			else {

				
				
				newgamemenuindex=8;
				
			}
			if(mx>=100 && mx<=350 && my>=430 && my<=470){
				continuemenuindex =11;
				

			}
			else{
				continuemenuindex=10;
				
			}

			if(mx>=100 && mx<=350 && my>=360 && my<=420){
				settingmenuindex =13;
				
			}
			else{
				settingmenuindex=12;
				
			}
			if(mx>=100 & mx<=350 && my>=290 && my<=340){
				exitmenuindex=15;
				
			}
			else{
				exitmenuindex=14;
			
			}


		}
		

	
}

//else if (gamephase==0 && subgamephase==1){

	//if(mx>=500 && mx<=540 && my>=450 && my<=470){
		//settingindex=5;
	//}
	//else{
		//settingindex=4;
	//}
//}
//}
	
//

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{		
	
		
		  if(gamephase==0 && subgamephase==4){
				
				 if(mx >= 290 && mx<=350 && my>=330 && my<=390){
					 gamephase=1;
				 }
				 else if(mx >= 390 && mx<=450 && my>=330 && my<=390){
					 gamephase=2;
				 }
				  else if(mx >= 490 && mx<=550 && my>=330 && my<=390){
					 gamephase=3;
				 }

				    else if(mx >= 590 && mx<=650 && my>=330 && my<=390){
					 gamephase=4;
				 }
		  }
		
		
		if(gamephase==3){
			p3.shootdec=true;
			//firedec=true;
			 fireBullet();
			}

		if(gamephase==4){
			p4.shootdec=true;
			fireBulletP4();
		}
		

	

	
		if(mx>=450 && mx<=530 && my>=100 && my<=150){
			subgamephase=3;
		}


		else if(losemenu && gamephase==1){
				
		if(mx>=450 && mx<=500 && my>=350 && my<=400){
			p1.life=3;
			
			lvl1fullinitialize();
			losemenu=false;
			

		}
		}

		else if(lvl1complete && gamephase==1){
			if(mx>=450 && mx<=500 && my>=350 && my<=400){
			p1.life=3;
			lvl1fullinitialize();
			lvl1complete=false;



		}

			else if(mx>=350 && mx<=400 && my>=350 && my<=400){
				gamephase=0;
				p1.life=3;
				lvl1fullinitialize();
				lvl1complete=false;
			}

			else if(mx>=550 && mx<=600 && my>=350 && my<=400){

				gamephase=2;
				lvl1complete=false;
			}
		}


		else if(lvl2complete && gamephase==2){
			if(mx>=450 && mx<=500 && my>=350 && my<=400){
			//p1.life=3;
			lvl2initialize();
			lvl2complete=false;



		}

			else if(mx>=350 && mx<=400 && my>=350 && my<=400){
				gamephase=0;
				
				lvl2initialize();
				lvl2complete=false;
			}

			else if(mx>=550 && mx<=600 && my>=350 && my<=400){

				gamephase=3;
				lvl2complete=false;
			}
		}
		else if(lvl3complete && gamephase==3){
			if(mx>=450 && mx<=500 && my>=350 && my<=400){
			
			
			 lvl3initializeGame();
			 lvl3complete=false;



		}

			else if(mx>=350 && mx<=400 && my>=350 && my<=400){
				gamephase=0;
				 lvl3initializeGame();
				
				lvl3complete=false;
			}

			else if(mx>=550 && mx<=600 && my>=350 && my<=400){

				gamephase=4;
				lvl3complete=false;
			}
		}
		
		else if(lvl2inmenu && gamephase==2){
				
		if(mx>=450 && mx<=500 && my>=350 && my<=400){
			p2.life=3;
			lvl2inmenu=false;


		}
		}

		else if(lvl3inmenu && gamephase==3){
			if(mx>=450 && mx<=500 && my>=350 && my<=400){
				
				
				
			lvl3inmenu=false;
			 lvl3initializeGame();


		}
		}
	
		

		else if(gamephase==0 && subgamephase==3){
			 if(mx>=100 && mx<=350 && my>=500 && my<=550){
				// gamephase=1;

				 subgamephase=4;
			 }


			

				 


			 




			 else if(mx>=100 & mx<=350 && my>=290 && my<=340){
				 gamephase=0;
				 subgamephase=0;
		}
		 }
		else if(mx>=900 && mx<=980 && my>=550 && my<=600){
			subgamephase=1;
		}

		else if (gamephase==0 && subgamephase==1){

			
			 if(mx>=500 && mx<=540 && my>=450 && my<=470){
				if(musicController==true){

				musicController=false;
				settingindex=5;
				PlaySound(NULL, NULL, SND_PURGE);
			}

				else if(musicController==false){
					musicController=true;
					settingindex=4;
					 PlaySound("openingmusicAH.wav", NULL, SND_LOOP | SND_ASYNC);
					
				}

				
			}
			 else if(mx>=750 && mx<=830 && my>=550 && my<=600){
				
			subgamephase=0;

			
			
		}
 
			
		


		
	
		
		
	}
		else if(mx>=30 && mx<=110 && my>=550 && my<=600){
			subgamephase=2;
		}

		 /*else if(gamephase==1){
			 if(mx>=750 && mx<=830 && my>=550 && my<=600) {
				 gamephase=0;
			 }

		 }*/

		
		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{	if(key == 27 ){
			if(gamephase==1 || gamephase==2 || gamephase==3){
			gamephase=0;
			subgamephase=4;
			}
		
	}
	if (key == '\r')
	{
		
	}

	if (key == ' '){
			
			if(onground && gamephase==1){
				p1.cjumpdec=true;
			}

			if(onground2 && gamephase==2 && !climbdec){
			jumpdec =true;
			}

			
				

			
		}

		
			
	

	
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	
	
	if (key == GLUT_KEY_RIGHT){

			//dx--;
		
		posleftdetector=false;
		idledetector=false;
		
		if(gamephase==3){
		p3.pos_x+=3;
		}
		if(gamephase==2){
		p2.pos_x+=3;
		
		p2collcheck.pos_x+=3;
		}
		if(gamephase==1){
		p1.pos_x+=3;
		p1collcheck.pos_x+=3;
		p1botline.pos_x+=3;
		}
		
		
		movementdetector++;
		counter=0;
	
		if(!firedec){
			b.pos_x+=3;
		}

	
		if(gamephase==4){
			p4.pos_x+=3;
			p4collcheck.pos_x+=3;

		}
		
		
		
			

		
			
		
	

	}

	

	//cout<<movementdetector<<endl;

	
	if (key == GLUT_KEY_LEFT)
	{	
		//dx++;
		posleftdetector=true;
		idledetector=false;
		if(!firedec){
			b.pos_x-=3;
		}
		if(gamephase==1){
		p1.pos_x-=3;
		p1collcheck.pos_x-=3;
		p1botline.pos_x-=3;
		}
		if(gamephase==2){
		p2.pos_x-=3;
		p2collcheck.pos_x-=3;
		}
		if(gamephase==3){
		p3.pos_x-=3;
		}
		if(gamephase==4){
			p4.pos_x-=3;
			p4collcheck.pos_x-=3;

		}
	
		
		movementdetector++;
		counter=0;
	}


	if(key == GLUT_KEY_UP){
		if(climbdec){

			p2.pos_y++;
			p2collcheck.pos_y++;
		}
	}

	if(key == GLUT_KEY_DOWN){
		if(climbdec){
			p2.pos_y--;
			p2collcheck.pos_y--;
		}
	}
	
	if (key == GLUT_KEY_HOME)
	{
		
	}
	
}



		
	void jumper(){
		boss.idleindex++;
			if(boss.idleindex>=3){
				boss.idleindex=0;
			}
	
		boss.atk1index++;
		if(boss.atk1index>=8){
			boss.atk1index=0;
		}
		boss.atk2index++;
		if(boss.atk2index>=6){
			boss.atk2index=0;
		}
		boss.b2index++;
		if(boss.b2index>=8){
			boss.b2width-=200;
		}
		if(boss.b2index>=10){

			boss.b2index=0;
			boss.b2width=50;
		}

		if(p1.cinAir){
			p1.cjumpindex++;
		}
		
		if(!p1.cinAir  ){
			p1.cjumpindex=0;

		}
		if(p1.cjumpindex>=10){
			p1.cjumpindex=0;
		}
		

		if(inAir ){
		jumpindex++;
		}
		
		if(!inAir  ){
			jumpindex=0;

		}
		if(jumpindex>=10){
			jumpindex=0;
			
		}
		
		bossindex++;
		if(bossindex>=3){
			bossindex=0;
		}


		for(int i=0;i<tarenemy.size();i++){
			tarenemy[i].tarindex++;
			if(tarenemy[i].tarindex>=3){
				tarenemy[i].tarindex=0;
			}
		}

		for(int i=0;i<flyenemy.size();i++){
			flyenemy[i].flyindex++;
			if(flyenemy[i].flyindex>=3){
				flyenemy[i].flyindex=0;
			}
			flyenemy[i].bindex++;
			if(flyenemy[i].bindex>=8){
				flyenemy[i].bindex=0;
			}
		}
		
		
	}
	void idle(){

			

		if(p3.shootdec){
			shootindex++;
			if(shootindex>=3){
				p3.shootdec=false;
				shootindex=0;
				
			}

		}
		if(p4.shootdec){
			shootindex++;
			if(shootindex>=3){
				p4.shootdec=false;
				shootindex=0;
				
			}

		}

		if(!idledetector && movementdetector>0 && !posleftdetector ){
			i++;
				if(i>=7){
					i=0;
				}

		

		}

		else if (!idledetector && movementdetector>0 && posleftdetector){

			j++;
			if(j>=7){
				j=0;
			}
		}

		if(!p3.active){
			deadindex++;
			if(deadindex>=9){
				deadindex=0;
				
			}

		}

		sp++;
		if(sp>=28){
			sp=24;
		}

		 if(idledetector){
		idleindex++;

		
		if(idleindex>=9){
			idleindex=0;
		}

		}

		counter++;
			if(counter>=3){
				 movementdetector=0;
				counter=0;
				idledetector=true;
			}

			//cout<<counter<<endl;

			

	}


	void Timer(){

	}
void emove(){
		if(active){
			boss.bpos_x-=15;
	}
		if(bossmove){
			// Define the desired distance between boss and p4
    float desiredDistance = 300.0f; // Adjust this value as needed
    float speed = 2.5f; // Adjust speed for smooth movement

    // If p4 moves left, the boss should follow while keeping distance
    float targetPosition = p4.pos_x + desiredDistance;
	
    if (boss.pos_x > targetPosition) {
        boss.pos_x -= speed; 
		boss.bpos_x=boss.pos_x;
			boss.b2pos_x=boss.pos_x-10;// Move left smoothly
    } else if (boss.pos_x < targetPosition) {
        boss.pos_x += speed; 
		boss.bpos_x=boss.pos_x;
			boss.b2pos_x=boss.pos_x-10;// Move right smoothly (in case of small errors)
    }
		}

		//cout<<jumpdec0<<endl;

	//lposdet =enemymove(e1,p3);
	 //moveAllEnemies();

	if(gamephase==1){
		

	if(p1.cjumpdec && !posleftdetector){
			p1.pos_x+=10;
			p1collcheck.pos_x+=10;
			p1.pos_y+=10;
			p1collcheck.pos_y+=10;
			p1botline.pos_x+=10;
			p1botline.pos_y+=10;
			p1.cinAir=true;
			onground=false;
		}
	else if(p1.cjumpdec && posleftdetector){
			
			p1.pos_x-=10;
			p1collcheck.pos_x-=10;
			p1.pos_y+=10;
			p1collcheck.pos_y+=10;
			p1botline.pos_x-=10;
			p1botline.pos_y+=10;
			p1.cinAir=true;
			onground1=false;
		}

		if(p1collcheck.pos_y>=ctemppos_y+120){
			p1.cjumpdec=false;
		}

		if(!p1.cjumpdec){
		ctemppos_y=p1collcheck.pos_y;
	}
	} 


	if(gamephase==2){
		if(onground2){
		temppos_y=p2collcheck.pos_y;
	}

	if(jumpdec && !posleftdetector){
			p2.pos_x+=10;
			p2collcheck.pos_x+=10;
			p2.pos_y+=10;
			p2collcheck.pos_y+=10;
			inAir=true;
			onground2=false;
		}
	else if(jumpdec && posleftdetector){
			
			p2.pos_x-=10;
			p2collcheck.pos_x-=10;
			p2.pos_y+=10;
			p2collcheck.pos_y+=10;
			inAir=true;
			onground2=false;
		}

		if(p2collcheck.pos_y>=temppos_y+100){
			jumpdec=false;
		}
	}

			bgindex++;
				if(bgindex>=112){
					bgindex =1;
				}
	b.pos_x+=50;
	

		for(int i=0;i<enemies.size();i++){
			enemies[i].enemyindex++;
	if(enemies[i].enemyindex>=39){
		enemies[i].enemyindex=0;
	}

	if(!lposdet){
	enemies[i].lenemyindex++;
	if(enemies[i].lenemyindex>=79){
		enemies[i].lenemyindex=40;
	}
		}
	
		
	
}

		for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i].isAttacking) {
            enemies[i].enemyatkindex++;
            if (enemies[i].enemyatkindex >= 62) { // Reset attack animation index
                enemies[i].enemyatkindex = 0;
				// p3.health-=20;
				 //p3.healthbarwidth-=40;
                //enemies[i].isAttacking = false; // Reset attack state
            }
        }
    }

		
}


	void iTimerFunction() {
    bulletMovement();
}



int main()
{	
	///srand((unsigned)time(NULL));
	iInitialize(resWidth, resHeight, "Ancient Hunter");
	srand(time(0));
	enemyAnimSaver();
	mcIdleAnimSaver();
	mcAnimWalkSaver();
	mcAnimLeftWalkSaver();
	mcAnimJumpSaver();
	mcAnimShootSaver();
	 leftAnimJumpSaver();
	bgMenuSaver();
	settingMenuSaver();
	 bgAnimSaver();
	 tileAnimSaver();

	initializeBullets();
	//initEnemies();

	

	if(musicController){
	PlaySound("openingmusicAH.wav",NULL,SND_LOOP | SND_ASYNC);
	}
	
	
	Gameobject o1(200,200,700,400);

	


	
	


	iSetTimer(40,emove);
	
	iSetTimer(100,jumper);
	iSetTimer(100,idle);
	iSetTimer(40, iTimerFunction);
	iSetTimer(40, iTimeFunction);
	

	
	 a =iLoadImage("BG.png");
	///updated see the documentations
	iStart();
	
	return 0;
}