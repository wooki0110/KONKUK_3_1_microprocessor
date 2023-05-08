# KON_3_1_microprocessor

## Final project

### 프로젝트 목적
Xilnx ZYNQ board 이용 Wifi에 사용되는 LDPCD, QRD 속도 개선

###LDPCD
#### 결과
![image](https://user-images.githubusercontent.com/98706037/236806535-90bc217f-3b9a-45b9-adb9-b7fe4d020159.png)

속도 개선 : 124.596us -> 22.866us
#### 적용 아이디어
(1) Loop Optimization
![image](https://user-images.githubusercontent.com/98706037/236806829-89b39892-fd2e-4d58-a4f0-515183e4ae6b.png)

(2) Initialize in For loop
![image](https://user-images.githubusercontent.com/98706037/236807048-33cd81ad-d561-4868-afb4-273f1438c646.png)

(3) Minimize access for global data 
![image](https://user-images.githubusercontent.com/98706037/236807179-a7f561a6-93d2-4548-8ebc-d7018dfdcd83.png)

(4) Use additional variable
![image](https://user-images.githubusercontent.com/98706037/236807314-6b46d093-00d7-47c4-8a27-706c2e95174c.png)

###QRD
#### 결과
(1) high delay & low SNR
![image](https://user-images.githubusercontent.com/98706037/236808314-7a023226-c51d-4131-880e-6c6a23f08a80.png)
속도 개선 : 59.224 -> 27.406
(2) low delay & high SNR
![image](https://user-images.githubusercontent.com/98706037/236808533-2b0e7d6a-7cfb-4f6e-8705-82279c64f25c.png)
속도 개선 : 59.224 -> 24.975


#### 적용 아이디어
(1) multiply&division -> shift

(2) Float square root approximation alogorithm
![image](https://user-images.githubusercontent.com/98706037/236808704-88147340-d7ad-4d3b-9a9c-84b94b5a059a.png)

(3) Use additional variable for division to multiply
![image](https://user-images.githubusercontent.com/98706037/236808757-ac4c9394-fab0-4ae9-8615-83ae4bdf8654.png)

(4) Use temporary variable
![image](https://user-images.githubusercontent.com/98706037/236808992-d08b2dc2-beac-41b9-873e-770bd1fcee88.png)

