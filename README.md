# HM10-ANCS
simple display that shows notifications

HMSoft verion V524 added ANCS support (not include HMSensor version)
================================================================================

1. How to open ANCS function
  1.1 Please read apple notification ducument first.
  1.2 Send AT+TYPE3 command change to AUTH and BOND mode.
  1.3 Send AT+ANCS1 command to open ANCS.
  1.4 Send AT+PASS[para1] command to set passcode. Default passcode is "000000"
  1.5 Send AT+RESET to restart module.
  Now you can use LightBlue or our software to scan and made a connect with module.
  iOS will ask you input passcode. please input your passcode value.
  If all is okay,  you should receive AT+ANCS[para1] command from module UART.
2. About AT+ANCS[para1] command
  AT+ANCSN: module open Notification Source SUCCESSED.
  AT+ANCSC: module open Control Point SUCCESSED.
  AT+ANCSD: module open Data Source SUCCESSED.
3. Get ANCS notification information
  When iOS notification center has an change (such as call, email, shortmessage)
  Module will output AT+ANCS8[para2] command through UART.
4. About AT+ANCS8[para2] command.
   Format such as : AT+ANCS801012345
       8: The length of the para1.
       0: EventID.
          EventIDNotificationAdded = 0,
          EventIDNotificationModified = 1,
          EventIDNotificationRemoved = 2,
          Reserved EventID values = 3¨C255
       1: CategoryID.
          CategoryIDOther = 0,
          CategoryIDIncomingCall = 1,
          CategoryIDMissedCall = 2,
          CategoryIDVoicemail = 3,
          CategoryIDSocial = 4,
          CategoryIDSchedule = 5,
          CategoryIDEmail = 6,
          CategoryIDNews = 7,
          CategoryIDHealthAndFitness = 8,
          CategoryIDBusinessAndFinance = 9,
          CategoryIDLocation = 10,
          CategoryIDEntertainment = 11,
          Reserved CategoryID values = 12¨C255
      01: CategoryCount
          The current number of active iOS notifications in the given category. 
          For example, if two unread emails are sitting in a user¡¯s email inbox, 
          and a new email is pushed to the user¡¯s iOS device, the value of CategoryCount is 3.
    2345: NotificationUID
          A 32-bit numerical value that is the unique identifier (UID) for the iOS notification. 
          This value can be used as a handle in commands sent to the Control Point characteristic 
          to retrieve more information about the iOS notification.
5. Get Notification Attributes
   AT+ANCS[para1][para2][para3]
   Format such as: AT+ANCS2345100
   para1: NotificationUID.
   Para2: NotificationAttributeID
          NotificationAttributeIDAppIdentifier = 0,
          NotificationAttributeIDTitle = 1, (Needs to be followed by a 2-bytes max length parameter)
          NotificationAttributeIDSubtitle = 2, (Needs to be followed by a 2-bytes max length parameter)
          NotificationAttributeIDMessage = 3, (Needs to be followed by a 2-bytes max length parameter)
          NotificationAttributeIDMessageSize = 4,
          NotificationAttributeIDDate = 5,
          Reserved NotificationAttributeID values = 6¨C255
   Para3: max length parameter
          If para2 value is 0, 4, 5, para3 must set to "00"
          if para2 value is 1, 2, 3, you need setup a number.
6. Aoubt Get Notification Attributes Response
   AT+ANCSW: Send request SUCCESSED.
   AT+ANCS[para1]: 
   para1 value is 0x00 ~ 0x14.
   Mean the next package length you need to receive.
   [........]: The byte array you need to receive.
               Show in apple Notification document Figure 2-6. (page 9)
   After you receive AT+ANCSW, you may receive AT+ANCS[para1] many times. until the Fingure 2-6 package is completed.
7. How to remove ANCS.
   7.1 Remove bond information from iOS.
   7.2 Execute AT+ERASE remove module bond information.
   7.3 Execute AT+ANCS0 close module ANCS function.
   7.4 Execute AT+RESET to restart module.


   ANCS is easy to use, you dont need write any iOS code. iOS will manage the bluetooth link and push the message to module.
   If you have any good idea, please mail me: guocg@jnhuamao.cn.
   My english is not good, I hope you can made this document perfect. 
   Thank you.



                                               HMSoft
                                               www.jnhuamao.cn
                                               www.huamaosoft.com
                                               2014-03-08
