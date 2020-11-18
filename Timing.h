  /*
   Timing Schedule
  */
    void TXtiming() // Timing
    {
    // run additional scripts here to generate data prior to TX if there is a large delay involved.
    if ((timeStatus() == timeSet) && (second() == 0) && (minute() >= 0)) 
    {
    setGPStime();
    if ((minute() % 10 == 0) && (second() <= 5)) // TX WSPR standard message
    {
      telemetry_set = true;
      loc4calc(); // Get position and update 4-char locator, 6-char locator and last 2 chars of 8-char locator
      call_telem(); // Update WSPR telemetry callsign based on previous information : position and altitude in meters
      loc_dbm_telem(); // Update WSPR telemetry locator and dbm. Get temperature, voltage, speed in knots, GPS status and sats number
      Serial.write("$PMTK161,0*28\r\n"); delay(700); //GPS Sleep - Off by Software
      //GPS_VCC_off(); //GPS off by hardware
      rf_on();
      freq = WSPR_FREQ;
      setModeWSPR(); // set WSPR standard mode
      encode(); // begin radio transmission
      rf_off(); delay(5);
      Serial.write("$PMTK101*32\r\n"); delay(50); //GPS Hotstart - On by Software
      //GPS_VCC_on(); //GPS on by hardware
    }
    
    else if ((minute() % 10 == 2) && (second() <= 5) && (telemetry_set == true))    // TX WSPR telemetry message
    {
      Serial.write("$PMTK161,0*28\r\n"); delay(700); //GPS Sleep - Off by Software
      //GPS_VCC_off(); //GPS off by hardware
      rf_on();
      freq = WSPR_FREQ;
      setModeWSPR_telem(); // set WSPR telemetry mode
      encode(); // begin radio transmission
      rf_off(); delay(5);
      Serial.write("$PMTK101*32\r\n"); delay(50); //GPS Hotstart - On by Software
      //GPS_VCC_on(); //GPS on by hardware
    }
    
    else if ((minute() % 10 == 4) && (second() <= 5) && (telemetry_set == true))    // TX WSPR standard message
    {
      Serial.write("$PMTK161,0*28\r\n"); delay(700); //GPS Sleep - Off by Software
      //GPS_VCC_off(); //GPS off by hardware
      rf_on();
      freq = WSPR_FREQ;
      setModeWSPR(); // set WSPR standard mode
      encode(); // begin radio transmission
      rf_off(); delay(5);
      Serial.write("$PMTK101*32\r\n"); delay(700); //GPS Hotstart - On by Software
      //GPS_VCC_on(); //GPS on by hardware
    }
    
    else if ((minute() % 10 == 6) && (second() <= 5) && (telemetry_set == true))    // TX WSPR standard message
    {
      Serial.write("$PMTK161,0*28\r\n"); delay(500); //GPS Sleep - Off by Software
      //GPS_VCC_off(); //GPS off by hardware
      rf_on();
      freq = WSPR_FREQ;
      setModeWSPR(); // set WSPR standard mode
      encode(); // begin radio transmission
      rf_off(); delay(5);
      Serial.write("$PMTK101*32\r\n"); delay(50); //GPS Hotstart - On by Software
      //GPS_VCC_on(); //GPS on by hardware
    }

    /*if (gps.location.age() > 800000)
    {
        delay(2000);
        Serial.print("$PMTK886,3*2B\r\n"); //Sets Balloon mode of SIM28ML
        delay(2000); */
    }
    }
    }
    
