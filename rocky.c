#include <kipr/wombat.h>

// Rocky (AKA GRABBY)

int ARM = 0;
int CLAW = 1;
int LEFT = 3;
int RIGHT = 0;
int FULL_FORWARD = 100;
int FULL_BACKWARD = -100;

int up = 0;
int down = 564;
int barely_down = 300;
int very_down = 800;
int closed = 2047;
int open = 1333;



int main()
{
    //wait_for_light(0);
    shut_down_in(119);
    
    enable_servos();
    // Closes Claw
    set_servo_position(CLAW,closed);
    // Puts the arm all the way up 
    set_servo_position(ARM,up);
    msleep(500);
  
    ao();
    
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    
    //backup and square up
    while (get_motor_position_counter(LEFT) > -1300) {
		motor(LEFT,FULL_BACKWARD);
        motor(RIGHT,FULL_BACKWARD);
    }
    
    ao();
    set_servo_position(CLAW,closed);
    set_servo_position(ARM,up);
    msleep(500);
    
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);

    //pivot right and knock down color squares
    while(get_motor_position_counter(RIGHT) > -1550) {
    	motor(LEFT,FULL_FORWARD);
        motor(RIGHT,-20);
    }
   
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    
    //backup straight from boxes      
    while (get_motor_position_counter(LEFT) > -1300) {
		motor(LEFT,FULL_BACKWARD);
        motor(RIGHT,FULL_BACKWARD);
     }
   
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    
    ao();
    set_servo_position(CLAW,open);
    msleep(500);
    
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    
    //pivot to face yellow boxes
    while (get_motor_position_counter(LEFT) < 1400) {
		motor(LEFT,96);
        motor(RIGHT,FULL_FORWARD);
    }
    
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    
    //backup and square up
    while (get_motor_position_counter(LEFT) > -1600) {
		motor(LEFT,FULL_BACKWARD);
        motor(RIGHT,FULL_BACKWARD);
    }
    
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    
    //approach yellow boxes
    while (get_motor_position_counter(LEFT) < 1600) {
		motor(LEFT,FULL_FORWARD);
        motor(RIGHT,FULL_FORWARD);
    }
    
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    
    ao();
    set_servo_position(ARM,down);
    msleep(1000);
    set_servo_position(CLAW,closed);
    msleep(1000);
    set_servo_position(ARM,up);
    msleep(500);
    
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    
    // turns left
    while (get_motor_position_counter(LEFT) > -2000) {
		motor(LEFT,-40);
        motor(RIGHT,40);
    }
    
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    
    ao();
    msleep(500);
    set_servo_position(CLAW,open);
    msleep(500);
    
    // goes backwards
    while(get_motor_position_counter(LEFT) > -2200) { 
    	motor(LEFT,FULL_BACKWARD);
        motor(RIGHT,FULL_BACKWARD);
    }
    
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    
    ao();
    
    set_servo_position(ARM,very_down);
    msleep(500);
    
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    // goes left
    while(get_motor_position_counter(RIGHT) < 1000) {
    	motor(RIGHT, 75);
        motor(LEFT, -75);
    }
    
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    // goes foward while slowly going left 
    while(get_motor_position_counter(RIGHT) < 6400) {
    	motor(RIGHT, 74);
        motor(LEFT,FULL_FORWARD);
    }
    
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    
    // goes backward while waiting for one of the buttons on the back to get pressed
    while (digital (0) == 0 && digital (1) == 0){
    	motor(LEFT,FULL_BACKWARD);
        motor(RIGHT,FULL_BACKWARD);
    }
    while ((digital (0) == 0 && digital (1) == 1) || (digital (0) == 1 && digital (1) == 0)){
    	motor(LEFT,FULL_BACKWARD);
        motor(RIGHT,FULL_BACKWARD);
    }
    
    // arm goes very down and claw opens to help with poms getting stuck
    enable_servos();
    set_servo_position(ARM,very_down);
    msleep(500);
    set_servo_position(CLAW,open);
    msleep(500);
    
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    // leftish
    while (get_motor_position_counter(LEFT) < 6500) {
		motor(LEFT, 25);
        motor(RIGHT, 75);
    }
    
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    /*
    // goes right
    while (get_motor_position_counter(LEFT) < 750) {
		motor(LEFT, 100);
        motor(RIGHT, -100);
    }
    */
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    // goes backward
    while (get_motor_position_counter(RIGHT) > -1200) {
		motor(LEFT, -100);
        motor(RIGHT, -100);
    }
    
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    // goes leftish
    while (get_motor_position_counter(RIGHT) < 850) {
		motor(LEFT, -70);
        motor(RIGHT, 100);
    }
    
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    // goes forward a bit 
    while (get_motor_position_counter(LEFT) < 850) {
		motor(LEFT, 75);
        motor(RIGHT, 75);
    }
    
    ao();
    
    set_servo_position(CLAW,closed);
    msleep(500);
    
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    // goes right
    while (get_motor_position_counter(LEFT) < 850) {
		motor(LEFT, 75);
        motor(RIGHT, -75);
    }
    
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    
    ao();
    
    set_servo_position(CLAW,closed);
    set_servo_position(ARM,up);
    msleep(500);
}