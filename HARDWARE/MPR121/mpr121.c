#include "mpr121.h"





unsigned char mpr121Read(uint8_t address)
{
  unsigned char  data;
  
  i2cSendStart();
 
  
  i2cSendByte(MPR121_W);	// write 0xB4
  i2cWaitForComplete();
  
  i2cSendByte(address);	// write register address
  i2cWaitForComplete();
  
  i2cSendStart();
  
  i2cSendByte(MPR121_R);	// write 0xB5
  i2cWaitForComplete();
  data =i2cReceiveByte(TRUE);
  
  
  i2cSendStop();
  
  //cbi(TWCR, TWEN);	// Disable TWI
  //sbi(TWCR, TWEN);	// Enable TWI
  
  return data;
}

void mpr121Write(unsigned char address, unsigned char data)
{
  i2cSendStart();
  
  i2cSendByte(MPR121_W);// write 0xB4
  i2cWaitForComplete();
  
  i2cSendByte(address);	// write register address
  i2cWaitForComplete();
  
  i2cSendByte(data);
  i2cWaitForComplete();
  
  i2cSendStop();

}

void mpr121QuickConfig(void)
{
	
	 mpr121_irqInit();//interrupt set
  // Section A
  // This group controls filtering when data is > baseline.
  mpr121Write(MHD_R, 0x01);
  mpr121Write(NHD_R, 0x01);
  mpr121Write(NCL_R, 0x00);
  mpr121Write(FDL_R, 0x00);

  // Section B
  // This group controls filtering when data is < baseline.
  mpr121Write(MHD_F, 0x01);
  mpr121Write(NHD_F, 0x01);
  mpr121Write(NCL_F, 0xFF);
  mpr121Write(FDL_F, 0x02);
  
  // Section C
  // This group sets touch and release thresholds for each electrode
  mpr121Write(ELE0_T, TOU_THRESH);
  mpr121Write(ELE0_R, REL_THRESH);
  mpr121Write(ELE1_T, TOU_THRESH);
  mpr121Write(ELE1_R, REL_THRESH);
  mpr121Write(ELE2_T, TOU_THRESH);
  mpr121Write(ELE2_R, REL_THRESH);
  mpr121Write(ELE3_T, TOU_THRESH);
  mpr121Write(ELE3_R, REL_THRESH);
  mpr121Write(ELE4_T, TOU_THRESH);
  mpr121Write(ELE4_R, REL_THRESH);
  mpr121Write(ELE5_T, TOU_THRESH);
  mpr121Write(ELE5_R, REL_THRESH);
  mpr121Write(ELE6_T, TOU_THRESH);
  mpr121Write(ELE6_R, REL_THRESH);
  mpr121Write(ELE7_T, TOU_THRESH);
  mpr121Write(ELE7_R, REL_THRESH);
  mpr121Write(ELE8_T, TOU_THRESH);
  mpr121Write(ELE8_R, REL_THRESH);
  mpr121Write(ELE9_T, TOU_THRESH);
  mpr121Write(ELE9_R, REL_THRESH);
  mpr121Write(ELE10_T, TOU_THRESH);
  mpr121Write(ELE10_R, REL_THRESH);
  mpr121Write(ELE11_T, TOU_THRESH);
  mpr121Write(ELE11_R, REL_THRESH);
  
  // Section D
  // Set the Filter Configuration
  // Set ESI2
  mpr121Write(FIL_CFG, 0x04);
  
  // Section E
  // Electrode Configuration
  // Enable 6 Electrodes and set to run mode
  // Set ELE_CFG to 0x00 to return to standby mode
  mpr121Write(ELE_CFG, 0x0C);	// Enables all 12 Electrodes
  //mpr121Write(ELE_CFG, 0x06);		// Enable first 6 electrodes
  
  // Section F
  // Enable Auto Config and auto Reconfig
  /*mpr121Write(ATO_CFG0, 0x0B);
  mpr121Write(ATO_CFGU, 0xC9);	// USL = (Vdd-0.7)/vdd*256 = 0xC9 @3.3V   mpr121Write(ATO_CFGL, 0x82);	// LSL = 0.65*USL = 0x82 @3.3V
  mpr121Write(ATO_CFGT, 0xB5);*/	// Target = 0.9*USL = 0xB5 @3.3V

}

char getPhoneNumber()
{
  int touchNumber;
	int j;
  uint16_t touchstatus;
	char key=-1;
  //Serial.println("Please Enter a phone number...");
  
    //while(key_pressed);//用while读取会阻塞程序运行
	if(key_pressed==0)//非阻塞方式
	{
	key_pressed=1;
    touchNumber = 0;
    
    touchstatus = mpr121Read(0x01) << 8;
    touchstatus |= mpr121Read(0x00);
    
    for (j=0; j<12; j++)  // Check how many electrodes were pressed
    {
      if ((touchstatus & (1<<j)))
        touchNumber++;
    }
    
    if (touchNumber == 1)
    {
      if (touchstatus & (1<<STAR))
        key = '*';
      else if (touchstatus & (1<<SEVEN))
        key = '7';
      else if (touchstatus & (1<<FOUR))
        key= '4';
      else if (touchstatus & (1<<ONE))
        key = '1';
      else if (touchstatus & (1<<ZERO))
        key= '0';
      else if (touchstatus & (1<<EIGHT))
        key = '8';
      else if (touchstatus & (1<<FIVE))
        key = '5';
      else if (touchstatus & (1<<TWO))
        key = '2';
      else if (touchstatus & (1<<POUND))
        key = '#';
      else if (touchstatus & (1<<NINE))
        key = '9';
      else if (touchstatus & (1<<SIX))
        key = '6';
      else if (touchstatus & (1<<THREE))
        key = '3';
        
      //Serial.print(key[i]);
      
    }
    else if (touchNumber == 0);
    else;
      //Serial.println("Only touch ONE button!");
	}
		return key;
}