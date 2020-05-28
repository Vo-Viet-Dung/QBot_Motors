//-----------------------------------------------------------------------------------------------
//  SỬ DỤNG 2 ĐỘNG CƠ: 
//  Tham khảo các hàm và tham số trong file thư viện WeMake/WMDCMotor.h
//  Tham khảo qui tắc đánh số cặp pin điều khiển động cơ ở file thư viện WeMake/WMDCPort.h 
//
//    @param[in]  speed   tốc độ di chuyển. số nguyên từ -100 tới 100. Nếu ngoài phạm vi thì làm tròn về 100. Phải > 10, <-10
//    motor.reverseRun(speed) // speed > 0 là tiến lên, speed < 0 là lùi
//    motor.run(speed)        // speed > 0 là lùi, speed < 0 là tiến lên
//-----------------------------------------------------------------------------------------------
#include<Arduino.h>
#include <WMHead.h>
#include <WMBoard.h>

/// Tạo hanlder điều khiển động cơ trái với 2 pin 8(hướng quay), và 6(công suất PWM)
WMDCMotor motor1(8);
/// Tạo hanlder điều khiển động cơ phải với 2 pin 7(hướng quay), và 5(công suất PWM)
WMDCMotor motor2(7);   

void setup() {
  motor1.reverseRun(100);
}

void loop() {
  motor2.reverseRun(50);      //Tiến về phía trước với tốc độ 50% tối đa
  delay(1000);                //Duy trì thiết lập động cơ như trên
  motor2.run(0);              //Dừng động cơ
  delay(1000);                //Duy trì thiết lập động cơ như trên
  motor2.run(30);             //Lùi về phía sau với tốc độ 30% tối đa
  delay(1000);                //Duy trì thiết lập động cơ như trên
  motor2.run(-11);            //Tiến về phía trước với tốc độ 11% tối đa. Thực nghiệm cho thấy công suất <= 10% là dừng động cơ luôn
  delay(1000);                //Duy trì thiết lập động cơ như trên
}
