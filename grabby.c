#include <kipr/wombat.h>

int ARM = 0;
int CLAW = 1;

int up = 0;
int down = 564;
int barely_down = 300;
int closed = 2047;
int open = 1333;

int LEFT = 3;
int RIGHT = 0;

int main()
{
    enable_servos();
    
    set_servo_position(CLAW,closed);
    set_servo_position(ARM,up);
    msleep(500);
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
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
    
    while(get_motor_position_counter(LEFT) > -600) {
    	motor(LEFT,-100);
        motor(RIGHT,-100);
    }
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    while (get_motor_position_counter(LEFT) > -1200) {
		motor(LEFT,-40);
        motor(RIGHT,40);
    }
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    while (get_motor_position_counter(LEFT) < 300) {
		motor(LEFT,95);
        motor(RIGHT,100);
    }
    ao();
    
    set_servo_position(CLAW,open);
    msleep(500);
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    while (get_motor_position_counter(LEFT) < 200) {
		motor(LEFT,98);
        motor(RIGHT,100);
    }
    ao();
    
    set_servo_position(ARM,barely_down);
    msleep(1000);
    set_servo_position(CLAW,closed);
    msleep(1000);
    set_servo_position(ARM,up);
    msleep(500);
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    while (get_motor_position_counter(LEFT) < 1200) {
		motor(LEFT,98);
        motor(RIGHT,100);
    }
    ao();
    msleep(500);
    set_servo_position(CLAW,open);
    msleep(500);
    
    //
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    while(get_motor_position_counter(LEFT) > -2000) {
    	motor(LEFT,-100);
        motor(RIGHT,-100);
    }
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    while(get_motor_position_counter(RIGHT) < 600) {
    	motor(RIGHT, 100);
        motor(LEFT, -100);
    }
    
    clear_motor_position_counter(0);
    clear_motor_position_counter(3);
    
    while(get_motor_position_counter(RIGHT) < 4000) {
    	motor(RIGHT, 80);
        motor(LEFT, 100);
    }
    
    set_servo_position(ARM,down);
    msleep(500);
    
}
