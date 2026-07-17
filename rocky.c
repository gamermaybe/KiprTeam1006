#include <kipr/wombat.h>

// Rocky (AKA GRABBY)
//mykee is the best

int ARM = 0;
int CLAW = 1;

int up = 0;
int down = 564;
int barely_down = 300;
int very_down = 650;
int closed = 2047;
int open = 1333;

int LEFT = 3;
int RIGHT = 0;

int main()
{ 
    wait_for_light(0);
    shut_down_in(119);
    
    enable_servos();
    
    set_servo_position(CLAW,closed);
    set_servo_position(ARM,up);
    msleep(500);
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    //knock down randomized cubes by twisting (start box)
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
    
    //back up to square with yellow cubes on pallete (start box)
    while(get_motor_position_counter(LEFT) > -600) {
    	motor(LEFT,-100);
        motor(RIGHT,-100);
    }
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    //square up with yellow cubes on pallete (start box)
    while (get_motor_position_counter(LEFT) > -1200) {
		motor(LEFT,-40);
        motor(RIGHT,40);
    }
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    //moves towards yellow cubes (start box)
    while (get_motor_position_counter(LEFT) < 300) {
		motor(LEFT,95);
        motor(RIGHT,100);
    }
    ao();
    
    set_servo_position(CLAW,open);
    msleep(500);
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    //lining up with yellow cubes (start box)
    while (get_motor_position_counter(LEFT) < 200) {
		motor(LEFT,98);
        motor(RIGHT,100);
    }
    ao();
    
    //moves claw down and grabs yellow cubes (start box)
    set_servo_position(ARM,barely_down);
    msleep(1000);
    set_servo_position(CLAW,closed);
    msleep(1000);
    set_servo_position(ARM,up);
    msleep(500);
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    //moves forward to place yellow cubes onto internal loading dock (start box)
    while (get_motor_position_counter(LEFT) < 1200) {
		motor(LEFT,98);
        motor(RIGHT,100);
    }
    ao();
    msleep(500);
    
    //sets yellow cubes onto internal loading dock
    set_servo_position(CLAW,open);
    msleep(500);
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    //back up a little bit (starting box)
    while(get_motor_position_counter(LEFT) > -2000) { 
    	motor(LEFT,-100);
        motor(RIGHT,-100);
    }
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    // sets arm down to move pom poms out of black line 
    set_servo_position(ARM,very_down);
    msleep(500);
    
    //turns slightly (warehouse)
    while(get_motor_position_counter(RIGHT) < 5) {
    	motor(RIGHT, 75);
        motor(LEFT, -75);
    }
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    //moving to middle of warehouse floor (warehouse floor)
    while(get_motor_position_counter(RIGHT) < 6000) {
    	motor(RIGHT, 80);
        motor(LEFT, 100);
    }
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    //backing up until back buttons hit the pipe wall thing (warehouse floor)
    while (digital (0) == 0 && digital (1) == 0){
    	motor(LEFT,-60);
        motor(RIGHT,-60);
    }
    while ((digital (0) == 0 && digital (1) == 1) || (digital (0) == 1 && digital (1) == 0)){
    	motor(LEFT, -40);
        motor(RIGHT, -40);
    }
    enable_servos();
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    //preps claw for moving something (warehouse floor)
    set_servo_position(ARM,very_down);
    msleep(500);
    set_servo_position(CLAW,open);
    msleep(500);
    
    //moving towards cube by botguy doors (warehouse floor)
    while (get_motor_position_counter(LEFT) < 6500) {
		motor(LEFT, 73);
        motor(RIGHT, 75);
    }
    ao();
    
    //STOP HERE AND LOOK AT THIS COMMENT
    //PLEASE STOP
    //I SAID STOP
    // NOTE: this down we can adjust to get the traffic cone and bring to the starting box
    // ALSO: please run this first so we can gauge how this does before we change anything else
    //now you may continue
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    while (get_motor_position_counter(LEFT) < 750) {
		motor(LEFT, 100);
        motor(RIGHT, -100);
    }
    ao();
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    while (get_motor_position_counter(RIGHT) > -850) {
		motor(LEFT, -100);
        motor(RIGHT, -100);
    }
    ao();
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    while (get_motor_position_counter(RIGHT) < 850) {
		motor(LEFT, -100);
        motor(RIGHT, 100);
    }
    ao();
    
    while (get_motor_position_counter(LEFT) < 850) {
		motor(LEFT, 75);
        motor(RIGHT, 75);
    }
    ao();
    
    set_servo_position(CLAW,closed);
    msleep(500);
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    while (get_motor_position_counter(LEFT) < 850) {
		motor(LEFT, 75);
        motor(RIGHT, -75);
    }
    ao();
}
