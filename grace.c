#include <kipr/wombat.h>

int LEFT = 3;
int RIGHT = 0;
int ARM = 0;

int UP = 1024;
int RELEASE = 40;

int main()
{
    wait_for_light (0);
    //arm up
    enable_servos();
    set_servo_position(ARM, UP);
    msleep(500);
    //push poms down ramp
    enable_servos();
    set_servo_position(ARM, RELEASE);
    msleep(500);
    
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    while (get_motor_position_counter(0) < 9000) {
		motor(LEFT,91);
        motor(RIGHT,89);
    }
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    while (get_motor_position_counter(0) < 5000) {
		motor(LEFT,90);
        motor(RIGHT,80);
    }
    //go back up
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    while (get_motor_position_counter(0) > -10000) {
		motor(LEFT,-90);
        motor(RIGHT,-80);
    }
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    while (get_motor_position_counter(0) > -5000) {
		motor(LEFT,-87);
        motor(RIGHT,-88);
    }
    //push block off platform
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    while (get_motor_position_counter(0) < 4000) {
		motor(LEFT,92);
        motor(RIGHT,88);
    }
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    while (get_motor_position_counter(0) < 5000) {
		motor(LEFT,92);
        motor(RIGHT,87);
    }

    //go back again
    clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    while (get_motor_position_counter(0) > -8000) {
		motor(LEFT,-89);
        motor(RIGHT,-89);
    }
    /*
    //Go down
     clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    while (get_motor_position_counter(0) < 12000) {
		motor(LEFT,95);
        motor(RIGHT,93);
    }
   clear_motor_position_counter(RIGHT);
    clear_motor_position_counter(LEFT);
    while (get_motor_position_counter(0) < 5000) {
		motor(LEFT,100);
        motor(RIGHT,70);
    } */
}


