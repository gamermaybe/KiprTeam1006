#include <kipr/wombat.h>

int ARM = 0;
int CLAW = 1;

int up = 0;
int down = 564;
int barely_down = 300;
int very_down = 800;
int closed = 2047;
int open = 1333;

int LEFT = 3;
int RIGHT = 0;
 

int main()
{
    wait_for_light (0);
    
    enable_servos();
    
    set_servo_position(CLAW,closed);
    set_servo_position(ARM,up);
    msleep(500);
  
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    //backup and square up
    while (get_motor_position_counter(LEFT) < 1200) {
		motor(LEFT,40);
        motor(RIGHT,-40);
    }
    ao();
    
    set_servo_position(CLAW,closed);
    set_servo_position(ARM,up);
    msleep(500);
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);

    //pivot right and knock down color squares
    while(get_motor_position_counter(LEFT) > -2000) {
    	motor(LEFT,-100);
        motor(RIGHT,-10);
    }
   
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
   //backup straight from boxes      
    while (get_motor_position_counter(LEFT) < 1200) {
		motor(LEFT,60);
        motor(RIGHT,-40);
     }
   
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    ao();
    
    set_servo_position(CLAW,open);
    msleep(500);
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    //pivot to face yellow boxes
    while (get_motor_position_counter(LEFT) < 1000) {
		motor(LEFT,98);
        motor(RIGHT,100);
    }
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    //backup and square up
    while (get_motor_position_counter(LEFT) < 1000) {
		motor(LEFT,40);
        motor(RIGHT,-40);
    }
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    //approach yellow boxes
    while (get_motor_position_counter(LEFT) > -1600) {
		motor(LEFT,-100);
        motor(RIGHT,100);
    }
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    ao();
        
    set_servo_position(ARM,down);
    msleep(1000);
    set_servo_position(CLAW,closed);
    msleep(1000);
    set_servo_position(ARM,up);
    msleep(500);
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    while (get_motor_position_counter(LEFT) > -1344) {
		motor(LEFT,-38);
        motor(RIGHT,40);
    }
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    ao();
    
    msleep(500);
    set_servo_position(CLAW,open);
    msleep(500);
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    while(get_motor_position_counter(LEFT) > -2000) { 
    	motor(LEFT,-100);
        motor(RIGHT,-100);
    }
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    ao();
    
    set_servo_position(ARM,very_down);
    msleep(500);
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    while(get_motor_position_counter(RIGHT) < 10) {
    	motor(RIGHT, 75);
        motor(LEFT, -75);
    }
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    while(get_motor_position_counter(RIGHT) < 6000) {
    	motor(RIGHT, 80);
        motor(LEFT, 100);
    }
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    while (digital (0) == 0 && digital (1) == 0){
    	motor(LEFT,-60);
        motor(RIGHT,-60);
    }
    while ((digital (0) == 0 && digital (1) == 1) || (digital (0) == 1 && digital (1) == 0)){
    	motor(LEFT, -60);
        motor(RIGHT, -60);
    }
    
    // Goes very down
    enable_servos();
    set_servo_position(ARM,very_down);
    msleep(500);
    set_servo_position(CLAW,open);
    msleep(500);
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    while (get_motor_position_counter(LEFT) < 6500) {
		motor(LEFT, 73);
        motor(RIGHT, 75);
    }
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    // goes right
    while (get_motor_position_counter(LEFT) < 750) {
		motor(LEFT, 100);
        motor(RIGHT, -100);
    }
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    // goes backward
    while (get_motor_position_counter(RIGHT) > -1000) {
		motor(LEFT, -100);
        motor(RIGHT, -100);
    }
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    // goes left
    while (get_motor_position_counter(RIGHT) < 850) {
		motor(LEFT, -100);
        motor(RIGHT, 100);
    }
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    // goes forward a bit 
    while (get_motor_position_counter(LEFT) < 850) {
		motor(LEFT, 75);
        motor(RIGHT, 75);
    }
    
    ao();
    
    set_servo_position(CLAW,closed);
    msleep(500);
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    // goes right
    while (get_motor_position_counter(LEFT) < 850) {
		motor(LEFT, 75);
        motor(RIGHT, -75);
    }
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    ao();
    
    set_servo_position(CLAW,closed);
    set_servo_position(ARM,up);
    msleep(500);
}