void setup_imu()
{
    // Serial.println("setup imu");
    // Try to initialize!
    if (!mpu.begin())
    {
        Serial.println("Failed to find MPU6050 chip");

        while (1)
        {
            Serial.println("Failed to find MPU6050 chip");

            delay(10);
        }
    }
    // Serial.println("MPU6050 Found!");
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

    mpu.setGyroRange(MPU6050_RANGE_500_DEG);

    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

    Serial.println("");

    // calibrate_imu();
}

void calibrate_imu(){
   // Initialize variables to store calibration values
    float ax_offset = 0, ay_offset = 0, az_offset = 0;
    float gx_offset = 0, gy_offset = 0, gz_offset = 0;



    delay(1000); // Allow time for the sensor to stabilize
    // Serial.println("Calibrating...");

    // Collect data for calibration
    for (int i = 0; i < 1000; i++)
    {
        get_imu_data(accel, gyro);

        ax_offset += accel[0];
        ay_offset += accel[1];
        az_offset += accel[2]; 
        gx_offset += gyro[0];
        gy_offset += gyro[1];
        gz_offset += gyro[2];

        delay(3); // Small delay to give the sensor time to reset
    }

    // Calculate the average offsets
    ax_offset /= 1000;
    ay_offset /= 1000;
    az_offset /= 1000;
    gx_offset /= 1000;
    gy_offset /= 1000;
    gz_offset /= 1000;

    // Set the calculated offsets
    accel_offset[0] += ax_offset;   
    accel_offset[1] += ay_offset;
    accel_offset[2] += az_offset;
    gyro_offset[0] += gx_offset;
    gyro_offset[1] += gy_offset;
    gyro_offset[2] += gz_offset;

    // // Print the calibration results
    // Serial.println("Calibration Complete!");
    // Serial.print("Accel Offsets: ");
    // Serial.print("X: ");
    // Serial.print(accel_offset[0]);
    // Serial.print(" Y: ");
    // Serial.print(accel_offset[1]);
    // Serial.print(" Z: ");
    // Serial.println(accel_offset[2]);

    // Serial.print("Gyro Offsets: ");
    // Serial.print("X: ");
    // Serial.print(gyro_offset[0]);
    // Serial.print(" Y: ");
    // Serial.print(gyro_offset[1]);
    // Serial.print(" Z: ");
    // Serial.println(gyro_offset[2]);
}

void get_imu_data(float *accel, float *gyro)
{
    sensors_event_t a, g, temp;

    mpu.getEvent(&a, &g, &temp);

    accel[0] = a.acceleration.x - accel_offset[0];
    accel[1] = a.acceleration.y - accel_offset[1];
    accel[2] = a.acceleration.z - accel_offset[2];

    gyro[0] = g.gyro.x - gyro_offset[0];
    gyro[1] = g.gyro.y - gyro_offset[1];
    gyro[2] = g.gyro.z - gyro_offset[2];
}