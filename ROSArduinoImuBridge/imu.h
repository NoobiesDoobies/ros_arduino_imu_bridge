// SDA -> A3
// SCL -> A2
// # define MPU_SDA A3
// # define MPU_SCL A2

// # define MPU_ADDR 0x68

# include <Adafruit_MPU6050.h>
# include <Wire.h>

float accel[3], gyro[3];
float accel_offset[3], gyro_offset[3];

Adafruit_MPU6050 mpu;

void setup_imu();
void calibrate_imu();
void get_imu_data(float * accel, float * gyro);